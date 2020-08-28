
#include <iostream>

#include "EmptyStatementNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol EmptyStatementNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol EmptyStatementNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}