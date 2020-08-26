#include <iostream>

#include "ParameterTypeNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ParameterTypeNode::analyse(Symbol symParam) {
  //Go straight to the value
  cout << "Paramtype: ";
  return children[0]->analyse();
}

Symbol ParameterTypeNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
