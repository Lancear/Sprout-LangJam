#include <iostream>

#include "AsCompoundNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol AsCompoundNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol AsCompoundNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
