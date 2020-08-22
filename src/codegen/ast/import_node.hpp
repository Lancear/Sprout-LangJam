#pragma once

#include "tree_node.hpp"

namespace ast
{
    class import_node : public tree_node
    {
        using tree_node::tree_node;

    public:
        llvm::Value *codegen() override;
    };
} // namespace ast
