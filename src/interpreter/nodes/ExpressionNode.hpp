#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class ExpressionNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    Symbol analyse(Symbol sym);
};
