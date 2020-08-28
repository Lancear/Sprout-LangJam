#include <iostream>

#include "ReturnStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ReturnStatementNode::analyse(Symbol symParam) {
  cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol ReturnStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
