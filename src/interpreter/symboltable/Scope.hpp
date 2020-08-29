#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Symbol.hpp"
#include "SimpleScope.hpp"
using namespace std;

class Scope : public SimpleScope{
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
	bool contains(string symbolName);
	Symbol get(string symbolName);
	void clear();
	map<string, Symbol> internalMap;
};
