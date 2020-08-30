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
  int lhs = get<int>(children[0]->execute().value);
  int rhs = get<int>(children[1]->execute().value);

  int result = 0;

  if(value == ">>") result = lhs >> rhs;
  else if(value == "<<") result = lhs << rhs; 
  else {
    ErrorHandler::error(value + " operator not found");
    return Symbol::ERROR();
  }

  return Symbol::EXPRESSION("int", result);
}
