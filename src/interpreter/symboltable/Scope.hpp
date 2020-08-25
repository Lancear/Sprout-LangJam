#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
using namespace std;

class Scope
{
private:
	map<string, char*> internalMap;

public:
	shared_ptr<Scope> parent;
	const vector<shared_ptr<Scope>> children;
	Scope(){
		this->parent = NULL;
	}
	Scope(shared_ptr<Scope> parent){
		this->parent = parent;
	}
	shared_ptr<Scope> getParent();
	void add(char *symbolName, char *symbolType);
	bool contains(char *symbolName);
	const char *get(char *symbolName);
	void clear();
};