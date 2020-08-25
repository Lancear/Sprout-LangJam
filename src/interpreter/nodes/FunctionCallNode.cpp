#include <iostream>

#include "FunctionCallNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol FunctionCallNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol FunctionCallNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
