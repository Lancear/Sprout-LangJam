
#include <iostream>

#include "ModulusExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ModulusExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol ModulusExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}