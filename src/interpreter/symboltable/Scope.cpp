#include "Scope.hpp"
#include <unordered_map>
#include <iostream>
#include <string>
#include "Symbol.hpp"
using namespace std;

shared_ptr<Scope> Scope::getParent(){
	return parent;
}

bool Scope::contains(char *symbolName){
	std::string symbolNameAsString(symbolName);
	auto search = internalMap.find(symbolNameAsString);
	return search != internalMap.end();
}

void Scope::add(Symbol symbol)
{
	//Using a string here because pointers as keys could be a bit chaotic
	std::string symbolNameAsString(symbol.name);
	internalMap.insert(std::make_pair(symbolNameAsString,symbol));
}

Symbol Scope::get(char * name)
{
	std::string symbolNameAsString(name);
	return internalMap.at(symbolNameAsString);
}

void Scope::clear(){
	internalMap.clear();
}