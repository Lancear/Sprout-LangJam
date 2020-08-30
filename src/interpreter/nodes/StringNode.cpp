#include <string>
#include <memory>

#include "StringNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol StringNode::addSymbols() {
  return Symbol::EXPRESSION("string", value);
}

Symbol StringNode::sematicCheck(Symbol sym) {
  return Symbol::EXPRESSION("string", value);
}

Symbol StringNode::execute(Symbol sym) {
  return Symbol::EXPRESSION("string", value);
}
