#include <string>
#include <memory>

#include "TypeNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

TypeNode::TypeNode(struct node * n, bool ref) : TypeNode(n) {
  isRef = ref;
}

Symbol TypeNode::addSymbols() {
  return Symbol::TYPE(value);
}

Symbol TypeNode::sematicCheck(Symbol sym) {
  if (!SymbolTable::getInstance()->contains(value)) {
    ErrorHandler::error("unknown type " + value);
    return Symbol::ERROR();
  }

  Symbol type = SymbolTable::getInstance()->get(value);

  if (!type.isType() && !type.isClass()) {
    ErrorHandler::error(value + " is not a type");
    return Symbol::ERROR();
  }

  return type;
}

Symbol TypeNode::execute(Symbol sym) {
  return SymbolTable::getInstance()->get(value);
}
