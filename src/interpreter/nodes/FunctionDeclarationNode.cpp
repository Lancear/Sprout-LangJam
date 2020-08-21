#include "FunctionDeclarationNode.hpp"
#include <iostream>
using namespace std;

void FunctionDeclarationNode::analyse() {
  cout << "Function: " << value << endl;
  children[1]->analyse();
}
