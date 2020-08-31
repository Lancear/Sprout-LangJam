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
    return Symbol::TYPE("string");
  }

  if (lhs.dataType.compare("int") != 0) {
    ErrorHandler::error(value + " lhs is not an integer");
    sym = Symbol::ERROR();
  }
  
  if (rhs.dataType.compare("int") != 0) {
    ErrorHandler::error(value + " lhs is not an integer");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol ArithmeticExprNode::execute(Symbol sym) {
  char op = value[0];
  Symbol lhs = children[0]->execute();
  Symbol rhs = children[1]->execute();

  if(children[0]->execute().dataType == "int" && children[1]->execute().dataType == "int") {
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
          ErrorHandler::error("x / 0 is undefined");
          return Symbol::ERROR();
        }

        result = get<int>(lhs.value) / get<int>(rhs.value);
        break;
      case '%':
        if(get<int>(rhs.value) == 0) {
          ErrorHandler::error("x mod 0 is undefined");
          return Symbol::ERROR();
        }

        result = get<int>(lhs.value) - get<int>(rhs.value) * (get<int>(lhs.value) / get<int>(rhs.value));
        break;
      default:
        ErrorHandler::error(value + " operator not found");
        return Symbol::ERROR();
    }

    return Symbol::EXPRESSION("int", result);
  }
  else if(children[0]->execute().dataType == "string" && children[1]->execute().dataType == "string") {
    return Symbol::EXPRESSION("string", get<string>(lhs.value) + get<string>(rhs.value));
  }

  return Symbol::EMPTY();
}
