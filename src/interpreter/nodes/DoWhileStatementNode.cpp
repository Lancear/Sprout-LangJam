#include <iostream>

#include "DoWhileStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol DoWhileStatementNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol DoWhileStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
