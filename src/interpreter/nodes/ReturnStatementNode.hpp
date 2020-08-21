#pragma once

#include "TreeNode.hpp"

class ReturnStatementNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    void analyse();
};
