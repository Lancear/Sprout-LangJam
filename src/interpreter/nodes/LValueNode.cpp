#include <iostream>

#include "LValueNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol LValueNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol LValueNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
