#include <iostream>

#include "AssignmentExpressionNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol AssignmentExpressionNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol AssignmentExpressionNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
