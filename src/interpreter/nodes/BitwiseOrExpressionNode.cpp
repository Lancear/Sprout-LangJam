
#include <iostream>

#include "BitwiseOrExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol BitwiseOrExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol BitwiseOrExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}