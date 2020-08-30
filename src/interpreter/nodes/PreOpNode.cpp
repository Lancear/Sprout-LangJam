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
  Symbol expr = children[0]->sematicCheck();
  Symbol sym = Symbol::TYPE(expr.dataType);

  if (expr.isError()) {
    return Symbol::ERROR();
  }

  if (value.compare("!") == 0) {
    if (expr.dataType.compare("bool") != 0) {
      ErrorHandler::error(value + " expr is not an boolean");
      sym = Symbol::ERROR();
    }
  }
  else {
    if (expr.dataType.compare("int") != 0) {
      ErrorHandler::error(value + " expr is not an integer");
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
