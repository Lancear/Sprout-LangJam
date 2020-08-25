%define api.pure full
%locations
%param { yyscan_t scanner }

%code top {
    #define _GNU_SOURCE
    #include <stdio.h>
    #include <string.h>
    #include "node.h"
    #include "error.h"
    
    #define YYERROR_VERBOSE 1
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

%token<string> NUMERIC_IMMEDIATE IDENTIFIER
%token<string> STR_CONSTANT CHAR_CONSTANT

%token KEYWORD_LET KEYWORD_WHILE KEYWORD_IF KEYWORD_FN KEYWORD_MUT
%token KEYWORD_CLASS KEYWORD_MODULE KEYWORD_EMIT KEYWORD_RETURN KEYWORD_EVENT
%token KEYWORD_DO KEYWORD_ELSE KEYWORD_MATCH KEYWORD_FOR KEYWORD_IMPORT KEYWORD_AS

%token OP_LEFT_PAREN OP_RIGHT_PAREN OP_LEFT_SQPAREN OP_RIGHT_SQPAREN OP_LEFT_BRACKET OP_RIGHT_BRACKET
%token OP_PLUS OP_MINUS OP_SHR OP_SHL OP_MOD OP_SLASH OP_STAR OP_BIN_AND OP_BIN_OR OP_LOG_AND OP_LOG_OR OP_XOR
%token OP_TENARY OP_COLON OP_ARROW OP_INCREMENT OP_DECREMENT OP_DOT OP_EQ OP_TILDE OP_BANG
%token OP_ADD_EQ OP_SUB_EQ OP_SHL_EQ OP_SHR_EQ OP_MUL_EQ OP_DIV_EQ OP_MOD_EQ OP_AND_EQ OP_OR_EQ OP_XOR_EQ
%token OP_CMP_EQ OP_CMP_GE OP_CMP_LE OP_CMP_GT OP_CMP_LT OP_CMP_NE
%token OP_COMMA OP_AT
%token SEMICOLON

%type<ast> ImportStatement FunctionDeclaration ParameterList ParameterListLoop FnCodeBlock
%type<ast> Statement StatementList ReturnStatement Expression DeclarationStatement CodeBlock
%type<ast> ConditionalStatement TypeNode WhileStatement ForStatement ModuleDeclaration TopLevelScope
%type<ast> CallParameterList LValue DoWhileStatement ClassDeclaration

%type<string> IndirectedIdentifier

%left OP_TENARY OP_COLON
%left OP_LOG_OR
%left OP_LOG_AND
%left OP_BIN_OR
%left OP_XOR
%left OP_BIN_AND
%left OP_CMP_EQ OP_CMP_NE
%left OP_CMP_GE OP_CMP_GT OP_CMP_LE OP_CMP_LT
%left OP_SHL OP_SHR
%left OP_PLUS OP_MINUS
%left OP_STAR OP_SLASH OP_MOD
%left OP_BANG OP_TILDE
%left OP_DOT OP_ARROW
%left OP_LEFT_SQPAREN OP_RIGHT_SQPAREN
%left OP_LEFT_PAREN OP_RIGHT_PAREN
%left OP_INCREMENT OP_DECREMENT

/* Shut the fuck up the dangling else shift-reduce conflict. */
%nonassoc KEYWORD_ELSE
%nonassoc OP_EQ

%start Start
%%

/* ********************************************************* */
/* GENERAL RULES */

Start
: TopLevelScope { dispatch($1); }
;

IndirectedIdentifier
: IDENTIFIER {
    $$ = strdup($1);
}
| IDENTIFIER OP_DOT IndirectedIdentifier {
    char * p;
    
    (void) asprintf(&p, "%s.%s", $1, $3);
    
    free($3);
    
    $$ = p;
}
;

TypeNode
: OP_COLON IndirectedIdentifier[name] {
    $$ = new_node(TypeCompound, NULL, NULL, $name);
}
;

CodeBlock
: FnCodeBlock { $$ = $1; }
| Statement { $$ = $1; }
;

/* ********************************************************* */
/* TOPLEVEL SCOPE */

TopLevelScope
: ImportStatement[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| FunctionDeclaration[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| ModuleDeclaration[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| ClassDeclaration[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| %empty { $$ = NULL; }
;

ModuleDeclaration
: KEYWORD_MODULE IndirectedIdentifier[id] OP_LEFT_BRACKET TopLevelScope[scope] OP_RIGHT_BRACKET {
    $$ = new_node(ModuleDeclaration, $scope, NULL, $id);
}
;

ClassDeclaration
: KEYWORD_CLASS IndirectedIdentifier[id] OP_LEFT_BRACKET TopLevelScope[scope] OP_RIGHT_BRACKET {
    $$ = new_node(ClassDeclaration, $scope, NULL, $id);
}
;

ImportStatement
: KEYWORD_IMPORT IndirectedIdentifier[pkg] SEMICOLON {
    $$ = new_node(ImportDeclaration, NULL, NULL, $pkg);
}
| KEYWORD_IMPORT IndirectedIdentifier[pkg] KEYWORD_AS IndirectedIdentifier[id] SEMICOLON {
    $$ = new_node(ImportDeclaration,
        new_node(AsCompound, NULL, NULL, $id),
    NULL, $pkg);
}
;

FunctionDeclaration
: KEYWORD_FN IndirectedIdentifier[name] ParameterList[param] FnCodeBlock[code] {
    $$ = new_node(FunctionDeclaration,
        append_brother(
            $param,
            $code
        ),
    NULL, $name);
}
| KEYWORD_FN IndirectedIdentifier[name] ParameterList[params] TypeNode[return_type] FnCodeBlock[code] {
    $$ = new_node(FunctionDeclaration,
        new_node(FunctionReturnType, NULL,
            append_brother(
                append_brother(
                    $params,
                    $code
                ), $return_type
            ), NULL
        ),
    NULL, $name);
}
;

ParameterList
: OP_LEFT_PAREN ParameterListLoop[loop] OP_RIGHT_PAREN {
    $$ = new_node(ParameterList, $loop, NULL, NULL);
}
| OP_LEFT_PAREN OP_RIGHT_PAREN {
    $$ = new_node(ParameterList, NULL, NULL, NULL);
}
;

ParameterListLoop
: IndirectedIdentifier[param_name] TypeNode[type] OP_COMMA ParameterListLoop[next] {
    $$ = new_node(Parameter,
        new_node(ParameterType, $type, NULL, NULL)
    , $next, $param_name);
}
| IndirectedIdentifier[param_name] TypeNode[type] {
    $$ = new_node(Parameter,
        new_node(ParameterType, $type, NULL, NULL)
    , NULL, $param_name);
}
;

FnCodeBlock
: OP_LEFT_BRACKET StatementList[stmt_list] OP_RIGHT_BRACKET {
    $$ = new_node(CodeBlock, $stmt_list, NULL, NULL);
}
| OP_LEFT_BRACKET OP_RIGHT_BRACKET {
    $$ = new_node(CodeBlock, NULL, NULL, NULL);
}
;

/* ********************************************************* */
/* STATEMENT */

StatementList
: Statement[stmt] {
    $$ = $stmt;
}
| StatementList[next] Statement[stmt] {
    $$ = append_brother($next, $stmt);
}
;

Statement
: ReturnStatement      { $$ = $1; }
| DeclarationStatement { $$ = $1; }
| ConditionalStatement { $$ = $1; }
| WhileStatement       { $$ = $1; }
| DoWhileStatement     { $$ = $1; }
| ForStatement         { $$ = $1; }
| Expression SEMICOLON { $$ = $1; }
| SEMICOLON            { $$ = NULL; }
;

WhileStatement
: KEYWORD_WHILE OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(WhileStatement,
        append_brother(
            $expr,
            $code
        ),
    NULL, NULL);
}
;

DoWhileStatement
: KEYWORD_DO CodeBlock[code] KEYWORD_WHILE OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN SEMICOLON {
    $$ = new_node(DoWhileStatement,
        append_brother(
            $expr,
            $code
        ),
    NULL, NULL);
}
;

ForStatement
: KEYWORD_FOR OP_LEFT_PAREN SEMICOLON SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        $code,
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN DeclarationStatement[decl] SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother($decl, $code),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN DeclarationStatement[decl] Expression[e1] SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother(append_brother($decl, $code), $e1),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN DeclarationStatement[decl] Expression[e1] SEMICOLON Expression[e2] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother(append_brother(append_brother($decl, $code), $e1), $e2),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN SEMICOLON Expression[e1] SEMICOLON Expression[e2] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother(append_brother($code, $e1), $e2),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN SEMICOLON SEMICOLON Expression[e2] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother($code, $e2),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN SEMICOLON Expression[e1] SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother($code, $e1),
    NULL, NULL);
}
;

ConditionalStatement
: KEYWORD_IF OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ConditionalStatement,
        append_brother(
            $expr,
            $code
        ),
    NULL, NULL);
}
| KEYWORD_IF OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN CodeBlock[code1] KEYWORD_ELSE CodeBlock[code2] {
    $$ = new_node(ConditionalStatement,
        new_node(ElseCompound,
            append_brother(
                $code1,
                $code2
            ),
        $expr, NULL),
    NULL, NULL);
}
;

DeclarationStatement
: KEYWORD_LET IndirectedIdentifier[name] OP_EQ Expression[value] SEMICOLON {
    $$ = new_node(LocalDeclarationStatement, $value, NULL, $name);
}
| KEYWORD_LET IndirectedIdentifier[name] TypeNode[type] OP_EQ Expression[value] SEMICOLON {
    $$ = new_node(LocalDeclarationStatement,
        new_node(VariableTypeNode, $type, $value, NULL)
    , NULL, $name);
}
| KEYWORD_MUT IndirectedIdentifier[name] OP_EQ Expression[value] SEMICOLON {
    $$ = new_node(MutableLocalDeclarationStatement, $value, NULL, $name);
}
| KEYWORD_MUT IndirectedIdentifier[name] TypeNode[type] OP_EQ Expression[value] SEMICOLON {
    $$ = new_node(MutableLocalDeclarationStatement,
        new_node(VariableTypeNode, $type, $value, NULL),
    NULL, $name);
}
| KEYWORD_MUT IndirectedIdentifier[name] TypeNode[type] SEMICOLON {
    $$ = new_node(MutableLocalDeclarationStatement,
        new_node(VariableTypeNode, $type, NULL, NULL)
    , NULL, $name);
}
;

ReturnStatement
: KEYWORD_RETURN Expression[value] SEMICOLON {
    $$ = new_node(ReturnStatement, $value, NULL, NULL);
}
| KEYWORD_RETURN SEMICOLON {
    $$ = new_node(ReturnStatement, NULL, NULL, NULL);
}
;

/* ********************************************************* */
/* EXPRESSION */

Expression
: NUMERIC_IMMEDIATE[imm] {
    $$ = new_node(NumericImmediate, NULL, NULL, $imm);
}
| LValue[ref] {
    $$ = $ref;
}
| Expression[expr1] OP_TENARY Expression[expr2] OP_COLON Expression[expr3] {
    $$ = new_node(Tenary, append_brother(append_brother($expr1, $expr2), $expr3), NULL, NULL);
}
| STR_CONSTANT[str] {
    $$ = new_node(StringImmediate, NULL, NULL, $str);
}
| Expression[expr1] OP_PLUS Expression[expr2] {
    $$ = new_node(AddExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_MINUS Expression[expr2] {
    $$ = new_node(SubtractExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_STAR Expression[expr2] {
    $$ = new_node(MultiplyExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_SLASH Expression[expr2] {
    $$ = new_node(DivideExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_MOD Expression[expr2] {
    $$ = new_node(ModulusExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_CMP_EQ Expression[expr2] {
    $$ = new_node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, "==");
}
| Expression[expr1] OP_CMP_GE Expression[expr2] {
    $$ = new_node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, ">=");
}
| Expression[expr1] OP_CMP_GT Expression[expr2] {
    $$ = new_node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, ">");
}
| Expression[expr1] OP_CMP_LT Expression[expr2] {
    $$ = new_node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, "<");
}
| Expression[expr1] OP_CMP_LE Expression[expr2] {
    $$ = new_node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, "<=");
}
| Expression[expr1] OP_CMP_NE Expression[expr2] {
    $$ = new_node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, "!=");
}
| LValue[expr1] OP_INCREMENT {
    $$ = new_node(PostOp,
        $expr1,
    NULL, "++");
}
| OP_INCREMENT LValue[expr1] {
    $$ = new_node(PreOp,
        $expr1,
    NULL, "++");
}
| LValue[expr1] OP_DECREMENT {
    $$ = new_node(PostOp,
        $expr1,
    NULL, "--");
}
| OP_DECREMENT LValue[expr1] {
    $$ = new_node(PreOp,
        $expr1,
    NULL, "--");
}
| LValue[expr1] OP_EQ Expression[expr2] {
    $$ = new_node(AssignmentExpression,
        append_brother($expr1, $expr2),
    NULL, NULL);
}
| IndirectedIdentifier[expr1] OP_LEFT_PAREN OP_RIGHT_PAREN {
    $$ = new_node(FunctionCall, NULL, NULL, $expr1);
}
| IndirectedIdentifier[expr1] OP_LEFT_PAREN CallParameterList[params] OP_RIGHT_PAREN {
    $$ = new_node(FunctionCall, $params, NULL, $expr1);
}
| OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN {
    $$ = $expr;
}
;

LValue
: IndirectedIdentifier { $$ = new_node(LValue, NULL, NULL, $1); }
;

/* ********************************************************* */
/* MISC */

CallParameterList
: CallParameterList OP_COMMA Expression {
    $$ = append_brother($1, $3);
}
| Expression {
    $$ = $1;
}
;

%%

void yyerror(YYLTYPE * yyllocp, yyscan_t unused, const char * msg) {
    parser_error(msg, yyllocp->first_line, yyllocp->first_column);
}
