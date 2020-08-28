
#include <iostream>

#include "LeftShiftAssignExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol LeftShiftAssignExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol LeftShiftAssignExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}