#include "Symbol.hpp"

static char* EMPTYSTRING = "<EMPTY>";
static char* ERRORSTRING = "<ERROR>";

bool Symbol::IsError(){
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

Symbol Symbol::EMPTY(){
	return Symbol(SymbolType::EMPTY, EMPTYSTRING, EMPTYSTRING, NULL);
}
Symbol Symbol::ERROR(){
	return Symbol(SymbolType::EMPTY, ERRORSTRING, ERRORSTRING, NULL);
}
Symbol Symbol::MODULE(char* name){
	return Symbol(SymbolType::MODULE, name, "<Module>", NULL);
}
Symbol Symbol::FUNCTION(char* name, char* returnType){
	return Symbol(SymbolType::FUNCTION, name,returnType, NULL);
}
Symbol Symbol::EXPRESSION(char* value){
	return Symbol(SymbolType::EXPRESSION, "<Expression>", "<Expression>", value);
}
Symbol Symbol::EXPRESSION()
{
	return Symbol(SymbolType::EXPRESSION, "<Expression>", "<Expression>", NULL);
}