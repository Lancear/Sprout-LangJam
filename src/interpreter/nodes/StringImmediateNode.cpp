#include <iostream>

#include "StringImmediateNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol StringImmediateNode::analyse(Symbol symParam) {
  cout << "Value: " << value << endl;
  return Symbol::EMPTY();
}

Symbol StringImmediateNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
