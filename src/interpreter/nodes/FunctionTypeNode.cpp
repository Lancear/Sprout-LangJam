#include <iostream>

#include "FunctionTypeNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol FunctionTypeNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol FunctionTypeNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
