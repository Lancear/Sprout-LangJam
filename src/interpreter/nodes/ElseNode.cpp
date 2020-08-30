#include <string>
#include <memory>

#include "ElseNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ElseNode::addSymbols() {
	SymbolTable::getInstance()->openNewScope();
	children[0]->addSymbols();
	SymbolTable::getInstance()->closeScope();
  return Symbol::EMPTY();
}

Symbol ElseNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  syms->enterScope();
  children[0]->sematicCheck();
  syms->exitScope();

  return Symbol::EMPTY();
}

Symbol ElseNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
