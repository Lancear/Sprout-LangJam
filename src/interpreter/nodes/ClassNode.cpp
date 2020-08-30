#include <string>
#include <memory>

#include "ClassNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ClassNode::addSymbols() {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  syms->openNewScope();
  Symbol s = Symbol::CLASS(value,*(syms->currentScope));
  syms->currentScope->parent->add(s);
   for (int i = 0; i < children.size(); i++) {
    children[i]->addSymbols();
  }
  syms->closeScope();
  return Symbol::EMPTY();
}

Symbol ClassNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  syms->enterScope();
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  syms->exitScope();
  return Symbol::EMPTY();
}

Symbol ClassNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
