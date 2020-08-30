#include <string>
#include <memory>

#include "BitwiseExprNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol BitwiseExprNode::addSymbols() {
  return Symbol::TYPE("int");
}

Symbol BitwiseExprNode::sematicCheck(Symbol param) {
  string lhs = children[0]->addSymbols().dataType;
  string rhs = children[1]->addSymbols().dataType;
  Symbol sym = Symbol::TYPE("int");

  if (lhs.compare("int") != 0) {
    ErrorHandler::error("lhs is not an integer");
    sym = Symbol::ERROR();
  }
  
  if (rhs.compare("int") != 0) {
    ErrorHandler::error("rhs is not an integer");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol BitwiseExprNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
