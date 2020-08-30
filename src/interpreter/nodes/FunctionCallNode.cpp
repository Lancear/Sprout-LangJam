#include <string>
#include <memory>

#include "FunctionCallNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol FunctionCallNode::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::TYPE("int");
}

Symbol FunctionCallNode::execute(Symbol sym) {
  Symbol args[children.size()];

  // for (int i = 0; i < args.size(); i++)

  return Symbol::EMPTY();
}
