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
     PROGRAM = 258,
     ELSE = 259,
     WHILE = 260,
     DO = 261,
     THEN = 262,
     IF = 263,
     OF = 264,
     FUNCTION = 265,
     PROCEDURE = 266,
     begin = 267,
     END = 268,
     ARRAY = 269,
     VAR = 270,
     NOT = 271,
     STRING = 272,
     ASSIGNMENT = 273,
     COLON = 274,
     COMMA = 275,
     INTEGER = 276,
     DOT = 277,
     DOTDOT = 278,
     EQUAL = 279,
     notEQUAL = 280,
     GE = 281,
     GT = 282,
     LBRAC = 283,
     LE = 284,
     LPAREN = 285,
     LT = 286,
     MINUS = 287,
     PLUS = 288,
     RBRAC = 289,
     REAL = 290,
     RPAREN = 291,
     SEMICOLON = 292,
     SLASH = 293,
     STAR = 294,
     CHAR = 295,
     NUM = 296,
     TOK_REL_OP = 297,
     String = 298,
     Char = 299,
     ID = 300
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define ELSE 259
#define WHILE 260
#define DO 261
#define THEN 262
#define IF 263
#define OF 264
#define FUNCTION 265
#define PROCEDURE 266
#define begin 267
#define END 268
#define ARRAY 269
#define VAR 270
#define NOT 271
#define STRING 272
#define ASSIGNMENT 273
#define COLON 274
#define COMMA 275
#define INTEGER 276
#define DOT 277
#define DOTDOT 278
#define EQUAL 279
#define notEQUAL 280
#define GE 281
#define GT 282
#define LBRAC 283
#define LE 284
#define LPAREN 285
#define LT 286
#define MINUS 287
#define PLUS 288
#define RBRAC 289
#define REAL 290
#define RPAREN 291
#define SEMICOLON 292
#define SLASH 293
#define STAR 294
#define CHAR 295
#define NUM 296
#define TOK_REL_OP 297
#define String 298
#define Char 299
#define ID 300




/* Copy the first part of user declarations.  */
#line 1 "pascal.y"

/***************
*input type:String,Char,NUM
*number:int,float,scientific
****************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "symtab.h"
//#include "symtab.c"
//#include "node.c"

extern int line_no;
int yydebug=1;
int yylex();
struct nodeType* newOpNode(int op);
extern struct nodeType* ASTRoot;


void yyerror (char const *s){
    extern char *yytext;
    extern int line_no;
    fprintf (stderr, "%s: at line %d symbol'%s'\n", s,line_no,yytext);
 }


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 30 "pascal.y"
{
    struct nodeType *node;
}
/* Line 193 of yacc.c.  */
#line 216 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 229 "y.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   113

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  125

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    14,    16,    20,    27,    28,    30,    39,
      41,    43,    45,    47,    51,    52,    56,    63,    68,    72,
      73,    78,    85,    87,    88,    92,    94,    96,   100,   104,
     106,   108,   115,   120,   121,   124,   129,   130,   132,   137,
     139,   143,   145,   149,   151,   155,   157,   161,   164,   169,
     171,   173,   175,   179,   182,   184,   186,   188,   190,   192,
     194,   196,   198,   200
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,     3,    45,    30,    48,    36,    37,    49,
      52,    58,    22,    -1,    45,    -1,    48,    20,    45,    -1,
      49,    15,    48,    19,    50,    37,    -1,    -1,    51,    -1,
      14,    28,    41,    23,    41,    34,     9,    50,    -1,    21,
      -1,    35,    -1,    17,    -1,    40,    -1,    52,    53,    37,
      -1,    -1,    54,    49,    58,    -1,    10,    45,    55,    19,
      51,    37,    -1,    11,    45,    55,    37,    -1,    30,    56,
      36,    -1,    -1,    57,    48,    19,    50,    -1,    57,    48,
      19,    50,    37,    56,    -1,    15,    -1,    -1,    12,    59,
      13,    -1,    60,    -1,    61,    -1,    60,    37,    61,    -1,
      62,    18,    66,    -1,    64,    -1,    58,    -1,     8,    66,
       7,    61,     4,    61,    -1,     5,    66,     6,    61,    -1,
      -1,    45,    63,    -1,    28,    66,    34,    63,    -1,    -1,
      45,    -1,    45,    30,    65,    36,    -1,    66,    -1,    65,
      20,    66,    -1,    67,    -1,    67,    72,    67,    -1,    68,
      -1,    67,    70,    68,    -1,    69,    -1,    68,    71,    69,
      -1,    45,    63,    -1,    45,    30,    65,    36,    -1,    41,
      -1,    43,    -1,    44,    -1,    30,    66,    36,    -1,    16,
      69,    -1,    33,    -1,    32,    -1,    39,    -1,    38,    -1,
      31,    -1,    27,    -1,    24,    -1,    29,    -1,    26,    -1,
      25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    72,    80,    89,   100,   106,   110,   128,
     133,   138,   143,   150,   156,   162,   171,   182,   193,   199,
     206,   213,   224,   228,   234,   245,   252,   256,   265,   272,
     277,   281,   291,   299,   306,   315,   323,   330,   337,   350,
     354,   363,   368,   377,   382,   391,   395,   404,   410,   420,
     425,   430,   435,   441,   454,   460,   469,   475,   485,   491,
     497,   503,   509,   515
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ELSE", "WHILE", "DO", "THEN",
  "IF", "OF", "FUNCTION", "PROCEDURE", "begin", "END", "ARRAY", "VAR",
  "NOT", "STRING", "ASSIGNMENT", "COLON", "COMMA", "INTEGER", "DOT",
  "DOTDOT", "EQUAL", "notEQUAL", "GE", "GT", "LBRAC", "LE", "LPAREN", "LT",
  "MINUS", "PLUS", "RBRAC", "REAL", "RPAREN", "SEMICOLON", "SLASH", "STAR",
  "CHAR", "NUM", "TOK_REL_OP", "String", "Char", "ID", "$accept", "prog",
  "identifier_list", "declarations", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "arguments", "parameter_list", "optional_var", "compound_statement",
  "optional_statements", "statement_list", "statement", "variable", "tail",
  "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", "addop", "mulop", "relop", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     0,     1,     8,     1,
       1,     1,     1,     3,     0,     3,     6,     4,     3,     0,
       4,     6,     1,     0,     3,     1,     1,     3,     3,     1,
       1,     6,     4,     0,     2,     4,     0,     1,     4,     1,
       3,     1,     3,     1,     3,     1,     3,     2,     4,     1,
       1,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       4,     6,    14,     0,     0,     0,     0,     0,    33,     0,
       6,     0,     0,    19,    19,     0,     0,    37,    30,     0,
      25,    26,     0,    29,    13,     0,     2,     0,    11,     9,
      10,    12,     0,     7,    23,     0,     0,     0,     0,    49,
      50,    51,    36,     0,    41,    43,    45,     0,     0,     0,
      34,    24,    33,     0,    15,     0,     5,    22,     0,     0,
       0,    17,    53,     0,     0,    47,    33,    60,    63,    62,
      59,    61,    58,    55,    54,     0,     0,    57,    56,     0,
      33,     0,     0,    39,    27,    28,     0,    18,     0,     0,
      52,     0,    32,    44,    42,    46,     0,    36,     0,    38,
       0,     0,    16,    48,    33,    35,    40,     0,    20,    31,
       0,    23,     0,    21,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    12,    42,    43,    14,    19,    20,    45,
      68,    69,    28,    29,    30,    31,    32,    60,    33,    92,
      93,    54,    55,    56,    85,    89,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int8 yypact[] =
{
      17,   -18,    50,    45,   -71,    19,   -71,   -12,    31,    29,
     -71,   -71,    62,    19,    60,    34,    33,    35,     1,    42,
     -71,    59,     5,    52,    52,    -9,    -9,    21,   -71,    71,
      48,   -71,    68,   -71,   -71,     3,   -71,    61,   -71,   -71,
     -71,   -71,    51,   -71,    72,    73,    53,    -9,    -9,   -71,
     -71,   -71,    14,    85,    36,   -28,   -71,    86,    -9,    -9,
     -71,   -71,     1,    -9,   -71,    54,   -71,   -71,    58,    19,
       8,   -71,   -71,    63,    -9,   -71,     1,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,    -9,    -9,   -71,   -71,    -9,
       1,    64,    -8,   -71,   -71,   -71,    74,   -71,    37,    65,
     -71,    -6,   -71,   -28,    41,   -71,    92,    75,    -9,   -71,
      66,     5,   -71,   -71,     1,   -71,   -71,    67,    69,   -71,
      91,    72,     5,   -71,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -11,    84,   -70,    38,   -71,   -71,   -71,    81,
     -10,   -71,     2,   -71,   -71,   -59,   -71,   -48,   -71,    39,
     -25,    23,    25,   -42,   -71,   -71,   -71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -37
static const yytype_int8 yytable[] =
{
      53,    57,    15,    94,    75,    72,    25,    47,     8,    26,
      87,    88,   108,    18,   108,    18,    21,   102,    13,    37,
       1,    48,    38,    73,     9,    38,    39,     3,   109,    39,
     113,   106,    49,    91,    50,    51,    52,    64,    95,   -36,
      40,   118,    58,    40,    74,    41,    27,   105,    41,    58,
       4,    59,   124,    22,     8,   119,   111,     8,    98,   115,
      77,    78,    79,    80,     6,    81,    11,    82,    83,    84,
      16,    17,    18,    83,    84,     5,    10,    13,    23,    34,
      24,    36,    44,   116,    61,    62,    63,    67,    66,    65,
      71,    76,    70,    90,    97,    96,   114,   110,   107,   100,
     122,   120,   112,    58,    35,    46,   121,   117,    99,   104,
     103,   123,     0,   101
};

static const yytype_int8 yycheck[] =
{
      25,    26,    13,    62,    52,    47,     5,    16,    20,     8,
      38,    39,    20,    12,    20,    12,    14,    76,    15,    14,
       3,    30,    17,    48,    36,    17,    21,    45,    36,    21,
      36,    90,    41,    58,    43,    44,    45,    35,    63,    18,
      35,   111,    28,    35,    30,    40,    45,    89,    40,    28,
       0,    30,   122,    19,    20,   114,    19,    20,    69,   107,
      24,    25,    26,    27,    45,    29,    37,    31,    32,    33,
      10,    11,    12,    32,    33,    30,    45,    15,    45,    37,
      45,    22,    30,   108,    13,    37,    18,    15,    37,    28,
      37,     6,    19,     7,    36,    41,     4,    23,    34,    36,
       9,    34,    37,    28,    20,    24,    37,    41,    70,    86,
      85,   121,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    47,    45,     0,    30,    45,    48,    20,    36,
      45,    37,    49,    15,    52,    48,    10,    11,    12,    53,
      54,    58,    19,    45,    45,     5,     8,    45,    58,    59,
      60,    61,    62,    64,    37,    49,    22,    14,    17,    21,
      35,    40,    50,    51,    30,    55,    55,    16,    30,    41,
      43,    44,    45,    66,    67,    68,    69,    66,    28,    30,
      63,    13,    37,    18,    58,    28,    37,    15,    56,    57,
      19,    37,    69,    66,    30,    63,     6,    24,    25,    26,
      27,    29,    31,    32,    33,    70,    72,    38,    39,    71,
       7,    66,    65,    66,    61,    66,    41,    36,    48,    51,
      36,    65,    61,    68,    67,    69,    61,    34,    20,    36,
      23,    19,    37,    36,     4,    63,    66,    41,    50,    61,
      34,    37,     9,    56,    50
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
#line 55 "pascal.y"
    {
        (yyval.node)=newNode(NODE_prog);
        //addChild($$,$4);
        addChild((yyval.node),(yyvsp[(7) - (10)].node));
        addChild((yyval.node),(yyvsp[(8) - (10)].node));
        addChild((yyval.node),(yyvsp[(9) - (10)].node));
        ASTRoot = (yyval.node);
        deleteNode((yyvsp[(1) - (10)].node));
        deleteNode((yyvsp[(3) - (10)].node));
        deleteNode((yyvsp[(5) - (10)].node));
        deleteNode((yyvsp[(6) - (10)].node));
        deleteNode((yyvsp[(10) - (10)].node));
        printf("Reduction(prog -> PROGRAM ID ( identifier_list ) ; declartions subprogram_declartions");
        printf("compound_statement.)\n"); 
      }
    break;

  case 3:
#line 72 "pascal.y"
    {
      (yyval.node)=newNode(NODE_identifier_list);
      (yyval.node)->lineno=line_no;
      printf("lineno:%d",(yyval.node)->lineno);
      (yyvsp[(1) - (1)].node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[(1) - (1)].node));
      printf("Reduction(identifier_list -> ID)\n");
    }
    break;

  case 4:
#line 80 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (3)].node);
      (yyvsp[(3) - (3)].node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[(3) - (3)].node));
      deleteNode((yyvsp[(2) - (3)].node));
      printf("Reduction(identifier_list -> identifier_list , ID)\n");
    }
    break;

  case 5:
#line 89 "pascal.y"
    {
      //$$=$1; 
      (yyval.node)=newNode(NODE_declarations);
      addChild((yyval.node),(yyvsp[(1) - (6)].node));     
      addChild((yyval.node),(yyvsp[(3) - (6)].node));
      addChild((yyval.node),(yyvsp[(5) - (6)].node));
      deleteNode((yyvsp[(2) - (6)].node));
      deleteNode((yyvsp[(4) - (6)].node));
      deleteNode((yyvsp[(6) - (6)].node));
      printf("Reduction(declartions -> declarations VAR identifier_list : type ;)\n");
    }
    break;

  case 6:
#line 100 "pascal.y"
    {
      (yyval.node)=newNode(NODE_declarations);
      printf("Reduction(declartions -> )\n");
    }
    break;

  case 7:
#line 106 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      printf("Reduction(type -> standard_type)\n");
    }
    break;

  case 8:
#line 110 "pascal.y"
    { 
      (yyval.node)=(yyvsp[(1) - (8)].node);
      (yyval.node)->nodeType=NODE_TYPE_ARRAY;
      (yyvsp[(3) - (8)].node)->nodeType = NODE_NUM;//init value
      addChild((yyval.node),(yyvsp[(3) - (8)].node));
      (yyvsp[(5) - (8)].node)->nodeType = NODE_NUM;//size of array
      addChild((yyval.node),(yyvsp[(5) - (8)].node));
      addChild((yyval.node),(yyvsp[(8) - (8)].node));//type of array

      deleteNode((yyvsp[(2) - (8)].node));
      deleteNode((yyvsp[(4) - (8)].node));
      deleteNode((yyvsp[(6) - (8)].node));
      deleteNode((yyvsp[(7) - (8)].node));

      printf("Reduction(type -> ARRAY ( NUM .. NUM ) OF type)\n");
    }
    break;

  case 9:
#line 128 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      (yyval.node)->nodeType = NODE_TYPE_INT;
      printf("Reduction(standard_type -> INTEGER)\n");
    }
    break;

  case 10:
#line 133 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      (yyval.node)->nodeType = NODE_TYPE_REAL;
      printf("Reduction(standard_type -> REAL)\n");
    }
    break;

  case 11:
#line 138 "pascal.y"
    {
        (yyval.node)=(yyvsp[(1) - (1)].node);
        (yyval.node)->nodeType = NODE_TYPE_STRING;
        printf("Reduction(standard_type -> STRING)\n");
      }
    break;

  case 12:
#line 143 "pascal.y"
    {
        (yyval.node)=(yyvsp[(1) - (1)].node);
        (yyval.node)->nodeType = NODE_TYPE_CHAR;
        printf("Reduction(standard_type -> CHAR)\n");
      }
    break;

  case 13:
#line 150 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (3)].node);
      addChild((yyval.node),(yyvsp[(2) - (3)].node));
      deleteNode((yyvsp[(3) - (3)].node));
      printf("Reduction(subprogram_declarations -> subprogram_declarations subprogram_declaration ;)\n"); 
    }
    break;

  case 14:
#line 156 "pascal.y"
    {
      (yyval.node)=newNode(NODE_subprogram_declarations);
      printf("Reduction(subprogram_declarations -> )\n"); 
    }
    break;

  case 15:
#line 162 "pascal.y"
    {
              (yyval.node)=newNode(NODE_subprogram_declaration);
              addChild((yyval.node),(yyvsp[(1) - (3)].node));
              addChild((yyval.node),(yyvsp[(2) - (3)].node));
              addChild((yyval.node),(yyvsp[(3) - (3)].node));
              printf("Reduction(subprogram_declaration -> subprogram_head declarations compound_statement)\n"); 
            }
    break;

  case 16:
#line 171 "pascal.y"
    {//funcion declaration
      (yyval.node)=newNode(NODE_subprogram_head);
      (yyvsp[(2) - (6)].node)->nodeType=NODE_FUNCTION;
      addChild((yyval.node),(yyvsp[(2) - (6)].node));
      addChild((yyval.node),(yyvsp[(5) - (6)].node));
      addChild((yyval.node),(yyvsp[(3) - (6)].node));
      deleteNode((yyvsp[(1) - (6)].node));
      deleteNode((yyvsp[(4) - (6)].node));
      deleteNode((yyvsp[(6) - (6)].node));
      printf("Reduction(subprogram_head -> FUNCTION ID arguments : standard_type ;)\n");  
    }
    break;

  case 17:
#line 182 "pascal.y"
    {//procedure declaration
      (yyval.node)=newNode(NODE_subprogram_head);
      (yyvsp[(2) - (4)].node)->nodeType=NODE_PROCEDURE;
      addChild((yyval.node),(yyvsp[(2) - (4)].node));
      addChild((yyval.node),(yyvsp[(3) - (4)].node));
      deleteNode((yyvsp[(1) - (4)].node));
      printf("Reduction(subprogram_head -> PROCEDURE ID arguments)\n"); 
    }
    break;

  case 18:
#line 193 "pascal.y"
    {
      (yyval.node)=(yyvsp[(2) - (3)].node);
      deleteNode((yyvsp[(1) - (3)].node));
      deleteNode((yyvsp[(3) - (3)].node));
      printf("Reduction(arguments -> ( parameter_list ) )\n");
    }
    break;

  case 19:
#line 199 "pascal.y"
    {
      (yyval.node)=newNode(NODE_arguments);  
      printf("Reduction(arguments ->  )\n");
    }
    break;

  case 20:
#line 206 "pascal.y"
    {
      (yyval.node)=newNode(NODE_parameter_list);
      addChild((yyval.node),(yyvsp[(2) - (4)].node));
      addChild((yyval.node),(yyvsp[(4) - (4)].node));
      deleteNode((yyvsp[(3) - (4)].node));
      printf("Reduction(parameter_list -> optional_var identifier_list : type )\n");
    }
    break;

  case 21:
#line 213 "pascal.y"
    {
      (yyval.node)=newNode(NODE_parameter_list);
      addChild((yyval.node),(yyvsp[(2) - (6)].node));
      addChild((yyval.node),(yyvsp[(4) - (6)].node));
      addChild((yyval.node),(yyvsp[(6) - (6)].node));
      deleteNode((yyvsp[(3) - (6)].node));
      deleteNode((yyvsp[(5) - (6)].node));
      printf("Reduction(parameter_list -> optional_var identifier_list : type ; parameter_list )\n");
    }
    break;

  case 22:
#line 224 "pascal.y"
    {
        
        printf("Reduction(optional_var -> VAR )\n");
      }
    break;

  case 23:
#line 228 "pascal.y"
    {
         
        printf("Reduction(optional_var ->  )\n");
      }
    break;

  case 24:
#line 234 "pascal.y"
    {
      (yyval.node)=(yyvsp[(2) - (3)].node);
      (yyvsp[(3) - (3)].node)->nodeType=NODE_END;
      addChild((yyval.node),(yyvsp[(3) - (3)].node));
      deleteNode((yyvsp[(1) - (3)].node));
      printf("Reduction(compound_statement -> begin optional_statements END )\n");
    }
    break;

  case 25:
#line 245 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      printf("Reduction(optional_statements -> statement_list )\n");
    }
    break;

  case 26:
#line 252 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      printf("Reduction(statements_list -> statement )\n");
    }
    break;

  case 27:
#line 256 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (3)].node);
      addChild((yyval.node),(yyvsp[(3) - (3)].node));
      deleteNode((yyvsp[(2) - (3)].node));
      printf("Reduction(statements_list -> statement_list ; statement )\n");
    }
    break;

  case 28:
#line 265 "pascal.y"
    {
      (yyval.node)=(yyvsp[(2) - (3)].node);
      (yyval.node)->nodeType=NODE_ASSIGNMENT;
      addChild((yyval.node),(yyvsp[(1) - (3)].node));
      addChild((yyval.node),(yyvsp[(3) - (3)].node));
      printf("Reduction(statement -> variable := expression )\n");  
    }
    break;

  case 29:
#line 272 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);

      printf("Reduction(statement -> procedure_statement )\n");
    }
    break;

  case 30:
#line 277 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      printf("Reduction(statement -> compound_statement )\n");
    }
    break;

  case 31:
#line 281 "pascal.y"
    {
      (yyval.node)=newNode(NODE_statement);
      addChild((yyval.node),(yyvsp[(2) - (6)].node));
      addChild((yyval.node),(yyvsp[(4) - (6)].node));
      addChild((yyval.node),(yyvsp[(6) - (6)].node));
      deleteNode((yyvsp[(1) - (6)].node));
      deleteNode((yyvsp[(3) - (6)].node));
      deleteNode((yyvsp[(5) - (6)].node));
      printf("Reduction(statement -> IF expression THEN statement ELSE statement )\n");
    }
    break;

  case 32:
#line 291 "pascal.y"
    {
      (yyval.node)=newNode(NODE_statement);
      addChild((yyval.node),(yyvsp[(2) - (4)].node));
      addChild((yyval.node),(yyvsp[(4) - (4)].node));
      deleteNode((yyvsp[(1) - (4)].node));
      deleteNode((yyvsp[(3) - (4)].node));
      printf("Reduction(statement -> WHILE expression DO statement )\n");
    }
    break;

  case 33:
#line 299 "pascal.y"
    {
      (yyval.node)=newNode(NODE_statement);
      printf("Reduction(statement ->  )\n");
    }
    break;

  case 34:
#line 306 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (2)].node);
      (yyvsp[(1) - (2)].node)->nodeType=NODE_SYM_REF;
      addChild((yyval.node),(yyvsp[(2) - (2)].node));
      printf("Reduction(variable -> ID tail )\n");
    }
    break;

  case 35:
#line 315 "pascal.y"
    {
      (yyval.node)=(yyvsp[(2) - (4)].node);

      addChild((yyval.node),(yyvsp[(4) - (4)].node));
      deleteNode((yyvsp[(1) - (4)].node));
      deleteNode((yyvsp[(3) - (4)].node));
      printf("Reduction(tail -> ( expression ) tail )\n");
    }
    break;

  case 36:
#line 323 "pascal.y"
    {
      (yyval.node)=newNode(NODE_tail);  
      printf("Reduction(tail -> )\n");  
    }
    break;

  case 37:
#line 330 "pascal.y"
    {
      (yyval.node)=newNode(NODE_procedure_statement);
      (yyvsp[(1) - (1)].node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[(1) - (1)].node));
      printf("procedureid:%s\n",(yyvsp[(1) - (1)].node)->string);
      printf("Reduction(procedure_statement -> ID )\n");
    }
    break;

  case 38:
#line 337 "pascal.y"
    {
      (yyval.node)=newNode(NODE_procedure_statement);
      (yyvsp[(1) - (4)].node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[(1) - (4)].node));
      addChild((yyval.node),(yyvsp[(3) - (4)].node));
      deleteNode((yyvsp[(2) - (4)].node));
      deleteNode((yyvsp[(4) - (4)].node));
      printf("procedureid:%s\n",(yyvsp[(1) - (4)].node)->string);
      printf("Reduction(procedure_statement -> ID ( expression_list ) )\n");
    }
    break;

  case 39:
#line 350 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      printf("Reduction(expression_list -> expression )\n");
    }
    break;

  case 40:
#line 354 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (3)].node);
      addChild((yyval.node),(yyvsp[(3) - (3)].node));
      deleteNode((yyvsp[(2) - (3)].node));
      printf("Reduction(expression_list -> expression_list COMMA expression )\n");
    }
    break;

  case 41:
#line 363 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      
      printf("Reduction(expression -> simple_expression )\n");
    }
    break;

  case 42:
#line 368 "pascal.y"
    {
      (yyval.node)=(yyvsp[(2) - (3)].node);
      addChild((yyval.node),(yyvsp[(1) - (3)].node));
      addChild((yyval.node),(yyvsp[(3) - (3)].node));
      printf("Reduction(expression -> simple_expression relop simple_expression )\n");
    }
    break;

  case 43:
#line 377 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);

      printf("Reduction(simple_expression -> term )\n");
    }
    break;

  case 44:
#line 382 "pascal.y"
    {
      (yyval.node)=(yyvsp[(2) - (3)].node);
      addChild((yyval.node),(yyvsp[(1) - (3)].node));
      addChild((yyval.node),(yyvsp[(3) - (3)].node));
      printf("Reduction(simple_expression -> simple_expression addop term )\n");
    }
    break;

  case 45:
#line 391 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      printf("Reduction(term -> factor )\n");
    }
    break;

  case 46:
#line 395 "pascal.y"
    {
      (yyval.node)=(yyvsp[(2) - (3)].node);
      addChild((yyval.node),(yyvsp[(1) - (3)].node));
      addChild((yyval.node),(yyvsp[(3) - (3)].node));
      printf("Reduction(term -> term mulop factor )\n");
    }
    break;

  case 47:
#line 404 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (2)].node);
      (yyval.node)->nodeType=NODE_ID;
      addChild((yyval.node),(yyvsp[(2) - (2)].node));
      printf("Reduction(factor -> ID tail )\n");
    }
    break;

  case 48:
#line 410 "pascal.y"
    {
      //$$=newNode(NODE_factor);
      (yyval.node)=(yyvsp[(1) - (4)].node);
      (yyval.node)->nodeType=NODE_ID;
      //addChild($$,$1);
      addChild((yyval.node),(yyvsp[(3) - (4)].node));
      deleteNode((yyvsp[(2) - (4)].node));
      deleteNode((yyvsp[(4) - (4)].node));
      printf("Reduction(factor -> ID ( expression_list ) )\n");
    }
    break;

  case 49:
#line 420 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      (yyval.node)->nodeType=NODE_NUM;
      printf("Reduction(factor -> NUM )\n");
    }
    break;

  case 50:
#line 425 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      (yyval.node)->nodeType=NODE_String;
      printf("Reduction(factor -> String )\n");
    }
    break;

  case 51:
#line 430 "pascal.y"
    {
      (yyval.node)=(yyvsp[(1) - (1)].node);
      (yyval.node)->nodeType=NODE_Char;
      printf("Reduction(factor -> Char )\n");
    }
    break;

  case 52:
#line 435 "pascal.y"
    {
      (yyval.node)=(yyvsp[(2) - (3)].node);
      deleteNode((yyvsp[(1) - (3)].node));
      deleteNode((yyvsp[(3) - (3)].node));
      printf("Reduction(factor -> ( expression ) )\n");
    }
    break;

  case 53:
#line 441 "pascal.y"
    {
      (yyval.node)=newNode(NODE_factor);
      int lineno=(yyvsp[(1) - (2)].node)->lineno;
      (yyvsp[(1) - (2)].node)=newOpNode(OP_NOT);
      (yyvsp[(1) - (2)].node)->lineno=lineno;

      addChild((yyval.node),(yyvsp[(1) - (2)].node));
      addChild((yyval.node),(yyvsp[(2) - (2)].node));
      printf("Reduction(factor -> ( NOT factor ) )\n");
    }
    break;

  case 54:
#line 454 "pascal.y"
    {
      (yyval.node)=newOpNode(OP_PLUS);
      (yyval.node)->lineno=(yyvsp[(1) - (1)].node)->lineno;
      deleteNode((yyvsp[(1) - (1)].node));
      printf("Reduction(addop -> PLUS )\n");
    }
    break;

  case 55:
#line 460 "pascal.y"
    {
      (yyval.node)=newOpNode(OP_MINUS);
      (yyval.node)->lineno=(yyvsp[(1) - (1)].node)->lineno;
      deleteNode((yyvsp[(1) - (1)].node));
      printf("Reduction(addop -> MINUS )\n");
    }
    break;

  case 56:
#line 469 "pascal.y"
    {
      (yyval.node)=newOpNode(OP_MUL);
      (yyval.node)->lineno=(yyvsp[(1) - (1)].node)->lineno;
      deleteNode((yyvsp[(1) - (1)].node));
      printf("Reduction(mulop -> STAR )\n");
    }
    break;

  case 57:
#line 475 "pascal.y"
    {
      (yyval.node)=newOpNode(OP_SLASH);
      (yyval.node)->lineno=(yyvsp[(1) - (1)].node)->lineno;
      deleteNode((yyvsp[(1) - (1)].node));
      printf("Reduction(mulop -> SLASH )\n");
    }
    break;

  case 58:
#line 485 "pascal.y"
    {
      (yyval.node)=newOpNode(OP_LT);
      (yyval.node)->lineno=(yyvsp[(1) - (1)].node)->lineno;
      deleteNode((yyvsp[(1) - (1)].node));
      printf("Reduction(relop -> LT )\n");
    }
    break;

  case 59:
#line 491 "pascal.y"
    {
      (yyval.node)=newOpNode(OP_GT);
      (yyval.node)->lineno=(yyvsp[(1) - (1)].node)->lineno;
      deleteNode((yyvsp[(1) - (1)].node));
      printf("Reduction(relop -> GT )\n");
    }
    break;

  case 60:
#line 497 "pascal.y"
    {
      (yyval.node)=newOpNode(OP_EQUAL);
      (yyval.node)->lineno=(yyvsp[(1) - (1)].node)->lineno;
      deleteNode((yyvsp[(1) - (1)].node));
      printf("Reduction(relop -> EQUAL )\n");
    }
    break;

  case 61:
#line 503 "pascal.y"
    {
      (yyval.node)=newOpNode(OP_LE);
      (yyval.node)->lineno=(yyvsp[(1) - (1)].node)->lineno;
      deleteNode((yyvsp[(1) - (1)].node));
      printf("Reduction(relop -> LE )\n");
    }
    break;

  case 62:
#line 509 "pascal.y"
    {
      (yyval.node)=newOpNode(OP_GE);
      (yyval.node)->lineno=(yyvsp[(1) - (1)].node)->lineno;
      deleteNode((yyvsp[(1) - (1)].node));
      printf("Reduction(relop -> GE )\n");
    }
    break;

  case 63:
#line 515 "pascal.y"
    {
      (yyval.node)=newOpNode(OP_notEQUAL);
      (yyval.node)->lineno=(yyvsp[(1) - (1)].node)->lineno;
      deleteNode((yyvsp[(1) - (1)].node));
      printf("Reduction(relop -> notEQUAL )\n");
    }
    break;


/* Line 1267 of yacc.c.  */
#line 2179 "y.tab.c"
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


#line 523 "pascal.y"

//# include "lex.yy.c"
int yywrap()
{
    return 1;
} 

struct nodeType *ASTRoot;

struct nodeType* newOpNode(int op) {
    struct nodeType *node = newNode(NODE_OP);
    node->op = op;

    return node;
}

int main(int argc, char** argv) {
    yyparse();
    printf("********************************\n"
           "*       No syntax error!       *\n"
           "********************************\n");

    printTree(ASTRoot, 0);

    SymbolTable.size = 0;
    ScopeStack[0]=&SymbolTable;
    printf("Create a new Scope\n");
    printf("Create a new SymbolTable\n");
    semanticCheck(ASTRoot);
    printf("Close a scope\n");
    printf("Close a SymbolTable\n");
    printf("********************************\n"
           "*      No semantic error!      *\n"
           "********************************\n");

    return 0;
}


