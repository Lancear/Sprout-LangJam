
#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class AddAssignExpressionNode : public TreeNode {
  using TreeNode::TreeNode;
  public:
    Symbol analyse(Symbol sym);
    Symbol execute(Symbol sym);
};