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
		cerr << "Expression in if is of type \"" << firstNode.dataType << "\", it should be of type bool" << endl;
		return Symbol::ERROR();
	}

	SymbolTable::getInstance()->enterScope();
	children[1-condIdx]->sematicCheck();
	SymbolTable::getInstance()->exitScope();

	return Symbol::EMPTY();
}

Symbol IfNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
