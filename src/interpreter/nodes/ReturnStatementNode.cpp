#include "ReturnStatementNode.hpp"
#include <iostream>
using namespace std;

void ReturnStatementNode::analyse() {
  cout << "Value: " << value << endl;
}
