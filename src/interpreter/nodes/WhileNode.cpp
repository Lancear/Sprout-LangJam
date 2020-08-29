#include <string>
#include <memory>

#include "WhileNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

void WhileNode::addSymbols() {
	children[0]->addSymbols();
	SymbolTable::getInstance()->openNewScope();
	children[1]->addSymbols();
	SymbolTable::getInstance()->closeScope();
}

Symbol WhileNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol WhileNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
