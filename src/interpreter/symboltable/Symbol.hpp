#pragma once
#include <vector>
#include <iostream>
using namespace std;

enum class SymbolType{EMPTY,EXPRESSION,MUTABLE,IMMUTABLE,FUNCTION,MODULE};
enum class ValueType{NONE, INT64, INT32, INT16, INT8, BOOL, STRING, CHAR, FLOAT, DOUBLE};

class Symbol {
	public:
		const char *name;
		const SymbolType type;
		char *value;
		const ValueType valueType;
		const bool isReference;
		const vector<Symbol> children;
		Symbol(char *name, SymbolType type, char *value, ValueType valueType, bool isReference, vector<Symbol> children)
			: name(name), type(type), value(value), isReference(isReference), valueType(valueType), children(children) {}
		Symbol()
			: name(NULL), type(SymbolType::EMPTY), value(NULL), isReference(false), valueType(ValueType::NONE), children(vector<Symbol>()) {}
};
