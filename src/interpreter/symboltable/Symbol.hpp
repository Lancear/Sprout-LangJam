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
		
		static Symbol EMPTY(){
			return Symbol(SymbolType::EMPTY, "<EMPTY>", "<EMPTY>", "<EMPTY>");
		}
};
