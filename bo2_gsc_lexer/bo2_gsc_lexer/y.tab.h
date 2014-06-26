/* A Bison parser, made by GNU Bison 2.7.1.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "..\\..\\gsc_cod9.y"

#include <stdio.h>
#include <vector>
#include "compiler_helper.h"

extern int lineCount;
int yylex(void);

void CompileError(char* errorString, ...);
void yyerror(char const *s);

void OnParsingComplete();

/* Line 371 of yacc.c  */
#line 82 "y.tab.h"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INCLUDE = 258,
     USING_ANIMTREE = 259,
     THREAD = 260,
     SWITCH = 261,
     CASE = 262,
     DEFAULT = 263,
     IF = 264,
     ELSE = 265,
     FOR = 266,
     WHILE = 267,
     FOREACH = 268,
     IN = 269,
     BREAK = 270,
     RETURN = 271,
     CONTINUE = 272,
     WAIT = 273,
     WAITTILLFRAMEEND = 274,
     UNDEFINED = 275,
     SHIFT_RIGHT_ASSIGN = 276,
     SHIFT_LEFT_ASSIGN = 277,
     PLUS_ASSIGN = 278,
     MINUS_ASSIGN = 279,
     MULTIPLY_ASSIGN = 280,
     DIVIDE_ASSIGN = 281,
     MOD_ASSIGN = 282,
     BIT_AND_ASSIGN = 283,
     BIT_EX_OR_ASSIGN = 284,
     BIT_OR_ASSIGN = 285,
     SHIFT_RIGHT_OP = 286,
     SHIFT_LEFT_OP = 287,
     INC_OP = 288,
     DEC_OP = 289,
     LOGICAL_AND_OP = 290,
     LOGICAL_OR_OP = 291,
     LESS_EQUAL_OP = 292,
     GREATER_EQUAL_OP = 293,
     EQUALITY_OP = 294,
     INEQUALITY_OP = 295,
     DEREFERENCE_FUNC_START = 296,
     REFERENCE_FUNC = 297,
     EMPTY_ARRAY = 298,
     INT_LITERAL = 299,
     FLOAT_LITERAL = 300,
     IDENTIFIER = 301,
     PATH = 302,
     STRING_LITERAL = 303,
     LOC_STRING_LITERAL = 304,
     HASH_STRING_LITERAL = 305,
     IFX = 306,
     UNARY_ANIMREF = 307,
     UNARY_MINUS = 308
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 15 "..\\..\\gsc_cod9.y"

	int intValue;
	float floatValue;
	char* stringValue;
	sNode* nodeValue;
	std::vector<sNode*>* nodeArrayValue;


/* Line 387 of yacc.c  */
#line 184 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 212 "y.tab.h"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1013

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNRULES -- Number of states.  */
#define YYNSTATES  267

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,     2,     2,    63,    56,     2,
      69,    70,    61,    59,    71,    60,    74,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    68,
      57,    75,    58,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    72,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,    54,    77,    65,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    66,    67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    10,    12,    15,    18,
      21,    25,    29,    35,    41,    42,    44,    48,    53,    60,
      67,    75,    76,    78,    82,    84,    86,    89,    92,    95,
      98,   102,   106,   108,   110,   112,   114,   119,   121,   123,
     125,   127,   129,   133,   135,   137,   139,   141,   143,   146,
     150,   154,   156,   158,   160,   162,   164,   166,   174,   176,
     178,   180,   182,   184,   186,   192,   196,   200,   204,   208,
     212,   216,   220,   224,   228,   232,   236,   240,   244,   248,
     252,   256,   260,   264,   267,   270,   273,   276,   279,   281,
     285,   287,   289,   291,   293,   295,   297,   299,   302,   305,
     308,   311,   314,   317,   321,   325,   329,   333,   337,   341,
     345,   349,   353,   357,   361,   363,   365,   367,   371,   375,
     378,   381,   384,   387,   391,   395,   398,   400,   403,   406,
     409,   412,   415,   419,   421,   424,   430,   438,   444,   454,
     460,   468,   469,   471,   472,   474,   475,   477
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      79,     0,    -1,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    80,    81,    -1,    80,    82,    -1,    80,    83,
      -1,     3,    47,    68,    -1,     3,    46,    68,    -1,     4,
      69,    48,    70,    68,    -1,    46,    69,    84,    70,   106,
      -1,    -1,    46,    -1,    84,    71,    46,    -1,    46,    69,
      87,    70,    -1,    47,    42,    46,    69,    87,    70,    -1,
      46,    42,    46,    69,    87,    70,    -1,    41,    96,    72,
      72,    69,    87,    70,    -1,    -1,    96,    -1,    87,    71,
      96,    -1,    85,    -1,    86,    -1,    90,    85,    -1,    90,
      86,    -1,     5,    85,    -1,     5,    86,    -1,    90,     5,
      85,    -1,    90,     5,    86,    -1,    46,    -1,    88,    -1,
      91,    -1,    93,    -1,    92,    73,    96,    72,    -1,    46,
      -1,    88,    -1,    91,    -1,    93,    -1,    97,    -1,    94,
      74,    46,    -1,    46,    -1,    88,    -1,    91,    -1,    93,
      -1,    97,    -1,    42,    46,    -1,    46,    42,    46,    -1,
      47,    42,    46,    -1,    46,    -1,    44,    -1,    45,    -1,
      48,    -1,    49,    -1,    50,    -1,    69,    96,    71,    96,
      71,    96,    70,    -1,    43,    -1,    20,    -1,    88,    -1,
      91,    -1,    93,    -1,    95,    -1,    96,    52,    96,    53,
      96,    -1,    96,    36,    96,    -1,    96,    35,    96,    -1,
      96,    54,    96,    -1,    96,    55,    96,    -1,    96,    56,
      96,    -1,    96,    39,    96,    -1,    96,    40,    96,    -1,
      96,    57,    96,    -1,    96,    58,    96,    -1,    96,    37,
      96,    -1,    96,    38,    96,    -1,    96,    32,    96,    -1,
      96,    31,    96,    -1,    96,    59,    96,    -1,    96,    60,
      96,    -1,    96,    61,    96,    -1,    96,    62,    96,    -1,
      96,    63,    96,    -1,    64,    96,    -1,    65,    96,    -1,
      60,    44,    -1,    60,    45,    -1,    63,    46,    -1,    97,
      -1,    69,    96,    70,    -1,   102,    -1,   103,    -1,   104,
      -1,   105,    -1,   106,    -1,   108,    -1,   109,    -1,    46,
      33,    -1,    46,    34,    -1,    91,    33,    -1,    91,    34,
      -1,    93,    33,    -1,    93,    34,    -1,   101,    75,    96,
      -1,   101,    23,    96,    -1,   101,    24,    96,    -1,   101,
      25,    96,    -1,   101,    26,    96,    -1,   101,    27,    96,
      -1,   101,    22,    96,    -1,   101,    21,    96,    -1,   101,
      28,    96,    -1,   101,    29,    96,    -1,   101,    30,    96,
      -1,    46,    -1,    91,    -1,    93,    -1,     7,    44,    53,
      -1,     7,    48,    53,    -1,     8,    53,    -1,    17,    68,
      -1,    15,    68,    -1,    16,    68,    -1,    16,    96,    68,
      -1,    18,    96,    68,    -1,    19,    68,    -1,    68,    -1,
      99,    68,    -1,   100,    68,    -1,    88,    68,    -1,    89,
      68,    -1,    76,    77,    -1,    76,   107,    77,    -1,    98,
      -1,   107,    98,    -1,     9,    69,    96,    70,    98,    -1,
       9,    69,    96,    70,    98,    10,    98,    -1,     6,    69,
      96,    70,   106,    -1,    11,    69,   110,    68,   111,    68,
     112,    70,    98,    -1,    12,    69,    96,    70,    98,    -1,
      13,    69,    46,    14,    96,    70,    98,    -1,    -1,   100,
      -1,    -1,    96,    -1,    -1,    99,    -1,   100,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    69,    73,    74,    75,    76,    77,    78,
      82,    83,    87,    91,    95,    96,    97,   102,   103,   104,
     109,   113,   114,   115,   120,   121,   122,   123,   128,   129,
     130,   131,   136,   137,   138,   139,   144,   149,   150,   151,
     152,   153,   158,   166,   167,   168,   169,   170,   174,   175,
     176,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   221,
     226,   227,   228,   229,   230,   231,   232,   236,   237,   238,
     239,   240,   241,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   259,   260,   261,   265,   266,   267,
     271,   272,   273,   274,   278,   279,   284,   285,   286,   287,
     288,   292,   293,   297,   298,   302,   303,   304,   308,   309,
     310,   314,   315,   319,   320,   324,   325,   326
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INCLUDE", "USING_ANIMTREE", "THREAD",
  "SWITCH", "CASE", "DEFAULT", "IF", "ELSE", "FOR", "WHILE", "FOREACH",
  "IN", "BREAK", "RETURN", "CONTINUE", "WAIT", "WAITTILLFRAMEEND",
  "UNDEFINED", "SHIFT_RIGHT_ASSIGN", "SHIFT_LEFT_ASSIGN", "PLUS_ASSIGN",
  "MINUS_ASSIGN", "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "MOD_ASSIGN",
  "BIT_AND_ASSIGN", "BIT_EX_OR_ASSIGN", "BIT_OR_ASSIGN", "SHIFT_RIGHT_OP",
  "SHIFT_LEFT_OP", "INC_OP", "DEC_OP", "LOGICAL_AND_OP", "LOGICAL_OR_OP",
  "LESS_EQUAL_OP", "GREATER_EQUAL_OP", "EQUALITY_OP", "INEQUALITY_OP",
  "DEREFERENCE_FUNC_START", "REFERENCE_FUNC", "EMPTY_ARRAY", "INT_LITERAL",
  "FLOAT_LITERAL", "IDENTIFIER", "PATH", "STRING_LITERAL",
  "LOC_STRING_LITERAL", "HASH_STRING_LITERAL", "IFX", "'?'", "':'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'",
  "'~'", "UNARY_ANIMREF", "UNARY_MINUS", "';'", "'('", "')'", "','", "']'",
  "'['", "'.'", "'='", "'{'", "'}'", "$accept", "translation_unit",
  "source_code", "include", "using_animtree", "func_definition",
  "parameter_list_opt", "func_call_noptr", "func_call_ptr",
  "argument_list_opt", "func_call_nothrd_expression",
  "func_call_thrd_expression", "func_valid_object",
  "array_subscripting_expression", "array_valid_name",
  "element_selection_expression", "element_valid_selection",
  "func_ref_expression", "expression", "parenthesized_expression",
  "statement", "inc_dec_statement", "assignment_statement",
  "operation_valid_lvalue", "labeled_statement", "jump_statement",
  "wait_statement", "expression_statement", "compound_statement",
  "statement_list", "selection_statement", "iteration_statement",
  "for_init_statement", "for_cond_expression", "for_loop_statement", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    63,    58,   124,    94,    38,    60,    62,    43,
      45,    42,    47,    37,    33,   126,   307,   308,    59,    40,
      41,    44,    93,    91,    46,    61,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    83,    84,    84,    84,    85,    85,    85,
      86,    87,    87,    87,    88,    88,    88,    88,    89,    89,
      89,    89,    90,    90,    90,    90,    91,    92,    92,    92,
      92,    92,    93,    94,    94,    94,    94,    94,    95,    95,
      95,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      98,    98,    98,    98,    98,    98,    98,    99,    99,    99,
      99,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   101,   101,   101,   102,   102,   102,
     103,   103,   103,   103,   104,   104,   105,   105,   105,   105,
     105,   106,   106,   107,   107,   108,   108,   108,   109,   109,
     109,   110,   110,   111,   111,   112,   112,   112
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     1,     2,     2,     2,
       3,     3,     5,     5,     0,     1,     3,     4,     6,     6,
       7,     0,     1,     3,     1,     1,     2,     2,     2,     2,
       3,     3,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     7,     1,     1,
       1,     1,     1,     1,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     3,     3,     2,
       2,     2,     2,     3,     3,     2,     1,     2,     2,     2,
       2,     2,     3,     1,     2,     5,     7,     5,     9,     5,
       7,     0,     1,     0,     1,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     3,     4,     5,     6,     0,
       0,     0,    14,     1,     7,     8,     9,    11,    10,     0,
      15,     0,     0,     0,     0,    12,     0,    13,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,     0,   126,     0,   131,    24,    25,
      33,     0,     0,   115,     0,   116,     0,    41,   133,     0,
       0,     0,    90,    91,    92,    93,    94,     0,    95,    96,
       0,    28,    29,     0,     0,     0,   119,     0,   141,     0,
       0,   121,    59,     0,    58,    52,    53,    51,     0,    54,
      55,    56,     0,     0,     0,     0,   122,     0,    60,     0,
      61,    62,    63,     0,    88,   120,     0,   125,     0,    97,
      98,     0,    21,     0,     0,   129,   130,     0,    26,    27,
      99,   100,     0,   101,   102,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   132,
     134,     0,   117,   118,     0,   114,    33,   115,   116,   142,
       0,     0,     0,    48,     0,     0,    85,    86,    87,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   124,     0,     0,     0,    22,     0,    89,    30,
      31,     0,    42,   110,   109,   104,   105,   106,   107,   108,
     111,   112,   113,   103,     0,     0,   143,     0,     0,    49,
      50,     0,    77,    76,    66,    65,    74,    75,    70,    71,
       0,    67,    68,    69,    72,    73,    78,    79,    80,    81,
      82,     0,    21,    17,     0,    21,    36,   137,   135,   144,
       0,   139,     0,     0,     0,    21,     0,    23,     0,     0,
     145,     0,     0,    64,     0,    19,    18,   136,   146,   147,
       0,   140,     0,    20,     0,    57,   138
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    21,    48,    49,   185,
      98,    51,    99,   100,    54,   101,    56,   102,   186,   104,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,   150,   240,   260
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -207
static const yytype_int16 yypact[] =
{
      20,    32,   -62,   -59,    25,    20,  -207,  -207,  -207,   -41,
     -38,   -15,     5,  -207,  -207,  -207,  -207,  -207,  -207,   -16,
    -207,    12,   -12,   -19,    14,  -207,   264,  -207,  -207,    93,
      -7,    -6,    36,    -4,    39,    43,    47,    51,   319,    53,
     352,    56,   352,    68,    85,  -207,   352,  -207,  -207,  -207,
      70,    78,    -1,   279,    84,   297,   106,   112,  -207,    91,
     124,    -8,  -207,  -207,  -207,  -207,  -207,   282,  -207,  -207,
     -34,  -207,  -207,   352,   163,   165,  -207,   352,     2,   352,
     190,  -207,  -207,   193,  -207,  -207,  -207,   -10,   201,  -207,
    -207,  -207,   107,   200,   352,   352,  -207,   352,    59,    93,
     148,   262,  -207,   753,    30,  -207,   787,  -207,   387,  -207,
    -207,   207,   352,   208,   537,  -207,  -207,    93,  -207,  -207,
    -207,  -207,   352,  -207,  -207,   209,  -207,  -207,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,  -207,
    -207,   573,  -207,  -207,   609,    76,    80,   148,   262,  -207,
     188,   645,   243,  -207,   212,   214,  -207,  -207,  -207,  -207,
    -207,   463,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,  -207,  -207,   191,   195,    90,   854,   196,  -207,  -207,
    -207,   425,  -207,   854,   854,   854,   854,   854,   854,   854,
     854,   854,   854,   854,   -19,    79,   352,    79,   352,   195,
     196,   352,   115,   115,   897,   864,   286,   286,   372,   372,
     821,   907,   940,   950,   286,   286,     7,     7,  -207,  -207,
    -207,   197,   352,  -207,   352,   352,  -207,  -207,   252,   854,
     199,  -207,   681,   500,   352,   352,   149,   854,   178,    79,
      89,    79,   352,   854,   181,  -207,  -207,  -207,  -207,  -207,
     215,  -207,   717,  -207,    79,  -207,  -207
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,  -207,   287,   291,   299,  -207,   -24,   -18,  -206,
     -26,  -207,   -14,   -23,  -207,   -20,  -207,  -207,    34,   -17,
      10,    57,   -77,  -207,  -207,  -207,  -207,  -207,   -21,  -207,
    -207,  -207,  -207,  -207,  -207
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int16 yytable[] =
{
      50,   149,    27,    53,   117,    71,    55,    11,   111,    57,
      12,    72,    52,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     1,     2,    13,   246,    17,   118,   248,
      18,   -32,   154,    19,   119,   112,   -32,   -32,    74,   254,
      42,    50,    75,    42,    53,    70,    44,    55,   145,    44,
      57,    20,   146,    52,    22,   147,    25,    26,   148,   112,
      28,    57,    73,   -37,   -43,    77,     3,   138,   178,   179,
     180,    46,   103,   -32,   106,   118,   108,   140,     9,    10,
     114,   119,    23,    24,    29,    30,    31,    32,    33,    76,
      34,    35,    36,   189,    37,    38,    39,    40,    41,   190,
     -33,   109,   110,   -41,   -47,   -33,   -33,   141,    78,   -32,
     111,   144,    79,   151,   -32,   -32,    80,   -32,   111,    81,
      42,   105,   -32,   -32,   107,    43,    44,   113,   159,   160,
      42,   161,   -38,   -44,    42,    43,    44,   112,   115,    70,
      44,   -37,   -43,   -38,   -44,   112,   116,    45,    46,   -37,
     -43,   156,   157,   -38,   -44,    26,   191,   122,    46,   126,
     233,   234,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   259,   176,   177,   178,   179,   180,    50,
     125,    50,    53,   237,    53,    55,   -47,    55,    57,   -34,
      57,    52,   127,    52,   -34,   -34,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   238,   142,   241,   143,   255,
     234,   -39,   -45,    50,   146,    50,    53,    53,    53,    55,
      55,    55,    57,    57,    57,    52,   152,    52,    50,   153,
     239,    53,   242,   155,    55,   243,   158,    57,   256,   234,
      52,   263,   234,   184,   187,   192,   206,   208,   209,   257,
     210,   261,   249,   231,   232,   235,   245,   250,   247,    29,
      30,    31,    32,    33,   266,    34,    35,    36,   253,    37,
      38,    39,    40,    41,   -34,   264,   262,    29,    30,    31,
      32,    33,    14,    34,    35,    36,    15,    37,    38,    39,
      40,    41,   -35,   -35,    16,    42,     0,   258,   -35,   -35,
      43,    44,   120,   121,     0,     0,     0,   162,   163,     0,
     -34,     0,     0,    42,     0,   -34,   -34,     0,    43,    44,
     123,   124,    45,    46,     0,   -40,   -46,     0,   -35,    82,
      26,    47,     0,   -35,   -35,   176,   177,   178,   179,   180,
      45,    46,   -39,   -45,     0,     0,     0,     0,    26,   139,
      42,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     -40,   -46,    82,     0,     0,     0,     0,     0,     0,    92,
       0,     0,    93,    94,    95,     0,     0,    96,    97,     0,
       0,     0,     0,    42,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   162,   163,     0,     0,     0,     0,   166,
     167,     0,    92,     0,     0,    93,    94,    95,   162,   163,
       0,    97,   164,   165,   166,   167,   168,   169,     0,   174,
     175,   176,   177,   178,   179,   180,     0,     0,     0,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,     0,     0,     0,     0,     0,   162,   163,     0,   183,
     164,   165,   166,   167,   168,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,     0,
       0,     0,     0,     0,   162,   163,     0,   236,   164,   165,
     166,   167,   168,   169,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,     0,     0,     0,
       0,   162,   163,   188,   211,   164,   165,   166,   167,   168,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,     0,     0,     0,     0,   162,   163,
       0,   252,   164,   165,   166,   167,   168,   169,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,     0,     0,     0,   162,   163,     0,   188,   164,   165,
     166,   167,   168,   169,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,     0,     0,     0,
     162,   163,     0,   204,   164,   165,   166,   167,   168,   169,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,     0,     0,     0,   162,   163,     0,   205,
     164,   165,   166,   167,   168,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,     0,
       0,     0,   162,   163,     0,   207,   164,   165,   166,   167,
     168,   169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,     0,     0,     0,   162,   163,
       0,   251,   164,   165,   166,   167,   168,   169,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,     0,     0,     0,   162,   163,     0,   265,   164,   165,
     166,   167,   168,   169,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,     0,   162,   163,
       0,   181,   164,   165,   166,   167,   168,   169,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,     0,   162,   163,     0,   182,   164,   165,   166,   167,
     168,   169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,   244,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   162,   163,     0,     0,   164,
     165,   166,   167,   168,   169,   162,   163,     0,     0,   164,
       0,   166,   167,   168,   169,     0,   170,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   162,   163,
       0,     0,     0,     0,   166,   167,   168,   169,   162,   163,
       0,     0,     0,     0,   166,   167,   168,   169,     0,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,     0,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   162,   163,     0,     0,     0,     0,   166,   167,   168,
     169,   162,   163,     0,     0,     0,     0,   166,   167,   168,
     169,     0,     0,     0,     0,     0,   173,   174,   175,   176,
     177,   178,   179,   180,     0,     0,     0,   174,   175,   176,
     177,   178,   179,   180
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-207)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      26,    78,    23,    26,     5,    29,    26,    69,    42,    26,
      69,    29,    26,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     3,     4,     0,   232,    68,    52,   235,
      68,    41,    42,    48,    52,    69,    46,    47,    44,   245,
      41,    67,    48,    41,    67,    46,    47,    67,    46,    47,
      67,    46,    78,    67,    70,    78,    68,    76,    78,    69,
      46,    78,    69,    73,    74,    69,    46,    75,    61,    62,
      63,    69,    38,     5,    40,    99,    42,    67,    46,    47,
      46,    99,    70,    71,     5,     6,     7,     8,     9,    53,
      11,    12,    13,   117,    15,    16,    17,    18,    19,   117,
      41,    33,    34,    73,    74,    46,    47,    73,    69,    41,
      42,    77,    69,    79,    46,    47,    69,    41,    42,    68,
      41,    68,    46,    47,    68,    46,    47,    42,    94,    95,
      41,    97,    73,    74,    41,    46,    47,    69,    68,    46,
      47,    73,    74,    73,    74,    69,    68,    68,    69,    73,
      74,    44,    45,    73,    74,    76,   122,    73,    69,    68,
      70,    71,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   250,    59,    60,    61,    62,    63,   205,
      74,   207,   205,   204,   207,   205,    74,   207,   205,    41,
     207,   205,    68,   207,    46,    47,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   205,    53,   207,    53,    70,
      71,    73,    74,   249,   250,   251,   249,   250,   251,   249,
     250,   251,   249,   250,   251,   249,    46,   251,   264,    46,
     206,   264,   208,    42,   264,   211,    46,   264,    70,    71,
     264,    70,    71,    46,    46,    46,    68,    14,    46,   249,
      46,   251,    10,    72,    69,    69,    69,    68,   234,     5,
       6,     7,     8,     9,   264,    11,    12,    13,   244,    15,
      16,    17,    18,    19,     5,    70,   252,     5,     6,     7,
       8,     9,     5,    11,    12,    13,     5,    15,    16,    17,
      18,    19,     5,    41,     5,    41,    -1,   250,    46,    47,
      46,    47,    33,    34,    -1,    -1,    -1,    31,    32,    -1,
      41,    -1,    -1,    41,    -1,    46,    47,    -1,    46,    47,
      33,    34,    68,    69,    -1,    73,    74,    -1,    41,    20,
      76,    77,    -1,    46,    47,    59,    60,    61,    62,    63,
      68,    69,    73,    74,    -1,    -1,    -1,    -1,    76,    77,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      73,    74,    20,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    63,    64,    65,    -1,    -1,    68,    69,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    60,    -1,    -1,    63,    64,    65,    31,    32,
      -1,    69,    35,    36,    37,    38,    39,    40,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    72,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    72,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    31,    32,    70,    71,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    31,    32,
      -1,    71,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    31,    32,    -1,    70,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      31,    32,    -1,    70,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    31,    32,    -1,    70,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    31,    32,    -1,    70,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    31,    32,
      -1,    70,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    31,    32,    -1,    70,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    31,    32,
      -1,    68,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    31,    32,    -1,    68,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    31,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    31,    32,    -1,    -1,    35,
      -1,    37,    38,    39,    40,    -1,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    46,    79,    80,    81,    82,    83,    46,
      47,    69,    69,     0,    81,    82,    83,    68,    68,    48,
      46,    84,    70,    70,    71,    68,    76,   106,    46,     5,
       6,     7,     8,     9,    11,    12,    13,    15,    16,    17,
      18,    19,    41,    46,    47,    68,    69,    77,    85,    86,
      88,    89,    90,    91,    92,    93,    94,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      46,    85,    86,    69,    44,    48,    53,    69,    69,    69,
      69,    68,    20,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    60,    63,    64,    65,    68,    69,    88,    90,
      91,    93,    95,    96,    97,    68,    96,    68,    96,    33,
      34,    42,    69,    42,    96,    68,    68,     5,    85,    86,
      33,    34,    73,    33,    34,    74,    68,    68,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    75,    77,
      98,    96,    53,    53,    96,    46,    88,    91,    93,   100,
     110,    96,    46,    46,    42,    42,    44,    45,    46,    96,
      96,    96,    31,    32,    35,    36,    37,    38,    39,    40,
      52,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    68,    68,    72,    46,    87,    96,    46,    70,    85,
      86,    96,    46,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    70,    70,    68,    70,    14,    46,
      46,    71,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    72,    69,    70,    71,    69,    72,   106,    98,    96,
     111,    98,    96,    96,    53,    69,    87,    96,    87,    10,
      68,    70,    71,    96,    87,    70,    70,    98,    99,   100,
     112,    98,    96,    70,    70,    70,    98
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 3:
/* Line 1787 of yacc.c  */
#line 69 "..\\..\\gsc_cod9.y"
    { compiler->sourceCode = (yyvsp[(1) - (1)].nodeArrayValue); OnParsingComplete(); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 73 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = new std::vector<sNode*>(1, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 74 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = new std::vector<sNode*>(1, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 75 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = new std::vector<sNode*>(1, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 76 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = (yyvsp[(1) - (2)].nodeArrayValue); (yyval.nodeArrayValue)->push_back((yyvsp[(2) - (2)].nodeValue)); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 77 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = (yyvsp[(1) - (2)].nodeArrayValue); (yyval.nodeArrayValue)->push_back((yyvsp[(2) - (2)].nodeValue)); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 78 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = (yyvsp[(1) - (2)].nodeArrayValue); (yyval.nodeArrayValue)->push_back((yyvsp[(2) - (2)].nodeValue)); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 82 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocInclude((yyvsp[(2) - (3)].stringValue)); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 83 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocInclude((yyvsp[(2) - (3)].stringValue)); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 87 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocUsingAnimTree((yyvsp[(3) - (5)].stringValue)); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 91 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncDefinition(IdentifierNode((yyvsp[(1) - (5)].stringValue)), (yyvsp[(3) - (5)].nodeArrayValue), (yyvsp[(5) - (5)].nodeValue)); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 95 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = 0; }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 96 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = new std::vector<sNode*>(1, IdentifierNode((yyvsp[(1) - (1)].stringValue))); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 97 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = (yyvsp[(1) - (3)].nodeArrayValue); (yyval.nodeArrayValue)->push_back(IdentifierNode((yyvsp[(3) - (3)].stringValue))); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 102 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncCallExpression(IdentifierNode((yyvsp[(1) - (4)].stringValue)), 0, (yyvsp[(3) - (4)].nodeArrayValue), 0, 0, 0, 0, 0); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 103 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncCallExpression(IdentifierNode((yyvsp[(3) - (6)].stringValue)), PathNode((yyvsp[(1) - (6)].stringValue)), (yyvsp[(5) - (6)].nodeArrayValue), 0, 0, 0, 0, 0); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 104 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncCallExpression(IdentifierNode((yyvsp[(3) - (6)].stringValue)), IdentifierNode((yyvsp[(1) - (6)].stringValue)), (yyvsp[(5) - (6)].nodeArrayValue), 0, 0, 0, 0, 0); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 109 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncCallExpression(0, 0, (yyvsp[(6) - (7)].nodeArrayValue), 1, (yyvsp[(2) - (7)].nodeValue), 0, 0, 0); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 113 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = 0; }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 114 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = new std::vector<sNode*>(1, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 115 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = (yyvsp[(1) - (3)].nodeArrayValue); (yyval.nodeArrayValue)->push_back((yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 120 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); (yyval.nodeValue)->funcCallExpression->isThread = 0; }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 121 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); (yyval.nodeValue)->funcCallExpression->isThread = 0; }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 122 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(2) - (2)].nodeValue); (yyval.nodeValue)->funcCallExpression->isThread = 0; (yyval.nodeValue)->funcCallExpression->isMethod = 1; (yyval.nodeValue)->funcCallExpression->methodObject = (yyvsp[(1) - (2)].nodeValue); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 123 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(2) - (2)].nodeValue); (yyval.nodeValue)->funcCallExpression->isThread = 0; (yyval.nodeValue)->funcCallExpression->isMethod = 1; (yyval.nodeValue)->funcCallExpression->methodObject = (yyvsp[(1) - (2)].nodeValue); }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 128 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(2) - (2)].nodeValue); (yyval.nodeValue)->funcCallExpression->isThread = 1; }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 129 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(2) - (2)].nodeValue); (yyval.nodeValue)->funcCallExpression->isThread = 1; }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 130 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(3) - (3)].nodeValue); (yyval.nodeValue)->funcCallExpression->isThread = 1; (yyval.nodeValue)->funcCallExpression->isMethod = 1; (yyval.nodeValue)->funcCallExpression->methodObject = (yyvsp[(1) - (3)].nodeValue); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 131 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(3) - (3)].nodeValue); (yyval.nodeValue)->funcCallExpression->isThread = 1; (yyval.nodeValue)->funcCallExpression->isMethod = 1; (yyval.nodeValue)->funcCallExpression->methodObject = (yyvsp[(1) - (3)].nodeValue); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 136 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = IdentifierNode((yyvsp[(1) - (1)].stringValue)); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 137 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 138 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 139 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 144 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocArraySubscriptingExpression((yyvsp[(1) - (4)].nodeValue), (yyvsp[(3) - (4)].nodeValue)); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 149 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = IdentifierNode((yyvsp[(1) - (1)].stringValue)); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 150 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 151 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 152 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 153 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 158 "..\\..\\gsc_cod9.y"
    {
																	int isSize = !strcmp((yyvsp[(3) - (3)].stringValue), "size");
																	(yyval.nodeValue) = AllocElementSelectionExpression(isSize, (yyvsp[(1) - (3)].nodeValue), isSize ? 0 : IdentifierNode((yyvsp[(3) - (3)].stringValue)));
																}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 166 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = IdentifierNode((yyvsp[(1) - (1)].stringValue)); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 167 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 168 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 169 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 170 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 174 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncRefExpression(0, IdentifierNode((yyvsp[(2) - (2)].stringValue))); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 175 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncRefExpression(IdentifierNode((yyvsp[(1) - (3)].stringValue)), IdentifierNode((yyvsp[(3) - (3)].stringValue))); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 176 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncRefExpression(PathNode((yyvsp[(1) - (3)].stringValue)), IdentifierNode((yyvsp[(3) - (3)].stringValue))); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 180 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_IDENTIFIER, IdentifierNode((yyvsp[(1) - (1)].stringValue))); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 181 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_INT, IntNode((yyvsp[(1) - (1)].intValue))); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 182 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_FLOAT, FloatNode((yyvsp[(1) - (1)].floatValue))); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 183 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_STRING, StringNode((yyvsp[(1) - (1)].stringValue))); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 184 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_LOC_STRING, LocStringNode((yyvsp[(1) - (1)].stringValue))); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 185 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_HASH_STRING, HashStringNode((yyvsp[(1) - (1)].stringValue))); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 186 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_VECTOR, (yyvsp[(2) - (7)].nodeValue), (yyvsp[(4) - (7)].nodeValue), (yyvsp[(6) - (7)].nodeValue)); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 187 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_EMPTY_ARRAY); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 188 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_UNDEFINED); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 189 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_FUNC_CALL_NOTHRD, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 190 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_ARRAY_SUBSCRIPTING, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 191 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_ELEMENT_SELECTION, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 192 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_FUNC_REF, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 193 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_TERNARY_OP, (yyvsp[(1) - (5)].nodeValue), (yyvsp[(3) - (5)].nodeValue), (yyvsp[(5) - (5)].nodeValue)); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 194 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_LOGICAL_OR_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 195 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_LOGICAL_AND_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 196 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_BIT_OR_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 197 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_BIT_EX_OR_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 198 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_BIT_AND_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 199 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_EQUALITY_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 200 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_INEQUALITY_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 201 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_LESS_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 202 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_GREATER_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 203 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_LESS_EQUAL_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 204 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_GREATER_EQUAL_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 205 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_SHIFT_LEFT_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 206 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_SHIFT_RIGHT_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 207 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_PLUS_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 208 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_MINUS_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 209 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_MULTIPLY_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 210 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_DIVIDE_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 211 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_MOD_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 212 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_BOOL_NOT_OP, (yyvsp[(2) - (2)].nodeValue)); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 213 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_BOOL_COMPLEMENT_OP, (yyvsp[(2) - (2)].nodeValue)); }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 214 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_INT, IntNode(-(yyvsp[(2) - (2)].intValue))); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 215 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_FLOAT, FloatNode(-(yyvsp[(2) - (2)].floatValue))); }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 216 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_UANIMREF_OP, IdentifierNode((yyvsp[(2) - (2)].stringValue))); }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 217 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 221 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(2) - (3)].nodeValue); }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 226 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 227 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 228 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 229 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 230 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 231 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 232 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 236 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_INC, IdentifierNode((yyvsp[(1) - (2)].stringValue))); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 237 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_DEC, IdentifierNode((yyvsp[(1) - (2)].stringValue))); }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 238 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_INC, (yyvsp[(1) - (2)].nodeValue)); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 239 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_DEC, (yyvsp[(1) - (2)].nodeValue)); }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 240 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_INC, (yyvsp[(1) - (2)].nodeValue)); }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 241 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_DEC, (yyvsp[(1) - (2)].nodeValue)); }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 245 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_REGULAR_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 246 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_PLUS_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 247 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_MINUS_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 248 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_MULTIPLY_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 249 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_DIVIDE_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 250 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_MOD_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 251 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_SHIFT_LEFT_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 252 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_SHIFT_RIGHT_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 253 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_BIT_AND_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 254 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_BIT_EX_OR_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 255 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_BIT_OR_ASSIGN, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 259 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = IdentifierNode((yyvsp[(1) - (1)].stringValue)); }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 260 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 261 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 265 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_CASE, IntNode((yyvsp[(2) - (3)].intValue))); }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 266 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_CASE, StringNode((yyvsp[(2) - (3)].stringValue))); }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 267 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_DEFAULT); }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 271 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_CONTINUE); }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 272 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_BREAK); }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 273 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_RETURN, 0); }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 274 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_RETURN, (yyvsp[(2) - (3)].nodeValue)); }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 278 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_WAIT, (yyvsp[(2) - (3)].nodeValue)); }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 279 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_WAITTILLFRAMEEND); }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 284 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_EXPRESSION_STATEMENT, 0); }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 285 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_EXPRESSION_STATEMENT, (yyvsp[(1) - (2)].nodeValue)); }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 286 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_EXPRESSION_STATEMENT, (yyvsp[(1) - (2)].nodeValue)); }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 287 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_EXPRESSION_STATEMENT, (yyvsp[(1) - (2)].nodeValue)); }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 288 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_EXPRESSION_STATEMENT, (yyvsp[(1) - (2)].nodeValue)); }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 292 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_COMPOUND, 0); }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 293 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_COMPOUND, (yyvsp[(2) - (3)].nodeArrayValue)); }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 297 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = new std::vector<sNode*>(1, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 298 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = (yyvsp[(1) - (2)].nodeArrayValue); (yyval.nodeArrayValue)->push_back((yyvsp[(2) - (2)].nodeValue)); }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 302 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_IF, (yyvsp[(3) - (5)].nodeValue), (yyvsp[(5) - (5)].nodeValue)); }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 303 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_IF_ELSE, (yyvsp[(3) - (7)].nodeValue), (yyvsp[(5) - (7)].nodeValue), (yyvsp[(7) - (7)].nodeValue)); }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 304 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_SWITCH, (yyvsp[(3) - (5)].nodeValue), (yyvsp[(5) - (5)].nodeValue)); }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 308 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_FOR, (yyvsp[(3) - (9)].nodeValue), (yyvsp[(5) - (9)].nodeValue), (yyvsp[(7) - (9)].nodeValue), (yyvsp[(9) - (9)].nodeValue)); }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 309 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_WHILE, (yyvsp[(3) - (5)].nodeValue), (yyvsp[(5) - (5)].nodeValue)); }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 310 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocStatement(TYPE_STMT_FOREACH, (yyvsp[(3) - (7)].stringValue), (yyvsp[(5) - (7)].nodeValue), (yyvsp[(7) - (7)].nodeValue)); }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 314 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = 0; }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 315 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 319 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = 0; }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 320 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 324 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = 0; }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 325 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 326 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;


/* Line 1787 of yacc.c  */
#line 2685 "y.tab.h"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2050 of yacc.c  */
#line 329 "..\\..\\gsc_cod9.y"


void yyerror(char const *s)
{
	CompileError("yyerror: %s\nat line %d\n", s, lineCount);
}