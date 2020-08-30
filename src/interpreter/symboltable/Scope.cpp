#include <unordered_map>
#include <iostream>
#include <string>

#include "Scope.hpp"
#include "Symbol.hpp"

using namespace std;

Scope* Scope::getParent(){
	return parent;
}

bool Scope::contains(string symbolName){
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

Symbol Scope::get(string name)
{
	std::string symbolNameAsString(name);
	return internalMap.at(symbolNameAsString);
}

void Scope::clear(){
	internalMap.clear();
}
