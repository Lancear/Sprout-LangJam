#pragma once

#include "TreeNode.hpp"

class ParameterTypeNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    void analyse();
};
