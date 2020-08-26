#include <iostream>

#include "ElseCompoundNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../symboltable/SymbolTable.hpp"

using namespace std;
Symbol ElseCompoundNode::analyse(Symbol symParam) {
	cout << "Else > ";
	//process the codeblock in new scope
	SymbolTable::getInstance()->openNewScope();
	children[0]->analyse();
	SymbolTable::getInstance()->closeScope();
	return Symbol::EMPTY();
}

Symbol ElseCompoundNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
