/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PLUS = 258,
     MINUS = 259,
     STAR = 260,
     SLASH = 261,
     PERCENT = 262,
     EQUAL = 263,
     NOTEQUAL = 264,
     LESSTHAN = 265,
     GREATERTHAN = 266,
     LESSTHANEQ = 267,
     GREATERTHANEQ = 268,
     AND = 269,
     OR = 270,
     NOT = 271,
     IDENTIFIER = 272,
     STR = 273,
     COMMA = 274,
     CHAR = 275,
     BIN = 276,
     HEX = 277,
     DEC = 278,
     TRUE = 279,
     FALSE = 280,
     IF = 281,
     ELSE = 282,
     WHILE = 283,
     DO = 284,
     BREAK = 285,
     SEMICOLON = 286,
     LPAREN = 287,
     RPAREN = 288,
     LBRACE = 289,
     RBRACE = 290,
     LBRACKET = 291,
     RBRACKET = 292,
     TYPEDEF = 293,
     ARRAY_COMMAS = 294
   };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define STAR 260
#define SLASH 261
#define PERCENT 262
#define EQUAL 263
#define NOTEQUAL 264
#define LESSTHAN 265
#define GREATERTHAN 266
#define LESSTHANEQ 267
#define GREATERTHANEQ 268
#define AND 269
#define OR 270
#define NOT 271
#define IDENTIFIER 272
#define STR 273
#define COMMA 274
#define CHAR 275
#define BIN 276
#define HEX 277
#define DEC 278
#define TRUE 279
#define FALSE 280
#define IF 281
#define ELSE 282
#define WHILE 283
#define DO 284
#define BREAK 285
#define SEMICOLON 286
#define LPAREN 287
#define RPAREN 288
#define LBRACE 289
#define RBRACE 290
#define LBRACKET 291
#define RBRACKET 292
#define TYPEDEF 293
#define ARRAY_COMMAS 294




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include "parser.tab.h"
#include "error.h"

#define YYDEBUG 1


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "parser.y"
{
    ASTNode* node;
}
/* Line 193 of yacc.c.  */
#line 185 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 198 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    18,    19,    21,
      25,    28,    30,    32,    34,    36,    38,    40,    42,    44,
      46,    48,    50,    52,    55,    59,    61,    63,    65,    69,
      76,    79,    82,    83,    86,    87,    91,    94,   100,   108,
     111,   114,   118,   120,   122,   124,   126,   128,   130,   132,
     134,   138,   142,   146,   150,   154,   159,   163,   167,   171,
     175,   179,   183,   187,   190,   193,   197,   202,   204,   205,
     209,   211,   216,   218,   220,   222,   224,   226,   228,   230
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    -1,    41,    42,    -1,    43,    57,    -1,
      43,    31,    -1,    45,    32,    44,    33,    -1,    -1,    45,
      -1,    45,    19,    44,    -1,    46,    17,    -1,    47,    -1,
      49,    -1,    50,    -1,    38,    -1,    53,    -1,    54,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,
      17,    -1,    46,    39,    -1,    52,    19,    51,    -1,    52,
      -1,    17,    -1,    62,    -1,    46,    51,    31,    -1,    26,
      32,    63,    33,    48,    55,    -1,    27,    54,    -1,    27,
      48,    -1,    -1,    48,    56,    -1,    -1,    34,    56,    35,
      -1,    34,    35,    -1,    28,    32,    63,    33,    48,    -1,
      29,    57,    28,    32,    63,    33,    31,    -1,    30,    31,
      -1,    63,    31,    -1,    63,     8,    63,    -1,    65,    -1,
      64,    -1,    66,    -1,    67,    -1,    70,    -1,    71,    -1,
      72,    -1,    62,    -1,    63,     3,    63,    -1,    63,     4,
      63,    -1,    63,     5,    63,    -1,    63,     6,    63,    -1,
      63,     7,    63,    -1,    63,     8,     8,    63,    -1,    63,
       9,    63,    -1,    63,    10,    63,    -1,    63,    11,    63,
      -1,    63,    12,    63,    -1,    63,    13,    63,    -1,    63,
      14,    63,    -1,    63,    15,    63,    -1,     4,    63,    -1,
      16,    63,    -1,    32,    63,    33,    -1,    17,    32,    68,
      33,    -1,    69,    -1,    -1,    63,    19,    69,    -1,    63,
      -1,    63,    36,    69,    37,    -1,    17,    -1,    24,    -1,
      25,    -1,    18,    -1,    20,    -1,    22,    -1,    21,    -1,
      23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    64,    66,    67,    71,    73,    74,    75,
      77,    81,    82,    83,    85,    88,    89,    90,    91,    92,
      93,    94,    99,   101,   104,   105,   107,   108,   110,   112,
     114,   115,   116,   118,   119,   121,   122,   124,   126,   128,
     130,   132,   134,   135,   136,   137,   138,   139,   140,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   157,   158,   160,   162,   163,   164,   166,
     167,   168,   170,   172,   173,   174,   175,   176,   177,   178
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "STAR", "SLASH",
  "PERCENT", "EQUAL", "NOTEQUAL", "LESSTHAN", "GREATERTHAN", "LESSTHANEQ",
  "GREATERTHANEQ", "AND", "OR", "NOT", "IDENTIFIER", "STR", "COMMA",
  "CHAR", "BIN", "HEX", "DEC", "TRUE", "FALSE", "IF", "ELSE", "WHILE",
  "DO", "BREAK", "SEMICOLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "TYPEDEF", "ARRAY_COMMAS", "$accept", "source",
  "sourceItem", "funcSignature", "listArgDef", "argDef", "typeRef",
  "builtin", "statement", "custom", "array", "listVarDeclared",
  "listVarDeclaredItem", "var", "if", "optionalElseStatement",
  "listStatement", "block", "while", "do", "break", "expression",
  "assignment", "expr", "binary", "unary", "braces", "call",
  "optionalListExpr", "listExpr", "indexer", "place", "literal", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    44,    44,    44,
      45,    46,    46,    46,    47,    48,    48,    48,    48,    48,
      48,    48,    49,    50,    51,    51,    52,    52,    53,    54,
      55,    55,    55,    56,    56,    57,    57,    58,    59,    60,
      61,    62,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    67,    68,    68,    69,
      69,    70,    71,    72,    72,    72,    72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     4,     0,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     1,     1,     3,     6,
       2,     2,     0,     2,     0,     3,     2,     5,     7,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     4,     1,     0,     3,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    22,    14,     3,     0,     0,     0,    11,
      12,    13,     5,     0,     4,     7,    10,    23,     0,     0,
      72,    75,    76,    78,    77,    79,    73,    74,     0,     0,
       0,     0,     0,    36,     0,    34,    15,    16,     0,    17,
      18,    19,    20,    21,    49,     0,    43,    42,    44,    45,
      46,    47,    48,     0,     8,    72,    63,    64,    68,     0,
       0,     0,    39,     0,    72,     0,    25,    49,     0,    33,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     6,     7,    70,     0,
      67,     0,     0,     0,    65,    28,     0,    50,    51,    52,
      53,    54,     0,    41,    56,    57,    58,    59,    60,    61,
      62,     0,     9,     0,    66,     0,     0,     0,    24,    55,
      71,    69,    32,    37,     0,     0,    29,     0,    31,    16,
      38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,     6,    53,    54,    34,     9,    35,    10,
      11,    65,    66,    36,    37,   126,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    89,    90,
      50,    51,    52
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -81
static const yytype_int16 yypact[] =
{
     -81,     5,   -81,   -81,   -81,   -81,   -21,   -24,    -2,   -81,
     -81,   -81,   -81,   108,   -81,    -5,   -81,   -81,   321,   321,
       7,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -14,     6,
      10,    16,   321,   -81,    84,   131,   -81,   -81,    13,   -81,
     -81,   -81,   -81,   -81,   -81,   167,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,    17,    30,    19,   282,   282,   321,   321,
     321,    24,   -81,   180,   -12,    37,    50,   -10,   282,   -81,
     -81,   321,   321,   321,   321,   321,   299,   321,   321,   321,
     321,   321,   321,   321,   -81,   321,   -81,    -5,   214,    38,
     -81,   231,   248,    40,   -81,   -81,   343,   282,   282,   282,
     282,   282,   321,   282,   282,   282,   282,   282,   282,   282,
     282,    33,   -81,   321,   -81,   131,   131,   321,   -81,   282,
     -81,   -81,    46,   -81,   265,   131,   -81,    43,   -81,   -81,
     -81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,   -81,   -11,    74,     2,   -81,   -80,   -81,
     -81,   -19,   -81,   -81,   -46,   -81,    45,    -4,   -81,   -81,
     -81,   -81,   -30,   -18,   -81,   -81,   -81,   -81,   -81,   -79,
     -81,   -81,   -81
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int16 yytable[] =
{
      56,    57,    14,     8,    67,     2,   111,   -26,    15,   -27,
      12,   -22,     3,    13,    63,    16,    68,     8,    59,   -26,
      58,   -27,     3,   -22,   -22,   -22,    61,   -22,   -22,   -22,
     -22,   -22,   -22,     4,   121,   122,   123,    17,    60,    58,
      88,    91,    92,     4,    13,   128,   -22,    62,    70,    87,
      86,    58,    93,    97,    98,    99,   100,   101,   103,   104,
     105,   106,   107,   108,   109,   110,    67,    88,    95,    96,
     120,   114,   117,   125,   130,     7,   112,   118,    68,   129,
      69,     0,     0,     0,   119,     0,     0,     0,    18,     8,
       0,     0,     0,     0,     0,    88,     0,     0,     0,   124,
      19,    64,    21,     0,    22,    23,    24,    25,    26,    27,
       0,     0,    18,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,    17,    19,    20,    21,     0,    22,    23,
      24,    25,    26,    27,    28,    18,    29,    30,    31,     0,
      32,     0,    13,    33,     0,     0,     4,    19,    20,    21,
       0,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      30,    31,     0,    32,     0,    13,     0,     0,     0,     4,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,    84,     0,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,    85,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,   113,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
      85,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   115,     0,     0,    85,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   116,     0,     0,    85,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   127,     0,
       0,    85,     0,    18,     0,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,    19,    55,    21,    85,    22,
      23,    24,    25,    26,    27,    18,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,    19,    55,    21,
       0,    22,    23,    24,    25,    26,    27,    18,     0,     0,
       0,     0,     0,    32,     0,     0,     0,     0,     0,    19,
      64,    21,     0,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,     0,     0,    32
};

static const yytype_int8 yycheck[] =
{
      18,    19,     6,     1,    34,     0,    85,    19,    32,    19,
      31,     4,    17,    34,    32,    17,    34,    15,    32,    31,
      32,    31,    17,    16,    17,    18,    30,    20,    21,    22,
      23,    24,    25,    38,   113,   115,   116,    39,    32,    32,
      58,    59,    60,    38,    34,   125,    39,    31,    35,    19,
      33,    32,    28,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    96,    85,    31,    19,
      37,    33,    32,    27,    31,     1,    87,    96,    96,   125,
      35,    -1,    -1,    -1,   102,    -1,    -1,    -1,     4,    87,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,
      16,    17,    18,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,     4,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    16,    17,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,     4,    28,    29,    30,    -1,
      32,    -1,    34,    35,    -1,    -1,    38,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,    -1,    32,    -1,    34,    -1,    -1,    -1,    38,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    36,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      36,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    33,    -1,    -1,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    33,    -1,    -1,    36,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    33,    -1,
      -1,    36,    -1,     4,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    36,    20,
      21,    22,    23,    24,    25,     4,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    25,     4,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,     0,    17,    38,    42,    43,    45,    46,    47,
      49,    50,    31,    34,    57,    32,    17,    39,     4,    16,
      17,    18,    20,    21,    22,    23,    24,    25,    26,    28,
      29,    30,    32,    35,    46,    48,    53,    54,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      70,    71,    72,    44,    45,    17,    63,    63,    32,    32,
      32,    57,    31,    63,    17,    51,    52,    62,    63,    56,
      35,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    31,    36,    33,    19,    63,    68,
      69,    63,    63,    28,    33,    31,    19,    63,    63,    63,
      63,    63,     8,    63,    63,    63,    63,    63,    63,    63,
      63,    69,    44,    19,    33,    33,    33,    32,    51,    63,
      37,    69,    48,    48,    63,    27,    55,    33,    48,    54,
      31
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 63 "parser.y"
    {{(yyval.node) = NULL;};}
    break;

  case 3:
#line 64 "parser.y"
    {{(yyval.node) = createNode("source", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), "");};}
    break;

  case 4:
#line 66 "parser.y"
    {{(yyval.node) = createNode(sourceItem, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), "");};}
    break;

  case 5:
#line 67 "parser.y"
    {{(yyval.node) = createNode(sourceItem, (yyvsp[(1) - (2)].node), NULL, "");};}
    break;

  case 6:
#line 71 "parser.y"
    {{(yyval.node) = createNode(funcSignature, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), "");};}
    break;

  case 7:
#line 73 "parser.y"
    {{(yyval.node) = NULL;};}
    break;

  case 8:
#line 74 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 9:
#line 75 "parser.y"
    {{(yyval.node) = createNode("listArgDef", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 10:
#line 77 "parser.y"
    {{(yyval.node) = createNode("argDef", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), "");};}
    break;

  case 11:
#line 81 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 12:
#line 82 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 13:
#line 83 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 14:
#line 85 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 15:
#line 88 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 16:
#line 89 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 17:
#line 90 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 18:
#line 91 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 19:
#line 92 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 20:
#line 93 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 21:
#line 94 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 22:
#line 99 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 23:
#line 101 "parser.y"
    {{(yyval.node) = createNode("array", (yyvsp[(1) - (2)].node), NULL, (yyvsp[(2) - (2)].node)->value);};}
    break;

  case 24:
#line 104 "parser.y"
    {{(yyval.node) = createNode("listVarDeclared", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 25:
#line 105 "parser.y"
    {{(yyval.node) = createNode("listVarDeclared", (yyvsp[(1) - (1)].node), NULL, "");};}
    break;

  case 26:
#line 107 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 27:
#line 108 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 28:
#line 110 "parser.y"
    {{(yyval.node) = createNode("var", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), "");};}
    break;

  case 29:
#line 112 "parser.y"
    {{(yyval.node) = createNode("if", (yyvsp[(3) - (6)].node), createNode("ifStatements", (yyvsp[(5) - (6)].node), (yyvsp[(6) - (6)].node), ""), "");};}
    break;

  case 30:
#line 114 "parser.y"
    {{(yyval.node) = createNode("elseif", (yyvsp[(2) - (2)].node), NULL, "");};}
    break;

  case 31:
#line 115 "parser.y"
    {{(yyval.node) = createNode("else", (yyvsp[(2) - (2)].node), NULL, "");};}
    break;

  case 32:
#line 116 "parser.y"
    {{(yyval.node) = NULL;};}
    break;

  case 33:
#line 118 "parser.y"
    {{(yyval.node) = createNode("listStatement", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), "");};}
    break;

  case 34:
#line 119 "parser.y"
    {{(yyval.node) = NULL;};}
    break;

  case 35:
#line 121 "parser.y"
    {{(yyval.node) = createNode("block", (yyvsp[(2) - (3)].node), NULL, "");};}
    break;

  case 36:
#line 122 "parser.y"
    {{(yyval.node) = createNode("block", NULL, NULL, "");};}
    break;

  case 37:
#line 124 "parser.y"
    {{(yyval.node) = createNode("while", (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), "");};}
    break;

  case 38:
#line 126 "parser.y"
    {{(yyval.node) = createNode("dowhile", (yyvsp[(2) - (7)].node), (yyvsp[(5) - (7)].node), "");};}
    break;

  case 39:
#line 128 "parser.y"
    {{(yyval.node) = createNode("break", NULL, NULL, "");};}
    break;

  case 40:
#line 130 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (2)].node);};}
    break;

  case 41:
#line 132 "parser.y"
    {{(yyval.node) = createNode("assigment", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 42:
#line 134 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 43:
#line 135 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 44:
#line 136 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 45:
#line 137 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 46:
#line 138 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 47:
#line 139 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 48:
#line 140 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 50:
#line 143 "parser.y"
    {{(yyval.node) = createNode("PLUS", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 51:
#line 144 "parser.y"
    {{(yyval.node) = createNode("MINUS", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 52:
#line 145 "parser.y"
    {{(yyval.node) = createNode("STAR", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 53:
#line 146 "parser.y"
    {{(yyval.node) = createNode("SLASH", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 54:
#line 147 "parser.y"
    {{(yyval.node) = createNode("PERCENT", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 55:
#line 148 "parser.y"
    {{(yyval.node) = createNode("EQUALITY", (yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node), "");};}
    break;

  case 56:
#line 149 "parser.y"
    {{(yyval.node) = createNode("NOTEQUAL", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 57:
#line 150 "parser.y"
    {{(yyval.node) = createNode("LESSTHAN", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 58:
#line 151 "parser.y"
    {{(yyval.node) = createNode("GREATERTHAN", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 59:
#line 152 "parser.y"
    {{(yyval.node) = createNode("LESSTHANEQ", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 60:
#line 153 "parser.y"
    {{(yyval.node) = createNode("GREATERTHANEQ", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 61:
#line 154 "parser.y"
    {{(yyval.node) = createNode("AND", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 62:
#line 155 "parser.y"
    {{(yyval.node) = createNode("OR", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 63:
#line 157 "parser.y"
    {{(yyval.node) = createNode("MINUS_UNARY", (yyvsp[(2) - (2)].node), NULL, "");};}
    break;

  case 64:
#line 158 "parser.y"
    {{(yyval.node) = createNode("NOT", (yyvsp[(2) - (2)].node), NULL, "");};}
    break;

  case 65:
#line 160 "parser.y"
    {{(yyval.node) = createNode("braces", (yyvsp[(2) - (3)].node), NULL, "");};}
    break;

  case 66:
#line 162 "parser.y"
    {{(yyval.node) = createNode("CALL", (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), "");};}
    break;

  case 67:
#line 163 "parser.y"
    {{(yyval.node) = createNode("optionalListExpr", (yyvsp[(1) - (1)].node), NULL, "");};}
    break;

  case 68:
#line 164 "parser.y"
    {{(yyval.node) = createNode("optionalListExpr", NULL, NULL, "");};}
    break;

  case 69:
#line 166 "parser.y"
    {{(yyval.node) = createNode("listExpr", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 70:
#line 167 "parser.y"
    {{(yyval.node) = createNode("listExpr", (yyvsp[(1) - (1)].node), NULL, "");};}
    break;

  case 71:
#line 168 "parser.y"
    {{(yyval.node) = createNode("indexer", (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), "");};}
    break;

  case 72:
#line 170 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 73:
#line 172 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 74:
#line 173 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 75:
#line 174 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 76:
#line 175 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 77:
#line 176 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 78:
#line 177 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 79:
#line 178 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;


/* Line 1267 of yacc.c.  */
#line 1949 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 179 "parser.y"


