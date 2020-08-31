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
	Symbol fnSym, sym;

	syms->openNewScope();

	string type = "void";
	if (children.size() == 4)
		type = children[3]->addSymbols().dataType;


	if (syms->currentScope->parent->contains(value)) {
    ErrorHandler::error("a symbol with this name already exists, name: " + value);
    sym = Symbol::ERROR();
  }
	else {
		fnSym = Symbol::FUNCTION(value, type, (void*)this);
		syms->currentScope->parent->add(fnSym);
	}
	
	for (int i = 0; i < children.size(); i++)
	{
		sym = children[i]->addSymbols();
	}
	
	this->scope = syms->currentScope;	
	syms->closeScope();

  return (sym.isError()) ? sym : fnSym;
}

Symbol FunctionNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();

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
	syms->pushScope(this->scope);

	int params = (children.size() == 4) ? 1 : 0;
	((ParamListNode*)children[params].get())->execute(args);

	int code = (children.size() == 4) ? 2 : 1;
	Symbol retVal = children[code]->execute();

	syms->popScope();
  return retVal;
}
