#include <string>
#include <memory>

#include "PostOpNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol PostOpNode::addSymbols() {
  return children[0]->addSymbols();
}

Symbol PostOpNode::sematicCheck(Symbol param) {
  Symbol expr = children[0]->sematicCheck();
  Symbol sym = Symbol::TYPE("int");

  if (expr.isError()) {
    return Symbol::ERROR();
  }

  if (expr.dataType.compare("int") != 0) {
    ErrorHandler::error(value + " expr is not an integer");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol PostOpNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
