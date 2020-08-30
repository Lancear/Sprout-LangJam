#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"

class DeclarationNode : public TreeNode {
  using TreeNode::TreeNode;

  public:
    bool isMut = false;

    DeclarationNode(struct node * n, bool isMut);
    Symbol addSymbols();
    Symbol sematicCheck(Symbol sym);
    Symbol execute(Symbol sym);
};
