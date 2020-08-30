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
  string lhs = children[0]->addSymbols().dataType;
  string rhs = children[1]->addSymbols().dataType;
  Symbol sym = Symbol::TYPE("bool");

  if (lhs.compare("bool") != 0) {
    ErrorHandler::error("lhs is not an boolean");
    sym = Symbol::ERROR();
  }
  
  if (rhs.compare("bool") != 0) {
    ErrorHandler::error("rhs is not an boolean");
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
