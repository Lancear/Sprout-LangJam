#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Symbol.hpp"
using namespace std;

class Scope
{
private:
	map<string, Symbol> internalMap;

public:
	shared_ptr<Scope> parent;
	vector<shared_ptr<Scope>> children;
	Scope(){
		this->parent = NULL;
	}
	Scope(shared_ptr<Scope> parent){
		this->parent = parent;
	}
	shared_ptr<Scope> getParent();
	void add(Symbol symbol);
	bool contains(char *symbolName);
	Symbol get(char *symbolName);
	void clear();
};
