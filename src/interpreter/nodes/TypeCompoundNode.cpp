#include <iostream>

#include "TypeCompoundNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol TypeCompoundNode::analyse(Symbol sym) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol TypeCompoundNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
