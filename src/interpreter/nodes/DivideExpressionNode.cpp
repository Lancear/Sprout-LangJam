
#include <iostream>

#include "DivideExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol DivideExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol DivideExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}