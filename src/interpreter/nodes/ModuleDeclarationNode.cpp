#include <iostream>

#include "ModuleDeclarationNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;
Symbol ModuleDeclarationNode::analyse(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  
  syms
    -> add(Symbol(SymbolType::MODULE, value, "<EMPTY>", "<MODULE>"))
    -> openNewScope();

  cout << syms->get(value).name << endl;
  return Symbol::EMPTY();
}

Symbol ModuleDeclarationNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
