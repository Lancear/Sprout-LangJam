#include <string>
#include <memory>
#include <variant>

#include "AssignmentNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol AssignmentNode::addSymbols() {
  return children[0]->addSymbols();
}

Symbol AssignmentNode::sematicCheck(Symbol param) {
  Symbol rhs = children[1]->sematicCheck();
  Symbol lhs = children[0]->sematicCheck();
  Symbol sym = lhs;

  if (lhs.isError() || rhs.isError()) {
    return Symbol::ERROR();
  }

  if (lhs.dataType.compare(rhs.dataType) != 0) {
    ErrorHandler::error(value + " lhs is not of the same type as rhs");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol AssignmentNode::execute(Symbol sym) {
  Symbol rhs = children[1]->execute();
  Symbol lhs = children[0]->execute();
  lhs.value = rhs.value;
  SymbolTable::getInstance()->add(lhs);

  if (lhs.dataType.compare("int") == 0)
    cout << lhs.name << ": " << get<int>(SymbolTable::getInstance()->get(lhs.name).value) << endl;
  return rhs;
}
