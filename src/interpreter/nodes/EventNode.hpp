#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"

class EventNode : public TreeNode {
  public:
    EventNode(struct node * n);
    Symbol addSymbols();
    Symbol sematicCheck(Symbol sym);
    Symbol execute(Symbol sym);
};
