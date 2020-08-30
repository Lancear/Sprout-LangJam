#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"

class ParamNode : public TreeNode {
  using TreeNode::TreeNode;

  public:
    bool isMut = false;

    ParamNode(struct node * n, bool isMut);
    Symbol addSymbols();
    Symbol sematicCheck(Symbol sym);
    Symbol execute(Symbol sym);
};
