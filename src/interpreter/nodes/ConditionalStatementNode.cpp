#include <iostream>

#include "ConditionalStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ConditionalStatementNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol ConditionalStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
