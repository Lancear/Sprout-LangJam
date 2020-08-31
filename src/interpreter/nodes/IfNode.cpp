#include <string>
#include <memory>

#include "IfNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol IfNode::addSymbols() {
	int condIdx = (children[0]->type == ElseCompound) ? 1 : 0;
	children[condIdx]->addSymbols();
	SymbolTable::getInstance()->openNewScope();
	children[1 - condIdx]->addSymbols();
	SymbolTable::getInstance()->closeScope();
  return Symbol::EMPTY();
}

Symbol IfNode::sematicCheck(Symbol sym) {
	//Check if it is if-else or if, if it is if-else, the first child is an elseCompound
	int condIdx = (children[0]->type == ElseCompound) ? 1 : 0;

	Symbol firstNode = children[condIdx]->sematicCheck();
	if (firstNode.dataType != "bool")
	{
		ErrorHandler::error("Expression in if is of type \"" + firstNode.dataType + "\", it should be of type bool", line, col);
		return Symbol::ERROR();
	}

	SymbolTable::getInstance()->enterScope();
	children[1-condIdx]->sematicCheck();
	SymbolTable::getInstance()->exitScope();

	return Symbol::EMPTY();
}

Symbol IfNode::execute(Symbol sym) {
	if(children[0]->type != ElseCompound){
		int condResult = get<int>(children[0]->execute().value);
		SymbolTable::getInstance()->enterScope();
		if(condResult == 1)
			children[1]->execute();
		SymbolTable::getInstance()->exitScope();
	}else{
		int condResult = get<int>(children[1]->execute().value);
		children[0]->execute(Symbol::EXPRESSION("bool",condResult));
	}
  	return Symbol::EMPTY();
}
