
#include <iostream>

#include "RightShiftAssignExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol RightShiftAssignExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol RightShiftAssignExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}