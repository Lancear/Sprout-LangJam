#pragma once

#include <memory>
#include <vector>
#include "../../parser/node.h"
#include "../symboltable/Symbol.hpp"

using namespace std;

class TreeNode {
  public:
    char * value;
	unsigned int line;
	unsigned int col;
    vector<unique_ptr<TreeNode>> children;

    explicit TreeNode(struct node * n);
    static unique_ptr<TreeNode> of(struct node * n);

    virtual Symbol analyse(Symbol sym) = 0;
    Symbol analyse();

    virtual Symbol execute(Symbol sym) = 0;
    Symbol execute();
};
