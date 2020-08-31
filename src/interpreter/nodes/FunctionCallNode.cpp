#include <string>
#include <memory>
#include <variant>
#include <iostream>

#include "FunctionCallNode.hpp"
#include "FunctionNode.hpp"
#include "ClassNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol FunctionCallNode::sematicCheck(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  Symbol sym = Symbol::EMPTY();
  FunctionNode* fn;
  Symbol args[children.size()];

  if (value.compare("Console.write") == 0) {
    args[0] = children[0]->sematicCheck();

    if (1 != children.size()) {
      ErrorHandler::error("Incorrect number of arguments for function call to " + value + ", got " + to_string(children.size()) + " arguments, expected  1", line, col);
      sym = Symbol::ERROR();
    }

    if (!args[0].isError() && args[0].dataType.compare("string") != 0) {
      ErrorHandler::error("datatype of argument 1 does not match the datatype of parameter 1, message datatype is " + args[0].dataType + ", expected string", line, col);
      sym = Symbol::ERROR();
    }

    return (sym.isError()) ? sym : Symbol::TYPE("void");
  }
  else if (value.compare("Console.writeln") == 0) {
    if (1 != children.size()) {
      ErrorHandler::error("Incorrect number of arguments for function call to " + value + ", got " + to_string(children.size()) + " arguments, expected 1", line, col);
      sym = Symbol::ERROR();
    }

    args[0] = children[0]->sematicCheck();

    if (!args[0].isError() && args[0].dataType.compare("string") != 0) {
      ErrorHandler::error("datatype of argument 1 does not match the datatype of parameter 1, message, datatype is " + args[0].dataType + ", expected string", line, col);
      sym = Symbol::ERROR();
    }

    return (sym.isError()) ? sym : Symbol::TYPE("void");
  }
  else if (value.compare("Console.readint") == 0) {
    return Symbol::TYPE("int");
  }
  else if (value.compare("Console.readchar") == 0) {
    return Symbol::TYPE("char");
  }
  else if (value.compare("Console.readbool") == 0) {
    return Symbol::TYPE("bool");
  }
  else if (value.compare("Console.readln") == 0) {
    return Symbol::TYPE("string");
  }
  else {
    if (!syms->contains(value)) {
      ErrorHandler::error("unknown function " + value, line, col);
      return Symbol::ERROR();
    }

    if (!syms->get(value).isFunction() && !syms->get(value).isClass()) {
      ErrorHandler::error(value + " is not a function", line, col);
      return Symbol::ERROR();
    }

    if (syms->get(value).isClass()) {
      ClassNode* clazz = (ClassNode*)get<void*>(syms->get(value).value);
      syms->pushScope(clazz->scope);
      fn = (FunctionNode*)get<void*>(syms->get(value).value);
      syms->popScope();
    }
    else {
      fn = (FunctionNode*)get<void*>(syms->get(value).value);
    }

    int paramsNode = (fn->children.size() == 4) ? 1 : 0;
    int nrOfParams = fn->children[paramsNode]->children.size();

    for (int i = 0; i < children.size(); i++) {
      args[i] = children[i]->sematicCheck();
    }

    if (nrOfParams != children.size()) {
      ErrorHandler::error("Incorrect number of arguments for function call to " + value + ", got " + to_string(children.size()) + " arguments, expected " + to_string(nrOfParams), line, col);
      sym = Symbol::ERROR();
    }
    else {
      syms->pushScope(fn->scope);

      for (int i = 0; i < nrOfParams; i++) {
        string paramName = fn->children[paramsNode]->children[i]->value;

        if (!args[i].isError() && syms->get(paramName).dataType.compare(args[i].dataType) != 0) {
          ErrorHandler::error("datatype of argument " + to_string(i + 1) + " does not match the datatype of parameter " + to_string(i + 1) + ", " + paramName + ", datatype is " + args[i].dataType + ", expected " + syms->get(paramName).dataType, line, col);
          sym = Symbol::ERROR();
        }
      }

      syms->popScope();
    }

    return (sym.isError()) ? sym : Symbol::TYPE(syms->get(value).dataType);
  } 
}

Symbol FunctionCallNode::execute(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  Symbol args[children.size()];

  for (int i = 0; i < children.size(); i++) {
    args[i] = children[i]->execute();
  }

  if (value.compare("Console.write") == 0) {
    cout << get<string>(args[0].value);
    return Symbol::EMPTY();
  }
  else if (value.compare("Console.writeln") == 0) {
    cout << get<string>(args[0].value) << endl;
    return Symbol::EMPTY();
  }
  else if (value.compare("Console.readint") == 0) {
    int x = 0;
    cin.clear();
    cin.ignore();
    cin >> x;
    return Symbol::EXPRESSION("int", x);
  }
  else if (value.compare("Console.readchar") == 0) {
    char x;
    cin.clear();
    cin.ignore();
    x = cin.get();
    return Symbol::EXPRESSION("char", (int)x);
  }
  else if (value.compare("Console.readbool") == 0) {
    string x;
    cin.clear();
    cin.ignore();
    getline (cin, x);
    return Symbol::EXPRESSION("bool", (x.compare("true") == 0));
  }
  else if (value.compare("Console.readln") == 0) {
    string x;
    cin.clear();
    cin.ignore();
    getline (cin, x);
    return Symbol::EXPRESSION("string", x);
  }
  else {
    FunctionNode* fn = (FunctionNode*)get<void*>(syms->get(value).value);
    return fn->execute(args);
  }
}
