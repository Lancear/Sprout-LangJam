#include <iostream>
#include <string>

#include "TreeNode.hpp"
#include "ImportNode.hpp"
#include "ImportAliasNode.hpp"
#include "ModuleNode.hpp"
#include "ClassNode.hpp"
#include "EventNode.hpp"
#include "FunctionNode.hpp"
#include "TypeNode.hpp"
#include "ParamListNode.hpp"
#include "ParamNode.hpp"
#include "CodeBlockNode.hpp"
#include "DeclarationNode.hpp"
#include "NumberNode.hpp"
#include "CharNode.hpp"
#include "StringNode.hpp"
#include "IdentifierNode.hpp"
#include "ReturnNode.hpp"
#include "IfNode.hpp"
#include "ElseNode.hpp"
#include "WhileNode.hpp"
#include "DoWhileNode.hpp"
#include "ForNode.hpp"
#include "TernaryExprNode.hpp"
#include "ArithmeticExprNode.hpp"
#include "RelationalExprNode.hpp"
#include "LogicalExprNode.hpp"
#include "BitwiseExprNode.hpp"
#include "ShiftExprNode.hpp"
#include "AssignmentNode.hpp"
#include "PreOpNode.hpp"
#include "PostOpNode.hpp"
#include "FunctionCallNode.hpp"
#include "EmitNode.hpp"
#include "EmptyNode.hpp"


#include "../symboltable/Symbol.hpp"
#include "../../parser/node.h"

using namespace std;

TreeNode::TreeNode(struct node * n) {
	line = n->line;
  col = n->col;

  value = (n->value) ? string(n->value) : "";
  type = n->type;

  n = n->child;
  while (n) {
    children.push_back(TreeNode::of(n));
    n = n->brother;
  }
}

unique_ptr<TreeNode> TreeNode::of(struct node * n) {
  switch (n->type) {
		case ImportDeclaration:
			return make_unique<ImportNode>(n);

		case AsCompound:
			return make_unique<ImportAliasNode>(n);

		case ModuleDeclaration:
			return make_unique<ModuleNode>(n);

		case ClassDeclaration:
			return make_unique<ClassNode>(n);

		case EventDeclaration:
			return make_unique<EventNode>(n);

		case FunctionDeclaration:
			return make_unique<FunctionNode>(n);

		case FunctionReturnType:
		case TypeCompound:
		case TypeList:
			n->type = TypeCompound;
			return make_unique<TypeNode>(n);

		case ImmutableReferenceTypeCompound:
		case MutableReferenceTypeCompound:
			return make_unique<TypeNode>(n->child, true);

		case ParameterList:
			return make_unique<ParamListNode>(n);

		case Parameter:
		case MutableParameter:
			return make_unique<ParamNode>(n, (n->type != Parameter));

		case ParameterType:
		case VariableTypeNode:
			return make_unique<TypeNode>(n->child, (n->child->type != TypeCompound));

		case CodeBlock:
			return make_unique<CodeBlockNode>(n);

		case LocalDeclarationStatement:
		case MutableLocalDeclarationStatement:
			return make_unique<DeclarationNode>(n, (n->type != LocalDeclarationStatement));

		case NumericImmediate:
			return make_unique<NumberNode>(n);
		
		case CharacterConstant:
			return make_unique<CharNode>(n);

		case StringImmediate:
			return make_unique<StringNode>(n);

		case LValue:
			return make_unique<IdentifierNode>(n);		

		case ReturnStatement:
			return make_unique<ReturnNode>(n);

		case ConditionalStatement:
			return make_unique<IfNode>(n);

		case ElseCompound:
			return make_unique<ElseNode>(n);

		case WhileStatement:
			return make_unique<WhileNode>(n);

		case DoWhileStatement:
			return make_unique<DoWhileNode>(n);

		case ForStatement:
			return make_unique<ForNode>(n);

		case Tenary:
			return make_unique<TernaryExprNode>(n);

		case AddExpression:
			n->value = "+";
			return make_unique<ArithmeticExprNode>(n);

		case SubtractExpression:
			n->value = "-";
			return make_unique<ArithmeticExprNode>(n);

		case MultiplyExpression:
			n->value = "*";
			return make_unique<ArithmeticExprNode>(n);

		case DivideExpression:
			n->value = "/";
			return make_unique<ArithmeticExprNode>(n);

		case ModulusExpression:
			n->value = "%";
			return make_unique<ArithmeticExprNode>(n);

		case ComparisonExpresison:
			return make_unique<RelationalExprNode>(n);

		case LogicalOrExpression:
			n->value = "||";
			return make_unique<LogicalExprNode>(n);

		case LogicalAndExpression:
			n->value = "&&";
			return make_unique<LogicalExprNode>(n);

		case BitwiseOrExpression:
			n->value = "|";
			return make_unique<BitwiseExprNode>(n);

		case BitwiseAndExpression:
			n->value = "&";
			return make_unique<BitwiseExprNode>(n);

		case BitwiseXorExpression:
			n->value = "^";
			return make_unique<BitwiseExprNode>(n);

		case LeftShiftExpression:
			n->value = "<<";
			return make_unique<ShiftExprNode>(n);

		case RightShiftExpression:
			n->value = ">>";
			return make_unique<ShiftExprNode>(n);

		case AssignmentExpression:
			n->value = "=";
			return make_unique<AssignmentNode>(n);

		case AddAssignExpression:
			n->value = "+=";
			return make_unique<AssignmentNode>(n);

		case SubtractAssignExpression:
			n->value = "-=";
			return make_unique<AssignmentNode>(n);

		case MultiplyAssignExpression:
			n->value = "*=";
			return make_unique<AssignmentNode>(n);

		case DivideAssignExpression:
			n->value = "/=";
			return make_unique<AssignmentNode>(n);

		case ModulusAssignExpression:
			n->value = "%=";
			return make_unique<AssignmentNode>(n);

		case BitwiseOrAssignExpression:
			n->value = "|=";
			return make_unique<AssignmentNode>(n);

		case BitwiseAndAssignExpression:
			n->value = "&=";
			return make_unique<AssignmentNode>(n);

		case BitwiseXorAssignExpression:
			n->value = "^=";
			return make_unique<AssignmentNode>(n);

		case LeftShiftAssignExpression:
			n->value = "<<=";
			return make_unique<AssignmentNode>(n);

		case RightShiftAssignExpression:
			n->value = ">>=";
			return make_unique<AssignmentNode>(n);

		case UnaryMinusExpression:
			n->value = "-";
			return make_unique<PreOpNode>(n);

		case LogicalNegationExpression:
			n->value = "!";
			return make_unique<PreOpNode>(n);

		case BitwiseNegationExpression:
			n->value = "~";
			return make_unique<PreOpNode>(n);

		case PreOp:
			return make_unique<PreOpNode>(n);

		case PostOp:
			return make_unique<PostOpNode>(n);

		case FunctionCall:
			return make_unique<FunctionCallNode>(n);

		case EmitStatement:
			return make_unique<EmitNode>(n);

		case EmptyStatement:
			return make_unique<EmptyNode>(n);

		default:
      cout << "ERRORROR: " << n->type << endl;
      return NULL;
  }
}

Symbol TreeNode::sematicCheck() {
  return this->sematicCheck(Symbol::EMPTY());
}

Symbol TreeNode::execute() {
  return this->execute(Symbol::EMPTY());
}

Symbol TreeNode::addSymbols() {
  for (int i = 0; i < children.size(); i++) {
    children[i]->addSymbols();
  }
	
  return Symbol::EMPTY();
}

Symbol TreeNode::sematicCheck(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->sematicCheck();
  }

  return Symbol::EMPTY();
}

Symbol TreeNode::execute(Symbol sym) {
  for (int i = 0; i < children.size(); i++) {
    children[i]->execute();
  }

  return Symbol::EMPTY();
}


