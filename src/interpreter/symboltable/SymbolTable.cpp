#include "SymbolTable.hpp"
#include "Scope.hpp"
#include <unordered_map>
#include <stdexcept>
#include <iostream>
#include <optional>
#include "Symbol.hpp"
using namespace std;

shared_ptr<SymbolTable> SymbolTable::_instance = NULL;

shared_ptr<SymbolTable> SymbolTable::getInstance(){
	if (_instance == NULL)
	{
		_instance.reset(new SymbolTable());
	}
	return _instance;
}

Symbol SymbolTable::get(char* symbol, shared_ptr<Scope> scope)
{
	shared_ptr<Scope> currentScope = scope;
	while (currentScope != 0)
	{
		if (currentScope->contains(symbol))
			return currentScope->get(symbol);
		currentScope = currentScope->getParent();
	}
	return Symbol::EMPTY();
}

Symbol SymbolTable::get(char* symbol)
{
	return get(symbol, currentScope);
}

bool SymbolTable::contains(char* symbol, shared_ptr<Scope> scope)
{
	shared_ptr<Scope> currentScope = scope;
	while (currentScope != 0)
	{
		if (currentScope->contains(symbol))
			return true;
		currentScope = currentScope->getParent();
	}
	return false;
}

bool SymbolTable::contains(char* symbol)
{
	return contains(symbol, currentScope);
}

SymbolTable *SymbolTable::add(Symbol symbol)
{
	currentScope->add(symbol);
	return this;
}

SymbolTable* SymbolTable::clear(){
	currentScope->clear();
	return this;
}

SymbolTable * SymbolTable::openNewScope(){
	currentScope = std::make_shared<Scope>(currentScope);
	return this;
}
SymbolTable * SymbolTable::closeScope(){
	if (currentScope->getParent() == 0)
		throw invalid_argument("No parent set. Error.");
		currentScope = currentScope->getParent();
	return this;
}

SymbolTable * SymbolTable::resetCursor(){
	currentScope = root;
	branches = stack<int>();
	branches.push(0);
	return this;
}

SymbolTable* SymbolTable::enterScope(){
	currentScope = currentScope->children.at(branches.top());
	branches.push(0);
	return this;
}

SymbolTable* SymbolTable::exitScope(){
	branches.pop();
	currentScope = currentScope->getParent();
	branches.push(branches.top() + 1);
	branches.pop();
	return this;
}
