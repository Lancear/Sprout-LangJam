%define api.pure full
%locations
%param { yyscan_t scanner }

%code top {
    #include <stdio.h>
    #include "node.h"
    #include "../error.h"
}

%code requires {
    typedef void * yyscan_t;
}

%union {
    char * string;
    struct node * ast;
}

%code {
    int yylex(YYSTYPE * yylvalp, YYLTYPE * yyllocp, yyscan_t scanner);
    void yyerror(YYLTYPE * yyllocp, yyscan_t unused, const char * msg);
    
    void dispatch(struct node *);
}

%token<string> NUMERIC_IMMEDIATE
%token<string> IDENTIFIER
%token<string> STR_CONSTANT
%token<string> CHAR_CONSTANT

%token KEYWORD_NEW
%token KEYWORD_LET
%token KEYWORD_DELETE
%token KEYWORD_WHILE
%token KEYWORD_IF
%token KEYWORD_FN
%token KEYWORD_MUT
%token KEYWORD_CLASS
%token KEYWORD_MODULE
%token KEYWORD_EMIT
%token KEYWORD_RETURN
%token KEYWORD_EVENT
%token KEYWORD_DO
%token KEYWORD_ELSE
%token KEYWORD_MATCH
%token KEYWORD_FOR
%token KEYWORD_IMPORT
%token KEYWORD_AS

%token OP_LEFT_PAREN
%token OP_RIGHT_PAREN
%token OP_LEFT_SQPAREN
%token OP_RIGHT_SQPAREN
%token OP_DOT
%token OP_PLUS
%token OP_MINUS
%token OP_SHR
%token OP_SHL
%token OP_MOD
%token OP_SLASH
%token OP_STAR
%token OP_LEFT_BRACKET
%token OP_RIGHT_BRACKET
%token OP_TENARY
%token OP_COLON
%token OP_ARROW
%token OP_INCREMENT
%token OP_DECREMENT
%token OP_BIN_AND
%token OP_BIN_OR
%token OP_LOG_AND
%token OP_LOG_OR
%token OP_XOR
%token OP_ADD_EQ
%token OP_SUB_EQ
%token OP_SHL_EQ
%token OP_SHR_EQ
%token OP_MUL_EQ
%token OP_DIV_EQ
%token OP_MOD_EQ
%token OP_AND_EQ
%token OP_OR_EQ
%token OP_XOR_EQ
%token OP_EQ
%token OP_CMP_EQ
%token OP_CMP_GE
%token OP_CMP_LE
%token OP_CMP_GT
%token OP_CMP_LT
%token OP_CMP_NE
%token OP_TIDLE
%token OP_COMMA
%token OP_BANG
%token OP_AT
%token SEMICOLON

%type<ast> ImportStatement FunctionDeclaration ParameterList ParameterListLoop FnCodeBlock Statement StatementList ReturnStatement Expression

%start TopLevelScope
%%

TopLevelScope
: ImportStatement TopLevelScope { dispatch($1); }
| FunctionDeclaration TopLevelScope { dispatch($1); }
| %empty { dispatch(NULL); }
;

ImportStatement
: KEYWORD_IMPORT IDENTIFIER SEMICOLON {
    $$ = new_node(ImportNode, NULL, NULL, $2);
}
| KEYWORD_IMPORT IDENTIFIER KEYWORD_AS IDENTIFIER SEMICOLON {
    $$ = new_node(ImportNode,
        new_node(AsNode, NULL, NULL, $4),
    NULL, $2);
}
;

FunctionDeclaration
: KEYWORD_FN IDENTIFIER ParameterList FnCodeBlock {
    $$ = new_node(FunctionDeclaration, append_brother($3, $4), NULL, $2);
}
| KEYWORD_FN IDENTIFIER ParameterList OP_COLON IDENTIFIER FnCodeBlock {
    $$ = new_node(FunctionDeclaration, new_node(FnNameNode, NULL, append_brother($3, $6), $5), NULL, $2);
}
;

ParameterList
: OP_LEFT_PAREN ParameterListLoop OP_RIGHT_PAREN {
    $$ = new_node(ParameterList, $2, NULL, NULL);
}
| OP_LEFT_PAREN OP_RIGHT_PAREN {
    $$ = new_node(ParameterList, NULL, NULL, NULL);
}
;

ParameterListLoop
: IDENTIFIER OP_COLON IDENTIFIER OP_COMMA ParameterListLoop {
    /* dejavu, I've just been in this parser state before */
    $$ = new_node(Parameter, new_node(ParameterType, NULL, NULL, $1), $5, $3);
}
| IDENTIFIER OP_COLON IDENTIFIER {
    $$ = new_node(Parameter, new_node(ParameterType, NULL, NULL, $1), NULL, $3);
}
;

FnCodeBlock
: OP_LEFT_BRACKET StatementList OP_RIGHT_BRACKET {
    $$ = new_node(CodeBlock, $2, NULL, NULL);
}
| OP_LEFT_BRACKET OP_RIGHT_BRACKET {
    $$ = new_node(CodeBlock, NULL, NULL, NULL);
}
;

StatementList
: Statement {
    $$ = new_node(StatementList, $1, NULL, NULL);
}
| StatementList Statement {
    $$ = new_node(StatementList, $2, $1, NULL);
}
;

Statement
: ReturnStatement {
    $$ = $1;
}
| SEMICOLON {
    $$ = new_node(EmptyStatement, NULL, NULL, NULL);
}
;

ReturnStatement
: KEYWORD_RETURN Expression SEMICOLON {
    $$ = new_node(ReturnStatement, $2, NULL, NULL);
}
| KEYWORD_RETURN SEMICOLON {
    $$ = new_node(ReturnStatement, NULL, NULL, NULL);
}
;

Expression
: NUMERIC_IMMEDIATE {
    $$ = new_node(Expression, NULL, NULL, $1);
}
;

%%

void yyerror(YYLTYPE * yyllocp, yyscan_t unused, const char * msg) {
    parser_error(msg, yyllocp->first_line, yyllocp->first_column);
}
