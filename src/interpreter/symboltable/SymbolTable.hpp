#pragma once
#include "Scope.hpp"
#include <stack>
#include <iostream>

class SymbolTable
{
	Scope *root, *currentScope;
	std::stack<int> branches; 
public:
		SymbolTable(){

			currentScope = root;
		}
		SymbolTable *add(char *name, char *symbolType);
		bool contains(char *name);
		const char *get(char *name);
		const char * get(char *name, Scope *scope);
		SymbolTable * clear();
		SymbolTable * openNewScope();
		SymbolTable * closeScope();
		SymbolTable * resetCursor();
		SymbolTable * enterScope();
		SymbolTable * exitScope();
};