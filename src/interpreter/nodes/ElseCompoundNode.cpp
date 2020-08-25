#include <iostream>

#include "ElseCompoundNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ElseCompoundNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol ElseCompoundNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
