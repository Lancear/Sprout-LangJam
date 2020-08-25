#include <iostream>

#include "LocalDeclarationStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol LocalDeclarationStatementNode::analyse(Symbol sym) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol LocalDeclarationStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
