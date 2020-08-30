#include <string>
#include <memory>

#include "ImportNode.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ImportNode::addSymbols() {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();

  for (int i = 0; i < children.size(); i++) {
    children[i]->addSymbols();
  }

  return Symbol::EMPTY();
}

Symbol ImportNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol ImportNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
