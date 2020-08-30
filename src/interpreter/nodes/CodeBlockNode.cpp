#include <string>
#include <memory>
#include <variant>

#include "CodeBlockNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol CodeBlockNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol CodeBlockNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    Symbol retVal = children[i]->execute();

    if (children[i]->type == ReturnStatement && !retVal.isEmpty()) {
      return retVal;
    }
  }

  return Symbol::EMPTY();
}
