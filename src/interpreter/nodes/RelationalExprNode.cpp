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
  string lhs = children[0]->addSymbols().dataType;
  string rhs = children[1]->addSymbols().dataType;
  Symbol sym = Symbol::TYPE("bool");

  if (value.compare("==") == 0 || value.compare("!=") == 0 && lhs.compare(rhs) != 0) {
    ErrorHandler::error("lhs is not of the same type as rhs");
    sym = Symbol::ERROR();
  }
  else {
    if (lhs.compare("int") != 0) {
      ErrorHandler::error("lhs is not an integer");
      sym = Symbol::ERROR();
    }
    
    if (rhs.compare("int") != 0) {
      ErrorHandler::error("rhs is not an integer");
      sym = Symbol::ERROR();
    }
  }
  
  return sym;
}

Symbol RelationalExprNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
