#include "codegen.hpp"
#include "ast/tree_node.hpp"

llvm::LLVMContext context;
llvm::IRBuilder<> builder(context);
std::unique_ptr<llvm::Module> module;

extern "C" void dispatch(node *n)
{
    if (n == nullptr)
        return;

    auto tree_node = ast::tree_node::construct_tree_node(n);

    module = std::make_unique<llvm::Module>("Sprout", context);

    tree_node->codegen(n)->print(llvm::errs());
}