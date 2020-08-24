#include "import_node.hpp"
#include "as_node.hpp"
#include "fn_decl_node.hpp"
#include "fn_param_list_node.hpp"
#include "fn_param_node.hpp"
#include "fn_param_type_node.hpp"
#include "code_block_node.hpp"
#include "stmt_list_node.hpp"
#include "return_stmt_node.hpp"
#include "literal_node.hpp"
#include "fn_return_type_node.hpp"
#include "empty_stmt_node.hpp"
#include "local_decl_stmt_node.hpp"
#include "mut_local_decl_stmt_node.hpp"
#include "local_type_node.hpp"
#include "identifier_node.hpp"
#include "add_expr_node.hpp"
#include "sub_expr_node.hpp"
#include "mul_expr_node.hpp"
#include "div_expr_node.hpp"
#include "mod_expr_node.hpp"
#include "tree_node.hpp"

ast::tree_node::tree_node(node *n)
{
    value = n->value ? n->value : "";

    for (node *child = n->child; child; child = child->brother)
    {
        children.push_back(construct_tree_node(child));
    }
}

std::unique_ptr<ast::tree_node> ast::tree_node::construct_tree_node(node *n)
{
    switch (n->type)
    {
    case ImportNode: return std::make_unique<import_node>(n);
    case AsNode: return std::make_unique<as_node>(n);
    case FunctionDeclaration: return std::make_unique<fn_decl_node>(n);
    case ParameterList: return std::make_unique<fn_param_list_node>(n);
    case Parameter: return std::make_unique<fn_param_node>(n);
    case ParameterType: return std::make_unique<fn_param_type_node>(n);
    case CodeBlock: return std::make_unique<code_block_node>(n);
    case StatementList: return std::make_unique<stmt_list_node>(n);
    case ReturnStatement: return std::make_unique<return_stmt_node>(n);
    case NumericImmediate: return std::make_unique<literal_node>(n);
    case FunctionReturnType: return std::make_unique<fn_return_type_node>(n);
    case EmptyStatement: return std::make_unique<empty_stmt_node>(n);
    case LocalDeclarationStatement: return std::make_unique<local_decl_stmt_node>(n);
    case MutableLocalDeclarationStatement: return std::make_unique<mut_local_decl_stmt_node>(n);
    case VariableTypeNode: return std::make_unique<local_type_node>(n);
    case SymbolImmediate: return std::make_unique<identifier_node>(n);
    case AddExpression: return std::make_unique<add_expr_node>(n);
    case SubtractExpression: return std::make_unique<sub_expr_node>(n);
    case MultiplyExpression: return std::make_unique<mul_expr_node>(n);
    case DivideExpression: return std::make_unique<div_expr_node>(n);
    case ModulusExpression: return std::make_unique<mod_expr_node>(n);

    default:
        return nullptr;
    }
}