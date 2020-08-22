#include <iostream>

#include "StatementListNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol StatementListNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol StatementListNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
