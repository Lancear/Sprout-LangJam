#include <string>
#include <memory>

#include "ClassNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"
#include "../symboltable/Scope.hpp"

using namespace std;

Symbol ClassNode::addSymbols() {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  syms->openNewScope();
  Symbol s = Symbol::CLASS(value, (void*)this);

  syms->currentScope->parent->add(s);
   for (int i = 0; i < children.size(); i++) {
    children[i]->addSymbols();
  }

  this->scope = syms->currentScope;
  syms->closeScope();
  return Symbol::EMPTY();
}

Symbol ClassNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << "(" << children.size() << ")" << endl;
  
  syms->enterScope();
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  syms->exitScope();
  return Symbol::EMPTY();
}

Symbol ClassNode::execute(Symbol sym) {
  return Symbol::EMPTY();
}
