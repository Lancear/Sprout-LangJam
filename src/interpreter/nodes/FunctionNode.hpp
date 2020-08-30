#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../symboltable/Scope.hpp"

class FunctionNode : public TreeNode {
  using TreeNode::TreeNode;

  public:
    Scope scope;

    Symbol addSymbols();
    Symbol sematicCheck(Symbol sym);
    Symbol execute(Symbol args[]);
};
