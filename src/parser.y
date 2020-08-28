%define api.pure full
%define api.token.raw
%define parse.error verbose
%locations
%param { yyscan_t scanner }

%code top {
    #define _GNU_SOURCE
    #include <stdio.h>
    #include <string.h>
    #include "node.h"
    #include "error.h"
    
    #define node(a, b, c, d) new_node(a, b, c, d, yyloc.first_line, yyloc.first_column)
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

%token END 0 "end of file"

%token<string> NUMERIC_IMMEDIATE "number" IDENTIFIER "identifier"
%token<string> STR_CONSTANT "string constant" CHAR_CONSTANT "character constant"

%token KEYWORD_LET "let" KEYWORD_WHILE "while" KEYWORD_IF "if" KEYWORD_FN "fn" KEYWORD_MUT "mut"
%token KEYWORD_CLASS "class" KEYWORD_MODULE "module" KEYWORD_EMIT "emit" KEYWORD_RETURN "return" KEYWORD_EVENT "event"
%token KEYWORD_DO "do" KEYWORD_ELSE "else" KEYWORD_MATCH "match" KEYWORD_FOR "for" KEYWORD_IMPORT "import" KEYWORD_AS "as"

%token OP_LEFT_PAREN "(" OP_RIGHT_PAREN ")" OP_LEFT_SQPAREN "[" OP_RIGHT_SQPAREN "]" OP_LEFT_BRACKET "{" OP_RIGHT_BRACKET "}"
%token OP_PLUS "+" OP_MINUS "-" OP_SHR ">>" OP_SHL "<<" OP_MOD "%" OP_SLASH "/" OP_STAR "*" OP_BIN_AND "&" OP_BIN_OR "|"
%token OP_LOG_AND "&&" OP_LOG_OR "||" OP_XOR "^" OP_TENARY "tenary operator" OP_COLON ":" OP_ARROW "->" OP_INCREMENT "++"
%token OP_DECREMENT "--" OP_DOT "." OP_EQ "=" OP_TILDE "~" OP_BANG "!" OP_ADD_EQ "+=" OP_SUB_EQ "-=" OP_SHL_EQ "<<=" OP_SHR_EQ ">>="
%token OP_MUL_EQ "*=" OP_DIV_EQ "/=" OP_MOD_EQ "%=" OP_AND_EQ "&=" OP_OR_EQ "|=" OP_XOR_EQ "^=" OP_CMP_EQ "==" OP_CMP_GE ">="
%token OP_CMP_LE "<=" OP_CMP_GT ">" OP_CMP_LT "<" OP_CMP_NE "!="
%token OP_COMMA "," OP_AT "@"
%token SEMICOLON ";"

%type<ast> ImportStatement FunctionDeclaration ParameterList ParameterListLoop CompoundStatement
%type<ast> Statement StatementList ReturnStatement Expression DeclarationStatement CodeBlock
%type<ast> ConditionalStatement TypeNode WhileStatement ForStatement ModuleDeclaration TopLevelScope
%type<ast> CallParameterList LValue DoWhileStatement ClassDeclaration ModuleScope ClassScope ImmutableDeclaration
%type<ast> TypeList TypeListLoop EventDeclaration FunctionCall EmitStatement

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

/**
 * Rule for formatting indirected identifiers (e.g. space1.space2.access3).
 * The following declarations are correct:
 *  => `space1 .  space2` => yields `space1.space2`
 *  => `space1  . space2` => yields `space1.space2`
 *  => `space1. space2` => yields `space1.space2`
 *  => `space1 .space2` => yields `space1.space2`
 *  => `space1.space2` => yields `space1.space2`
 * Spaces can be replaced with arbitrary amounts of any whitespace character
 * recognized by the lexer.
 */
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

/**
 * A type compound is just an indirected identifier preceded with a colon.
 * Note: Mutable references and immutable references.
 */
TypeNode
: OP_COLON IndirectedIdentifier[name] {
    $$ = node(TypeCompound, NULL, NULL, $name);
}
| OP_COLON OP_BIN_AND IndirectedIdentifier[name] {
    $$ = node(ImmutableReferenceTypeCompound, NULL, NULL, $name);
}
| OP_COLON OP_BIN_AND KEYWORD_MUT IndirectedIdentifier[name] {
    $$ = node(MutableReferenceTypeCompound, NULL, NULL, $name);
}
;

/**
 * A code block is either a compound statement, or a single statement.
 */
CodeBlock
: CompoundStatement { $$ = $1; }
| Statement { $$ = $1; }
;

/**
 * Parameter list.
 *  `(param1:type1, param2:type2, param3:type3)`
 *  `()`
 */
ParameterList
: OP_LEFT_PAREN ParameterListLoop[loop] OP_RIGHT_PAREN {
    $$ = node(ParameterList, $loop, NULL, NULL);
}
| OP_LEFT_PAREN OP_RIGHT_PAREN {
    $$ = node(ParameterList, NULL, NULL, NULL);
}
;

ParameterListLoop
: IDENTIFIER[param_name] TypeNode[type] OP_COMMA ParameterListLoop[next] {
    $$ = node(Parameter,
        node(ParameterType, $type, NULL, NULL)
    , $next, $param_name);
}
| IDENTIFIER[param_name] TypeNode[type] {
    $$ = node(Parameter,
        node(ParameterType, $type, NULL, NULL)
    , NULL, $param_name);
}
| KEYWORD_MUT IDENTIFIER[param_name] TypeNode[type] OP_COMMA ParameterListLoop[next] {
    $$ = node(MutableParameter,
        node(ParameterType, $type, NULL, NULL)
    , $next, $param_name);
}
| KEYWORD_MUT IDENTIFIER[param_name] TypeNode[type] {
    $$ = node(MutableParameter,
        node(ParameterType, $type, NULL, NULL)
    , NULL, $param_name);
}
;

TypeList
: OP_LEFT_PAREN TypeListLoop[loop] OP_RIGHT_PAREN {
    $$ = node(TypeList, $loop, NULL, NULL);
}
| OP_LEFT_PAREN OP_RIGHT_PAREN {
    $$ = node(TypeList, NULL, NULL, NULL);
}
;

TypeListLoop
: IndirectedIdentifier[type] OP_COMMA TypeListLoop[next] {
    $$ = node(TypeList, NULL, $next, $type);
}
| IndirectedIdentifier[type] {
    $$ = node(TypeList, NULL, NULL, $type);
}
;

/* ********************************************************* */
/* TOPLEVEL SCOPE */

/**
 * In the toplevel scope, you can import stuff, declare normal functions,
 * declare modules and declare classes.
 */
TopLevelScope
: ImportStatement[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| FunctionDeclaration[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| ModuleDeclaration[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| ClassDeclaration[decl] TopLevelScope { $$ = append_brother($decl, $2); }
| %empty { $$ = NULL; }
;

/**
 * Inside classes you can declare methods.
 */
ClassScope
: FunctionDeclaration[decl] ClassScope { $$ = append_brother($decl, $2); }
| DeclarationStatement[decl] ClassScope { $$ = append_brother($decl, $2); }
| EventDeclaration[decl] ClassScope { $$ = append_brother($decl, $2); }
| %empty { $$ = NULL; }
;

/**
 * In the module scope, you can import stuff, declare normal functions
 * and declare classes.
 *
 * Nested modules are disallowed.
 */
ModuleScope
: ImportStatement[decl] ModuleScope { $$ = append_brother($decl, $2); }
| FunctionDeclaration[decl] ModuleScope { $$ = append_brother($decl, $2); }
| ClassDeclaration[decl] ModuleScope { $$ = append_brother($decl, $2); }
| ImmutableDeclaration[decl] ModuleScope { $$ = append_brother($decl, $2); }
| %empty { $$ = NULL; }
;

/**
 * Module declaration syntax.
 */
ModuleDeclaration
: KEYWORD_MODULE IndirectedIdentifier[id] OP_LEFT_BRACKET ModuleScope[scope] OP_RIGHT_BRACKET {
    $$ = node(ModuleDeclaration, $scope, NULL, $id);
}
;

EventDeclaration
: KEYWORD_EVENT IDENTIFIER[id] TypeList[type] SEMICOLON {
    $$ = node(EventDeclaration, $type, NULL, $id);
}
;

/**
 * Class declaration syntax.
 */
ClassDeclaration
: KEYWORD_CLASS IDENTIFIER[id] OP_LEFT_BRACKET ClassScope[scope] OP_RIGHT_BRACKET {
    $$ = node(ClassDeclaration, $scope, NULL, $id);
}
;

/**
 * `import` and `import x as y` syntax.
 */
ImportStatement
: KEYWORD_IMPORT IndirectedIdentifier[pkg] SEMICOLON {
    $$ = node(ImportDeclaration, NULL, NULL, $pkg);
}
| KEYWORD_IMPORT IndirectedIdentifier[pkg] KEYWORD_AS IDENTIFIER[id] SEMICOLON {
    $$ = node(ImportDeclaration,
        node(AsCompound, NULL, NULL, $id),
    NULL, $pkg);
}
;

/**
 * Function declaration:
 *  `fn blah(...):blah {'
 *  `fn blah(...) {`
 */
FunctionDeclaration
: KEYWORD_FN IDENTIFIER[name] ParameterList[param] CompoundStatement[code] {
    $$ = node(FunctionDeclaration,
        append_brother(
            $param,
            $code
        ),
    NULL, $name);
}
| KEYWORD_FN IDENTIFIER[name] ParameterList[params] TypeNode[return_type] CompoundStatement[code] {
    $$ = node(FunctionDeclaration,
        node(FunctionReturnType, NULL,
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

/**
 * Compount statement syntax.
 *  `{ s1; s2; s3 }`
 *  `{ }`
 */
CompoundStatement
: OP_LEFT_BRACKET StatementList[stmt_list] OP_RIGHT_BRACKET {
    $$ = node(CodeBlock, $stmt_list, NULL, NULL);
}
| OP_LEFT_BRACKET OP_RIGHT_BRACKET {
    $$ = node(CodeBlock, NULL, NULL, NULL);
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

/**
 * Currently supported statements.
 */
Statement
: ReturnStatement      { $$ = $1; }
| DeclarationStatement { $$ = $1; }
| ConditionalStatement { $$ = $1; }
| WhileStatement       { $$ = $1; }
| DoWhileStatement     { $$ = $1; }
| ForStatement         { $$ = $1; }
| Expression SEMICOLON { $$ = $1; }
| EmitStatement        { $$ = $1; }
| SEMICOLON            { $$ = NULL; }
;

EmitStatement
: KEYWORD_EMIT FunctionCall[call] SEMICOLON {
    $$ = node(EmitStatement, $call, NULL, NULL);
}
;

/**
 * `while' statement syntax.
 *     `while(condition) code;`
 */
WhileStatement
: KEYWORD_WHILE OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = node(WhileStatement,
        append_brother(
            $expr,
            $code
        ),
    NULL, NULL);
}
;

/**
 * `do..while' statement syntax.
 *     `do code; while(condition);`
 */
DoWhileStatement
: KEYWORD_DO CodeBlock[code] KEYWORD_WHILE OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN SEMICOLON {
    $$ = node(DoWhileStatement,
        append_brother(
            $expr,
            $code
        ),
    NULL, NULL);
}
;

/**
 * `for` syntax:
 *     `for(;;) s;`
 *     `for(a;;) s;`
 *     `for(a; b;) s;`
 *     `for(a; b; c) s;`
 *     `for(; b; c) s;`
 *     `for(;; c) s;`
 *     `for(; b;) s;`
 *     `for(a;; c) s;`
 */
ForStatement
: KEYWORD_FOR OP_LEFT_PAREN SEMICOLON SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = node(ForStatement,
        $code,
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN DeclarationStatement[decl] SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = node(ForStatement,
        append_brother($decl, $code),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN DeclarationStatement[decl] Expression[e1] SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = node(ForStatement,
        append_brother(append_brother($decl, $code), $e1),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN DeclarationStatement[decl] Expression[e1] SEMICOLON Expression[e2] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = node(ForStatement,
        append_brother(append_brother(append_brother($decl, $code), $e1), $e2),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN SEMICOLON Expression[e1] SEMICOLON Expression[e2] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = node(ForStatement,
        append_brother(append_brother($code, $e1), $e2),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN SEMICOLON SEMICOLON Expression[e2] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = node(ForStatement,
        append_brother($code, $e2),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN SEMICOLON Expression[e1] SEMICOLON OP_RIGHT_PAREN CodeBlock[code] {
    $$ = node(ForStatement,
        append_brother($code, $e1),
    NULL, NULL);
}
| KEYWORD_FOR OP_LEFT_PAREN DeclarationStatement[decl] SEMICOLON Expression[e2] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = node(ForStatement,
        append_brother(append_brother($decl, $code), $e2),
    NULL, NULL);
}
;

ConditionalStatement
: KEYWORD_IF OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN CodeBlock[code] {
    $$ = node(ConditionalStatement,
        append_brother(
            $expr,
            $code
        ),
    NULL, NULL);
}
| KEYWORD_IF OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN CodeBlock[code1] KEYWORD_ELSE CodeBlock[code2] {
    $$ = node(ConditionalStatement,
        node(ElseCompound,
            append_brother(
                $code1,
                $code2
            ),
        $expr, NULL),
    NULL, NULL);
}
;

DeclarationStatement
: ImmutableDeclaration { $$ = $1; }
| KEYWORD_MUT IDENTIFIER[name] OP_EQ Expression[value] SEMICOLON {
    $$ = node(MutableLocalDeclarationStatement, $value, NULL, $name);
}
| KEYWORD_MUT IDENTIFIER[name] TypeNode[type] OP_EQ Expression[value] SEMICOLON {
    $$ = node(MutableLocalDeclarationStatement,
        node(VariableTypeNode, $type, $value, NULL),
    NULL, $name);
}
| KEYWORD_MUT IDENTIFIER[name] TypeNode[type] SEMICOLON {
    $$ = node(MutableLocalDeclarationStatement,
        node(VariableTypeNode, $type, NULL, NULL)
    , NULL, $name);
}
;

ImmutableDeclaration
: KEYWORD_LET IDENTIFIER[name] OP_EQ Expression[value] SEMICOLON {
    $$ = node(LocalDeclarationStatement, $value, NULL, $name);
}
| KEYWORD_LET IDENTIFIER[name] TypeNode[type] OP_EQ Expression[value] SEMICOLON {
    $$ = node(LocalDeclarationStatement,
        node(VariableTypeNode, $type, $value, NULL)
    , NULL, $name);
}
;

ReturnStatement
: KEYWORD_RETURN Expression[value] SEMICOLON {
    $$ = node(ReturnStatement, $value, NULL, NULL);
}
| KEYWORD_RETURN SEMICOLON {
    $$ = node(ReturnStatement, NULL, NULL, NULL);
}
;

/* ********************************************************* */
/* EXPRESSION */

Expression
: NUMERIC_IMMEDIATE[imm] {
    $$ = node(NumericImmediate, NULL, NULL, $imm);
}
| LValue[ref] {
    $$ = $ref;
}
| Expression[expr1] OP_TENARY Expression[expr2] OP_COLON Expression[expr3] {
    $$ = node(Tenary, append_brother(append_brother($expr1, $expr2), $expr3), NULL, NULL);
}
| STR_CONSTANT[str] {
    $$ = node(StringImmediate, NULL, NULL, $str);
}
| Expression[expr1] OP_PLUS Expression[expr2] {
    $$ = node(AddExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_MINUS Expression[expr2] {
    $$ = node(SubtractExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_STAR Expression[expr2] {
    $$ = node(MultiplyExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_SLASH Expression[expr2] {
    $$ = node(DivideExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_MOD Expression[expr2] {
    $$ = node(ModulusExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_SHL Expression[expr2] {
    $$ = node(LeftShiftExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_SHR Expression[expr2] {
    $$ = node(LeftShiftExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_BIN_AND Expression[expr2] {
    $$ = node(BitwiseAndExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_BIN_OR Expression[expr2] {
    $$ = node(BitwiseOrExpression,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, NULL);
}
| Expression[expr1] OP_CMP_EQ Expression[expr2] {
    $$ = node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, "==");
}
| Expression[expr1] OP_CMP_GE Expression[expr2] {
    $$ = node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, ">=");
}
| Expression[expr1] OP_CMP_GT Expression[expr2] {
    $$ = node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, ">");
}
| Expression[expr1] OP_CMP_LT Expression[expr2] {
    $$ = node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, "<");
}
| Expression[expr1] OP_CMP_LE Expression[expr2] {
    $$ = node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, "<=");
}
| Expression[expr1] OP_CMP_NE Expression[expr2] {
    $$ = node(ComparisonExpresison,
        append_brother(
            $expr1,
            $expr2
        ),
    NULL, "!=");
}
| LValue[expr1] OP_INCREMENT {
    $$ = node(PostOp,
        $expr1,
    NULL, "++");
}
| OP_INCREMENT LValue[expr1] {
    $$ = node(PreOp,
        $expr1,
    NULL, "++");
}
| LValue[expr1] OP_DECREMENT {
    $$ = node(PostOp,
        $expr1,
    NULL, "--");
}
| OP_DECREMENT LValue[expr1] {
    $$ = node(PreOp,
        $expr1,
    NULL, "--");
}
| LValue[expr1] OP_EQ Expression[expr2] {
    $$ = node(AssignmentExpression,
        append_brother($expr1, $expr2),
    NULL, NULL);
}
| FunctionCall[call] {
    $$ = $call;
}
| OP_LEFT_PAREN Expression[expr] OP_RIGHT_PAREN {
    $$ = $expr;
}
;

FunctionCall
: IndirectedIdentifier[expr1] OP_LEFT_PAREN OP_RIGHT_PAREN {
    $$ = node(FunctionCall, NULL, NULL, $expr1);
}
| IndirectedIdentifier[expr1] OP_LEFT_PAREN CallParameterList[params] OP_RIGHT_PAREN {
    $$ = node(FunctionCall, $params, NULL, $expr1);
}
;

LValue
: IndirectedIdentifier { $$ = node(LValue, NULL, NULL, $1); }
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
