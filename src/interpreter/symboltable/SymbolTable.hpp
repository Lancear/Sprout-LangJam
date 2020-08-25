#pragma once
#include "Scope.hpp"
#include <stack>
#include <iostream>
#include <memory>
using namespace std;

class SymbolTable
{ 
public:
	static weak_ptr<SymbolTable> getInstance();
	SymbolTable *add(char *name, char *symbolType);
	bool contains(char *name);
	bool contains(char *name, shared_ptr<Scope> scope);
	const char *get(char *name);
	const char *get(char *name, shared_ptr<Scope> scope);
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
