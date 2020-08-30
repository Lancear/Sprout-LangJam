#include <string>
#include <memory>

#include "ForNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ForNode::addSymbols() {
	SymbolTable::getInstance()->openNewScope();
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->addSymbols();
	}
	SymbolTable::getInstance()->closeScope();
  return Symbol::EMPTY();
}

Symbol ForNode::sematicCheck(Symbol sym) {
  SymbolTable::getInstance()->enterScope();
  for (int i = 0; i < children.size(); i++)
	{
		children[i]->sematicCheck();
	}
  SymbolTable::getInstance()->exitScope();

  return Symbol::EMPTY();
}

Symbol ForNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
