#include <string>
#include <memory>

#include "WhileNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol WhileNode::addSymbols() {
	children[0]->addSymbols();
	SymbolTable::getInstance()->openNewScope();
	children[1]->addSymbols();
	SymbolTable::getInstance()->closeScope();
  return Symbol::EMPTY();
}

Symbol WhileNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  children[0]->sematicCheck();
	SymbolTable::getInstance()->enterScope();
	children[1]->sematicCheck();
	SymbolTable::getInstance()->exitScope();

  return Symbol::EMPTY();
}

Symbol WhileNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
