
#include <iostream>

#include "EventDeclarationNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol EventDeclarationNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol EventDeclarationNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}