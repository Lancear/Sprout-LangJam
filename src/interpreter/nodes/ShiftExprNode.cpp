#include <string>
#include <memory>

#include "ShiftExprNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ShiftExprNode::addSymbols() {
  return Symbol::TYPE("int");
}

Symbol ShiftExprNode::sematicCheck(Symbol param) {
  Symbol lhs = children[0]->sematicCheck();
  Symbol rhs = children[1]->sematicCheck();
  Symbol sym = Symbol::TYPE("int");

  if (lhs.isError() || rhs.isError()) {
    return Symbol::ERROR();
  }

  if (lhs.dataType.compare("int") != 0) {
    ErrorHandler::error(value + " lhs is not an integer");
    sym = Symbol::ERROR();
  }
  
  if (rhs.dataType.compare("int") != 0) {
    ErrorHandler::error(value + " rhs is not an integer");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol ShiftExprNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
