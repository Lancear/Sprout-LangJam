#pragma once

#include "TreeNode.hpp"

class StatementListNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    void analyse();
};
