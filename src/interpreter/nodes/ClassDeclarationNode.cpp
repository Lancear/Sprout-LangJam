#include <iostream>

#include "ClassDeclarationNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ClassDeclarationNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol ClassDeclarationNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
