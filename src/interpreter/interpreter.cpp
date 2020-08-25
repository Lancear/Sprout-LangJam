#include "interpreter.hpp"
#include "./nodes/TreeNode.hpp"
#include "./symboltable/SymbolTable.hpp"
#include <iostream>
#include "./symboltable/Symbol.hpp"
using namespace std;

void test(Symbol name);

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
	table->add(Symbol());
	test(Symbol());

	//Example of a normal Symbol
	Symbol s = Symbol(SymbolType::FUNCTION,"var1", "Hello World", "string", false);
	if(s.type == SymbolType::FUNCTION){
		printf("*Normal Symbol works.\n");
	}
	//Example of an Emtpy symbol
	Symbol s2 = Symbol();
	if(s2.type == SymbolType::EMPTY){
		printf("*Empty Symbol also works.\n");
	}
}

void test(Symbol name){
	shared_ptr<SymbolTable> table = SymbolTable::getInstance();

	cout << "*Does the singleton work? " << (table->contains(name.value) > 0 ? "true" : "false") << "\n";
}
