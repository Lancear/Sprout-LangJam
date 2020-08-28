
#include <iostream>

#include "MultiplyAssignExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol MultiplyAssignExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol MultiplyAssignExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}