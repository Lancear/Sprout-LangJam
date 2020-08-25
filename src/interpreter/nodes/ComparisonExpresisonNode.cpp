#include <iostream>

#include "ComparisonExpresisonNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ComparisonExpresisonNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol ComparisonExpresisonNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
