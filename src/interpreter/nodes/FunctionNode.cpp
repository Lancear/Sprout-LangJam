#include <string>
#include <memory>

#include "FunctionNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol FunctionNode::addSymbols() {
	shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
	syms->openNewScope();
	Symbol s = Symbol::FUNCTION(value, "?", (void*)this);
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
  cout << type << ":  " << value << endl;

  syms->enterScope();
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->sematicCheck();
	}
	syms->exitScope();

  return Symbol::EMPTY();
}

Symbol FunctionNode::execute(Symbol args[]) {
	cout << "Executing ... " << endl;

  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
