#include <iostream>

#include "MutableLocalDeclarationStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol MutableLocalDeclarationStatementNode::analyse(Symbol symParam) {
  cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol MutableLocalDeclarationStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
