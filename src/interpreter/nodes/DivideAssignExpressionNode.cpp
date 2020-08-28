
#include <iostream>

#include "DivideAssignExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol DivideAssignExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol DivideAssignExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}