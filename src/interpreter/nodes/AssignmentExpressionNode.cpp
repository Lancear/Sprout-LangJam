#include <iostream>

#include "AssignmentExpressionNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol AssignmentExpressionNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol AssignmentExpressionNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
