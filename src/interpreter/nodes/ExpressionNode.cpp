#include <iostream>

#include "ExpressionNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ExpressionNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}
