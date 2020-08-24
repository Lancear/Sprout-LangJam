#pragma once

#include "tree_node.hpp"

namespace ast
{
    class identifier_node : public tree_node
    {
        using tree_node::tree_node;

    public:
        llvm::Value *codegen(node* n) override;
    };
} // namespace ast
