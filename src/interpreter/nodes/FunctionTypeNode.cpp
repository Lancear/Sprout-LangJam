#include <iostream>

#include "FunctionTypeNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol FunctionTypeNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}
