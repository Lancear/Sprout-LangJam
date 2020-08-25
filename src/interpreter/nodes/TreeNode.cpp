#include <iostream>

#include "TreeNode.hpp"
#include "ImportDeclarationNode.hpp"
#include "AsCompoundNode.hpp"
#include "FunctionDeclarationNode.hpp"
#include "ParameterListNode.hpp"
#include "ParameterNode.hpp"
#include "ParameterTypeNode.hpp"
#include "CodeBlockNode.hpp"
#include "StatementListNode.hpp"
#include "ReturnStatementNode.hpp"
#include "NumericImmediateNode.hpp"
#include "FunctionTypeNode.hpp"
#include "LocalDeclarationStatementNode.hpp"
#include "MutableLocalDeclarationStatementNode.hpp"
#include "VariableTypeNodeNode.hpp"
#include "ConditionalStatementNode.hpp"
#include "ElseCompoundNode.hpp"
#include "TypeCompoundNode.hpp"
#include "StringImmediateNode.hpp"
#include "ComparisonExpresisonNode.hpp"
#include "WhileStatementNode.hpp"
#include "ForStatementNode.hpp"
#include "ModuleDeclarationNode.hpp"
#include "AssignmentExpressionNode.hpp"
#include "FunctionCallNode.hpp"
#include "LValueNode.hpp"
#include "DoWhileStatementNode.hpp"
#include "PostOpNode.hpp"
#include "PreOpNode.hpp"
#include "ClassDeclarationNode.hpp"
#include "ArithmeticExpressionNode.hpp"
#include "TenaryNode.hpp"
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
  return this->analyse(Symbol::EMPTY());
}

Symbol TreeNode::execute() {
  return this->execute(Symbol::EMPTY());
}

unique_ptr<TreeNode> TreeNode::of(struct node * n) {
  switch (n->type) {
    case CodeBlock:
      return make_unique<CodeBlockNode>(n);

    case AddExpression:
    case SubtractExpression:
    case MultiplyExpression:
    case DivideExpression:
    case ModulusExpression:
      return make_unique<ArithmeticExpressionNode>(n);

    case FunctionDeclaration:
      return make_unique<FunctionDeclarationNode>(n);

    case FunctionReturnType:
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

	case ImportDeclaration:
		return make_unique<ImportDeclarationNode>(n);

	case AsCompound:
		return make_unique<AsCompoundNode>(n);

	case NumericImmediate:
		return make_unique<NumericImmediateNode>(n);

	case LocalDeclarationStatement:
		return make_unique<LocalDeclarationStatementNode>(n);

	case MutableLocalDeclarationStatement:
		return make_unique<MutableLocalDeclarationStatementNode>(n);

	case VariableTypeNode:
		return make_unique<VariableTypeNodeNode>(n);

	case ConditionalStatement:
		return make_unique<ConditionalStatementNode>(n);

	case ElseCompound:
		return make_unique<ElseCompoundNode>(n);

	case TypeCompound:
		return make_unique<TypeCompoundNode>(n);

	case StringImmediate:
		return make_unique<StringImmediateNode>(n);

	case ComparisonExpresison:
		return make_unique<ComparisonExpresisonNode>(n);

	case WhileStatement:
		return make_unique<WhileStatementNode>(n);

	case ForStatement:
		return make_unique<ForStatementNode>(n);

	case ModuleDeclaration:
		return make_unique<ModuleDeclarationNode>(n);

	case AssignmentExpression:
		return make_unique<AssignmentExpressionNode>(n);

	case FunctionCall:
		return make_unique<FunctionCallNode>(n);

	case LValue:
		return make_unique<LValueNode>(n);

	case DoWhileStatement:
		return make_unique<DoWhileStatementNode>(n);

	case PostOp:
		return make_unique<PostOpNode>(n);

	case PreOp:
		return make_unique<PreOpNode>(n);

	case ClassDeclaration:
		return make_unique<ClassDeclarationNode>(n);

	case Tenary:
		return make_unique<TenaryNode>(n);

	default:
      cout << "ERRORROR: " << n->type << endl;
      return nullptr;
  }
}
