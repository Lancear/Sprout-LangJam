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
	auto search = internalMap.find(symbolName);
	return search != internalMap.end();
}

void Scope::add(Symbol symbol)
{
	if (contains(symbol.name)) {
		internalMap.erase(symbol.name);
	}

	internalMap.insert(std::make_pair(symbol.name,symbol));
}

Symbol Scope::get(string name)
{
	return internalMap.at(name);
}

void Scope::clear(){
	internalMap.clear();
}
