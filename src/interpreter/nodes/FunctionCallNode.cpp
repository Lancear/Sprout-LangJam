#include <iostream>

#include "FunctionCallNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol FunctionCallNode::analyse(Symbol sym) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol FunctionCallNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
