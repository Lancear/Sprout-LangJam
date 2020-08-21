#include "TreeNode.hpp"
#include "FunctionNode.hpp"
#include "../../parser/node.h"

TreeNode::TreeNode(char * val) {
  value = val;
}

TreeNode * TreeNode::of(struct node * n) {
  switch (n->type) {
    case FunctionDeclaration:
      return new FunctionNode(n->value);
    
    default:
      return 0;
  }
}
