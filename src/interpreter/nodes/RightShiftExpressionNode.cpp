
#include <iostream>

#include "RightShiftExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol RightShiftExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol RightShiftExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}