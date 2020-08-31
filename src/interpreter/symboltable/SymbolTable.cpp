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

SymbolTable * SymbolTable::update(Symbol symbol) {
	Scope* internalScope = currentScope;
	while (internalScope != 0)
	{
		if (internalScope->contains(symbol.name)) {
			internalScope->add(symbol);
			return this;
		}

		internalScope = internalScope->getParent();
	}

	return this;
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
	// skip scope with predefined symbols
	currentScope = root->children.at(0).get();

	branches = stack<stack<int>>();
	branches.push(stack<int>());
	branches.top().push(0);

	callstack = stack<Scope*>();
	callstack.push(currentScope);

	return this;
}



SymbolTable* SymbolTable::enterScope(){
	currentScope = currentScope->children.at(branches.top().top()).get();
	branches.top().push(0);
	return this;
}

SymbolTable* SymbolTable::exitScope(){
	branches.top().pop();
	currentScope = currentScope->getParent();
	int top = branches.top().top();
	branches.top().pop();
	branches.top().push(top + 1);
	return this;
}



SymbolTable* SymbolTable::pushScope(Scope * scope) {
	callstack.push(scope);
	branches.push(stack<int>());
	branches.top().push(0);
	currentScope = callstack.top();
	return this;
}

SymbolTable* SymbolTable::popScope(){
	callstack.pop();
	branches.pop();
	currentScope = callstack.top();
	return this;
}
