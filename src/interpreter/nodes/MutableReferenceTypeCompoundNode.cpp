
#include <iostream>

#include "MutableReferenceTypeCompoundNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol MutableReferenceTypeCompoundNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol MutableReferenceTypeCompoundNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}