#include <iostream>

#include "ForStatementNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../symboltable/SymbolTable.hpp"

using namespace std;
Symbol ForStatementNode::analyse(Symbol symParam) {
	cout << "For > " << endl;
	SymbolTable::getInstance()->openNewScope();
	for(int i = 0; i < children.size(); i++){
		cout << "call!" << endl;
		children[i]->analyse();
	}
	SymbolTable::getInstance()->closeScope();
	/*
	Symbol whileExp = children[0]->analyse();
	if (whileExp.type != SymbolType::EXPRESSION || whileExp.valueType != "boolean")
	{
		cerr << "While structure expects an Expression of type boolean, instead got " << whileExp.valueType;
		return Symbol::ERROR();
	}

	//Processing the remaining child in a new scope
	children[1]->analyse();
	*/
	return Symbol::EMPTY();
}

Symbol ForStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
