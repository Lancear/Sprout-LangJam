#include "SymbolTable.hpp"
//TODO: Find out why i have to link Scope.cpp here
#include "Scope.hpp"
#include <unordered_map>
#include <stdexcept>
using namespace std;

const char *SymbolTable::get(char *name){
	return get(name, currentScope);
}

const char* SymbolTable::get(char* name, Scope* scope){
	Scope* currentScope = scope;
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

bool SymbolTable::contains(char *name, Scope* scope)
{
	Scope *currentScope = scope;
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
	//TODO: Check if i the pointer here is a good idea
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
