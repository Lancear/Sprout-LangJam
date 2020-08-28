#pragma once
#include <vector>
#include <iostream>
#include <string>

#include "Symbol.hpp"
#include "Any.hpp"

using namespace std;

enum class SymbolType{EMPTY,EXPRESSION,MUTABLE,IMMUTABLE,FUNCTION,MODULE,TYPE};

class Symbol {
	public:
		string name;
		SymbolType type;
		AnyType value;
		string valueType;
		bool isReference;
		vector<Symbol> children = vector<Symbol>();
		Symbol(SymbolType type, string name, string valueType,AnyType value,bool isReference)
			: name(name), type(type), value(value), isReference(isReference), valueType(valueType) {}
		Symbol(SymbolType type, string name, string valueType, AnyType value)
			: name(name), type(type), value(value), isReference(false), valueType(valueType) {}

		Symbol(SymbolType type, string name, string valueType)
			: name(name), type(type), value(value), isReference(false) {}
		
		bool isError();
		bool isEmpty();
		bool isFunction();
		bool isModule();
		bool isMutable();
		bool isImmutable();
		bool isExpression();

		static Symbol EMPTY();
		static Symbol ERROR();
		static Symbol MODULE(string name);
		static Symbol FUNCTION(string name, string returnType);
		static Symbol EXPRESSION(string valueType, AnyType value);
		static Symbol EXPRESSION(string valueType);
		static Symbol TYPE(string valueType);
};
