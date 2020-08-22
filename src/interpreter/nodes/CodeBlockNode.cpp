#include <iostream>

#include "CodeBlockNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol CodeBlockNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol CodeBlockNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
