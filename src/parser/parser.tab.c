/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 7 "src/parser/parser.y"

    #define _GNU_SOURCE
    #include <stdio.h>
    #include <string.h>
    #include "node.h"
    #include "error.h"
    
    #define node(a, b, c, d) new_node(a, b, c, d, yyloc.first_line, yyloc.first_column)

#line 77 "src/parser/parser.tab.c"




# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 127 "src/parser/parser.tab.c"

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

#line 214 "src/parser/parser.tab.c"

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


/* Unqualified %code blocks.  */
#line 26 "src/parser/parser.y"

    int yylex(YYSTYPE * yylvalp, YYLTYPE * yyllocp, yyscan_t scanner);
    void yyerror(YYLTYPE * yyllocp, yyscan_t unused, const char * msg);
    
    void dispatch(struct node *);

#line 251 "src/parser/parser.tab.c"

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  267

#define YYUNDEFTOK  2
#define YYMAXUTOK   324


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX) (YYX)

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,   104,   107,   123,   126,   129,   138,   139,
     148,   151,   157,   162,   167,   172,   180,   183,   189,   192,
     205,   206,   207,   208,   209,   216,   217,   218,   219,   229,
     230,   231,   232,   233,   240,   246,   255,   264,   267,   280,
     288,   308,   311,   320,   323,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   344,   354,   369,   391,   396,   410,
     424,   438,   452,   466,   480,   497,   505,   518,   519,   522,
     527,   535,   538,   546,   549,   558,   561,   564,   567,   570,
     573,   581,   589,   597,   605,   613,   621,   629,   637,   645,
     653,   661,   669,   677,   685,   693,   701,   709,   717,   725,
     733,   741,   749,   757,   765,   773,   781,   789,   797,   802,
     807,   812,   817,   822,   827,   832,   837,   840,   846,   849,
     855,   862,   865
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"number\"",
  "\"identifier\"", "\"string constant\"", "\"character constant\"",
  "\"let\"", "\"while\"", "\"if\"", "\"fn\"", "\"mut\"", "\"class\"",
  "\"module\"", "\"emit\"", "\"return\"", "\"event\"", "\"do\"",
  "\"else\"", "\"match\"", "\"for\"", "\"import\"", "\"as\"", "\"(\"",
  "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"+\"", "\"-\"", "\">>\"",
  "\"<<\"", "\"%\"", "\"/\"", "\"*\"", "\"&\"", "\"|\"", "\"&&\"",
  "\"||\"", "\"^\"", "\"tenary operator\"", "\":\"", "\"->\"", "\"++\"",
  "\"--\"", "\".\"", "\"=\"", "\"~\"", "\"!\"", "\"+=\"", "\"-=\"",
  "\"<<=\"", "\">>=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"",
  "\"^=\"", "\"==\"", "\">=\"", "\"<=\"", "\">\"", "\"<\"", "\"!=\"",
  "\",\"", "\"@\"", "\";\"", "NEG", "$accept", "Start",
  "IndirectedIdentifier", "TypeNode", "CodeBlock", "ParameterList",
  "ParameterListLoop", "TypeList", "TypeListLoop", "TopLevelScope",
  "ClassScope", "ModuleScope", "ModuleDeclaration", "EventDeclaration",
  "ClassDeclaration", "ImportStatement", "FunctionDeclaration",
  "CompoundStatement", "StatementList", "Statement", "EmitStatement",
  "WhileStatement", "DoWhileStatement", "ForStatement",
  "ConditionalStatement", "DeclarationStatement", "ImmutableDeclaration",
  "ReturnStatement", "Expression", "FunctionCall", "LValue",
  "CallParameterList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     203,    21,    49,    51,    51,    14,   -95,   203,   203,   203,
     203,    23,    50,    37,    94,   -14,   -95,   -95,   -95,   -95,
     -95,    38,    42,     8,    51,   154,   120,   -95,    89,   123,
     -95,   130,   142,     9,   136,   -95,   170,   176,   177,   156,
       8,     8,     8,   -95,   -95,   164,   154,   154,   154,   154,
     125,   137,    89,   -95,   -95,   -95,   -95,   184,   186,    51,
      -1,   191,   189,   410,   -95,   410,    51,    51,   410,   410,
     -95,   194,   238,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   667,   -95,    85,    16,   -95,   -95,    81,   113,   196,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     115,   157,   410,   410,   194,   152,   -95,   680,   214,   -95,
     -95,     0,   432,   -95,   -95,   -95,   -95,   -95,   -95,   327,
     -95,   -95,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   -95,   -95,   -95,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,    51,   -95,   410,   182,   410,
      10,   101,   166,   -95,   115,   450,   492,   -95,   -95,   215,
     227,   274,   -95,   -95,   893,   -15,   134,   134,   255,   255,
     -95,   -95,   -95,  1036,   991,   979,   942,  1028,   879,   474,
     418,   418,   418,   418,   474,   -95,   893,   893,   893,   893,
     893,   893,   893,   893,   893,   893,   -95,   720,   410,   733,
     410,   -95,   -95,   171,   224,   -95,   -95,   191,   191,   410,
     340,   773,   350,   786,   -95,   410,   410,   -95,   826,   -95,
     839,    51,   -95,   -95,   233,   510,   191,   552,   363,   191,
     570,   397,   893,   930,   -95,   -95,   -95,   191,   188,   -95,
     191,   191,   612,   -95,   191,   191,   630,   -95,   -95,   -95,
     -95,   191,   -95,   -95,   191,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      24,     0,     0,     0,     0,     0,     2,    24,    24,    24,
      24,     0,     0,     3,     0,     0,     1,    22,    23,    20,
      21,     0,     0,    28,     0,    33,     0,    37,     0,     0,
      11,     0,     0,     0,     0,    39,     0,     0,     0,     0,
      28,    28,    28,    67,     4,     0,    33,    33,    33,    33,
       0,    13,     0,    10,    75,    79,    76,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     0,
      53,   120,     0,    43,    52,    48,    49,    50,    47,    46,
      45,     0,   116,    77,     0,     5,    40,     0,     0,     0,
      36,    27,    25,    26,    34,    31,    29,    30,    32,    38,
       0,    15,     0,     0,     0,     0,    74,     0,     0,     8,
       9,     0,     0,   114,   120,   109,   111,   112,   113,     0,
      41,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,   108,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,     0,     0,
       0,     0,     0,    12,     0,     0,     0,    54,    73,     0,
       0,     0,   117,   118,   122,     0,    80,    82,    92,    90,
      88,    86,    84,    94,    96,    98,    99,   100,     0,   102,
     103,   106,   104,   105,   107,   115,    81,    83,    91,    93,
      85,    87,    89,    95,    97,   101,     7,     0,     0,     0,
       0,    70,    17,    19,     0,    35,    14,     0,     0,     0,
       0,     0,     0,     0,   119,     0,     0,    71,     0,    68,
       0,     0,    16,    55,    65,     0,     0,     0,     0,     0,
       0,     0,   121,    78,    72,    69,    18,     0,     0,    57,
       0,     0,     0,    58,     0,     0,     0,    66,    56,    62,
      63,     0,    64,    59,     0,    61,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,    -3,   -16,    74,   -95,   -94,   -95,    29,   169,
     185,   216,   -95,   -95,    -8,    12,  1062,    84,   -95,   -22,
     -95,   -95,   -95,   -95,   -95,    -7,    27,   -95,   -37,   195,
      13,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    71,    34,   108,    22,    31,   162,   214,     6,
      39,    45,     7,    40,     8,     9,    10,   109,    72,   110,
      74,    75,    76,    77,    78,    79,    43,    80,    81,    82,
      83,   175
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    15,    54,    13,    55,    56,   163,    36,    26,   224,
      73,    37,    51,    13,    16,    36,    42,    46,     1,    37,
      13,    44,    63,   107,    38,    11,   112,   155,   113,    65,
      85,   117,   118,    42,    42,    42,   101,    47,    46,    46,
      46,    46,    28,    66,    67,    84,    21,    68,    69,    29,
     121,   225,    49,    12,    27,    13,   104,   210,    47,    47,
      47,    47,    30,   114,   114,   165,   166,   106,   170,    32,
     216,   158,   160,    49,    49,    49,    49,    23,   211,   115,
     116,   156,   174,    24,    33,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   171,    13,    35,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    86,    28,
     207,    25,   209,    33,    50,   212,    29,    52,   157,   142,
     143,    33,   144,   221,   223,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    54,    13,    55,    56,    36,
      57,    58,   206,    37,    53,    33,    59,    60,   213,    61,
     159,    36,    62,    32,     1,    63,     2,   126,   127,   128,
      64,   228,    65,   230,    87,     4,    17,    18,    19,    20,
      88,    89,   235,   237,    90,   240,    66,    67,   242,   243,
      68,    69,    94,    99,    54,    13,    55,    56,    36,    57,
      58,   252,    37,   100,   256,    59,    60,   102,    61,   103,
      70,    62,   111,     1,    63,     2,     3,   119,    32,   161,
     167,    65,   169,   164,     4,    91,    92,    93,   213,   208,
      54,    13,    55,    56,   215,    66,    67,   231,   219,    68,
      69,    54,    13,    55,    56,    36,    57,    58,   232,    37,
      63,   247,    59,    60,   105,    61,   258,    65,    62,    70,
     246,    63,    95,    96,    97,    98,   120,     0,    65,     0,
       0,    66,    67,     0,     0,    68,    69,    54,    13,    55,
      56,     0,    66,    67,   122,   123,    68,    69,   126,   127,
     128,   233,   234,     0,     0,   220,     0,    63,     0,     0,
       0,     0,     0,     0,    65,     0,    70,     0,     0,     0,
     249,     0,     0,   253,     0,     0,     0,     0,    66,    67,
       0,   257,    68,    69,   259,   260,     0,     0,   262,   263,
      54,    13,    55,    56,     0,   265,     0,     0,   266,     0,
       0,     0,   222,    54,    13,    55,    56,     0,     0,     0,
      63,   173,     0,    54,    13,    55,    56,    65,     0,     0,
       0,     0,     0,    63,   236,     0,    54,    13,    55,    56,
      65,    66,    67,    63,   239,    68,    69,     0,     0,     0,
      65,     0,     0,     0,    66,    67,    63,   251,    68,    69,
       0,     0,     0,    65,    66,    67,     0,     0,    68,    69,
      54,    13,    55,    56,     0,     0,     0,    66,    67,     0,
       0,    68,    69,    54,    13,    55,    56,     0,     0,     0,
      63,   255,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
      65,    66,    67,     0,     0,    68,    69,   122,   123,   124,
     125,   126,   127,   128,    66,    67,   172,     0,    68,    69,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   217,     0,     0,     0,     0,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,   122,   123,   124,   125,   126,   127,   128,
     135,   136,   137,   138,   139,   140,   218,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   248,   136,   137,   138,   139,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,   250,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   254,     0,     0,     0,     0,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,   261,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   264,     0,     0,     0,     0,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,     0,     0,     0,     0,     0,   135,   136,   137,
     138,   139,   140,     0,     0,   141,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,     0,     0,   168,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,     0,     0,   227,     0,
       0,     0,     0,   135,   136,   137,   138,   139,   140,     0,
       0,   229,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     0,     0,
       0,     0,     0,   135,   136,   137,   138,   139,   140,     0,
       0,   238,     0,     0,     0,     0,   135,   136,   137,   138,
     139,   140,     0,     0,   241,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,   136,   137,   138,
     139,   140,     0,     0,   244,     0,     0,     0,     0,   135,
     136,   137,   138,   139,   140,     0,     0,   245,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   226,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,     0,     0,     0,     0,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,   135,   136,   137,   138,   139,   140,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,   133,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,     0,   135,   136,   137,   138,   139,   140,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,   133,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,     0,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,   135,   136,   137,   138,   139,   140,   122,   123,   124,
     125,   126,   127,   128,   129,   122,   123,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,    48,   135,   136,
     137,   138,   139,   140,     0,     0,   135,   136,   137,   138,
     139,   140,    41,    41,    41,     0,     0,     0,    48,    48,
      48,    48
};

static const yytype_int16 yycheck[] =
{
       3,     4,     3,     4,     5,     6,   100,     7,    22,    24,
      32,    11,    28,     4,     0,     7,    23,    25,    10,    11,
       4,    24,    23,    60,    16,     4,    63,    11,    65,    30,
      33,    68,    69,    40,    41,    42,    52,    25,    46,    47,
      48,    49,     4,    44,    45,    36,    23,    48,    49,    11,
      72,    66,    25,     4,    68,     4,    59,    47,    46,    47,
      48,    49,    24,    66,    67,   102,   103,    68,    68,    27,
     164,    87,    88,    46,    47,    48,    49,    27,    68,    66,
      67,    84,   119,    46,    42,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   111,     4,    22,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    34,     4,
     157,    27,   159,    42,     4,    24,    11,     4,    47,    44,
      45,    42,    47,   170,   171,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     3,     4,     5,     6,     7,
       8,     9,   155,    11,    24,    42,    14,    15,   161,    17,
      47,     7,    20,    27,    10,    23,    12,    33,    34,    35,
      28,   208,    30,   210,     4,    21,     7,     8,     9,    10,
       4,     4,   219,   220,    28,   222,    44,    45,   225,   226,
      48,    49,    28,    68,     3,     4,     5,     6,     7,     8,
       9,   238,    11,    66,   241,    14,    15,    23,    17,    23,
      68,    20,    23,    10,    23,    12,    13,    23,    27,    23,
      68,    30,     8,    66,    21,    40,    41,    42,   231,    47,
       3,     4,     5,     6,    68,    44,    45,    66,    23,    48,
      49,     3,     4,     5,     6,     7,     8,     9,    24,    11,
      23,    18,    14,    15,    59,    17,    68,    30,    20,    68,
     231,    23,    46,    47,    48,    49,    28,    -1,    30,    -1,
      -1,    44,    45,    -1,    -1,    48,    49,     3,     4,     5,
       6,    -1,    44,    45,    29,    30,    48,    49,    33,    34,
      35,   217,   218,    -1,    -1,    68,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    68,    -1,    -1,    -1,
     236,    -1,    -1,   239,    -1,    -1,    -1,    -1,    44,    45,
      -1,   247,    48,    49,   250,   251,    -1,    -1,   254,   255,
       3,     4,     5,     6,    -1,   261,    -1,    -1,   264,    -1,
      -1,    -1,    68,     3,     4,     5,     6,    -1,    -1,    -1,
      23,    24,    -1,     3,     4,     5,     6,    30,    -1,    -1,
      -1,    -1,    -1,    23,    24,    -1,     3,     4,     5,     6,
      30,    44,    45,    23,    24,    48,    49,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    44,    45,    23,    24,    48,    49,
      -1,    -1,    -1,    30,    44,    45,    -1,    -1,    48,    49,
       3,     4,     5,     6,    -1,    -1,    -1,    44,    45,    -1,
      -1,    48,    49,     3,     4,     5,     6,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    44,    45,    -1,    -1,    48,    49,    29,    30,    31,
      32,    33,    34,    35,    44,    45,    24,    -1,    48,    49,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    24,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    60,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      60,    61,    62,    63,    64,    65,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    24,    61,    62,    63,    64,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    60,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    24,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    60,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    24,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    60,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    -1,    -1,    68,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    65,    -1,
      -1,    68,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    -1,    -1,    68,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    -1,    -1,    68,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    65,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    29,    30,    31,
      32,    33,    34,    35,    36,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    60,    61,
      62,    63,    64,    65,    -1,    -1,    60,    61,    62,    63,
      64,    65,    40,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    12,    13,    21,    71,    79,    82,    84,    85,
      86,     4,     4,     4,    72,    72,     0,    79,    79,    79,
      79,    23,    75,    27,    46,    27,    22,    68,     4,    11,
      24,    76,    27,    42,    73,    87,     7,    11,    16,    80,
      83,    86,    95,    96,    72,    81,    84,    85,    86,    96,
       4,    73,     4,    24,     3,     5,     6,     8,     9,    14,
      15,    17,    20,    23,    28,    30,    44,    45,    48,    49,
      68,    72,    88,    89,    90,    91,    92,    93,    94,    95,
      97,    98,    99,   100,    36,    72,    87,     4,     4,     4,
      28,    80,    80,    80,    28,    81,    81,    81,    81,    68,
      66,    73,    23,    23,    72,    99,    68,    98,    74,    87,
      89,    23,    98,    98,    72,   100,   100,    98,    98,    23,
      28,    89,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    60,    61,    62,    63,    64,
      65,    68,    44,    45,    47,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    11,    72,    47,    73,    47,
      73,    23,    77,    76,    66,    98,    98,    68,    68,     8,
      68,    95,    24,    24,    98,   101,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    72,    98,    47,    98,
      47,    68,    24,    72,    78,    68,    76,    24,    24,    23,
      68,    98,    68,    98,    24,    66,    42,    68,    98,    68,
      98,    66,    24,    74,    74,    98,    24,    98,    68,    24,
      98,    68,    98,    98,    68,    68,    78,    18,    24,    74,
      24,    24,    98,    74,    24,    24,    98,    74,    68,    74,
      74,    24,    74,    74,    24,    74,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    74,    74,
      75,    75,    76,    76,    76,    76,    77,    77,    78,    78,
      79,    79,    79,    79,    79,    80,    80,    80,    80,    81,
      81,    81,    81,    81,    82,    83,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    91,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    95,    95,    95,
      95,    96,    96,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     2,     3,     4,     1,     1,
       3,     2,     4,     2,     5,     3,     3,     2,     3,     1,
       2,     2,     2,     2,     0,     2,     2,     2,     0,     2,
       2,     2,     2,     0,     5,     4,     5,     3,     5,     4,
       5,     3,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     3,     5,     7,     6,     6,     7,
       8,     8,     7,     7,     7,     5,     7,     1,     5,     6,
       4,     5,     6,     3,     2,     1,     1,     1,     5,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     3,     3,     4,
       1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 89 "src/parser/parser.y"
                { dispatch((yyvsp[0].ast)); }
#line 1838 "src/parser/parser.tab.c"
    break;

  case 3:
#line 104 "src/parser/parser.y"
             {
    (yyval.string) = strdup((yyvsp[0].string));
}
#line 1846 "src/parser/parser.tab.c"
    break;

  case 4:
#line 107 "src/parser/parser.y"
                                         {
    char * p;
    
    (void) asprintf(&p, "%s.%s", (yyvsp[-2].string), (yyvsp[0].string));
    
    free((yyvsp[0].string));
    
    (yyval.string) = p;
}
#line 1860 "src/parser/parser.tab.c"
    break;

  case 5:
#line 123 "src/parser/parser.y"
                                      {
    (yyval.ast) = node(TypeCompound, NULL, NULL, (yyvsp[0].string));
}
#line 1868 "src/parser/parser.tab.c"
    break;

  case 6:
#line 126 "src/parser/parser.y"
                                                 {
    (yyval.ast) = node(ImmutableReferenceTypeCompound, NULL, NULL, (yyvsp[0].string));
}
#line 1876 "src/parser/parser.tab.c"
    break;

  case 7:
#line 129 "src/parser/parser.y"
                                                             {
    (yyval.ast) = node(MutableReferenceTypeCompound, NULL, NULL, (yyvsp[0].string));
}
#line 1884 "src/parser/parser.tab.c"
    break;

  case 8:
#line 138 "src/parser/parser.y"
                    { (yyval.ast) = (yyvsp[0].ast); }
#line 1890 "src/parser/parser.tab.c"
    break;

  case 9:
#line 139 "src/parser/parser.y"
            { (yyval.ast) = (yyvsp[0].ast); }
#line 1896 "src/parser/parser.tab.c"
    break;

  case 10:
#line 148 "src/parser/parser.y"
                                                       {
    (yyval.ast) = node(ParameterList, (yyvsp[-1].ast), NULL, NULL);
}
#line 1904 "src/parser/parser.tab.c"
    break;

  case 11:
#line 151 "src/parser/parser.y"
                               {
    (yyval.ast) = node(ParameterList, NULL, NULL, NULL);
}
#line 1912 "src/parser/parser.tab.c"
    break;

  case 12:
#line 157 "src/parser/parser.y"
                                                                         {
    (yyval.ast) = node(Parameter,
        node(ParameterType, (yyvsp[-2].ast), NULL, NULL)
    , (yyvsp[0].ast), (yyvsp[-3].string));
}
#line 1922 "src/parser/parser.tab.c"
    break;

  case 13:
#line 162 "src/parser/parser.y"
                                        {
    (yyval.ast) = node(Parameter,
        node(ParameterType, (yyvsp[0].ast), NULL, NULL)
    , NULL, (yyvsp[-1].string));
}
#line 1932 "src/parser/parser.tab.c"
    break;

  case 14:
#line 167 "src/parser/parser.y"
                                                                                     {
    (yyval.ast) = node(MutableParameter,
        node(ParameterType, (yyvsp[-2].ast), NULL, NULL)
    , (yyvsp[0].ast), (yyvsp[-3].string));
}
#line 1942 "src/parser/parser.tab.c"
    break;

  case 15:
#line 172 "src/parser/parser.y"
                                                    {
    (yyval.ast) = node(MutableParameter,
        node(ParameterType, (yyvsp[0].ast), NULL, NULL)
    , NULL, (yyvsp[-1].string));
}
#line 1952 "src/parser/parser.tab.c"
    break;

  case 16:
#line 180 "src/parser/parser.y"
                                                  {
    (yyval.ast) = node(TypeList, (yyvsp[-1].ast), NULL, NULL);
}
#line 1960 "src/parser/parser.tab.c"
    break;

  case 17:
#line 183 "src/parser/parser.y"
                               {
    (yyval.ast) = node(TypeList, NULL, NULL, NULL);
}
#line 1968 "src/parser/parser.tab.c"
    break;

  case 18:
#line 189 "src/parser/parser.y"
                                                         {
    (yyval.ast) = node(TypeList, NULL, (yyvsp[0].ast), (yyvsp[-2].string));
}
#line 1976 "src/parser/parser.tab.c"
    break;

  case 19:
#line 192 "src/parser/parser.y"
                             {
    (yyval.ast) = node(TypeList, NULL, NULL, (yyvsp[0].string));
}
#line 1984 "src/parser/parser.tab.c"
    break;

  case 20:
#line 205 "src/parser/parser.y"
                                      { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1990 "src/parser/parser.tab.c"
    break;

  case 21:
#line 206 "src/parser/parser.y"
                                          { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1996 "src/parser/parser.tab.c"
    break;

  case 22:
#line 207 "src/parser/parser.y"
                                        { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2002 "src/parser/parser.tab.c"
    break;

  case 23:
#line 208 "src/parser/parser.y"
                                       { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2008 "src/parser/parser.tab.c"
    break;

  case 24:
#line 209 "src/parser/parser.y"
         { (yyval.ast) = NULL; }
#line 2014 "src/parser/parser.tab.c"
    break;

  case 25:
#line 216 "src/parser/parser.y"
                                       { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2020 "src/parser/parser.tab.c"
    break;

  case 26:
#line 217 "src/parser/parser.y"
                                        { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2026 "src/parser/parser.tab.c"
    break;

  case 27:
#line 218 "src/parser/parser.y"
                                    { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2032 "src/parser/parser.tab.c"
    break;

  case 28:
#line 219 "src/parser/parser.y"
         { (yyval.ast) = NULL; }
#line 2038 "src/parser/parser.tab.c"
    break;

  case 29:
#line 229 "src/parser/parser.y"
                                    { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2044 "src/parser/parser.tab.c"
    break;

  case 30:
#line 230 "src/parser/parser.y"
                                        { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2050 "src/parser/parser.tab.c"
    break;

  case 31:
#line 231 "src/parser/parser.y"
                                     { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2056 "src/parser/parser.tab.c"
    break;

  case 32:
#line 232 "src/parser/parser.y"
                                         { (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2062 "src/parser/parser.tab.c"
    break;

  case 33:
#line 233 "src/parser/parser.y"
         { (yyval.ast) = NULL; }
#line 2068 "src/parser/parser.tab.c"
    break;

  case 34:
#line 240 "src/parser/parser.y"
                                                                                              {
    (yyval.ast) = node(ModuleDeclaration, (yyvsp[-1].ast), NULL, (yyvsp[-3].string));
}
#line 2076 "src/parser/parser.tab.c"
    break;

  case 35:
#line 246 "src/parser/parser.y"
                                                        {
    (yyval.ast) = node(EventDeclaration, (yyvsp[-1].ast), NULL, (yyvsp[-2].string));
}
#line 2084 "src/parser/parser.tab.c"
    break;

  case 36:
#line 255 "src/parser/parser.y"
                                                                                  {
    (yyval.ast) = node(ClassDeclaration, (yyvsp[-1].ast), NULL, (yyvsp[-3].string));
}
#line 2092 "src/parser/parser.tab.c"
    break;

  case 37:
#line 264 "src/parser/parser.y"
                                                     {
    (yyval.ast) = node(ImportDeclaration, NULL, NULL, (yyvsp[-1].string));
}
#line 2100 "src/parser/parser.tab.c"
    break;

  case 38:
#line 267 "src/parser/parser.y"
                                                                               {
    (yyval.ast) = node(ImportDeclaration,
        node(AsCompound, NULL, NULL, (yyvsp[-1].string)),
    NULL, (yyvsp[-3].string));
}
#line 2110 "src/parser/parser.tab.c"
    break;

  case 39:
#line 280 "src/parser/parser.y"
                                                                           {
    (yyval.ast) = node(FunctionDeclaration,
        append_brother(
            (yyvsp[-1].ast),
            (yyvsp[0].ast)
        ),
    NULL, (yyvsp[-2].string));
}
#line 2123 "src/parser/parser.tab.c"
    break;

  case 40:
#line 288 "src/parser/parser.y"
                                                                                                  {
    (yyval.ast) = node(FunctionDeclaration,
        node(FunctionReturnType, NULL,
            append_brother(
                append_brother(
                    (yyvsp[-2].ast),
                    (yyvsp[0].ast)
                ), (yyvsp[-1].ast)
            ), NULL
        ),
    NULL, (yyvsp[-3].string));
}
#line 2140 "src/parser/parser.tab.c"
    break;

  case 41:
#line 308 "src/parser/parser.y"
                                                            {
    (yyval.ast) = node(CodeBlock, (yyvsp[-1].ast), NULL, NULL);
}
#line 2148 "src/parser/parser.tab.c"
    break;

  case 42:
#line 311 "src/parser/parser.y"
                                   {
    (yyval.ast) = node(CodeBlock, NULL, NULL, NULL);
}
#line 2156 "src/parser/parser.tab.c"
    break;

  case 43:
#line 320 "src/parser/parser.y"
                  {
    (yyval.ast) = (yyvsp[0].ast);
}
#line 2164 "src/parser/parser.tab.c"
    break;

  case 44:
#line 323 "src/parser/parser.y"
                                      {
    (yyval.ast) = append_brother((yyvsp[-1].ast), (yyvsp[0].ast));
}
#line 2172 "src/parser/parser.tab.c"
    break;

  case 45:
#line 332 "src/parser/parser.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2178 "src/parser/parser.tab.c"
    break;

  case 46:
#line 333 "src/parser/parser.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2184 "src/parser/parser.tab.c"
    break;

  case 47:
#line 334 "src/parser/parser.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2190 "src/parser/parser.tab.c"
    break;

  case 48:
#line 335 "src/parser/parser.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2196 "src/parser/parser.tab.c"
    break;

  case 49:
#line 336 "src/parser/parser.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2202 "src/parser/parser.tab.c"
    break;

  case 50:
#line 337 "src/parser/parser.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2208 "src/parser/parser.tab.c"
    break;

  case 51:
#line 338 "src/parser/parser.y"
                       { (yyval.ast) = (yyvsp[-1].ast); }
#line 2214 "src/parser/parser.tab.c"
    break;

  case 52:
#line 339 "src/parser/parser.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2220 "src/parser/parser.tab.c"
    break;

  case 53:
#line 340 "src/parser/parser.y"
                       { (yyval.ast) = NULL; }
#line 2226 "src/parser/parser.tab.c"
    break;

  case 54:
#line 344 "src/parser/parser.y"
                                            {
    (yyval.ast) = node(EmitStatement, (yyvsp[-1].ast), NULL, NULL);
}
#line 2234 "src/parser/parser.tab.c"
    break;

  case 55:
#line 354 "src/parser/parser.y"
                                                                              {
    (yyval.ast) = node(WhileStatement,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2247 "src/parser/parser.tab.c"
    break;

  case 56:
#line 369 "src/parser/parser.y"
                                                                                                   {
    (yyval.ast) = node(DoWhileStatement,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[-5].ast)
        ),
    NULL, NULL);
}
#line 2260 "src/parser/parser.tab.c"
    break;

  case 57:
#line 391 "src/parser/parser.y"
                                                                               {
    (yyval.ast) = node(ForStatement,
        (yyvsp[0].ast),
    NULL, NULL);
}
#line 2270 "src/parser/parser.tab.c"
    break;

  case 58:
#line 396 "src/parser/parser.y"
                                                                                                {
    (yyval.ast) = node(ForStatement,
        append_brother(
            append_brother(
                append_brother(
                    (yyvsp[-3].ast),
                    (yyvsp[0].ast)
                ),
                node(EmptyStatement, NULL, NULL, NULL)
            ),
            node(EmptyStatement, NULL, NULL, NULL)
        ),
    NULL, NULL);
}
#line 2289 "src/parser/parser.tab.c"
    break;

  case 59:
#line 410 "src/parser/parser.y"
                                                                                                               {
    (yyval.ast) = node(ForStatement,
        append_brother(
            append_brother(
                append_brother(
                    (yyvsp[-4].ast),
                    (yyvsp[0].ast)
                ),
                (yyvsp[-3].ast)
            ),
            node(EmptyStatement, NULL, NULL, NULL)
        ),
    NULL, NULL);
}
#line 2308 "src/parser/parser.tab.c"
    break;

  case 60:
#line 424 "src/parser/parser.y"
                                                                                                                              {
    (yyval.ast) = node(ForStatement,
        append_brother(
            append_brother(
                append_brother(
                    (yyvsp[-5].ast),
                    (yyvsp[0].ast)
                ),
                (yyvsp[-4].ast)
            ),
            (yyvsp[-2].ast)
        ),
    NULL, NULL);
}
#line 2327 "src/parser/parser.tab.c"
    break;

  case 61:
#line 438 "src/parser/parser.y"
                                                                                                             {
    (yyval.ast) = node(ForStatement,
        append_brother(
            append_brother(
                append_brother(
                    node(EmptyStatement, NULL, NULL, NULL),
                    (yyvsp[0].ast)
                ),
                (yyvsp[-4].ast)
            ),
            (yyvsp[-2].ast)
        ),
    NULL, NULL);
}
#line 2346 "src/parser/parser.tab.c"
    break;

  case 62:
#line 452 "src/parser/parser.y"
                                                                                              {
    (yyval.ast) = node(ForStatement,
        append_brother(
            append_brother(
                append_brother(
                    node(EmptyStatement, NULL, NULL, NULL),
                    (yyvsp[0].ast)
                ),
                node(EmptyStatement, NULL, NULL, NULL)
            ),
            (yyvsp[-2].ast)
        ),
    NULL, NULL);
}
#line 2365 "src/parser/parser.tab.c"
    break;

  case 63:
#line 466 "src/parser/parser.y"
                                                                                              {
    (yyval.ast) = node(ForStatement,
        append_brother(
            append_brother(
                append_brother(
                    node(EmptyStatement, NULL, NULL, NULL),
                    (yyvsp[0].ast)
                ),
                (yyvsp[-3].ast)
            ),
            node(EmptyStatement, NULL, NULL, NULL)
        ),
    NULL, NULL);
}
#line 2384 "src/parser/parser.tab.c"
    break;

  case 64:
#line 480 "src/parser/parser.y"
                                                                                                               {
    (yyval.ast) = node(ForStatement,
        append_brother(
            append_brother(
                append_brother(
                    (yyvsp[-4].ast),
                    (yyvsp[0].ast)
                ),
                node(EmptyStatement, NULL, NULL, NULL)
            ),
            (yyvsp[-2].ast)
        ),
    NULL, NULL);
}
#line 2403 "src/parser/parser.tab.c"
    break;

  case 65:
#line 497 "src/parser/parser.y"
                                                                           {
    (yyval.ast) = node(ConditionalStatement,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2416 "src/parser/parser.tab.c"
    break;

  case 66:
#line 505 "src/parser/parser.y"
                                                                                                          {
    (yyval.ast) = node(ConditionalStatement,
        node(ElseCompound,
            append_brother(
                (yyvsp[-2].ast),
                (yyvsp[0].ast)
            ),
        (yyvsp[-4].ast), NULL),
    NULL, NULL);
}
#line 2431 "src/parser/parser.tab.c"
    break;

  case 67:
#line 518 "src/parser/parser.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2437 "src/parser/parser.tab.c"
    break;

  case 68:
#line 519 "src/parser/parser.y"
                                                                 {
    (yyval.ast) = node(MutableLocalDeclarationStatement, (yyvsp[-1].ast), NULL, (yyvsp[-3].string));
}
#line 2445 "src/parser/parser.tab.c"
    break;

  case 69:
#line 522 "src/parser/parser.y"
                                                                                {
    (yyval.ast) = node(MutableLocalDeclarationStatement,
        node(VariableTypeNode, (yyvsp[-3].ast), (yyvsp[-1].ast), NULL),
    NULL, (yyvsp[-4].string));
}
#line 2455 "src/parser/parser.tab.c"
    break;

  case 70:
#line 527 "src/parser/parser.y"
                                                        {
    (yyval.ast) = node(MutableLocalDeclarationStatement,
        node(VariableTypeNode, (yyvsp[-1].ast), NULL, NULL)
    , NULL, (yyvsp[-2].string));
}
#line 2465 "src/parser/parser.tab.c"
    break;

  case 71:
#line 535 "src/parser/parser.y"
                                                                 {
    (yyval.ast) = node(LocalDeclarationStatement, (yyvsp[-1].ast), NULL, (yyvsp[-3].string));
}
#line 2473 "src/parser/parser.tab.c"
    break;

  case 72:
#line 538 "src/parser/parser.y"
                                                                                {
    (yyval.ast) = node(LocalDeclarationStatement,
        node(VariableTypeNode, (yyvsp[-3].ast), (yyvsp[-1].ast), NULL)
    , NULL, (yyvsp[-4].string));
}
#line 2483 "src/parser/parser.tab.c"
    break;

  case 73:
#line 546 "src/parser/parser.y"
                                             {
    (yyval.ast) = node(ReturnStatement, (yyvsp[-1].ast), NULL, NULL);
}
#line 2491 "src/parser/parser.tab.c"
    break;

  case 74:
#line 549 "src/parser/parser.y"
                           {
    (yyval.ast) = node(ReturnStatement, NULL, NULL, NULL);
}
#line 2499 "src/parser/parser.tab.c"
    break;

  case 75:
#line 558 "src/parser/parser.y"
                         {
    (yyval.ast) = node(NumericImmediate, NULL, NULL, (yyvsp[0].string));
}
#line 2507 "src/parser/parser.tab.c"
    break;

  case 76:
#line 561 "src/parser/parser.y"
                   {
    (yyval.ast) = node(CharacterConstant, NULL, NULL, (yyvsp[0].string));
}
#line 2515 "src/parser/parser.tab.c"
    break;

  case 77:
#line 564 "src/parser/parser.y"
              {
    (yyval.ast) = (yyvsp[0].ast);
}
#line 2523 "src/parser/parser.tab.c"
    break;

  case 78:
#line 567 "src/parser/parser.y"
                                                                           {
    (yyval.ast) = node(Tenary, append_brother(append_brother((yyvsp[-4].ast), (yyvsp[-2].ast)), (yyvsp[0].ast)), NULL, NULL);
}
#line 2531 "src/parser/parser.tab.c"
    break;

  case 79:
#line 570 "src/parser/parser.y"
                    {
    (yyval.ast) = node(StringImmediate, NULL, NULL, (yyvsp[0].string));
}
#line 2539 "src/parser/parser.tab.c"
    break;

  case 80:
#line 573 "src/parser/parser.y"
                                              {
    (yyval.ast) = node(AddExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2552 "src/parser/parser.tab.c"
    break;

  case 81:
#line 581 "src/parser/parser.y"
                                            {
    (yyval.ast) = node(AddAssignExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2565 "src/parser/parser.tab.c"
    break;

  case 82:
#line 589 "src/parser/parser.y"
                                               {
    (yyval.ast) = node(SubtractExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2578 "src/parser/parser.tab.c"
    break;

  case 83:
#line 597 "src/parser/parser.y"
                                            {
    (yyval.ast) = node(SubtractAssignExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2591 "src/parser/parser.tab.c"
    break;

  case 84:
#line 605 "src/parser/parser.y"
                                              {
    (yyval.ast) = node(MultiplyExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2604 "src/parser/parser.tab.c"
    break;

  case 85:
#line 613 "src/parser/parser.y"
                                            {
    (yyval.ast) = node(MultiplyAssignExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2617 "src/parser/parser.tab.c"
    break;

  case 86:
#line 621 "src/parser/parser.y"
                                               {
    (yyval.ast) = node(DivideExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2630 "src/parser/parser.tab.c"
    break;

  case 87:
#line 629 "src/parser/parser.y"
                                            {
    (yyval.ast) = node(DivideAssignExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2643 "src/parser/parser.tab.c"
    break;

  case 88:
#line 637 "src/parser/parser.y"
                                             {
    (yyval.ast) = node(ModulusExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2656 "src/parser/parser.tab.c"
    break;

  case 89:
#line 645 "src/parser/parser.y"
                                            {
    (yyval.ast) = node(ModulusAssignExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2669 "src/parser/parser.tab.c"
    break;

  case 90:
#line 653 "src/parser/parser.y"
                                             {
    (yyval.ast) = node(LeftShiftExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2682 "src/parser/parser.tab.c"
    break;

  case 91:
#line 661 "src/parser/parser.y"
                                            {
    (yyval.ast) = node(LeftShiftAssignExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2695 "src/parser/parser.tab.c"
    break;

  case 92:
#line 669 "src/parser/parser.y"
                                             {
    (yyval.ast) = node(RightShiftExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2708 "src/parser/parser.tab.c"
    break;

  case 93:
#line 677 "src/parser/parser.y"
                                            {
    (yyval.ast) = node(RightShiftAssignExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2721 "src/parser/parser.tab.c"
    break;

  case 94:
#line 685 "src/parser/parser.y"
                                                 {
    (yyval.ast) = node(BitwiseAndExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2734 "src/parser/parser.tab.c"
    break;

  case 95:
#line 693 "src/parser/parser.y"
                                            {
    (yyval.ast) = node(BitwiseAndAssignExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2747 "src/parser/parser.tab.c"
    break;

  case 96:
#line 701 "src/parser/parser.y"
                                                {
    (yyval.ast) = node(BitwiseOrExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2760 "src/parser/parser.tab.c"
    break;

  case 97:
#line 709 "src/parser/parser.y"
                                           {
    (yyval.ast) = node(BitwiseOrAssignExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2773 "src/parser/parser.tab.c"
    break;

  case 98:
#line 717 "src/parser/parser.y"
                                                 {
    (yyval.ast) = node(LogicalAndExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2786 "src/parser/parser.tab.c"
    break;

  case 99:
#line 725 "src/parser/parser.y"
                                                {
    (yyval.ast) = node(LogicalOrExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2799 "src/parser/parser.tab.c"
    break;

  case 100:
#line 733 "src/parser/parser.y"
                                             {
    (yyval.ast) = node(BitwiseXorExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2812 "src/parser/parser.tab.c"
    break;

  case 101:
#line 741 "src/parser/parser.y"
                                            {
    (yyval.ast) = node(BitwiseXorAssignExpression,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, NULL);
}
#line 2825 "src/parser/parser.tab.c"
    break;

  case 102:
#line 749 "src/parser/parser.y"
                                                {
    (yyval.ast) = node(ComparisonExpresison,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, "==");
}
#line 2838 "src/parser/parser.tab.c"
    break;

  case 103:
#line 757 "src/parser/parser.y"
                                                {
    (yyval.ast) = node(ComparisonExpresison,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, ">=");
}
#line 2851 "src/parser/parser.tab.c"
    break;

  case 104:
#line 765 "src/parser/parser.y"
                                                {
    (yyval.ast) = node(ComparisonExpresison,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, ">");
}
#line 2864 "src/parser/parser.tab.c"
    break;

  case 105:
#line 773 "src/parser/parser.y"
                                                {
    (yyval.ast) = node(ComparisonExpresison,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, "<");
}
#line 2877 "src/parser/parser.tab.c"
    break;

  case 106:
#line 781 "src/parser/parser.y"
                                                {
    (yyval.ast) = node(ComparisonExpresison,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, "<=");
}
#line 2890 "src/parser/parser.tab.c"
    break;

  case 107:
#line 789 "src/parser/parser.y"
                                                {
    (yyval.ast) = node(ComparisonExpresison,
        append_brother(
            (yyvsp[-2].ast),
            (yyvsp[0].ast)
        ),
    NULL, "!=");
}
#line 2903 "src/parser/parser.tab.c"
    break;

  case 108:
#line 797 "src/parser/parser.y"
                             {
    (yyval.ast) = node(PostOp,
        (yyvsp[-1].ast),
    NULL, "++");
}
#line 2913 "src/parser/parser.tab.c"
    break;

  case 109:
#line 802 "src/parser/parser.y"
                             {
    (yyval.ast) = node(PreOp,
        (yyvsp[0].ast),
    NULL, "++");
}
#line 2923 "src/parser/parser.tab.c"
    break;

  case 110:
#line 807 "src/parser/parser.y"
                             {
    (yyval.ast) = node(PostOp,
        (yyvsp[-1].ast),
    NULL, "--");
}
#line 2933 "src/parser/parser.tab.c"
    break;

  case 111:
#line 812 "src/parser/parser.y"
                             {
    (yyval.ast) = node(PreOp,
        (yyvsp[0].ast),
    NULL, "--");
}
#line 2943 "src/parser/parser.tab.c"
    break;

  case 112:
#line 817 "src/parser/parser.y"
                            {
    (yyval.ast) = node(BitwiseNegationExpression,
        (yyvsp[0].ast),
    NULL, NULL);
}
#line 2953 "src/parser/parser.tab.c"
    break;

  case 113:
#line 822 "src/parser/parser.y"
                           {
    (yyval.ast) = node(LogicalNegationExpression,
        (yyvsp[0].ast),
    NULL, NULL);
}
#line 2963 "src/parser/parser.tab.c"
    break;

  case 114:
#line 827 "src/parser/parser.y"
                                      {
    (yyval.ast) = node(UnaryMinusExpression,
        (yyvsp[0].ast),
    NULL, NULL);
}
#line 2973 "src/parser/parser.tab.c"
    break;

  case 115:
#line 832 "src/parser/parser.y"
                                        {
    (yyval.ast) = node(AssignmentExpression,
        append_brother((yyvsp[-2].ast), (yyvsp[0].ast)),
    NULL, NULL);
}
#line 2983 "src/parser/parser.tab.c"
    break;

  case 116:
#line 837 "src/parser/parser.y"
                     {
    (yyval.ast) = (yyvsp[0].ast);
}
#line 2991 "src/parser/parser.tab.c"
    break;

  case 117:
#line 840 "src/parser/parser.y"
                                                {
    (yyval.ast) = (yyvsp[-1].ast);
}
#line 2999 "src/parser/parser.tab.c"
    break;

  case 118:
#line 846 "src/parser/parser.y"
                                                           {
    (yyval.ast) = node(FunctionCall, NULL, NULL, (yyvsp[-2].string));
}
#line 3007 "src/parser/parser.tab.c"
    break;

  case 119:
#line 849 "src/parser/parser.y"
                                                                                     {
    (yyval.ast) = node(FunctionCall, (yyvsp[-1].ast), NULL, (yyvsp[-3].string));
}
#line 3015 "src/parser/parser.tab.c"
    break;

  case 120:
#line 855 "src/parser/parser.y"
                       { (yyval.ast) = node(LValue, NULL, NULL, (yyvsp[0].string)); }
#line 3021 "src/parser/parser.tab.c"
    break;

  case 121:
#line 862 "src/parser/parser.y"
                                        {
    (yyval.ast) = append_brother((yyvsp[-2].ast), (yyvsp[0].ast));
}
#line 3029 "src/parser/parser.tab.c"
    break;

  case 122:
#line 865 "src/parser/parser.y"
             {
    (yyval.ast) = (yyvsp[0].ast);
}
#line 3037 "src/parser/parser.tab.c"
    break;


#line 3041 "src/parser/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 870 "src/parser/parser.y"


void yyerror(YYLTYPE * yyllocp, yyscan_t unused, const char * msg) {
    parser_error(msg, yyllocp->first_line, yyllocp->first_column);
}
