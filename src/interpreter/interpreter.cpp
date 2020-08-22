#include "interpreter.hpp"
#include "./nodes/TreeNode.hpp"
#include "./symboltable/SymbolTable.hpp"
#include <iostream>
using namespace std;

void dispatch(struct node * n) {    
    if(!n) return;

    unique_ptr<TreeNode> tree = TreeNode::of(n); // wraps our nodes around the original parse-tree
    if(!tree) return;
    
    tree->analyse();

    // Testing out the symbol table
    SymbolTable table;
    table.add("var1","string");
    cout << table.get("var1") << ", found the thing? " << endl;
    cout << table.get("var1") << endl; 
}
