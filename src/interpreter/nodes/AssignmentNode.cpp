#include <string>
#include <memory>

#include "AssignmentNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol AssignmentNode::addSymbols() {
  return children[0]->addSymbols();
}

Symbol AssignmentNode::sematicCheck(Symbol param) {
  Symbol rhs = children[1]->sematicCheck();
  Symbol lhs = children[0]->sematicCheck();
  Symbol sym = Symbol::TYPE(lhs.dataType);

  if (lhs.isError() || rhs.isError()) {
    return Symbol::ERROR();
  }

  if (lhs.dataType.compare(rhs.dataType) != 0) {
    ErrorHandler::error(value + " lhs is not of the same type as rhs");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol AssignmentNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
