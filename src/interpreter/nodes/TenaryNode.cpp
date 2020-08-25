#include <iostream>

#include "TenaryNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol TenaryNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol TenaryNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
