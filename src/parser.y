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

%token<string> NUMERIC_IMMEDIATE
%token<string> IDENTIFIER
%token<string> STR_CONSTANT
%token<string> CHAR_CONSTANT

%token KEYWORD_LET
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
%token OP_TILDE
%token OP_COMMA
%token OP_BANG
%token OP_AT
%token SEMICOLON

%type<ast> ImportStatement FunctionDeclaration ParameterList ParameterListLoop FnCodeBlock Statement StatementList ReturnStatement Expression DeclarationStatement CodeBlock ConditionalStatement TypeNode WhileStatement ForStatement ModuleDeclaration TopLevelScope

%type<string> IndirectedIdentifier

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

%start Start
%%

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

ModuleDeclaration
: KEYWORD_MODULE IndirectedIdentifier[id] OP_LEFT_BRACKET TopLevelScope[scope] OP_RIGHT_BRACKET {
    $$ = new_node(ModuleDeclaration, $scope, NULL, $id);
}
;

Start
: TopLevelScope { dispatch($1); }
;

TopLevelScope
: ImportStatement[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| FunctionDeclaration[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| ModuleDeclaration[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| %empty { $$ = NULL; }
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

TypeNode
: OP_COLON IndirectedIdentifier[name] {
    $$ = new_node(TypeCompound, NULL, NULL, $name);
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

CodeBlock
: FnCodeBlock { $$ = $1; }
| Statement { $$ = $1; }
;

StatementList
: Statement[stmt] {
    $$ = new_node(StatementList, $stmt, NULL, NULL);
}
| StatementList[next] Statement[stmt] {
    $$ = new_node(StatementList, $stmt, $next, NULL);
}
;

Statement
: ReturnStatement      { $$ = $1; }
| DeclarationStatement { $$ = $1; }
| ConditionalStatement { $$ = $1; }
| WhileStatement       { $$ = $1; }
| ForStatement         { $$ = $1; }
| SEMICOLON {
    $$ = new_node(EmptyStatement, NULL, NULL, NULL);
}
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

ForStatement
: KEYWORD_FOR OP_LEFT_BRACKET SEMICOLON SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        $code,
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_BRACKET DeclarationStatement[decl] SEMICOLON SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother($decl, $code),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_BRACKET DeclarationStatement[decl] SEMICOLON Expression[e1] SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother(append_brother($decl, $code), $e1),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_BRACKET DeclarationStatement[decl] SEMICOLON Expression[e1] SEMICOLON Expression[e2] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother(append_brother(append_brother($decl, $code), $e1), $e2),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_BRACKET SEMICOLON Expression[e1] SEMICOLON Expression[e2] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother(append_brother($code, $e1), $e2),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_BRACKET SEMICOLON SEMICOLON Expression[e2] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = new_node(ForStatement,
        append_brother($code, $e2),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_BRACKET SEMICOLON Expression[e1] SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
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

Expression
: NUMERIC_IMMEDIATE[imm] {
    $$ = new_node(NumericImmediate, NULL, NULL, $imm);
}
| IndirectedIdentifier[ref] {
    $$ = new_node(SymbolImmediate, NULL, NULL, $ref);
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
| OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN {
    $$ = $expr;
}
;

%%

void yyerror(YYLTYPE * yyllocp, yyscan_t unused, const char * msg) {
    parser_error(msg, yyllocp->first_line, yyllocp->first_column);
}
