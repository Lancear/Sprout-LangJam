#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class ParamListNode : public TreeNode {
  using TreeNode::TreeNode;

  public:
    Symbol execute(Symbol args[]);
};
