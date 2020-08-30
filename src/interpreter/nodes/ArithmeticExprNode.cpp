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
  string lhs = children[0]->addSymbols().dataType;
  string rhs = children[1]->addSymbols().dataType;
  Symbol sym = Symbol::TYPE("int");

  if (value.compare("+") == 0) {
    return Symbol::TYPE((lhs.compare("string") == 0 || rhs.compare("string") == 0) ? "string" : "int");
  }

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

Symbol ArithmeticExprNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
