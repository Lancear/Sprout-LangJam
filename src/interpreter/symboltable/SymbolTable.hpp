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
		SymbolTable *clear();
		
		/**
		 *  creates a new scope as a child of the actual scope
		 */ 
		SymbolTable *openNewScope();

		/**
		 *  closes the current scope and goes back to the parent scope
		 */ 
		SymbolTable *closeScope();

		/**
		 *  reset the cursor to the file-scope
		 */ 
		SymbolTable *resetCursor();

		/**
		 *  traverses the symboltable, use enterScope to go to the next scope
		 */ 
		SymbolTable *enterScope();

		/**
		 *  traverses the symboltable, use exitScope to go to the parent of the current scope.
		 *  next enterScope will go to the next child of that scope
		 */ 
		SymbolTable *exitScope();

		/**
		 * keeps track of a call-stack of scopes, pushScope adds a scope to the call-stack
		 */
		SymbolTable *pushScope(Scope scope);

		/**
		 * keeps track of a call-stack of scopes, popScope removes the top scope of the call-stack
		 */
		SymbolTable *popScope();

		static shared_ptr<SymbolTable> _instance;
		SymbolTable()
		{
			root = std::make_shared<Scope>();
			currentScope = root.get();

			// predefined types/values
			add(Symbol::TYPE("int"));
			add(Symbol::TYPE("bool"));
			add(Symbol::TYPE("char"));
			add(Symbol::TYPE("string"));
			add(Symbol::IMMUTABLE("true", "bool", 1));
			add(Symbol::IMMUTABLE("false", "bool", 0));
			openNewScope();
		}
		shared_ptr<Scope> root;

		/**
		 * The scope currently pointed add through usage of openNewScope/enterScope/pushScope
		 */
		Scope* currentScope;

	protected:
		stack<stack<int>> branches;
		stack<Scope> callstack;
};
