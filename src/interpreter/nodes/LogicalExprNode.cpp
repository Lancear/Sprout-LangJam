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
    ErrorHandler::error(value + " lhs is not a boolean");
    sym = Symbol::ERROR();
  }
  
  if (rhs.dataType.compare("bool") != 0) {
    ErrorHandler::error(value + " rhs is not a boolean");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol LogicalExprNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
