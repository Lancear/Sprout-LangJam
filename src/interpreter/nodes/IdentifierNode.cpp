#include <string>
#include <memory>

#include "IdentifierNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol IdentifierNode::addSymbols() {
  return (SymbolTable::getInstance()->contains(value)) ? SymbolTable::getInstance()->get(value) : Symbol::EMPTY();
}

Symbol IdentifierNode::sematicCheck(Symbol sym) {
  if (!SymbolTable::getInstance()->contains(value)) {
    ErrorHandler::error("unknown identifier");
    return Symbol::ERROR();
  }

  return SymbolTable::getInstance()->get(value);
}

Symbol IdentifierNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
