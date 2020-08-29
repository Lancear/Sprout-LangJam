#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class TernaryExprNode : public TreeNode {
  using TreeNode::TreeNode;

  public:
    Symbol sematicCheck(Symbol sym);
    Symbol execute(Symbol sym);
};
