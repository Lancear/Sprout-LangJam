#include <string>
#include <memory>

#include "CharNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol CharNode::addSymbols() {
  return Symbol::EXPRESSION("char", (int)value[0]);
}

Symbol CharNode::sematicCheck(Symbol sym) {
  return Symbol::EXPRESSION("char", (int)value[0]);
}

Symbol CharNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
