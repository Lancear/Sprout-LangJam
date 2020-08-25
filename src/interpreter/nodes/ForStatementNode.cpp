#include <iostream>

#include "ForStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ForStatementNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol ForStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
