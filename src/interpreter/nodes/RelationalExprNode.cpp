#include <string>
#include <memory>

#include "RelationalExprNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol RelationalExprNode::addSymbols() {
  return Symbol::TYPE("bool");
}

Symbol RelationalExprNode::sematicCheck(Symbol param) {
  Symbol lhs = children[0]->sematicCheck();
  Symbol rhs = children[1]->sematicCheck();
  Symbol sym = Symbol::TYPE("bool");

  if (lhs.isError() || rhs.isError()) {
    return Symbol::ERROR();
  }

  if (value.compare("==") == 0 || value.compare("!=") == 0){
    if (lhs.dataType.compare(rhs.dataType) != 0) {
      ErrorHandler::error(value + " lhs is not of the same type as rhs", line, col);
      sym = Symbol::ERROR();
    }
  }
  else {
    if (lhs.dataType.compare("int") != 0) {
		ErrorHandler::error(value + " lhs is not an integer", line, col);
		sym = Symbol::ERROR();
    }
    
    if (rhs.dataType.compare("int") != 0) {
		ErrorHandler::error(value + " rhs is not an integer", line, col);
		sym = Symbol::ERROR();
    }
  }
  
  return sym;
}

Symbol RelationalExprNode::execute(Symbol sym) {
  Symbol lhs = children[0]->execute();
  Symbol rhs = children[1]->execute();

  if(value == "==") {
    if(lhs.dataType.compare("string") == 0) return get<string>(lhs.value) == get<string>(rhs.value) ? Symbol::EXPRESSION("bool", 1) : Symbol::EXPRESSION("bool", 0);
    else return get<int>(lhs.value) == get<int>(rhs.value) ? Symbol::EXPRESSION("bool", 1) : Symbol::EXPRESSION("bool", 0);
  }
  else if(value == "!=") {
    if(lhs.dataType.compare("string") == 0) return get<string>(lhs.value) != get<string>(rhs.value) ? Symbol::EXPRESSION("bool", 1) : Symbol::EXPRESSION("bool", 0);
    else return get<int>(lhs.value) != get<int>(rhs.value) ? Symbol::EXPRESSION("bool", 1) : Symbol::EXPRESSION("bool", 0);
  }
  else if(value == "<") {
    return get<int>(lhs.value) < get<int>(rhs.value) ? Symbol::EXPRESSION("bool", 1) : Symbol::EXPRESSION("bool", 0);
  }
  else if(value == ">") {
    return get<int>(lhs.value) > get<int>(rhs.value) ? Symbol::EXPRESSION("bool", 1) : Symbol::EXPRESSION("bool", 0);
  }
  else if(value == ">=") {
    return get<int>(lhs.value) >= get<int>(rhs.value) ? Symbol::EXPRESSION("bool", 1) : Symbol::EXPRESSION("bool", 0);
  }
  else if(value == "<=") {
    return get<int>(lhs.value) <= get<int>(rhs.value) ? Symbol::EXPRESSION("bool", 1) : Symbol::EXPRESSION("bool", 0);
  }

  ErrorHandler::error(value + " operator not found", line, col);
  return Symbol::ERROR();
}
