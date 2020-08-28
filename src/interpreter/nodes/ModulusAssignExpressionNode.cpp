
#include <iostream>

#include "ModulusAssignExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ModulusAssignExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol ModulusAssignExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}