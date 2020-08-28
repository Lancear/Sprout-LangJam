const fs = require('fs');

const classes = "SubtractExpressionNode,MultiplyExpressionNode,AddAssignExpressionNode,AddExpressionNode,BitwiseAndAssignExpressionNode,BitwiseAndExpressionNode,BitwiseNegationExpressionNode,BitwiseOrAssignExpressionNode,BitwiseOrExpressionNode,BitwiseXorAssignExpressionNode";
let clazzes = classes.split(",");
clazzes.forEach(clazz => {
	let hpp = generateHPP(clazz);
	let cpp = generateCPP(clazz);
	fs.writeFileSync(clazz + '.hpp', hpp);
	fs.writeFileSync(clazz + '.cpp', cpp);
});

function generateCPP(name) {
	return cppFile = `
#include <iostream>

#include "${name}.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol ${name}::analyse(Symbol param) {
  shared_ptr<SymbolTable> syms = SymbolTable::getInstance();
  return Symbol::EMPTY();
}

Symbol ${name}::execute(Symbol sym) {
  return Symbol::EMPTY();
}`;
}

function generateHPP(name) {
	return cppFile = `
#pragma once

#include "TreeNode.hpp"
#include "../symboltable/Symbol.hpp"

class ${name} : public TreeNode {
  using TreeNode::TreeNode;
  public:
    Symbol analyse(Symbol sym);
    Symbol execute(Symbol sym);
};`;
}