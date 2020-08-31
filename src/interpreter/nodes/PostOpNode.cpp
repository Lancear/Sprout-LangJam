#include <string>
#include <memory>

#include "PostOpNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol PostOpNode::addSymbols() {
  return children[0]->addSymbols();
}

Symbol PostOpNode::sematicCheck(Symbol param) {
  Symbol expr = children[0]->sematicCheck();
  Symbol sym = Symbol::TYPE("int");

  if (expr.isError()) {
    return Symbol::ERROR();
  }

  if (expr.dataType.compare("int") != 0) {
    ErrorHandler::error(value + " expr is not an integer");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol PostOpNode::execute(Symbol sym) {
  Symbol lhs = children[0]->execute();
  int result = 0;

  if(value == "++") {
    result = get<int>(lhs.value)++;
    SymbolTable::getInstance()->update(lhs);
  } 
  else if(value == "--") {
    result = get<int>(lhs.value)--;
    SymbolTable::getInstance()->update(lhs);
  } 
  else {
    ErrorHandler::error(value + " operator not found");
    return Symbol::ERROR();
  }

  return Symbol::EXPRESSION("int", result);
}
