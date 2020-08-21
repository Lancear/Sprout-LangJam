#pragma once

#include "TreeNode.hpp"

class FunctionNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    void analyse();
};
