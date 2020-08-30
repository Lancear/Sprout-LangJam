#include <string>
#include <memory>

#include "DoWhileNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol DoWhileNode::addSymbols() {
  SymbolTable::getInstance()->openNewScope();
  children[0]->addSymbols();
  SymbolTable::getInstance()->closeScope();
  children[1]->addSymbols();
  return Symbol::EMPTY();
}

Symbol DoWhileNode::sematicCheck(Symbol sym) {
	Symbol whileNode = children[1]->sematicCheck();
	if (whileNode.dataType != "bool")
	{
		cerr << "Expression in do-while loop is of type \"" << whileNode.dataType << "\", it should be of type bool" << endl;
		return Symbol::ERROR();
	}
	SymbolTable::getInstance()->enterScope();
	children[0]->sematicCheck();
	SymbolTable::getInstance()->exitScope();

	return Symbol::EMPTY();
}

Symbol DoWhileNode::execute(Symbol sym) {
	SymbolTable::getInstance()->enterScope();
	Scope * s = SymbolTable::getInstance()->currentScope;
	SymbolTable::getInstance()->exitScope();
	do{
		SymbolTable::getInstance()->pushScope(s);
		children[0]->execute();
		SymbolTable::getInstance()->popScope();
	} while (get<int>(children[1]->execute().value) == 1);
	return Symbol::EMPTY();
}
