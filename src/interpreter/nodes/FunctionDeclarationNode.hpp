#pragma once

#include "TreeNode.hpp"

class FunctionDeclarationNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    void analyse();
};
