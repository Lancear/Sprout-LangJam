#include <variant>

#include "interpreter.hpp"
#include "ErrorHandler.hpp"
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

  if (ErrorHandler::hadError) return;
  
  SymbolTable::getInstance()->resetCursor();
  FunctionNode* main = (FunctionNode*)get<void*>( SymbolTable::getInstance()->get("main").value );
  Symbol args[0];
  Symbol retVal = main->execute(args);

  if (!retVal.isEmpty())
    cout << get<int>(retVal.value) << endl;
}
