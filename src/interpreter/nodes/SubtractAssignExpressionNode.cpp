
#include <iostream>

#include "SubtractAssignExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol SubtractAssignExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol SubtractAssignExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}