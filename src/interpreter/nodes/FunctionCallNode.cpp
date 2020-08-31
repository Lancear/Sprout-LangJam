#include <string>
#include <memory>
#include <variant>

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

  if (!syms->contains(value)) {
    ErrorHandler::error("unknown function " + value);
    return Symbol::ERROR();
  }

  if (!syms->get(value).isFunction() && !syms->get(value).isClass()) {
    ErrorHandler::error(value + " is not a function");
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

  Symbol args[children.size()];
  for (int i = 0; i < children.size(); i++) {
    args[i] = children[i]->sematicCheck();
  }

  if (nrOfParams != children.size()) {
    ErrorHandler::error("Incorrect number of arguments for function call to " + value + ", got " + to_string(children.size()) + " arguments, expected " + to_string(nrOfParams));
    sym = Symbol::ERROR();
  }
  else {
    syms->pushScope(fn->scope);

    for (int i = 0; i < nrOfParams; i++) {
      string paramName = fn->children[paramsNode]->children[i]->value;

      if (!args[i].isError() && syms->get(paramName).dataType.compare(args[i].dataType) != 0) {
        ErrorHandler::error("datatype of argument " + to_string(i + 1) + " does not match the datatype of parameter " + to_string(i + 1) + ", " + paramName + ", datatype is " + args[i].dataType + ", expected " + syms->get(paramName).dataType);
        sym = Symbol::ERROR();
      }
    }

    syms->popScope();
  }  

  return (sym.isError()) ? sym : Symbol::TYPE(syms->get(value).dataType);
}

Symbol FunctionCallNode::execute(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  Symbol args[children.size()];

  for (int i = 0; i < children.size(); i++) {
    args[i] = children[i]->execute();
  }

  FunctionNode* fn = (FunctionNode*)get<void*>(syms->get(value).value);
  return fn->execute(args);
}
