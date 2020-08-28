
#include <iostream>

#include "SubtractExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol SubtractExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol SubtractExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}