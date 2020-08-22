#include <iostream>

#include "ReturnStatementNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ReturnStatementNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}
