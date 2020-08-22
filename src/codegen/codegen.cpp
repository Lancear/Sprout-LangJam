#include <stdio.h>

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

extern "C" void dispatch(node *n)
{
    if (n == nullptr)
        return;

    auto tree_node = ast::tree_node::construct_tree_node(n);

    
}
