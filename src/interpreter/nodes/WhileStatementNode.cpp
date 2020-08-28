#include <iostream>

#include "WhileStatementNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../symboltable/SymbolTable.hpp"

using namespace std;
Symbol WhileStatementNode::analyse(Symbol symParam) {
	cout << "while > ";
	Symbol whileExp = children[0]->analyse();
	if (whileExp.type != SymbolType::EXPRESSION || whileExp.valueType != "boolean")
	{
		cerr << "While structure expects an Expression of type boolean, instead got " << whileExp.valueType;
		return Symbol::ERROR();
	}

	//Processing the remaining child in a new scope
	children[1]->analyse();

	return Symbol::EMPTY();
}

Symbol WhileStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
