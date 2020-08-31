#include <string>
#include <memory>
#include <variant>

#include "DeclarationNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"

using namespace std;

DeclarationNode::DeclarationNode(struct node * n, bool mut) : DeclarationNode(n) {
  isMut = mut;
}

Symbol DeclarationNode::addSymbols() {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();

  if (syms->containsInCurrentScope(value)) {
	  ErrorHandler::error("a symbol with this name already exists, name: " + value, line, col);
	  return Symbol::ERROR();
  }

	Symbol s;
  string type = children[0]->addSymbols().dataType;

	if (isMut) {
    if (type.compare("string") == 0) {
      s = Symbol::MUTABLE(value,type,"");
    }
    else if (syms->get(type).isClass()) {
      s = Symbol::MUTABLE(value,type, (void*)NULL);
    }
    else {
      s = Symbol::MUTABLE(value,type,0);
    }
	}
  else {
		if (type.compare("string") == 0) {
      s = Symbol::IMMUTABLE(value,type,"");
    }
    else if (syms->get(type).isClass()) {
      s = Symbol::IMMUTABLE(value,type, (void*)NULL);
    }
    else {
      s = Symbol::IMMUTABLE(value,type,0);
    }
	}

	syms->add(s);
  return s;
}

Symbol DeclarationNode::sematicCheck(Symbol sym) {
  Symbol typeSym, valSym;

  if (children[0]->type == VariableTypeNode || children[0]->type == TypeCompound) {
    typeSym = children[0]->sematicCheck();
  }

  if ((children[0]->type != VariableTypeNode && children[0]->type != TypeCompound) || children.size() == 2) {
    valSym = children[children.size() - 1]->sematicCheck();
  }

  return (typeSym.isError() || valSym.isError()) ? Symbol::ERROR() : SymbolTable::getInstance()->get(value);
}

Symbol DeclarationNode::execute(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  Symbol sym = syms->get(value);

  if ((children[0]->type != VariableTypeNode && children[0]->type != TypeCompound) || children.size() == 2) {
    sym.value = children[children.size() - 1]->execute().value;
    syms->add(sym);
  }

  return Symbol::EMPTY();
}
