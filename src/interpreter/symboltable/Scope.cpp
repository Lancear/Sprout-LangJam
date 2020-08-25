#include "Scope.hpp"
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

shared_ptr<Scope> Scope::getParent(){
	return parent;
}

bool Scope::contains(char *symbolName){
	std::string symbolNameAsString(symbolName);
	auto search = internalMap.find(symbolNameAsString);
	return search != internalMap.end();
}

void Scope::add(char *symbolName, char *symbolType){
	//Using a string here because pointers as keys could be a bit chaotic
	std::string symbolNameAsString(symbolName);
	internalMap[symbolNameAsString] = symbolType;
}

const char * Scope::get(char *symbolName){
	std::string symbolNameAsString(symbolName);
	return internalMap.at(symbolNameAsString);
}

void Scope::clear(){
	internalMap.clear();
}