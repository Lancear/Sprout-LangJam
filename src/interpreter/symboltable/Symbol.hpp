#pragma once
#include <vector>
#include <iostream>
#include "Symbol.hpp"
using namespace std;

enum class SymbolType{EMPTY,EXPRESSION,MUTABLE,IMMUTABLE,FUNCTION,MODULE};

class Symbol {
	public:
		char *name;
		SymbolType type;
		char *value;
		char *valueType;
		bool isReference;
		vector<Symbol> children = vector<Symbol>();
		Symbol(SymbolType type, char *name, char *valueType,char *value,bool isReference)
			: name(name), type(type), value(value), isReference(isReference), valueType(valueType) {}
		Symbol(SymbolType type, char *name, char *valueType, char *value)
			: name(name), type(type), value(value), isReference(false), valueType(valueType) {}
		
		bool IsError();
		bool isEmpty();
		bool isFunction();
		bool isModule();
		bool isMutable();
		bool isImmutable();

		static Symbol EMPTY();
		static Symbol ERROR();
		static Symbol MODULE(char* name);
		static Symbol FUNCTION(char *name, char *returnType);
		static Symbol EXPRESSION(char* value);
		static Symbol EXPRESSION();
};
