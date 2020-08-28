
#include <iostream>

#include "BitwiseXorAssignExpressionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol BitwiseXorAssignExpressionNode::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol BitwiseXorAssignExpressionNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}