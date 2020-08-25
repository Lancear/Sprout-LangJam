#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class ClassDeclarationNode : public TreeNode {
  using TreeNode::TreeNode;
  public:
    Symbol analyse(Symbol sym);
    Symbol execute(Symbol sym);
};
