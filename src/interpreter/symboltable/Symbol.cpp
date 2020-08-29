#include <string>
#include <map>
#include "Symbol.hpp"

static string EMPTYSTRING = "<EMPTY>";
static string ERRORSTRING = "<ERROR>";

bool Symbol::isError(){
	return name == ERRORSTRING;
}
bool Symbol::isEmpty()
{
	return name == EMPTYSTRING;
}
bool Symbol::isFunction()
{
	return type == SymbolType::FUNCTION;
}
bool Symbol::isModule()
{
	return type == SymbolType::MODULE;
}
bool Symbol::isMutable()
{
	return type == SymbolType::MUTABLE;
}
bool Symbol::isImmutable()
{
	return type == SymbolType::IMMUTABLE;
}

bool Symbol::isExpression() {
	return type == SymbolType::EXPRESSION;
}

Symbol Symbol::EMPTY(){
	Symbol s = Symbol();
	s.name = "<EMPTY>";
	s.dataType = "<EMPTY>";
	s.type = SymbolType::EMPTY;
	return s;
}

Symbol Symbol::ERROR(){
	Symbol s = Symbol();
	s.name = "<ERROR>";
	s.dataType = "<ERROR>";
	s.type = SymbolType::ERROR;
	return s;
}
Symbol Symbol::MODULE(string name, SimpleScope value)
{
	Symbol s = Symbol();
	s.name = name;
	s.value = value;
	s.dataType = "<MODULE>";
	s.type = SymbolType::MODULE;
	return s;
}
Symbol Symbol::MODULE(string name, SimpleScope value)
{
	Symbol s = Symbol();
	s.name = name;
	s.value = value;
	s.dataType = "<MODULE>";
	s.type = SymbolType::MODULE;
	return s;
}
Symbol Symbol::FUNCTION(string name, string returnType, SimpleTreeNode body)
{
	Symbol s = Symbol();
	s.name = name;
	s.value = body;
	s.dataType = returnType;
	s.type = SymbolType::FUNCTION;
	return s;
}
Symbol Symbol::EXPRESSION(string dataType, int value){
	Symbol s = Symbol();
	s.name = "<EXPRESSION>";
	s.value = value;
	s.dataType = dataType;
	s.type = SymbolType::EXPRESSION;
	return s;
}
Symbol Symbol::EXPRESSION(string dataType, string value){
	Symbol s = Symbol();
	s.name = "<EXPRESSION>";
	s.value = value;
	s.dataType = dataType;
	s.type = SymbolType::EXPRESSION;
	return s;
}
Symbol Symbol::MUTABLE(string name, string dataType, int value){
	Symbol s = Symbol();
	s.name = name;
	s.value = value;
	s.dataType = dataType;
	s.type = SymbolType::MUTABLE;
	return s;
}
Symbol Symbol::MUTABLE(string name, string dataType, string value){
	Symbol s = Symbol();
	s.name = name;
	s.value = value;
	s.dataType = dataType;
	s.type = SymbolType::MUTABLE;
	return s;
}
Symbol Symbol::IMMUTABLE(string name, string dataType, int value){
	Symbol s = Symbol();
	s.name = name;
	s.value = value;
	s.dataType = dataType;
	s.type = SymbolType::IMMUTABLE;
	return s;
}
Symbol Symbol::IMMUTABLE(string name, string dataType, string value){
	Symbol s = Symbol();
	s.name = name;
	s.value = value;
	s.dataType = dataType;
	s.type = SymbolType::IMMUTABLE;
	return s;
}
Symbol Symbol::TYPE(string dataType){
	Symbol s = Symbol();
	s.name = "<TYPE>";
	s.dataType = dataType;
	s.type = SymbolType::TYPE;
	return s;
}
