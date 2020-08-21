#include "interpreter.hpp"
#include "TreeNode.hpp"
#include <iostream>
using namespace std;

void dispatch(struct node * n) {    
    if(!n) return;

    TreeNode * tree = TreeNode::of(n);
    if(!tree) return;
    
    tree->analyse();
}
