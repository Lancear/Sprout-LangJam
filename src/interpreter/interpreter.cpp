#include "interpreter.hpp"
#include "./nodes/TreeNode.hpp"
#include <iostream>

void dispatch(struct node *n){
	if(!n) return;

    unique_ptr<TreeNode> tree = TreeNode::of(n); // wraps our nodes around the original parse-tree
    if(!tree) return;

    tree->analyse(); // semantical analysis
    // tree->execute(); // interpreter execution
}
