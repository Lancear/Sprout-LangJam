#include "interpreter.hpp"
#include "./nodes/TreeNode.hpp"
#include "./nodes/FileNode.hpp"
#include <iostream>

void dispatch(struct node *n){
	if(!n) return;

    unique_ptr<TreeNode> tree = make_unique<FileNode>(n);

    tree->addSymbols();
    // tree->execute(); // interpreter execution
}
