
#include <iostream>

#include "FunctionReturnTypeNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol FunctionReturnTypeNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol FunctionReturnTypeNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}