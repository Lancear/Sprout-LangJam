#include <iostream>

#include "NumericImmediateNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol NumericImmediateNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol NumericImmediateNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
