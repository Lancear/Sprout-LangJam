#include <unordered_map>
#include <stdexcept>
#include <iostream>
#include <optional>
#include <string>

#include "SymbolTable.hpp"
#include "Scope.hpp"
#include "Symbol.hpp"
using namespace std;

shared_ptr<SymbolTable> SymbolTable::_instance = make_shared<SymbolTable>();

shared_ptr<SymbolTable> SymbolTable::getInstance(){
	return _instance;
}

Symbol SymbolTable::get(string symbol, Scope* scope)
{
	Scope* internalScope = scope;
	while (internalScope != 0)
	{
		if (internalScope->contains(symbol))
			return internalScope->get(symbol);
		internalScope = internalScope->getParent();
	}
	return Symbol::EMPTY();
}

Symbol SymbolTable::get(string symbol)
{
	Scope* internalScope = currentScope;
	while (internalScope != 0)
	{
		if (internalScope->contains(symbol))
			return internalScope->get(symbol);
		internalScope = internalScope->getParent();
	}
	return Symbol::EMPTY();
}

bool SymbolTable::containsInCurrentScope(string symbol)
{
	return currentScope->contains(symbol);
}

bool SymbolTable::contains(string symbol)
{
	Scope* internalScope = currentScope;
	while (internalScope != 0)
	{
		if (internalScope->contains(symbol))
			return true;
		internalScope = internalScope->getParent();
	}
	return false;
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
	currentScope = new Scope(currentScope);
	return this;
}
SymbolTable * SymbolTable::closeScope(){
	if (currentScope->getParent() == 0)
		throw invalid_argument("No parent set. Error.");

	currentScope = currentScope->getParent();
	return this;
}

SymbolTable * SymbolTable::resetCursor(){
	currentScope = root.get();
	branches = stack<int>();
	branches.push(0);
	return this;
}

SymbolTable* SymbolTable::enterScope(){
	currentScope = currentScope->children.at(branches.top()).get();
	branches.push(0);
	return this;
}

SymbolTable* SymbolTable::exitScope(){
	branches.pop();
	currentScope = currentScope->getParent();
	int top = branches.top();
	branches.pop();
	branches.push(top + 1);
	return this;
}
