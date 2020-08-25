#pragma once
#include <vector>
#include <iostream>
using namespace std;

enum class SymbolType{EMPTY,EXPRESSION,MUTABLE,IMMUTABLE,FUNCTION,MODULE};

class Symbol {
	public:
		const char *name;
		const SymbolType type;
		char *value;
		const char *valueType;
		const bool isReference;
		const vector<Symbol> children;
		Symbol(char *name, SymbolType type, char *value, char* valueType, bool isReference, vector<Symbol> children)
			: name(name), type(type), value(value), isReference(isReference), valueType(valueType), children(children) {}
		Symbol()
			: name(NULL), type(SymbolType::EMPTY), value(NULL), isReference(false), valueType(NULL), children(vector<Symbol>()) {}
};
