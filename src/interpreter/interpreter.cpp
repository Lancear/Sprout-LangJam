#include "interpreter.hpp"
#include "./nodes/TreeNode.hpp"
#include "./symboltable/SymbolTable.hpp"
#include <iostream>
using namespace std;

void test(char *name);

void dispatch(struct node *n){
	if(!n) return;

    unique_ptr<TreeNode> tree = TreeNode::of(n); // wraps our nodes around the original parse-tree
    if(!tree) return;
    
    tree->analyse(); // semantical analysis
    tree->execute(); // interpreter execution

    // Testing out the symbol table
	char* name = "var1";
	char* value = "string";
	shared_ptr<SymbolTable> table = SymbolTable::getInstance();
	table->add(name, value);
	test(name);
}

void test(char* name){
	shared_ptr<SymbolTable > table = SymbolTable::getInstance();
	cout << "Found it? " << (table->contains(name) > 0 ? "true" : "false") << "\n";
	cout << "Value: " << table->get(name) << endl;
}
