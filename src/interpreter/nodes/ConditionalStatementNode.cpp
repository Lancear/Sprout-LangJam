#include <iostream>

#include "ConditionalStatementNode.hpp"
#include "../symboltable/Symbol.hpp"
#include "../symboltable/SymbolTable.hpp"

using namespace std;
Symbol ConditionalStatementNode::analyse(Symbol symParam) {
  cout << "If > ";

  Symbol ifValue = children[0]->analyse();
  if(ifValue.type != SymbolType::EXPRESSION || ifValue.valueType != "boolean"){
	  cerr << "Function `" << value << "` expects an Expression of type boolean, instead got " << ifValue.valueType;
	  return Symbol::ERROR();
  }

  SymbolTable::getInstance()->openNewScope();
  
  //Processing the remaining children in a new scope
  for (int i = 1; i < children.size(); i++)
  {
	  children[i]->analyse();
  }

  SymbolTable::getInstance()->closeScope();

  return Symbol::EMPTY();
}

Symbol ConditionalStatementNode::execute(Symbol sym) {
  cout << "Executing: " << value << endl;
  return Symbol::EMPTY();
}
