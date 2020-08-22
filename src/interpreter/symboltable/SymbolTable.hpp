#pragma once
#include "Scope.hpp"
#include <stack>
#include <iostream>
#include <memory>
using namespace std;

class SymbolTable
{ 
public:
	static shared_ptr<SymbolTable> getInstance();
	SymbolTable *add(char *name, char *symbolType);
	bool contains(char *name);
	bool contains(char *name, Scope *scope);
	const char *get(char *name);
	const char *get(char *name, Scope *scope);
	SymbolTable *clear();
	SymbolTable *openNewScope();
	SymbolTable *closeScope();
	SymbolTable *resetCursor();
	SymbolTable *enterScope();
	SymbolTable *exitScope();
	~SymbolTable()
	{
		delete root;
		}

private:
	static shared_ptr<SymbolTable> _instance;
	SymbolTable()
	{
		root = new Scope();
		currentScope = root;
	}
	Scope *root, *currentScope;
	std::stack<int> branches;
	//Dont know what that does yet
	SymbolTable(const SymbolTable &);
	SymbolTable &operator=(const SymbolTable &);
};
