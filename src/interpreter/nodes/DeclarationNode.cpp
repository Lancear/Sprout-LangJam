#include <string>
#include <memory>

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
	Symbol s;
  string type = children[0]->addSymbols().dataType;

	if(isMut){
		s = Symbol::MUTABLE(value,type,"?");
	}else{
		s = Symbol::IMMUTABLE(value,type,"?");
	}

	SymbolTable::getInstance()->add(s);
  return Symbol::EMPTY();
}

Symbol DeclarationNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout  << type << ":  " << syms->get(value).dataType << "  " << value << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol DeclarationNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
