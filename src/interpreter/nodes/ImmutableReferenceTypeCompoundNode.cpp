
#include <iostream>

#include "ImmutableReferenceTypeCompoundNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ImmutableReferenceTypeCompoundNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol ImmutableReferenceTypeCompoundNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}