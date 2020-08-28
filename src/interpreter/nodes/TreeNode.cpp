#include <iostream>
#include <string>

#include "TreeNode.hpp"
#include "ArithmeticExpressionNode.hpp"
#include "AddAssignExpressionNode.hpp"
#include "AddExpressionNode.hpp"
#include "AsCompoundNode.hpp"
#include "AssignmentExpressionNode.hpp"
#include "BitwiseAndAssignExpressionNode.hpp"
#include "BitwiseAndExpressionNode.hpp"
#include "BitwiseNegationExpressionNode.hpp"
#include "BitwiseOrAssignExpressionNode.hpp"
#include "BitwiseOrExpressionNode.hpp"
#include "BitwiseXorAssignExpressionNode.hpp"
#include "BitwiseXorExpressionNode.hpp"
#include "ClassDeclarationNode.hpp"
#include "CodeBlockNode.hpp"
#include "ComparisonExpresisonNode.hpp"
#include "ConditionalStatementNode.hpp"
#include "DivideAssignExpressionNode.hpp"
#include "DivideExpressionNode.hpp"
#include "DoWhileStatementNode.hpp"
#include "ElseCompoundNode.hpp"
#include "EmitStatementNode.hpp"
#include "EmptyStatementNode.hpp"
#include "EventDeclarationNode.hpp"
#include "ForStatementNode.hpp"
#include "FunctionCallNode.hpp"
#include "FunctionDeclarationNode.hpp"
#include "FunctionReturnTypeNode.hpp"
#include "ImmutableReferenceTypeCompoundNode.hpp"
#include "ImportDeclarationNode.hpp"
#include "LValueNode.hpp"
#include "LeftShiftAssignExpressionNode.hpp"
#include "LeftShiftExpressionNode.hpp"
#include "LocalDeclarationStatementNode.hpp"
#include "LogicalAndExpressionNode.hpp"
#include "LogicalNegationExpressionNode.hpp"
#include "LogicalOrExpressionNode.hpp"
#include "ModuleDeclarationNode.hpp"
#include "ModulusAssignExpressionNode.hpp"
#include "ModulusExpressionNode.hpp"
#include "MultiplyAssignExpressionNode.hpp"
#include "MultiplyExpressionNode.hpp"
#include "MutableLocalDeclarationStatementNode.hpp"
#include "MutableParameterNode.hpp"
#include "MutableReferenceTypeCompoundNode.hpp"
#include "NumericImmediateNode.hpp"
#include "ParameterNode.hpp"
#include "ParameterListNode.hpp"
#include "ParameterTypeNode.hpp"
#include "PostOpNode.hpp"
#include "PreOpNode.hpp"
#include "ReturnStatementNode.hpp"
#include "RightShiftAssignExpressionNode.hpp"
#include "RightShiftExpressionNode.hpp"
#include "StatementListNode.hpp"
#include "StringImmediateNode.hpp"
#include "SubtractAssignExpressionNode.hpp"
#include "SubtractExpressionNode.hpp"
#include "TenaryNode.hpp"
#include "TypeCompoundNode.hpp"
#include "TypeListNode.hpp"
#include "UnaryMinusExpressionNode.hpp"
#include "VariableTypeNodeNode.hpp"
#include "WhileStatementNode.hpp"
#include "../../parser/node.h"
#include "../symboltable/Symbol.hpp"

using namespace std;

TreeNode::TreeNode(struct node * n) {
  value = n->value ? string(n->value) : "";
  line = n->line;
  col = n->col;

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

	case AddAssignExpression:
		return make_unique<AddAssignExpressionNode>(n);

	case AsCompound:
		return make_unique<AsCompoundNode>(n);

	case AssignmentExpression:
		return make_unique<AssignmentExpressionNode>(n);

	case BitwiseAndAssignExpression:
		return make_unique<BitwiseAndAssignExpressionNode>(n);

	case BitwiseAndExpression:
		return make_unique<BitwiseAndExpressionNode>(n);

	case BitwiseNegationExpression:
		return make_unique<BitwiseNegationExpressionNode>(n);

	case BitwiseOrAssignExpression:
		return make_unique<BitwiseOrAssignExpressionNode>(n);

	case BitwiseOrExpression:
		return make_unique<BitwiseOrExpressionNode>(n);

	case BitwiseXorAssignExpression:
		return make_unique<BitwiseXorAssignExpressionNode>(n);

	case BitwiseXorExpression:
		return make_unique<BitwiseXorExpressionNode>(n);

	case ClassDeclaration:
		return make_unique<ClassDeclarationNode>(n);

	case ComparisonExpresison:
		return make_unique<ComparisonExpresisonNode>(n);

	case ConditionalStatement:
		return make_unique<ConditionalStatementNode>(n);

	case DivideAssignExpression:
		return make_unique<DivideAssignExpressionNode>(n);

	case DoWhileStatement:
		return make_unique<DoWhileStatementNode>(n);

	case ElseCompound:
		return make_unique<ElseCompoundNode>(n);

	case EmitStatement:
		return make_unique<EmitStatementNode>(n);

	case EmptyStatement:
		return make_unique<EmptyStatementNode>(n);

	case EventDeclaration:
		return make_unique<EventDeclarationNode>(n);

	case ForStatement:
		return make_unique<ForStatementNode>(n);

	case FunctionCall:
		return make_unique<FunctionCallNode>(n);

	case FunctionDeclaration:
		return make_unique<FunctionDeclarationNode>(n);

	case FunctionReturnType:
		return make_unique<FunctionReturnTypeNode>(n);

	case ImmutableReferenceTypeCompound:
		return make_unique<ImmutableReferenceTypeCompoundNode>(n);

	case ImportDeclaration:
		return make_unique<ImportDeclarationNode>(n);

	case LValue:
		return make_unique<LValueNode>(n);

	case LeftShiftAssignExpression:
		return make_unique<LeftShiftAssignExpressionNode>(n);

	case LeftShiftExpression:
		return make_unique<LeftShiftExpressionNode>(n);

	case LocalDeclarationStatement:
		return make_unique<LocalDeclarationStatementNode>(n);

	case LogicalAndExpression:
		return make_unique<LogicalAndExpressionNode>(n);

	case LogicalNegationExpression:
		return make_unique<LogicalNegationExpressionNode>(n);

	case LogicalOrExpression:
		return make_unique<LogicalOrExpressionNode>(n);

	case ModuleDeclaration:
		return make_unique<ModuleDeclarationNode>(n);

	case ModulusAssignExpression:
		return make_unique<ModulusAssignExpressionNode>(n);

	case MultiplyAssignExpression:
		return make_unique<MultiplyAssignExpressionNode>(n);

	case MutableLocalDeclarationStatement:
		return make_unique<MutableLocalDeclarationStatementNode>(n);

	case MutableParameter:
		return make_unique<MutableParameterNode>(n);

	case MutableReferenceTypeCompound:
		return make_unique<MutableReferenceTypeCompoundNode>(n);

	case NumericImmediate:
		return make_unique<NumericImmediateNode>(n);

	case Parameter:
		return make_unique<ParameterNode>(n);

	case ParameterList:
		return make_unique<ParameterListNode>(n);

	case ParameterType:
		return make_unique<ParameterTypeNode>(n);

	case PostOp:
		return make_unique<PostOpNode>(n);

	case PreOp:
		return make_unique<PreOpNode>(n);

	case ReturnStatement:
		return make_unique<ReturnStatementNode>(n);

	case RightShiftAssignExpression:
		return make_unique<RightShiftAssignExpressionNode>(n);

	case RightShiftExpression:
		return make_unique<RightShiftExpressionNode>(n);

	case StatementList:
		return make_unique<StatementListNode>(n);

	case StringImmediate:
		return make_unique<StringImmediateNode>(n);

	case SubtractAssignExpression:
		return make_unique<SubtractAssignExpressionNode>(n);

	case Tenary:
		return make_unique<TenaryNode>(n);

	case TypeCompound:
		return make_unique<TypeCompoundNode>(n);

	case TypeList:
		return make_unique<TypeListNode>(n);

	case UnaryMinusExpression:
		return make_unique<UnaryMinusExpressionNode>(n);

	case VariableTypeNode:
		return make_unique<VariableTypeNodeNode>(n);

	case WhileStatement:
		return make_unique<WhileStatementNode>(n);

	default:
      cout << "ERRORROR: " << n->type << endl;
      return nullptr;
  }
}
