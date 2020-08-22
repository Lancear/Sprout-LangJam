#include "Scope.hpp"
#include <unordered_map>
#include <iostream>
#include <string>
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
	std::string symbolNameAsString(symbolName);
	internalMap[symbolNameAsString] = symbolType;
}

const char * Scope::get(char *symbolName){
	std::string symbolNameAsString(symbolName);
	return this->internalMap.at(symbolNameAsString);
}

void Scope::clear(){
	this->internalMap.clear();
}