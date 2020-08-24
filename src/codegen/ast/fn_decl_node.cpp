#include "fn_decl_node.hpp"

llvm::Type* get_type(std::string type, llvm::LLVMContext& context)
{
    if(type == "void") return llvm::Type::getVoidTy(context);

    if(type == "i8") return llvm::Type::getInt8Ty(context);
    if(type == "i16") return llvm::Type::getInt16Ty(context);
    if(type == "i32") return llvm::Type::getInt32Ty(context);
    if(type == "i64") return llvm::Type::getInt64Ty(context);

    return nullptr;
}

std::pair<std::vector<std::string>, unsigned int> get_arg_info(node* n) {
    std::vector<std::string> types;
    unsigned int size = 0;

    for (node *arg = n->child->brother->child; arg; arg = arg->brother) {
        types.push_back(arg->child->value);
        size++;
    }

    return std::make_pair(types, size);
}

llvm::Value *ast::fn_decl_node::codegen(node* n)
{
    unsigned int arg_size = get_arg_info(n).second;
    auto fn_return_type_node = ast::tree_node::construct_tree_node(n->child);
    auto fn_return_val_node = ast::tree_node::construct_tree_node(n->child->brother->brother->child->child->child);

    std::vector<llvm::Type*> args(arg_size, llvm::Type::getVoidTy(context));

    for(int i = 0; i < arg_size; i++) {
        args.at(i) = get_type(get_arg_info(n).first.at(i), context);
    }

    llvm::FunctionType *func_type = llvm::FunctionType::get(get_type(fn_return_type_node->value, context), args, false);

    llvm::Function *func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, ast::fn_decl_node::value, module.get());

    llvm::BasicBlock *BB = llvm::BasicBlock::Create(context, "body", func);
    builder.SetInsertPoint(BB);

    llvm::ConstantInt *zero = llvm::ConstantInt::get(llvm::IntegerType::getInt32Ty(context), std::stoi(fn_return_val_node->value)); //TODO fix
    builder.CreateRet(zero);

    llvm::verifyFunction(*func);

    return func;
}
