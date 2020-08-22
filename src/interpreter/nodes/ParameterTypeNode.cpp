#include <iostream>

#include "ParameterTypeNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ParameterTypeNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}
