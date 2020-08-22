#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class ReturnStatementNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    Symbol analyse(Symbol sym);
};
