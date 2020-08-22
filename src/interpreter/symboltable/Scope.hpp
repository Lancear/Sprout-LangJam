#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;

class Scope
{
private:
	map<string, char*> internalMap;

public:
	Scope *parent;
	const vector<Scope*> children;
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