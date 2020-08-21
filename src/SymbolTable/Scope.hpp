#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Scope
{
public:
	Scope *parent;
	const vector<Scope*> children;
	unordered_map<string, string> internalMap;
	Scope(){
		this->parent = NULL;
	}
	Scope(Scope * parent){
		this->parent = parent;
	}
	Scope* getParent();
	void add(char *symbolName, char *symbolType);
	bool contains(char *symbolName);
	const char *get(char *symbolName);
	void clear();
};