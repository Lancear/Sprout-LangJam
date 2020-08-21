#pragma once

#include "TreeNode.hpp"

class FunctionTypeNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    void analyse();
};
