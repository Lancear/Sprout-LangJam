#pragma once

#include "TreeNode.hpp"

class CodeBlockNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    void analyse();
};
