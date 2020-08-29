#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"

class FileNode : public TreeNode {
  public:
    FileNode(struct node * n);
};
