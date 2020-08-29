#include <string>
#include <memory>

#include "DoWhileNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

void DoWhileNode::addSymbols() {
  SymbolTable::getInstance()->openNewScope();
  children[0]->addSymbols();
  SymbolTable::getInstance()->closeScope();
  children[1]->addSymbols();
}

Symbol DoWhileNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol DoWhileNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
