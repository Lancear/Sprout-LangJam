#include <iostream>

#include "PreOpNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol PreOpNode::analyse(Symbol sym) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol PreOpNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
