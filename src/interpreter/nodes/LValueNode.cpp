#include <iostream>

#include "LValueNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol LValueNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol LValueNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
