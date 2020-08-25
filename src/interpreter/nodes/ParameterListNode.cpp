#include <iostream>

#include "ParameterListNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ParameterListNode::analyse(Symbol symParam) {
  cout << "Params: " << children.size() << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->analyse();
  }
  
  return Symbol::EMPTY();
}

Symbol ParameterListNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
