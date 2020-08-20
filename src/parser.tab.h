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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 11 "parser.y"

    typedef void * yyscan_t;

#line 52 "parser.tab.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMERIC_IMMEDIATE = 258,
    IDENTIFIER = 259,
    STR_CONSTANT = 260,
    CHAR_CONSTANT = 261,
    KEYWORD_NEW = 262,
    KEYWORD_LET = 263,
    KEYWORD_DELETE = 264,
    KEYWORD_WHILE = 265,
    KEYWORD_IF = 266,
    KEYWORD_FN = 267,
    KEYWORD_MUT = 268,
    KEYWORD_CLASS = 269,
    KEYWORD_MODULE = 270,
    KEYWORD_EMIT = 271,
    KEYWORD_RETURN = 272,
    KEYWORD_EVENT = 273,
    KEYWORD_DO = 274,
    KEYWORD_ELSE = 275,
    KEYWORD_MATCH = 276,
    KEYWORD_FOR = 277,
    KEYWORD_IMPORT = 278,
    KEYWORD_AS = 279,
    OP_LEFT_PAREN = 280,
    OP_RIGHT_PAREN = 281,
    OP_LEFT_SQPAREN = 282,
    OP_RIGHT_SQPAREN = 283,
    OP_DOT = 284,
    OP_PLUS = 285,
    OP_MINUS = 286,
    OP_SHR = 287,
    OP_SHL = 288,
    OP_MOD = 289,
    OP_SLASH = 290,
    OP_STAR = 291,
    OP_LEFT_BRACKET = 292,
    OP_RIGHT_BRACKET = 293,
    OP_TENARY = 294,
    OP_COLON = 295,
    OP_ARROW = 296,
    OP_INCREMENT = 297,
    OP_DECREMENT = 298,
    OP_BIN_AND = 299,
    OP_BIN_OR = 300,
    OP_LOG_AND = 301,
    OP_LOG_OR = 302,
    OP_XOR = 303,
    OP_ADD_EQ = 304,
    OP_SUB_EQ = 305,
    OP_SHL_EQ = 306,
    OP_SHR_EQ = 307,
    OP_MUL_EQ = 308,
    OP_DIV_EQ = 309,
    OP_MOD_EQ = 310,
    OP_AND_EQ = 311,
    OP_OR_EQ = 312,
    OP_XOR_EQ = 313,
    OP_EQ = 314,
    OP_CMP_EQ = 315,
    OP_CMP_GE = 316,
    OP_CMP_LE = 317,
    OP_CMP_GT = 318,
    OP_CMP_LT = 319,
    OP_CMP_NE = 320,
    OP_TIDLE = 321,
    OP_COMMA = 322,
    OP_BANG = 323,
    OP_AT = 324,
    SEMICOLON = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "parser.y"

    char * string;
    struct node * ast;

#line 139 "parser.tab.h"

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

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
