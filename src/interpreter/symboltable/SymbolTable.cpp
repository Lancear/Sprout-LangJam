#include "SymbolTable.hpp"
#include "Scope.hpp"
#include <unordered_map>
#include <stdexcept>
#include <iostream>
using namespace std;

shared_ptr<SymbolTable> SymbolTable::_instance = NULL;

weak_ptr<SymbolTable> SymbolTable::getInstance(){
	if (_instance == NULL)
	{
		_instance.reset(new SymbolTable());
	}
	weak_ptr<SymbolTable> tablePtr = _instance;
	return tablePtr;
}

const char *SymbolTable::get(char *name){
	return get(name, currentScope);
}

const char* SymbolTable::get(char* name, shared_ptr<Scope> scope){
	shared_ptr<Scope> currentScope = scope;
	while(currentScope != 0){
		if(currentScope->contains(name))
			return currentScope->get(name);
		currentScope = currentScope->getParent();
	}
	return NULL;
}

bool SymbolTable::contains(char *name)
{
	return contains(name, currentScope);
}

bool SymbolTable::contains(char *name, shared_ptr<Scope> scope)
{
	shared_ptr<Scope> currentScope = scope;
	while (currentScope != 0)
	{
		if (currentScope->contains(name))
			return true;
		currentScope = currentScope->getParent();
	}
	return false;
}

SymbolTable *SymbolTable::add(char *name, char *symbolType)
{
	currentScope->add(name, symbolType);
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
