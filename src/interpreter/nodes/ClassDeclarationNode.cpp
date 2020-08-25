#include <iostream>

#include "ClassDeclarationNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ClassDeclarationNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol ClassDeclarationNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
