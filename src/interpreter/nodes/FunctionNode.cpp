#include <string>
#include <memory>
#include <variant>


#include "FunctionNode.hpp"
#include "ParamListNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol FunctionNode::addSymbols() {
	shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
	syms->openNewScope();

	string type = "void";
	if (children.size() == 4)
		type = children[3]->addSymbols().dataType;


	Symbol s = Symbol::FUNCTION(value, type, (void*)this);
	syms->currentScope->parent->add(s);
	
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->addSymbols();
	}
	
	this->scope = *syms->currentScope;	
	cout << this->scope.parent << endl;
	cout << get<int>(this->scope.parent->parent->get("true").value) << endl;
	syms->closeScope();
  return Symbol::EMPTY();
}

Symbol FunctionNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  "  << syms->get(value).dataType << " " << value << endl;

  syms->enterScope();
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->sematicCheck();
	}
	syms->exitScope();

  return Symbol::EMPTY();
}

Symbol FunctionNode::execute(Symbol args[]) {
	shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
	cout << "Executing ... " << endl;
	syms->pushScope(this->scope);
	cout << this->scope.parent << endl;
	cout << syms->currentScope->parent << endl;
	cout << get<int>(this->scope.parent->parent->get("true").value) << endl;


	int params = (children.size() == 4) ? 1 : 0;
	((ParamListNode*)children[params].get())->execute(args);

	int code = (children.size() == 4) ? 2 : 1;
	Symbol retVal = children[code]->execute();

	syms->popScope();
  return retVal;
}
