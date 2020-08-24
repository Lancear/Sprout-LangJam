#include "empty_stmt_node.hpp"

llvm::Value *ast::empty_stmt_node::codegen(node* n)
{
    return nullptr;
}
