#include <iostream>

#include "CodeBlockNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol CodeBlockNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol CodeBlockNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
