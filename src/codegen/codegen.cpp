#include <iostream>

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include "codegen.hpp"
#include "ast/import_node.hpp"
#include "ast/as_node.hpp"
#include "ast/fn_decl_node.hpp"
#include "ast/fn_param_list_node.hpp"
#include "ast/fn_param_node.hpp"
#include "ast/fn_param_type_node.hpp"
#include "ast/code_block_node.hpp"
#include "ast/stmt_list_node.hpp"
#include "ast/return_stmt_node.hpp"
#include "ast/literal_node.hpp"
#include "ast/fn_return_type_node.hpp"
#include "ast/empty_stmt_node.hpp"
#include "ast/local_decl_stmt_node.hpp"
#include "ast/mut_local_decl_stmt_node.hpp"
#include "ast/local_type_node.hpp"
#include "ast/identifier_node.hpp"
#include "ast/add_expr_node.hpp"
#include "ast/sub_expr_node.hpp"
#include "ast/mul_expr_node.hpp"
#include "ast/div_expr_node.hpp"
#include "ast/mod_expr_node.hpp"
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

    std::string return_type = tree_node->children.at(0)->value;
    unsigned int arg_size = 2;

    std::vector<llvm::Type*> args(arg_size, llvm::Type::getDoubleTy(context));

    llvm::FunctionType *func_type = llvm::FunctionType::get(llvm::Type::getVoidTy(context), args, false);

    llvm::Function *func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, tree_node->value, module.get());

    llvm::BasicBlock *BB = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(BB);

    llvm::ConstantInt *zero = llvm::ConstantInt::get(llvm::IntegerType::getInt32Ty(context), 0);
    builder.CreateRet(zero);

    llvm::verifyFunction(*func);

    module->print(llvm::errs(), nullptr);
}
