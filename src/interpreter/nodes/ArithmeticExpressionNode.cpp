#include <iostream>

#include "ArithmeticExpressionNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ArithmeticExpressionNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol ArithmeticExpressionNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
