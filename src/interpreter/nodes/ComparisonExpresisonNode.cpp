#include <iostream>

#include "ComparisonExpresisonNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ComparisonExpresisonNode::analyse(Symbol symParam) {
  if (value) cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol ComparisonExpresisonNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
