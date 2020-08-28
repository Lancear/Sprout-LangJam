
#include <iostream>

#include "UnaryMinusExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol UnaryMinusExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol UnaryMinusExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}