#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class PostOpNode : public TreeNode {
  using TreeNode::TreeNode;

  public:
    Symbol sematicCheck(Symbol sym);
    Symbol execute(Symbol sym);
};
