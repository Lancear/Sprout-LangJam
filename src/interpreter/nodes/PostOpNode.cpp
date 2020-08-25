#include <iostream>

#include "PostOpNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol PostOpNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}

Symbol PostOpNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol();
}
