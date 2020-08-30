%{

#include "error.h"
#include "lexer.h"

#include "parser.tab.h"

#define YY_USER_ACTION                          \
  yylloc->first_line = yylloc->last_line;       \
  yylloc->first_column = yylloc->last_column;   \
  if (yylloc->last_line == yylineno)            \
    yylloc->last_column += yyleng;              \
  else                                          \
    yylloc->last_line = yylineno,               \
    yylloc->last_column = yytext                \
      + yyleng - strrchr(yytext, '\n');

/* may switch later */

%}

%option noinput nounput noyywrap 8bit nodefault
%option yylineno
%option reentrant bison-bridge bison-locations

%%
let         return(KEYWORD_LET);
while       return(KEYWORD_WHILE);
if          return(KEYWORD_IF);
fn          return(KEYWORD_FN);
mut         return(KEYWORD_MUT);
class       return(KEYWORD_CLASS);
module      return(KEYWORD_MODULE);
emit        return(KEYWORD_EMIT);
return      return(KEYWORD_RETURN);
event       return(KEYWORD_EVENT);
do          return(KEYWORD_DO);
else        return(KEYWORD_ELSE);
match       return(KEYWORD_MATCH);
for         return(KEYWORD_FOR);
import      return(KEYWORD_IMPORT);
as          return(KEYWORD_AS);

"("         return(OP_LEFT_PAREN);
")"         return(OP_RIGHT_PAREN);
"["         return(OP_LEFT_SQPAREN);
"]"         return(OP_RIGHT_SQPAREN);
"."         return(OP_DOT);
"+"         return(OP_PLUS);
"-"         return(OP_MINUS);
"/"         return(OP_SLASH);
"*"         return(OP_STAR);
"%"         return(OP_MOD);
"=="        return(OP_CMP_EQ);
">="        return(OP_CMP_GE);
"<="        return(OP_CMP_LE);
">"         return(OP_CMP_GT);
"<"         return(OP_CMP_LT);
"!="        return(OP_CMP_NE);
"++"        return(OP_INCREMENT);
"--"        return(OP_DECREMENT);
"{"         return(OP_LEFT_BRACKET);
"}"         return(OP_RIGHT_BRACKET);
"?"         return(OP_TENARY);
":"         return(OP_COLON);
">>"        return(OP_SHR);
"<<"        return(OP_SHL);
"&"         return(OP_BIN_AND);
"|"         return(OP_BIN_OR);
"^"         return(OP_XOR);
"&&"        return(OP_LOG_AND);
"||"        return(OP_LOG_OR);
"="         return(OP_EQ);
";"         return(SEMICOLON);
"+="        return(OP_ADD_EQ);
"-="        return(OP_SUB_EQ);
"*="        return(OP_MUL_EQ);
"/="        return(OP_DIV_EQ);
"%="        return(OP_MOD_EQ);
"<<="       return(OP_SHL_EQ);
">>="       return(OP_SHR_EQ);
"&="        return(OP_AND_EQ);
"|="        return(OP_OR_EQ);
"^="        return(OP_XOR_EQ);

"->"        return(OP_ARROW);

"~"         return(OP_TILDE);
","         return(OP_COMMA);
"!"         return(OP_BANG);
"@"         return(OP_AT);

\'\\?.\'                   {
    yylval->string = strdup(yytext);
    return(CHAR_CONSTANT);
}

\"(\\.|[^\"])*\"           {
    yylval->string = strdup(yytext);
    return(STR_CONSTANT);
}

[A-Za-z_][0-9A-Za-z_]*     {
    yylval->string = strdup(yytext);
    return(IDENTIFIER);
}

\-?(0[xbo])?([0-9A-Fa-f])+ {
    yylval->string = strdup(yytext);
    return(NUMERIC_IMMEDIATE);
}

[\n\t\r\f ] { ; }
.           { lexer_error(yylineno); }

%%

void process_file(const char * name) {
    yyscan_t yyscanner;
    
    yylex_init(&yyscanner);
    yyset_in(fopen(name, "rb"), yyscanner);
    yyparse(yyscanner);
    yylex_destroy(yyscanner);
}
