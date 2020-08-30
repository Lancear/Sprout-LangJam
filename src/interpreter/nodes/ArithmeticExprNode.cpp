#include <string>
#include <memory>

#include "ArithmeticExprNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ArithmeticExprNode::addSymbols() {
  if (value.compare("+") == 0) {
    string lhs = children[0]->addSymbols().dataType;
    string rhs = children[1]->addSymbols().dataType;

    return Symbol::TYPE((lhs.compare("string") == 0 || rhs.compare("string") == 0) ? "string" : "int");
  }

  return Symbol::TYPE("int");
}

Symbol ArithmeticExprNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol ArithmeticExprNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
