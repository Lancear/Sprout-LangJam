#include <variant>

#include "interpreter.hpp"
#include "./nodes/SimpleTreeNode.hpp"
#include "./nodes/TreeNode.hpp"
#include "./nodes/FileNode.hpp"
#include "./nodes/FunctionNode.hpp"
#include "./symboltable/SymbolTable.hpp"
#include "./symboltable/Symbol.hpp"

using namespace std;

void dispatch(struct node *n){
	if(!n) return;

    unique_ptr<TreeNode> tree = make_unique<FileNode>(n);

    tree->addSymbols();
    SymbolTable::getInstance()->resetCursor();
    tree->sematicCheck();
    
    SymbolTable::getInstance()->resetCursor();
    cout << SymbolTable::getInstance()->get("main").dataType << endl;
}
