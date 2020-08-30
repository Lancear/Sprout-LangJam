#pragma once

#include <memory>
#include <vector>
#include <string>

#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"
#include "SimpleTreeNode.hpp"

using namespace std;

class TreeNode : public SimpleTreeNode{
  public:
    unsigned int line;
    unsigned int col;
    
    string value;
    int type;

    vector<unique_ptr<TreeNode>> children;

    explicit TreeNode(struct node * n);
    static unique_ptr<TreeNode> of(struct node * n);

    virtual Symbol addSymbols();

    virtual Symbol sematicCheck(Symbol sym);
    Symbol sematicCheck();

    virtual Symbol execute(Symbol sym);
    Symbol execute();

  protected:
    explicit TreeNode() {};
};
