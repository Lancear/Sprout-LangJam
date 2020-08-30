#include <string>
#include <memory>

#include "ParamListNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ParamListNode::execute(Symbol args[]) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute(args[i]);
  }

  return Symbol::EMPTY();
}
