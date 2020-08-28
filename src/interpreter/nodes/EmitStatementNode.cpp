
#include <iostream>

#include "EmitStatementNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol EmitStatementNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol EmitStatementNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}