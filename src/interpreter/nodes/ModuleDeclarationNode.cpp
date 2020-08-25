#include <iostream>

#include "ModuleDeclarationNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ModuleDeclarationNode::analyse(Symbol symParam) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  Symbol sym = Symbol(SymbolType::MODULE, value, "<EMPTY>", "<MODULE>");
  cout << "Module " << value << " > ";

  if (syms->containsInCurrentScope((char*)sym.name)) {
    cerr << "Symbol `" << sym.name << "` already exists as type " << (int)syms->get(sym.name).type;
    return Symbol::ERROR();
  }

  syms->add(sym)->openNewScope();

  for (int i = 0; i < children.size(); i++) {
    children[i]->analyse();
  }
  
  syms->closeScope();
  return Symbol::EMPTY();
}

Symbol ModuleDeclarationNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
