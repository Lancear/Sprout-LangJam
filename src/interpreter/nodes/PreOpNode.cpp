#include <string>
#include <memory>

#include "PreOpNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol PreOpNode::addSymbols() {
  return children[0]->addSymbols();
}


Symbol PreOpNode::sematicCheck(Symbol param) {
  string expr = children[0]->addSymbols().dataType;
  Symbol sym = Symbol::TYPE(expr);

  if (value.compare("!")) {
    if (expr.compare("bool") != 0) {
      ErrorHandler::error("expr is not an boolean");
      sym = Symbol::ERROR();
    }
  }
  else {
    if (expr.compare("int") != 0) {
      ErrorHandler::error("expr is not an integer");
      sym = Symbol::ERROR();
    }
  }

  return sym;
}

Symbol PreOpNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
