#include <iostream>

#include "StringImmediateNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol StringImmediateNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol StringImmediateNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
