#include "SymbolTable.hpp"
//TODO: Find out why i have to link Scope.cpp here
#include "Scope.hpp"
#include <unordered_map>
#include <stdexcept>
using namespace std;

const char *SymbolTable::get(char *name){
	return get(name, this->currentScope);
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
	Scope *currentScope = this->currentScope;
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
	this->currentScope->add(name, symbolType);
	return this;
}

SymbolTable* SymbolTable::clear(){
	this->currentScope->clear();
	return this;
}

SymbolTable * SymbolTable::openNewScope(){
	this->currentScope = new Scope(this->currentScope);
	return this;
}
SymbolTable * SymbolTable::closeScope(){
	if (this->currentScope->getParent() == 0)
		throw invalid_argument("No parent set. Error.");
		this->currentScope = this->currentScope->getParent();
	return this;
}

SymbolTable * SymbolTable::resetCursor(){
	this->currentScope = this->root;
	this->branches = stack<int>();
	this->branches.push(0);
	return this;
}

SymbolTable* SymbolTable::enterScope(){
	this->currentScope = this->currentScope->children.at(this->branches.top());
	this->branches.push(0);
	return this;
}

SymbolTable* SymbolTable::exitScope(){
	this->branches.pop();
	this->currentScope = this->currentScope->getParent();
	this->branches.push(branches.top() + 1);
	branches.pop();
	return this;
}
