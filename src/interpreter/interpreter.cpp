#include "interpreter.hpp"
#include "./nodes/TreeNode.hpp"
#include "./nodes/FileNode.hpp"
#include "./SymbolTable/SymbolTable.hpp"

void dispatch(struct node *n){
	if(!n) return;

    unique_ptr<TreeNode> tree = make_unique<FileNode>(n);

    tree->addSymbols();
    tree->sematicCheck();
    // SymbolTable::instance()->get("main").value->execute();
}
