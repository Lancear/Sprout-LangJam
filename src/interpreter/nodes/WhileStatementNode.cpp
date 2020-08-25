#include <iostream>

#include "WhileStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol WhileStatementNode::analyse(Symbol sym) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol WhileStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
