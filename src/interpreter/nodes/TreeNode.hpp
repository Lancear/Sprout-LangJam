#pragma once

#include "../../parser/node.h"

class TreeNode {
  public:
    char * value;

    explicit TreeNode(char * val);
    static TreeNode * of(struct node * n);

    virtual void analyse() = 0;
};
