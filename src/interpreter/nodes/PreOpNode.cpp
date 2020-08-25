#include <iostream>

#include "PreOpNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol PreOpNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol PreOpNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
