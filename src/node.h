
#ifndef NODE_H
#define NODE_H

enum {
    ImportNode, AsNode, FunctionDeclaration, ParameterList, Parameter, ParameterType,
    CodeBlock, StatementList, ReturnStatement, Expression, FunctionReturnType, EmptyStatement
};

struct node {
    struct node * child, * brother;
    char * value;
    unsigned int type;
};

struct node * new_node(unsigned int type, struct node * child, struct node * brother, char * value);
struct node * append_brother(struct node * parent, struct node * brother);

#endif
