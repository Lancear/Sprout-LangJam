#include <iostream>

#include "FunctionDeclarationNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol FunctionDeclarationNode::analyse(Symbol symParam) {
  cout << "Function: " << value << endl;
  children[1]->analyse();
  return Symbol::EMPTY();
}

Symbol FunctionDeclarationNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
