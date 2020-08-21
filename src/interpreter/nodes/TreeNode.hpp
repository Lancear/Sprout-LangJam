#pragma once

#include <memory>
#include <vector>
#include "../../parser/node.h"

using namespace std;

class TreeNode {
  public:
    char * value;
    vector<TreeNode*> children;

    explicit TreeNode(struct node * n);
    static TreeNode * of(struct node * n);

    virtual void analyse() = 0;
};
