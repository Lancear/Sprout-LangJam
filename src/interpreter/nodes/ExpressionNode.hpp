#pragma once

#include "TreeNode.hpp"

class ExpressionNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    void analyse();
};
