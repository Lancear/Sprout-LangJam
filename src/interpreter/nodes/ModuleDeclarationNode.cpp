#include <iostream>

#include "ModuleDeclarationNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ModuleDeclarationNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol ModuleDeclarationNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
