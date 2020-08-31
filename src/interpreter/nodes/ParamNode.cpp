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
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();

  if (syms->containsInCurrentScope(value)) {
    ErrorHandler::error("a symbol with this name already exists, name: " + value);
    return Symbol::ERROR();
  }

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

	syms->add(s);
  return s;
}

Symbol ParamNode::sematicCheck(Symbol sym) {
  if (children[0]->type != VariableTypeNode || children.size() == 2) {
    return children[children.size() - 1]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol ParamNode::execute(Symbol arg) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  Symbol param = syms->get(value);
  param.value = arg.value;
  syms->add(param);

  return Symbol::EMPTY();
}
