
#include <iostream>

#include "BitwiseXorExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol BitwiseXorExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol BitwiseXorExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}