#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"

class TypeNode : public TreeNode {
  using TreeNode::TreeNode;

  public:
    bool isRef = false;

    TypeNode(struct node * n, bool isRef);
    void addSymbols();
    Symbol sematicCheck(Symbol sym);
    Symbol execute(Symbol sym);
};
