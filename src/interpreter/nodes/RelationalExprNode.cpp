#include <string>
#include <memory>

#include "RelationalExprNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol RelationalExprNode::addSymbols() {
  return Symbol::TYPE("bool");
}

Symbol RelationalExprNode::sematicCheck(Symbol param) {
  Symbol lhs = children[0]->sematicCheck();
  Symbol rhs = children[1]->sematicCheck();
  Symbol sym = Symbol::TYPE("bool");

  if (lhs.isError() || rhs.isError()) {
    return Symbol::ERROR();
  }

  if (value.compare("==") == 0 || value.compare("!=") == 0){
    if (lhs.dataType.compare(rhs.dataType) != 0) {
      ErrorHandler::error(value + " lhs is not of the same type as rhs");
      sym = Symbol::ERROR();
    }
  }
  else {
    if (lhs.dataType.compare("int") != 0) {
      ErrorHandler::error(value + " lhs is not an integer");
      sym = Symbol::ERROR();
    }
    
    if (rhs.dataType.compare("int") != 0) {
      ErrorHandler::error(value + " rhs is not an integer");
      sym = Symbol::ERROR();
    }
  }
  
  return sym;
}

Symbol RelationalExprNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
