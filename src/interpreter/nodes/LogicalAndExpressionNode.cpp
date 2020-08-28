
#include <iostream>

#include "LogicalAndExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol LogicalAndExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol LogicalAndExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}