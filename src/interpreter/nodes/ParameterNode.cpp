#include <iostream>

#include "ParameterNode.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ParameterNode::analyse(Symbol sym) {
  cout << "Param: " << value << endl;
  return Symbol();
}
