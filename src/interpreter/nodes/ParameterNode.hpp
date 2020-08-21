#pragma once

#include "TreeNode.hpp"

class ParameterNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    void analyse();
};
