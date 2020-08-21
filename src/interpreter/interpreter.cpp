#include "interpreter.hpp"
#include "./nodes/TreeNode.hpp"
#include <iostream>
using namespace std;

void dispatch(struct node * n) {    
    if(!n) return;

    TreeNode * tree = TreeNode::of(n); // wraps our nodes around the original parse-tree
    if(!tree) return;
    
    tree->analyse();
}
