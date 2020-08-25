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
		Symbol(SymbolType type, char *name, char *valueType,char *value,bool isReference)
			: name(name), type(type), value(value), isReference(isReference), valueType(valueType) {}
		Symbol(SymbolType type, char *name, char *valueType, char *value)
			: name(name), type(type), value(value), isReference(false), valueType(valueType) {}
		Symbol()
			: name(NULL), type(SymbolType::EMPTY), value(NULL), isReference(false), valueType(NULL) {}
		static Symbol EMPTY(){
			return Symbol(SymbolType::EMPTY, NULL,NULL,NULL);
		}
};
