#include <iostream>

#include "VariableTypeNodeNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol VariableTypeNodeNode::analyse(Symbol sym) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol VariableTypeNodeNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}