#include <iostream>

#include "TypeCompoundNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol TypeCompoundNode::analyse(Symbol symParam) {
  cout << "Value: " << value << endl;
  return Symbol::EXPRESSION(value);
}

Symbol TypeCompoundNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
