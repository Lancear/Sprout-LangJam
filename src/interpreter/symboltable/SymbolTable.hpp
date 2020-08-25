#pragma once
#include "Scope.hpp"
#include <stack>
#include <iostream>
#include <memory>
#include "Symbol.hpp"
using namespace std;

class SymbolTable
{ 
public:
	static shared_ptr<SymbolTable> getInstance();
	SymbolTable *add(Symbol symbol);
	bool containsInCurrentScope(char *symbol);
	bool contains(char* symbol);
	Symbol get(char* symbol, shared_ptr<Scope> scope);
	Symbol get(char* symbol);
	//Seeing as i return "this" here, i think a pointer will suffice 
	SymbolTable *clear();
	SymbolTable *openNewScope();
	SymbolTable *closeScope();
	SymbolTable *resetCursor();
	SymbolTable *enterScope();
	SymbolTable *exitScope();

private:
	static shared_ptr<SymbolTable> _instance;
	SymbolTable()
	{
		root = std::make_shared<Scope>();
		currentScope = root;
	}
	shared_ptr<Scope> root;
	shared_ptr<Scope> currentScope;
	std::stack<int> branches;
	SymbolTable(const SymbolTable &);
	SymbolTable &operator=(const SymbolTable &);
};
