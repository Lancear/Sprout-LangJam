#pragma once

#include "tree_node.hpp"

namespace ast
{
    class mut_local_decl_stmt_node : public tree_node
    {
        using tree_node::tree_node;

    public:
        llvm::Value *codegen() override;
    };
} // namespace ast
