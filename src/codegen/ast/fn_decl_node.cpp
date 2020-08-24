#include "fn_decl_node.hpp"

llvm::Value *ast::fn_decl_node::codegen()
{
    //std::string return_type = tree_node->children.at(0)->value;
    unsigned int arg_size = 2;

    std::vector<llvm::Type*> args(arg_size, llvm::Type::getDoubleTy(context));

    llvm::FunctionType *func_type = llvm::FunctionType::get(llvm::Type::getVoidTy(context), args, false);

    llvm::Function *func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, ast::fn_decl_node::value, module.get());

    llvm::BasicBlock *BB = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(BB);

    llvm::ConstantInt *zero = llvm::ConstantInt::get(llvm::IntegerType::getInt32Ty(context), 0);
    builder.CreateRet(zero);

    llvm::verifyFunction(*func);

    return func;
}
