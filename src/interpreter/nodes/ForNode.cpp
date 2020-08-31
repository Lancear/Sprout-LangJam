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
		SymbolTable::getInstance()->exitScope();
		return Symbol::EMPTY();
	}

	int idx = 2;

	if(children[1]->type != CodeBlock)
		idx--;
	Symbol s = children[idx++]->sematicCheck();

	if (s.dataType != "<EMPTY>" && s.dataType != "bool")
	{
		cerr << "Expression in for is of type \"" << s.dataType << "\", it should be of type bool" << endl;
		SymbolTable::getInstance()->exitScope();
		return Symbol::ERROR();
	}
	for(idx; idx < children.size(); idx++){
		children[idx]->sematicCheck();
	}

  SymbolTable::getInstance()->exitScope();
  return Symbol::EMPTY();
}

Symbol ForNode::execute(Symbol sym) {
	SymbolTable::getInstance()->enterScope();
	Scope * s = SymbolTable::getInstance()->currentScope;
	if(children.size() != 1)
		children[0]->execute();
	SymbolTable::getInstance()->exitScope();
	if (children.size() == 1)
	{
		while(true){
			SymbolTable::getInstance()->pushScope(s);
			children[0]->execute();
			SymbolTable::getInstance()->popScope();
		}
		return Symbol::EMPTY();
	}
	//If for has 4 children, if we have no codeblock, we reduce the idx by one
	int idxModifier = children.size() == 4 ? 0 : 1;

	//Check if we have a third statement
	bool thirdExp = children[3-idxModifier]->type != EmptyStatement;
	//If the second statement is empty, we have an endless loop
	if (children[2-idxModifier]->type == EmptyStatement)
	{
		while (true)
		{
			SymbolTable::getInstance()->pushScope(s);
			if (idxModifier == 0)
				children[1]->execute();
			if (thirdExp)
				children[3 - idxModifier]->execute();
			SymbolTable::getInstance()->popScope();
		}
	}
	else
	{
		SymbolTable::getInstance()->pushScope(s);
		int value = get<int>(children[2 - idxModifier]->execute().value);
		SymbolTable::getInstance()->popScope();

		while (value == 1)
		{
			SymbolTable::getInstance()->pushScope(s);
			if (idxModifier == 0)
				children[1]->execute();
			if (thirdExp)
				children[3 - idxModifier]->execute();
			value = get<int>(children[2 - idxModifier]->execute().value);
			SymbolTable::getInstance()->popScope();
		}
	}
	return Symbol::EMPTY();
}
