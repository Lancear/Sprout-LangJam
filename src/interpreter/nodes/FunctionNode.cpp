#include "FunctionNode.hpp"
#include <iostream>
using namespace std;

void FunctionNode::analyse() {
  cout << "Calls its children and handles its semantic checks and so on..." << endl;
  cout << "Value: " << value << endl;
}
