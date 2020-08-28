
#include <iostream>

#include "TypeListNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol TypeListNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol TypeListNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}