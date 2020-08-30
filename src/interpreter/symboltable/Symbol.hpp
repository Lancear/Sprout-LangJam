#pragma once

#include <vector>
#include <iostream>
#include <variant>
#include <string>
#include <map>

using namespace std;

enum class SymbolType{EMPTY,EXPRESSION,MUTABLE,IMMUTABLE,FUNCTION,MODULE,TYPE,ERROR};

class Symbol {
	public:
		string name;
		SymbolType type;
		variant<int, string, void*> value;
		string dataType;
		bool isReference;
		vector<Symbol> children = vector<Symbol>();
		
		bool isError();
		bool isEmpty();
		bool isFunction();
		bool isModule();
		bool isMutable();
		bool isImmutable();
		bool isExpression();

		static Symbol EMPTY();
		static Symbol ERROR();
		static Symbol MODULE(string name, void* scope);
		static Symbol CLASS(string name, void* scope);
		static Symbol FUNCTION(string name, string returnType, void* body);
		static Symbol EXPRESSION(string dataType, int value);
		static Symbol EXPRESSION(string dataType, string value);
		static Symbol MUTABLE(string name, string dataType, int value);
		static Symbol MUTABLE(string name, string dataType, string value);
		static Symbol IMMUTABLE(string name, string dataType, int value);
		static Symbol IMMUTABLE(string name, string dataType, string value);
		static Symbol TYPE(string dataType);
		Symbol(){}
};
