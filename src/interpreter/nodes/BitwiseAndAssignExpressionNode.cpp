
#include <iostream>

#include "BitwiseAndAssignExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol BitwiseAndAssignExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol BitwiseAndAssignExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}