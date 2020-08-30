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
  string type = children[0]->addSymbols().dataType;

	if (isMut) {
    if (type.compare("string") == 0) {
      s = Symbol::MUTABLE(value,type,"");
    }
    else {
      s = Symbol::MUTABLE(value,type,0);
    }
	}
  else {
		if (type.compare("string") == 0) {
      s = Symbol::MUTABLE(value,type,"");
    }
    else {
      s = Symbol::MUTABLE(value,type,0);
    }
	}

	SymbolTable::getInstance()->add(s);
  return Symbol::EMPTY();
}

Symbol ParamNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout  << type << ":  " << syms->get(value).dataType << "  " << value << endl;
  
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
