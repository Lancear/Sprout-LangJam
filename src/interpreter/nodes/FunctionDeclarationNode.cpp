#include <iostream>

#include "FunctionDeclarationNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../symboltable/SymbolTable.hpp"
using namespace std;

Symbol FunctionDeclarationNode::analyse(Symbol symParam) {
	//TODO: Check for correct return type from codeblock
  cout << "Function: " << value << endl;
  SymbolTable::getInstance()->openNewScope();
  for (int i = 0; i < children.size(); i++)
  {
	  children[i]->analyse();
  }
  SymbolTable::getInstance()->closeScope();
  return Symbol::EMPTY();
}

Symbol FunctionDeclarationNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
