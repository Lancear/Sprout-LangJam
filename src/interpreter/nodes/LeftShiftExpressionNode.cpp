
#include <iostream>

#include "LeftShiftExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol LeftShiftExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol LeftShiftExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}