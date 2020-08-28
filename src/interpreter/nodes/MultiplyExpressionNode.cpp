
#include <iostream>

#include "MultiplyExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol MultiplyExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol MultiplyExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}