#include <string>
#include <memory>

#include "BitwiseExprNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol BitwiseExprNode::addSymbols() {
  return Symbol::TYPE("int");
}

Symbol BitwiseExprNode::sematicCheck(Symbol param) {
  string lhs = children[0]->sematicCheck().dataType;
  string rhs = children[1]->sematicCheck().dataType;
  Symbol sym = Symbol::TYPE("int");

  if (lhs.compare("int") != 0) {
    ErrorHandler::error("lhs is not an integer");
    sym = Symbol::ERROR();
  }
  
  if (rhs.compare("int") != 0) {
    ErrorHandler::error("rhs is not an integer");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol BitwiseExprNode::execute(Symbol sym) {
  char op = value[0];
  int lhs = get<int>(children[0]->execute().value);
  int rhs = get<int>(children[1]->execute().value);

  int result = 0;

  switch(op) {
    case '|':
      result = lhs | rhs;
      break;
    case '&':
      result = lhs & rhs;
      break;
    case '^':
      result = lhs ^ rhs;
      break;
    default:
      break;
  }

  return Symbol::EXPRESSION("int", result);
}