#pragma once

#include <memory>
#include <vector>
#include <llvm/IR/Value.h>

#include "../../parser/node.h"

namespace ast
{
    class tree_node
    {
    public:
        tree_node(node *n);

        static std::unique_ptr<tree_node> construct_tree_node(node *n);

        std::string value;
        std::vector<std::unique_ptr<tree_node>> children;

        virtual llvm::Value *codegen(node* n) = 0;
    };
} // namespace ast
