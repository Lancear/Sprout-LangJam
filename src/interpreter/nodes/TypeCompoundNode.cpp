#include <iostream>

#include "TypeCompoundNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol TypeCompoundNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol TypeCompoundNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
