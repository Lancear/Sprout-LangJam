#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class ParameterListNode : public TreeNode {
  using TreeNode::TreeNode;
  
  public:
    Symbol analyse(Symbol sym);
};
