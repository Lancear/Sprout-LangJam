#include <string>
#include <memory>

#include "LogicalExprNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol LogicalExprNode::addSymbols() {
  return Symbol::TYPE("bool");
}

Symbol LogicalExprNode::sematicCheck(Symbol param) {
  Symbol lhs = children[0]->sematicCheck();
  Symbol rhs = children[1]->sematicCheck();
  Symbol sym = Symbol::TYPE("bool");

  if (lhs.isError() || rhs.isError()) {
    return Symbol::ERROR();
  }

  if (lhs.dataType.compare("bool") != 0) {
	  ErrorHandler::error(value + " lhs is not a boolean", line, col);
	  sym = Symbol::ERROR();
  }
  
  if (rhs.dataType.compare("bool") != 0) {
	  ErrorHandler::error(value + " rhs is not a boolean", line, col);
	  sym = Symbol::ERROR();
  }

  return sym;
}

Symbol LogicalExprNode::execute(Symbol sym) {
  int lhs = get<int>(children[0]->execute().value);
  int rhs = get<int>(children[1]->execute().value);
  int result = 0;

  if(value == "||") result = lhs || rhs;
  else if(value == "&&") result = lhs && rhs;
  else {
	  ErrorHandler::error(value + " operator not found", line, col);
	  return Symbol::ERROR();
  }

  return Symbol::EXPRESSION("bool", result);
}
