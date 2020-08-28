
#include <iostream>

#include "BitwiseAndExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol BitwiseAndExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol BitwiseAndExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}