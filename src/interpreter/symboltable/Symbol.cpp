#include <string>

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
	return Symbol(SymbolType::EMPTY, EMPTYSTRING, EMPTYSTRING);
}
Symbol Symbol::ERROR(){
	return Symbol(SymbolType::EMPTY, ERRORSTRING, ERRORSTRING);
}
Symbol Symbol::MODULE(string name){
	return Symbol(SymbolType::MODULE, name, string("<Module>"));
}
Symbol Symbol::FUNCTION(string name, string returnType){
	return Symbol(SymbolType::FUNCTION, name,returnType);
}

Symbol Symbol::EXPRESSION(string valueType, AnyType value){
	return Symbol(SymbolType::EXPRESSION, string("<Expression>"), valueType, value);
}
Symbol Symbol::EXPRESSION(string valueType)
{
	return Symbol(SymbolType::EXPRESSION, string("<Expression>"), valueType);
}

Symbol Symbol::TYPE(string valueType) {
	return Symbol(SymbolType::TYPE, valueType, valueType);
}
