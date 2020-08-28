
#include <iostream>

#include "LogicalNegationExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol LogicalNegationExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol LogicalNegationExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}