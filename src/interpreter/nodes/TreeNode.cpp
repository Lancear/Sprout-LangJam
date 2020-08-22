#include <iostream>

#include "TreeNode.hpp"
#include "CodeBlockNode.hpp"
#include "ExpressionNode.hpp"
#include "FunctionDeclarationNode.hpp"
#include "FunctionTypeNode.hpp"
#include "ParameterNode.hpp"
#include "ParameterListNode.hpp"
#include "ParameterTypeNode.hpp"
#include "ReturnStatementNode.hpp"
#include "StatementListNode.hpp"
#include "../../parser/node.h"
#include "../symboltable/Symbol.hpp"

using namespace std;

TreeNode::TreeNode(struct node * n) {
  value = n->value;

  n = n->child;
  while (n) {
    children.push_back(TreeNode::of(n));
    n = n->brother;
  }
}

Symbol TreeNode::analyse() {
  return this->analyse(Symbol());
}

Symbol TreeNode::execute() {
  return this->execute(Symbol());
}

unique_ptr<TreeNode> TreeNode::of(struct node * n) {
  switch (n->type) {
    case CodeBlock:
      return make_unique<CodeBlockNode>(n);

    case Expression:
      return make_unique<ExpressionNode>(n);

    case FunctionDeclaration:
      return make_unique<FunctionDeclarationNode>(n);

    case FnNameNode:
      return make_unique<FunctionTypeNode>(n);

    case Parameter:
      return make_unique<ParameterNode>(n);

    case ParameterList:
      return make_unique<ParameterListNode>(n);

    case ParameterType:
      return make_unique<ParameterTypeNode>(n);

    case ReturnStatement:
      return make_unique<ReturnStatementNode>(n);

    case StatementList:
      return make_unique<StatementListNode>(n);
    
    default:
      cout << "ERRORROR: " << n->type << endl;
      return nullptr;
  }
}
