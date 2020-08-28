
#include <iostream>

#include "LogicalOrExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol LogicalOrExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol LogicalOrExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}