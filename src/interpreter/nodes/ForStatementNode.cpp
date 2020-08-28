#include <iostream>

#include "ForStatementNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../symboltable/SymbolTable.hpp"

using namespace std;
Symbol ForStatementNode::analyse(Symbol symParam) {
	cout << "For > " << endl;
	SymbolTable::getInstance()->openNewScope();
	Symbol exp0 = children[0]->analyse();
	Symbol exp1 = children[1]->analyse();
	Symbol exp2 = children[2]->analyse();
	Symbol codeBlock = children[3]->analyse();

	
	if (exp1.type == SymbolType::EMPTY || exp1.valueType != "boolean")
	{
		cerr << "While structure expects an Expression of type boolean";
		return Symbol::ERROR();
	}
	SymbolTable::getInstance()->closeScope();
	return Symbol::EMPTY();
}

Symbol ForStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
