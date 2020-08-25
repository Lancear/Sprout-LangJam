#include <iostream>

#include "ImportDeclarationNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ImportDeclarationNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol ImportDeclarationNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
