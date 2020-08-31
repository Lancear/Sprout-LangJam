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
	Symbol fnSym;
	Symbol sym = Symbol::EMPTY();

	syms->openNewScope();

	string type = "void";
	if (children.size() == 4) {
		sym = children[3]->addSymbols();
		type = sym.dataType;
	}

	if (syms->currentScope->parent->contains(value)) {
    ErrorHandler::error("a symbol with this name already exists, name: " + value);
    sym = Symbol::ERROR();
  }
	else if (!sym.isError()) {
		fnSym = Symbol::FUNCTION(value, type, (void*)this);
		syms->currentScope->parent->add(fnSym);
	}
	
	int params = (children.size() == 4) ? 1 : 0;
	sym = children[params]->addSymbols();

	int code = (children.size() == 4) ? 2 : 1;
	sym = children[code]->addSymbols();
	
	this->scope = syms->currentScope;	
	syms->closeScope();

  return (sym.isError()) ? sym : fnSym;
}

Symbol FunctionNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();

  syms->enterScope();
	for (int i = (children.size() == 4) ? 1 : 0; i < children.size(); i++)
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
