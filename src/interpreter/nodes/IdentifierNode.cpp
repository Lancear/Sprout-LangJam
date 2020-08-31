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
	  ErrorHandler::error("unknown identifier " + value, line, col);
	  return Symbol::ERROR();
  }

  if (!SymbolTable::getInstance()->contains(SymbolTable::getInstance()->get(value).dataType)) {
    ErrorHandler::error("unknown type " + SymbolTable::getInstance()->get(value).dataType, line, col);
    return Symbol::ERROR();
  }

  Symbol type = SymbolTable::getInstance()->get(SymbolTable::getInstance()->get(value).dataType);

  if (!type.isType() && !type.isClass()) {
    ErrorHandler::error(SymbolTable::getInstance()->get(value).dataType + "is not a type", line, col);
    return Symbol::ERROR();
  }

  return SymbolTable::getInstance()->get(value);
}

Symbol IdentifierNode::execute(Symbol sym) {
  return SymbolTable::getInstance()->get(value);
}
