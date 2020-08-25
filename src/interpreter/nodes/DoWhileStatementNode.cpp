#include <iostream>

#include "DoWhileStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol DoWhileStatementNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol DoWhileStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
