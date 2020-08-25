#include <iostream>

#include "WhileStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol WhileStatementNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol WhileStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
