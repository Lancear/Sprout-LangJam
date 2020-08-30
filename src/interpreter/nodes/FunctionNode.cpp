#include <string>
#include <memory>

#include "FunctionNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol FunctionNode::addSymbols() {
	shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
	syms->openNewScope();
	this->scope = *syms->currentScope;

	string type = "void";
	if (children.size() == 4)
		type = children[3]->addSymbols().dataType;


	Symbol s = Symbol::FUNCTION(value, type, (void*)this);
	syms->currentScope->parent->add(s);
	
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->addSymbols();
	}
	
	syms->closeScope();
  return Symbol::EMPTY();
}

Symbol FunctionNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  "  << syms->get(value).dataType << " " << value << endl;

  syms->enterScope();
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->sematicCheck();
	}
	syms->exitScope();

  return Symbol::EMPTY();
}

Symbol FunctionNode::execute(Symbol args[]) {
	shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
	cout << "Executing ... " << endl;
	syms->pushScope(this->scope);

  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

	syms->popScope();
  return Symbol::EMPTY();
}
