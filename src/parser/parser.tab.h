/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_PARSER_PARSER_TAB_H_INCLUDED
# define YY_YY_SRC_PARSER_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 17 "src/parser/parser.y"

    typedef void * yyscan_t;

#line 52 "src/parser/parser.tab.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    NUMERIC_IMMEDIATE = 3,
    IDENTIFIER = 4,
    STR_CONSTANT = 5,
    CHAR_CONSTANT = 6,
    KEYWORD_LET = 7,
    KEYWORD_WHILE = 8,
    KEYWORD_IF = 9,
    KEYWORD_FN = 10,
    KEYWORD_MUT = 11,
    KEYWORD_CLASS = 12,
    KEYWORD_MODULE = 13,
    KEYWORD_EMIT = 14,
    KEYWORD_RETURN = 15,
    KEYWORD_EVENT = 16,
    KEYWORD_DO = 17,
    KEYWORD_ELSE = 18,
    KEYWORD_MATCH = 19,
    KEYWORD_FOR = 20,
    KEYWORD_IMPORT = 21,
    KEYWORD_AS = 22,
    OP_LEFT_PAREN = 23,
    OP_RIGHT_PAREN = 24,
    OP_LEFT_SQPAREN = 25,
    OP_RIGHT_SQPAREN = 26,
    OP_LEFT_BRACKET = 27,
    OP_RIGHT_BRACKET = 28,
    OP_PLUS = 29,
    OP_MINUS = 30,
    OP_SHR = 31,
    OP_SHL = 32,
    OP_MOD = 33,
    OP_SLASH = 34,
    OP_STAR = 35,
    OP_BIN_AND = 36,
    OP_BIN_OR = 37,
    OP_LOG_AND = 38,
    OP_LOG_OR = 39,
    OP_XOR = 40,
    OP_TENARY = 41,
    OP_COLON = 42,
    OP_ARROW = 43,
    OP_INCREMENT = 44,
    OP_DECREMENT = 45,
    OP_DOT = 46,
    OP_EQ = 47,
    OP_TILDE = 48,
    OP_BANG = 49,
    OP_ADD_EQ = 50,
    OP_SUB_EQ = 51,
    OP_SHL_EQ = 52,
    OP_SHR_EQ = 53,
    OP_MUL_EQ = 54,
    OP_DIV_EQ = 55,
    OP_MOD_EQ = 56,
    OP_AND_EQ = 57,
    OP_OR_EQ = 58,
    OP_XOR_EQ = 59,
    OP_CMP_EQ = 60,
    OP_CMP_GE = 61,
    OP_CMP_LE = 62,
    OP_CMP_GT = 63,
    OP_CMP_LT = 64,
    OP_CMP_NE = 65,
    OP_COMMA = 66,
    OP_AT = 67,
    SEMICOLON = 68,
    NEG = 69
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "src/parser/parser.y"

    char * string;
    struct node * ast;

#line 139 "src/parser/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_SRC_PARSER_PARSER_TAB_H_INCLUDED  */
