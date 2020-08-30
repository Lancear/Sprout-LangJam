#pragma once

#include <string>

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"

using namespace std;

class ArithmeticExprNode : public TreeNode {
  using TreeNode::TreeNode;

  public:
    Symbol addSymbols();
    Symbol sematicCheck(Symbol sym);
    Symbol execute(Symbol sym);
};
