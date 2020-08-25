#include <iostream>

#include "ConditionalStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ConditionalStatementNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol ConditionalStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
