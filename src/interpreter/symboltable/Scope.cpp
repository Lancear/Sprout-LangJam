#include "Scope.hpp"
#include <unordered_map>
#include <iostream>
using namespace std;

Scope * Scope::getParent(){
	return this->parent;
}

bool Scope::contains(char *symbolName){
	std::string symbolNameAsString(symbolName);
	auto search = this->internalMap.find(symbolNameAsString);
	return search != this->internalMap.end();
}

void Scope::add(char *symbolName, char *symbolType){
	//Converted into strings because i thought that would change something, which it did not
	std::string symbolNameAsString(symbolName);
	std::string symbolTypeAsString(symbolType);
	this->internalMap.insert(pair<string, string>(symbolNameAsString, symbolTypeAsString));
}

const char * Scope::get(char *symbolName){
	std::string symbolNameAsString(symbolName);
	return this->internalMap.at(symbolNameAsString).c_str();
}

void Scope::clear(){
	this->internalMap.clear();
}