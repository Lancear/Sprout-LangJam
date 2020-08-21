#pragma once

#include "TreeNode.hpp"

class ParameterListNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    void analyse();
};
