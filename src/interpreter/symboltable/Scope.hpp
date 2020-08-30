#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Symbol.hpp"
using namespace std;

class Scope {
public:
	Scope* parent;
	vector<shared_ptr<Scope>> children;
	Scope(){
		this->parent = nullptr;
	}
	Scope(Scope* parent){
		this->parent = parent;
		parent->children.push_back((shared_ptr<Scope>)this);
	}
	Scope* getParent();
	void add(Symbol symbol);
	bool contains(string symbolName);
	Symbol get(string symbolName);
	void clear();
	map<string, Symbol> internalMap;
};
