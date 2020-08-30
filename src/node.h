
#ifndef NODE_H
#define NODE_H

enum {
    ImportDeclaration, AsCompound, FunctionDeclaration, ParameterList, Parameter, ParameterType,
    CodeBlock, StatementList, ReturnStatement, NumericImmediate, FunctionReturnType,
    LocalDeclarationStatement, MutableLocalDeclarationStatement, VariableTypeNode,
    AddExpression, SubtractExpression, MultiplyExpression, DivideExpression, ModulusExpression,
    ConditionalStatement, ElseCompound, TypeCompound, StringImmediate, ComparisonExpresison, WhileStatement,
    ForStatement, ModuleDeclaration, AssignmentExpression, FunctionCall, LValue, DoWhileStatement,
    /* currently I'm the second one */
    PostOp, PreOp,
    ClassDeclaration, Tenary, EventDeclaration, TypeList, EmitStatement,
    ImmutableReferenceTypeCompound, MutableReferenceTypeCompound, LeftShiftExpression, 
    RightShiftExpression, BitwiseAndExpression, BitwiseOrExpression, BitwiseXorExpression,
    EmptyStatement, LogicalOrExpression, LogicalAndExpression,
    AddAssignExpression, SubtractAssignExpression, MultiplyAssignExpression, DivideAssignExpression,
    ModulusAssignExpression, RightShiftAssignExpression, LeftShiftAssignExpression, BitwiseAndAssignExpression,
    BitwiseOrAssignExpression, BitwiseXorAssignExpression, LogicalNegationExpression, BitwiseNegationExpression,
    UnaryMinusExpression, CommaExpression, InlineOn, Lambda, MutableTypeCompound, CharacterConstant
};

struct node {
    struct node * child, * brother;
    char * value;
    unsigned int type;
    unsigned int line, col;
};

struct node * new_node(
    unsigned int type,
    struct node * child, struct node * brother,
    char * value,
    unsigned int line, unsigned int col
);

struct node * append_brother(struct node * parent, struct node * brother);

#endif
