#include <string>
#include <memory>

#include "WhileNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol WhileNode::addSymbols() {
	children[0]->addSymbols();
	SymbolTable::getInstance()->openNewScope();
	children[1]->addSymbols();
	SymbolTable::getInstance()->closeScope();
	return Symbol::EMPTY();
}

Symbol WhileNode::sematicCheck(Symbol sym) {
	Symbol whileNode = children[0]->sematicCheck();
	if(whileNode.dataType != "bool"){
		cerr << "Expression in while loop is of type \"" << whileNode.dataType << "\", it should be of type bool" << endl;
		return Symbol::ERROR();
	}
	SymbolTable::getInstance()->enterScope();
	children[1]->sematicCheck();
	SymbolTable::getInstance()->exitScope();

	return Symbol::EMPTY();
}

Symbol WhileNode::execute(Symbol sym) {
	SymbolTable::getInstance()->enterScope();
	Scope * s = SymbolTable::getInstance()->currentScope;
	SymbolTable::getInstance()->exitScope();

	while (get<int>(children[0]->execute().value) == 1){
		SymbolTable::getInstance()->pushScope(s);
		children[1]->execute();
		SymbolTable::getInstance()->popScope();
	}
	return Symbol::EMPTY();
}
