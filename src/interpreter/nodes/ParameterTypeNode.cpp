#include <iostream>

#include "ParameterTypeNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ParameterTypeNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol ParameterTypeNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
