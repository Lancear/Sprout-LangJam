
#include <iostream>

#include "MutableParameterNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol MutableParameterNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol MutableParameterNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}