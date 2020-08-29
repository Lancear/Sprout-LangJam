#include <string>
#include <memory>

#include "IfNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

void IfNode::addSymbols() {
	children[0]->addSymbols();
	SymbolTable::getInstance()->openNewScope();
	children[1]->addSymbols();
	SymbolTable::getInstance()->closeScope();
}

Symbol IfNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol IfNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
