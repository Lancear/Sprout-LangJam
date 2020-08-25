#include <iostream>

#include "ImportDeclarationNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ImportDeclarationNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol ImportDeclarationNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
