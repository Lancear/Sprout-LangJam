#include <string>
#include <memory>

#include "ArithmeticExprNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ArithmeticExprNode::addSymbols() {
  if (value.compare("+") == 0) {
    string lhs = children[0]->addSymbols().dataType;
    string rhs = children[1]->addSymbols().dataType;

    return Symbol::TYPE((lhs.compare("string") == 0 || rhs.compare("string") == 0) ? "string" : "int");
  }

  return Symbol::TYPE("int");
}

Symbol ArithmeticExprNode::sematicCheck(Symbol param) {
  Symbol lhs = children[0]->sematicCheck();
  Symbol rhs = children[1]->sematicCheck();
  Symbol sym = Symbol::TYPE("int");

  if (lhs.isError() || rhs.isError()) {
    return Symbol::ERROR();
  }

  if (value.compare("+") == 0 && (lhs.dataType.compare("string") == 0 || rhs.dataType.compare("string") == 0)) {
    if (lhs.dataType.compare("void") == 0) {
      ErrorHandler::error(value + " lhs is no value, it is void", line, col);
	    sym = Symbol::ERROR();
    }

    if (rhs.dataType.compare("void") == 0) {
      ErrorHandler::error(value + " lhs is no value, it is void", line, col);
	    sym = Symbol::ERROR();
    }

    return Symbol::TYPE("string");
  }

  if (lhs.dataType.compare("int") != 0) {
    ErrorHandler::error(value + " lhs is not an integer", line, col);
    sym = Symbol::ERROR();
  }
  
  if (rhs.dataType.compare("int") != 0) {
	  ErrorHandler::error(value + " lhs is not an integer", line, col);
	  sym = Symbol::ERROR();
  }

  return sym;
}

Symbol ArithmeticExprNode::execute(Symbol sym) {
  char op = value[0];
  Symbol lhs = children[0]->execute();
  Symbol rhs = children[1]->execute();

  if(lhs.dataType == "int" && rhs.dataType == "int") {
    int result = 0;

    switch(op) {
      case '+':
        result = get<int>(lhs.value) + get<int>(rhs.value);
        break;
      case '-':
        result = get<int>(lhs.value) - get<int>(rhs.value);
        break;
      case '*':
        result = get<int>(lhs.value) * get<int>(rhs.value);
        break;
      case '/':
        if(get<int>(rhs.value) == 0) {
			ErrorHandler::error("x / 0 is undefined", line, col);
			return Symbol::ERROR();
        }

        result = get<int>(lhs.value) / get<int>(rhs.value);
        break;
      case '%':
        if(get<int>(rhs.value) == 0) {
			ErrorHandler::error("x mod 0 is undefined", line, col);
			return Symbol::ERROR();
        }

        result = get<int>(lhs.value) - get<int>(rhs.value) * (get<int>(lhs.value) / get<int>(rhs.value));
        break;
      default:
		  ErrorHandler::error(value + " operator not found", line, col);
		  return Symbol::ERROR();
    }

    return Symbol::EXPRESSION("int", result);
  }
  else if(lhs.dataType == "string" && rhs.dataType == "string") {
    return Symbol::EXPRESSION("string", get<string>(lhs.value) + get<string>(rhs.value));
  }
  else if(lhs.dataType == "string" && rhs.dataType == "int") {
    return Symbol::EXPRESSION("string", get<string>(lhs.value) + to_string(get<int>(rhs.value)));
  }
  else if(lhs.dataType == "int" && rhs.dataType == "string") {
    return Symbol::EXPRESSION("string", to_string(get<int>(lhs.value)) + get<string>(rhs.value));
  }
  else if(lhs.dataType == "string" && rhs.dataType == "bool") {
    string result;
    get<int>(rhs.value) == 1 ? result = "true" : result = "false";
    return Symbol::EXPRESSION("string", get<string>(lhs.value) + result);
  }
  else if(lhs.dataType == "bool" && rhs.dataType == "string") {
    string result;
    get<int>(lhs.value) == 1 ? result = "true" : result = "false";
    return Symbol::EXPRESSION("string", result + get<string>(rhs.value));
  }
  else if(lhs.dataType == "string" && rhs.dataType == "char") {
    return Symbol::EXPRESSION("string", get<string>(lhs.value) + (char)get<int>(rhs.value));
  }
  else if(lhs.dataType == "char" && rhs.dataType == "string") {
    return Symbol::EXPRESSION("string", string(1, (char)get<int>(lhs.value)) + get<string>(rhs.value));
  }

  ErrorHandler::error("expression not handled", line, col);
  return Symbol::ERROR();
}
