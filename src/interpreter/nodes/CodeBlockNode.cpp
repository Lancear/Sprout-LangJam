#include <iostream>

#include "CodeBlockNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol CodeBlockNode::analyse(Symbol sym) {
  cout << "Value: " << value << endl;
  return Symbol();
}
