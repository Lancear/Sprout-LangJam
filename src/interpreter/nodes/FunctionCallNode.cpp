#include <string>
#include <memory>
#include <variant>

#include "FunctionCallNode.hpp"
#include "FunctionNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol FunctionCallNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::TYPE(syms->get(value).dataType);
}

Symbol FunctionCallNode::execute(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  Symbol args[children.size()];

  for (int i = 0; i < children.size(); i++) {
    args[i] = children[i]->execute();
  }

  FunctionNode* fn = (FunctionNode*)get<void*>(syms->get(value).value);
  return fn->execute(args);
}
