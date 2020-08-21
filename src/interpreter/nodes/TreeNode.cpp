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

using namespace std;

TreeNode::TreeNode(struct node * n) {
  value = n->value;

  n = n->child;
  while (n) {
    children.push_back(TreeNode::of(n));
    n = n->brother;
  }
}

TreeNode * TreeNode::of(struct node * n) {
  switch (n->type) {
    case CodeBlock:
      return new CodeBlockNode(n);

    case Expression:
      return new ExpressionNode(n);

    case FunctionDeclaration:
      return new FunctionDeclarationNode(n);

    case FnNameNode:
      return new FunctionTypeNode(n);

    case Parameter:
      return new ParameterNode(n);

    case ParameterList:
      return new ParameterListNode(n);

    case ParameterType:
      return new ParameterTypeNode(n);

    case ReturnStatement:
      return new ReturnStatementNode(n);

    case StatementList:
      return new StatementListNode(n);
    
    default:
      cout << "ERRORROR: " << n->type << endl;
      return 0;
  }
}
