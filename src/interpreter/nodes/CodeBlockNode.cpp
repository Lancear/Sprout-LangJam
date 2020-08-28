#include <iostream>

#include "CodeBlockNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol CodeBlockNode::analyse(Symbol symParam) {
  for(int i = 0; i < children.size(); i++){
	  children[i]->analyse();
  }
  return Symbol::EMPTY();
}

Symbol CodeBlockNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
