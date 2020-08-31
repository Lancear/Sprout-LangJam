#include <string>
#include <memory>

#include "ElseNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ElseNode::addSymbols() {
	SymbolTable::getInstance()->openNewScope();
	children[0]->addSymbols();
	SymbolTable::getInstance()->closeScope();
	
	SymbolTable::getInstance()->openNewScope();
	children[1]->addSymbols();
	SymbolTable::getInstance()->closeScope();
  return Symbol::EMPTY();
}

Symbol ElseNode::sematicCheck(Symbol sym) {
	SymbolTable::getInstance()->enterScope();
	children[0]->sematicCheck();
	SymbolTable::getInstance()->exitScope();

	SymbolTable::getInstance()->enterScope();
	children[1]->sematicCheck();
	SymbolTable::getInstance()->exitScope();
	return Symbol::EMPTY();
}

Symbol ElseNode::execute(Symbol sym) {
	Symbol result = Symbol::EMPTY();
	SymbolTable::getInstance()->enterScope();
	if(get<int>(sym.value) == 1){
		result = children[0]->execute();
	}else{
		result = children[1]->execute();
	}
	SymbolTable::getInstance()->exitScope();
	return result;
}
