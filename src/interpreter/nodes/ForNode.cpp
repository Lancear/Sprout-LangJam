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

	children[0]->sematicCheck();


	if(children.size() == 1){
		return Symbol::EMPTY();
	}

	int idx = 2;

	if(children[1]->type != CodeBlock)
		idx--;
	Symbol s = children[idx++]->sematicCheck();

	if (s.dataType != "<EMPTY>" && s.dataType != "bool")
	{
		cerr << "Expression in for is of type \"" << s.dataType << "\", it should be of type bool" << endl;
		return Symbol::ERROR();
	}
	for(idx; idx < children.size(); idx++){
		children[idx]->sematicCheck();
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
