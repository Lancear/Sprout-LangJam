#include <iostream>

#include "DoWhileStatementNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../symboltable/SymbolTable.hpp"

using namespace std;
Symbol DoWhileStatementNode::analyse(Symbol symParam) {
	cout << "do while > ";
	Symbol doWhileExp = children[1]->analyse();
	if (doWhileExp.type != SymbolType::EXPRESSION || doWhileExp.valueType != "boolean")
	{
		cerr << "Do while structure expects an Expression of type boolean, instead got " << doWhileExp.valueType;
		return Symbol::ERROR();
	}

	//Processing the remaining child in a new scope
	SymbolTable::getInstance()->openNewScope();
	children[0]->analyse();
	SymbolTable::getInstance()->closeScope();

	return Symbol::EMPTY();
}

Symbol DoWhileStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
