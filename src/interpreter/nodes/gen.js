const hppFile =(name)=>
`#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class ${name} : public TreeNode {
  using TreeNode::TreeNode;

  public:
    void addSymbols();
    Symbol sematicCheck(Symbol sym);
    Symbol execute(Symbol sym);
};
`;

const cppFile =(name)=> 
`#include <string>
#include <memory>

#include "${name}.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

void ${name}::addSymbols() {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;

  for (int i = 0; i < children.size(); i++) {
    children[i]->addSymbols();
  }
}

Symbol ${name}::sematicCheck(Symbol sym) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  cout << type << ":  " << value << endl;
  
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol ${name}::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}
`;

const fs = require('fs').promises;

const generate =(name)=> {
  console.log(`Generating ${name}...`);
  fs.writeFile(name + ".hpp", hppFile(name));
  fs.writeFile(name + ".cpp", cppFile(name));
}

generate("CharNode");
