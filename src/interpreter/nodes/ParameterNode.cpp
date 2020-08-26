#include <iostream>

#include "ParameterNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ParameterNode::analyse(Symbol symParam) {
  cout << "Param " << value << endl;
  Symbol type = children[0]->analyse();
  return Symbol(SymbolType::IMMUTABLE,value,type.value,NULL);
}

Symbol ParameterNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
