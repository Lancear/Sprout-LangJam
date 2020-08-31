#include <string>
#include <memory>

#include "TernaryExprNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol TernaryExprNode::addSymbols() {
  return children[1]->addSymbols();
}

Symbol TernaryExprNode::sematicCheck(Symbol param) {
  Symbol cond = children[0]->sematicCheck();
  Symbol lhs = children[1]->sematicCheck();
  Symbol rhs = children[2]->sematicCheck();

  if (cond.isError() || lhs.isError() || rhs.isError()) {
    return Symbol::ERROR();
  }

  Symbol sym = lhs;

  if (cond.dataType.compare("bool") != 0) {
	  ErrorHandler::error(value + " condition is not a boolean", line, col);
	  sym = Symbol::ERROR();
  }

  if (lhs.dataType.compare(rhs.dataType) != 0) {
	  ErrorHandler::error(value + " lhs is not of the same type as rhs", line, col);
	  sym = Symbol::ERROR();
  }

  return sym;
}

Symbol TernaryExprNode::execute(Symbol sym) {
  Symbol statement = children[0]->execute();
  Symbol lhs = children[1]->execute();
  Symbol rhs = children[2]->execute();

  if(get<int>(statement.value)) {
    if(lhs.dataType.compare("int") == 0) return Symbol::EXPRESSION("int", get<int>(lhs.value));
    else if(lhs.dataType.compare("string") == 0) return Symbol::EXPRESSION("string", get<string>(lhs.value));
    else if(lhs.dataType.compare("bool") == 0) return Symbol::EXPRESSION("bool", get<int>(lhs.value));
    else if(lhs.dataType.compare("char") == 0) return Symbol::EXPRESSION("char", get<int>(lhs.value));

    ErrorHandler::error("ternary lhs failed", line, col);
    return Symbol::ERROR();
  }
  else {
    if(lhs.dataType.compare("int") == 0) return Symbol::EXPRESSION("int", get<int>(rhs.value));
    else if(lhs.dataType.compare("string") == 0) return Symbol::EXPRESSION("string", get<string>(rhs.value));
    else if(lhs.dataType.compare("bool") == 0) return Symbol::EXPRESSION("bool", get<int>(rhs.value));
    else if(lhs.dataType.compare("char") == 0) return Symbol::EXPRESSION("char", get<int>(rhs.value));

    ErrorHandler::error("ternary rhs failed", line, col);
    return Symbol::ERROR();
  }

  ErrorHandler::error("ternary failed", line, col);
  return Symbol::ERROR();
}
