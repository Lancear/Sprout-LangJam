#include <iostream>

#include "AsCompoundNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol AsCompoundNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol AsCompoundNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
