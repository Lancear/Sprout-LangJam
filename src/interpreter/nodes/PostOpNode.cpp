#include <iostream>

#include "PostOpNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol PostOpNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol PostOpNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
