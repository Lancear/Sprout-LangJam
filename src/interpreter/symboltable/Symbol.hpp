#pragma once
#include <vector>
#include <iostream>
#include "Symbol.hpp"
using namespace std;

enum class SymbolType{EMPTY,EXPRESSION,MUTABLE,IMMUTABLE,FUNCTION,MODULE};

class Symbol {
	public:
		const char *name;
		const SymbolType type;
		char *value;
		const char *valueType;
		const bool isReference;
		const vector<Symbol> children = vector<Symbol>();
		Symbol(char *name, SymbolType type, char *value, char* valueType, bool isReference, vector<Symbol> children)
			: name(name), type(type), value(value), isReference(isReference), valueType(valueType){}
		Symbol()
			: name(NULL), type(SymbolType::EMPTY), value(NULL), isReference(false), valueType(NULL) {}
		//TODO: Static function that create functions and module and normal constructor without reference, switch symboltype and name and value and valuetype, maybe EMPTY
};
