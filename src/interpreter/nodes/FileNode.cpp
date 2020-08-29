#include <string>

#include "FileNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"

using namespace std;

FileNode::FileNode(struct node * n) {
  line = 0;
  col = 0;

  value = "";
  type = -1;

  while (n) {
    children.push_back(TreeNode::of(n));
    n = n->brother;
  }
}
