#include "ParameterListNode.hpp"
#include <iostream>
using namespace std;

void ParameterListNode::analyse() {
  cout << "Params: " << children.size() << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->analyse();
  }
}
