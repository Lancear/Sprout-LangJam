#include <string>
#include <memory>

#include "ParamNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"

using namespace std;

ParamNode::ParamNode(struct node * n, bool mut) : ParamNode(n) {
  isMut = mut;
}

Symbol ParamNode::addSymbols() {
	Symbol s;
	if (isMut)
	{
		s = Symbol::MUTABLE(value, "?", "?");
	}
	else
	{
		s = Symbol::IMMUTABLE(value, "?", "?");
	}
	SymbolTable::getInstance()->add(s);
  return Symbol::EMPTY();
}

Symbol ParamNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol ParamNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
