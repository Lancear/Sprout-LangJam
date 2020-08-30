#pragma once

#include <stack>
#include <iostream>
#include <memory>
#include <string>

#include "Scope.hpp"
#include "Symbol.hpp"

using namespace std;

class SymbolTable
{ 
public:
	static shared_ptr<SymbolTable> getInstance();
	SymbolTable *add(Symbol symbol);
	bool containsInCurrentScope(string symbol);
	bool contains(string symbol);
	Symbol get(string symbol, Scope* scope);
	Symbol get(string symbol);
	//Seeing as i return "this" here, i think a pointer will suffice 
	SymbolTable *clear();
	SymbolTable *openNewScope();
	SymbolTable *closeScope();
	SymbolTable *resetCursor();
	SymbolTable *enterScope();
	SymbolTable *exitScope();
	static shared_ptr<SymbolTable> _instance;
	SymbolTable()
	{
		root = std::make_shared<Scope>();
		currentScope = root.get();
	}
	shared_ptr<Scope> root;
	Scope* currentScope;
	std::stack<int> branches;
};
