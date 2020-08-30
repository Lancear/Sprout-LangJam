#include <string>
#include <memory>

#include "TernaryExprNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol TernaryExprNode::addSymbols() {
  return children[1]->addSymbols();
}

Symbol TernaryExprNode::sematicCheck(Symbol param) {
  Symbol cond = children[0]->sematicCheck();
  Symbol lhs = children[1]->sematicCheck();
  Symbol rhs = children[2]->sematicCheck();

  if (cond.isError() || lhs.isError() || rhs.isError()) {
    return Symbol::ERROR();
  }

  Symbol sym = lhs;

  if (cond.dataType.compare("bool") != 0) {
    ErrorHandler::error(value + " condition is not a boolean");
    sym = Symbol::ERROR();
  }

  if (lhs.dataType.compare(rhs.dataType) != 0) {
    ErrorHandler::error(value + " lhs is not of the same type as rhs");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol TernaryExprNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
