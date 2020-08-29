#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class FunctionCallNode : public TreeNode {
  using TreeNode::TreeNode;

  public:
    void addSymbols();
    Symbol sematicCheck(Symbol sym);
    Symbol execute(Symbol sym);
};
