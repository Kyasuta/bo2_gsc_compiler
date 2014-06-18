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

void yyerror(char const *s);

void OnParsingComplete(std::vector<sNode*>* sourceCode);

/* Line 371 of yacc.c  */
#line 81 "y.tab.h"

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
     DEVBLOCK_START = 298,
     DEVBLOCK_END = 299,
     EMPTY_ARRAY = 300,
     INT_LITERAL = 301,
     FLOAT_LITERAL = 302,
     IDENTIFIER = 303,
     PATH = 304,
     STRING_LITERAL = 305,
     LOC_STRING_LITERAL = 306,
     HASH_STRING_LITERAL = 307,
     IFX = 308,
     UNARY_ANIMREF = 309,
     UNARY_MINUS = 310
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 14 "..\\..\\gsc_cod9.y"

	int intValue;
	float floatValue;
	char* stringValue;
	sNode* nodeValue;
	std::vector<char*>* stringArrayValue;
	std::vector<sNode*>* nodeArrayValue;


/* Line 387 of yacc.c  */
#line 186 "y.tab.h"
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
#line 214 "y.tab.h"

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
#define YYLAST   1027

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNRULES -- Number of states.  */
#define YYNSTATES  262

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
       2,     2,     2,     2,     2,     2,     2,     2,    76,    68,
      57,    75,    58,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    72,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,    54,    78,    65,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    66,
      67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    10,    12,    15,    18,
      21,    25,    29,    35,    41,    42,    44,    48,    51,    54,
      57,    59,    61,    66,    73,    80,    88,    89,    91,    95,
      97,    99,   102,   105,   108,   111,   115,   119,   121,   123,
     125,   127,   132,   134,   136,   138,   140,   142,   146,   148,
     150,   152,   154,   156,   159,   163,   167,   169,   171,   173,
     175,   177,   179,   187,   189,   191,   193,   195,   197,   199,
     203,   207,   211,   215,   219,   223,   227,   231,   235,   239,
     243,   247,   251,   255,   259,   263,   267,   271,   274,   277,
     280,   283,   286,   288,   292,   296,   300,   304,   308,   312,
     316,   320,   324,   328,   332,   336,   338,   340,   342,   344,
     346,   348,   350,   352,   354,   356,   360,   364,   367,   370,
     373,   376,   380,   384,   387,   388,   390,   391,   393,   394,
     396,   398,   400,   403,   406,   409,   412,   415,   419,   421,
     424,   430,   438,   444,   454,   460
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      80,     0,    -1,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    81,    82,    -1,    81,    83,    -1,    81,    84,
      -1,     3,    49,    68,    -1,     3,    48,    68,    -1,     4,
      69,    50,    70,    68,    -1,    48,    69,    85,    70,   111,
      -1,    -1,    48,    -1,    85,    71,    48,    -1,    48,    87,
      -1,    94,    87,    -1,    96,    87,    -1,    33,    -1,    34,
      -1,    48,    69,    90,    70,    -1,    49,    42,    48,    69,
      90,    70,    -1,    48,    42,    48,    69,    90,    70,    -1,
      41,    99,    72,    72,    69,    90,    70,    -1,    -1,    99,
      -1,    90,    71,    99,    -1,    88,    -1,    89,    -1,    93,
      88,    -1,    93,    89,    -1,     5,    88,    -1,     5,    89,
      -1,    93,     5,    88,    -1,    93,     5,    89,    -1,    48,
      -1,    91,    -1,    94,    -1,    96,    -1,    95,    73,    99,
      72,    -1,    48,    -1,    91,    -1,    94,    -1,    96,    -1,
     100,    -1,    97,    74,    48,    -1,    48,    -1,    91,    -1,
      94,    -1,    96,    -1,   100,    -1,    42,    48,    -1,    48,
      42,    48,    -1,    49,    42,    48,    -1,    48,    -1,    46,
      -1,    47,    -1,    50,    -1,    51,    -1,    52,    -1,    69,
      99,    71,    99,    71,    99,    70,    -1,    45,    -1,    20,
      -1,    91,    -1,    94,    -1,    96,    -1,    98,    -1,    99,
      36,    99,    -1,    99,    35,    99,    -1,    99,    54,    99,
      -1,    99,    55,    99,    -1,    99,    56,    99,    -1,    99,
      39,    99,    -1,    99,    40,    99,    -1,    99,    57,    99,
      -1,    99,    58,    99,    -1,    99,    37,    99,    -1,    99,
      38,    99,    -1,    99,    32,    99,    -1,    99,    31,    99,
      -1,    99,    59,    99,    -1,    99,    60,    99,    -1,    99,
      61,    99,    -1,    99,    62,    99,    -1,    99,    63,    99,
      -1,    64,    99,    -1,    65,    99,    -1,    60,    46,    -1,
      60,    47,    -1,    63,    48,    -1,   100,    -1,    69,    99,
      70,    -1,   102,    75,    99,    -1,   102,    23,    99,    -1,
     102,    24,    99,    -1,   102,    25,    99,    -1,   102,    26,
      99,    -1,   102,    27,    99,    -1,   102,    22,    99,    -1,
     102,    21,    99,    -1,   102,    28,    99,    -1,   102,    29,
      99,    -1,   102,    30,    99,    -1,    48,    -1,    94,    -1,
      96,    -1,   104,    -1,   105,    -1,   106,    -1,   110,    -1,
     111,    -1,   113,    -1,   114,    -1,     7,    46,    76,    -1,
       7,    50,    76,    -1,     8,    76,    -1,    17,    68,    -1,
      15,    68,    -1,    16,    68,    -1,    16,    99,    68,    -1,
      18,    99,    68,    -1,    19,    68,    -1,    -1,   101,    -1,
      -1,    99,    -1,    -1,    86,    -1,   101,    -1,    68,    -1,
      86,    68,    -1,    91,    68,    -1,    92,    68,    -1,   101,
      68,    -1,    77,    78,    -1,    77,   112,    78,    -1,   103,
      -1,   112,   103,    -1,     9,    69,    99,    70,   103,    -1,
       9,    69,    99,    70,   103,    10,   103,    -1,     6,    69,
      99,    70,   111,    -1,    11,    69,   107,    68,   108,    68,
     109,    70,   103,    -1,    12,    69,    99,    70,   103,    -1,
      13,    69,    48,    14,    99,    70,   103,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    69,    73,    74,    75,    76,    77,    78,
      82,    83,    87,    91,    95,    96,    97,   102,   103,   104,
     108,   109,   114,   115,   116,   121,   125,   126,   127,   132,
     133,   134,   135,   140,   141,   142,   143,   148,   149,   150,
     151,   156,   161,   162,   163,   164,   165,   170,   175,   176,
     177,   178,   179,   183,   184,   185,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   229,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   247,   248,   249,   253,   254,
     255,   256,   257,   258,   259,   264,   265,   266,   270,   271,
     272,   273,   277,   278,   281,   283,   286,   288,   291,   293,
     294,   299,   300,   301,   302,   303,   307,   308,   312,   313,
     317,   318,   319,   323,   324,   325
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
  "DEREFERENCE_FUNC_START", "REFERENCE_FUNC", "DEVBLOCK_START",
  "DEVBLOCK_END", "EMPTY_ARRAY", "INT_LITERAL", "FLOAT_LITERAL",
  "IDENTIFIER", "PATH", "STRING_LITERAL", "LOC_STRING_LITERAL",
  "HASH_STRING_LITERAL", "IFX", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "UNARY_ANIMREF", "UNARY_MINUS",
  "';'", "'('", "')'", "','", "']'", "'['", "'.'", "'='", "':'", "'{'",
  "'}'", "$accept", "translation_unit", "source_code", "include",
  "using_animtree", "func_definition", "parameter_list_opt",
  "inc_dec_expression", "inc_dec", "func_call_noptr", "func_call_ptr",
  "argument_list_opt", "func_call_nothrd_expression",
  "func_call_thrd_expression", "func_valid_object",
  "array_subscripting_expression", "array_valid_name",
  "element_selection_expression", "element_valid_selection",
  "func_ref_expression", "expression", "parenthesized_expression",
  "assignment_expression", "operation_valid_lvalue", "statement",
  "labeled_statement", "jump_statement", "wait_statement",
  "for_init_value_opt", "for_condition_opt", "for_modify_value_opt",
  "expression_statement", "compound_statement", "statement_list",
  "selection_statement", "iteration_statement", YY_NULL
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
     305,   306,   307,   308,   124,    94,    38,    60,    62,    43,
      45,    42,    47,    37,    33,   126,   309,   310,    59,    40,
      41,    44,    93,    91,    46,    61,    58,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    84,    85,    85,    85,    86,    86,    86,
      87,    87,    88,    88,    88,    89,    90,    90,    90,    91,
      91,    91,    91,    92,    92,    92,    92,    93,    93,    93,
      93,    94,    95,    95,    95,    95,    95,    96,    97,    97,
      97,    97,    97,    98,    98,    98,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   103,   103,
     103,   103,   103,   103,   103,   104,   104,   104,   105,   105,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     109,   110,   110,   110,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   114,   114,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     1,     2,     2,     2,
       3,     3,     5,     5,     0,     1,     3,     2,     2,     2,
       1,     1,     4,     6,     6,     7,     0,     1,     3,     1,
       1,     2,     2,     2,     2,     3,     3,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     2,     3,     3,     1,     1,     1,     1,
       1,     1,     7,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     2,     2,
       2,     3,     3,     2,     0,     1,     0,     1,     0,     1,
       1,     1,     2,     2,     2,     2,     2,     3,     1,     2,
       5,     7,     5,     9,     5,     7
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
       0,     0,     0,   105,     0,   131,     0,   136,     0,    29,
      30,    38,     0,     0,   106,     0,   107,     0,    46,     0,
       0,   138,   108,   109,   110,   111,   112,     0,   113,   114,
       0,    33,    34,     0,     0,     0,   117,     0,   124,     0,
       0,   119,    64,     0,    63,    57,    58,    56,     0,    59,
      60,    61,     0,     0,     0,     0,   120,     0,    65,     0,
      66,    67,    68,     0,    92,   118,     0,   123,     0,    20,
      21,     0,    26,    17,     0,     0,   132,   133,   134,     0,
      31,    32,    18,     0,    19,     0,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   139,
       0,   115,   116,     0,   105,    38,   106,   107,   125,     0,
       0,     0,    53,     0,     0,    89,    90,    91,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     122,     0,     0,     0,    27,     0,    93,    35,    36,     0,
      47,   101,   100,    95,    96,    97,    98,    99,   102,   103,
     104,    94,     0,     0,   126,     0,     0,    54,    55,     0,
      81,    80,    70,    69,    78,    79,    74,    75,    71,    72,
      73,    76,    77,    82,    83,    84,    85,    86,     0,    26,
      22,     0,    26,    41,   142,   140,   127,     0,   144,     0,
       0,    26,     0,    28,     0,     0,   128,     0,     0,     0,
      24,    23,   141,   129,   130,     0,   145,     0,    25,     0,
      62,   143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    21,    48,   113,    49,
      50,   183,    98,    52,    99,   100,    55,   101,    57,   102,
     184,   104,    59,    60,    61,    62,    63,    64,   149,   237,
     255,    65,    66,    67,    68,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -185
static const yytype_int16 yypact[] =
{
      11,   -32,   -62,   -18,    43,    11,  -185,  -185,  -185,   -22,
     -19,    12,    22,  -185,  -185,  -185,  -185,  -185,  -185,     3,
    -185,    17,    -8,     2,    53,  -185,    15,  -185,  -185,    67,
      29,   -10,    30,    45,    51,    58,    63,    44,   325,    72,
     366,    92,   366,    48,   103,  -185,   366,  -185,   110,  -185,
    -185,    26,   116,    37,   100,    74,   281,    82,   113,   121,
     335,  -185,  -185,  -185,  -185,  -185,  -185,   255,  -185,  -185,
     -34,  -185,  -185,   366,   115,   138,  -185,   366,   -30,   366,
     168,  -185,  -185,   169,  -185,  -185,  -185,    77,   176,  -185,
    -185,  -185,    57,   183,   366,   366,  -185,   366,   252,    67,
     350,   354,  -185,   767,    50,  -185,   801,  -185,   401,  -185,
    -185,   187,   366,  -185,   189,   551,  -185,  -185,  -185,    67,
    -185,  -185,  -185,   366,  -185,   193,  -185,   366,   366,   366,
     366,   366,   366,   366,   366,   366,   366,   366,  -185,  -185,
     587,  -185,  -185,   623,   269,    79,   350,   354,  -185,   177,
     659,   230,  -185,   199,   200,  -185,  -185,  -185,  -185,  -185,
     477,   366,   366,   366,   366,   366,   366,   366,   366,   366,
     366,   366,   366,   366,   366,   366,   366,   366,   366,  -185,
    -185,   178,   180,    84,   835,   182,  -185,  -185,  -185,   439,
    -185,   835,   835,   835,   835,   835,   835,   835,   835,   835,
     835,   835,     2,   272,   366,   272,   366,   180,   182,   366,
      76,    76,   878,   845,     6,     6,   964,   964,   888,   921,
     931,     6,     6,    81,    81,  -185,  -185,  -185,   184,   366,
    -185,   366,   366,  -185,  -185,   242,   835,   186,  -185,   695,
     514,   366,    88,   835,   105,   272,    61,   272,   366,   123,
    -185,  -185,  -185,  -185,  -185,   188,  -185,   731,  -185,   272,
    -185,  -185
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,  -185,   251,   254,   270,  -185,    46,   -44,   -28,
     -24,  -184,   -26,  -185,   -13,   -23,  -185,   -20,  -185,  -185,
      34,   -17,   -74,  -185,    10,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,   -21,  -185,  -185,  -185
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -53
static const yytype_int16 yytable[] =
{
      51,    71,    27,    54,   148,    72,    56,    11,   111,    58,
     122,    42,   124,    53,     1,     2,     9,    10,   144,    44,
      29,    30,    31,    32,    33,   120,    34,    35,    36,   121,
      37,    38,    39,    40,    41,   112,    74,   161,   162,    46,
      75,    51,   119,    13,    54,   242,    17,    56,   244,    18,
      58,    12,   145,   -37,    53,   146,    42,   249,   147,     3,
      25,    58,    19,    43,    44,   174,   175,   176,   177,   178,
      20,   120,   103,    22,   106,   121,   108,   139,    42,    26,
     115,   109,   110,    45,    46,    70,    44,    23,    24,   -37,
     111,   187,    26,    47,   117,   188,   -37,   -37,    73,   -43,
     -49,    28,    42,   155,   156,   -39,    76,   140,    42,    43,
      44,   143,    81,   150,    77,    70,    44,   112,   -37,   153,
      78,   -42,   -48,   -46,   -52,   -37,   -37,    79,   158,   159,
      46,   160,    80,   109,   110,   174,   175,   176,   177,   178,
     105,   -39,   176,   177,   178,   114,   112,   123,   -39,   -39,
     -42,   -48,   -43,   -49,   230,   231,   125,   189,   250,   231,
     107,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   254,   -44,   -50,   251,   231,    51,   116,    51,
      54,   234,    54,    56,   118,    56,    58,   -52,    58,   126,
      53,   141,    53,   258,   231,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   235,   142,   238,   151,   152,   154,    51,
     145,    51,    54,    54,    54,    56,    56,    56,    58,    58,
      58,   157,    53,    51,    53,   182,    54,   185,   236,    56,
     239,   190,    58,   240,   206,   204,    53,   207,   208,   229,
     228,   232,   245,   241,   246,   252,    14,   256,   259,    15,
      29,    30,    31,    32,    33,   243,    34,    35,    36,   261,
      37,    38,    39,    40,    41,    16,     0,    29,    30,    31,
      32,    33,   257,    34,    35,    36,   -40,    37,    38,    39,
      40,    41,   253,   -38,     0,     0,    42,     0,     0,     0,
     -38,   -38,     0,    43,    44,     0,     0,     0,     0,     0,
     -37,   111,     0,    42,   109,   110,     0,   -37,   -37,     0,
      43,    44,   -40,    45,    46,   -43,   -49,     0,     0,   -40,
     -40,     0,    26,   138,     0,     0,     0,     0,   112,     0,
      45,    46,   -42,   -48,     0,    82,     0,     0,     0,    26,
       0,     0,     0,     0,   -45,   -51,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    42,    83,     0,     0,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,     0,     0,     0,     0,    92,    82,     0,    93,    94,
      95,   -39,     0,    96,    97,   -40,     0,     0,   -39,   -39,
       0,     0,   -40,   -40,     0,     0,     0,    42,    83,     0,
     137,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,   -44,   -50,     0,    92,   -45,   -51,    93,
      94,    95,   161,   162,     0,    97,   163,   164,   165,   166,
     167,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,     0,     0,     0,     0,
     161,   162,     0,   181,   163,   164,   165,   166,   167,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,     0,     0,     0,     0,   161,   162,
       0,   233,   163,   164,   165,   166,   167,   168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,     0,     0,     0,     0,   161,   162,   186,   209,   163,
     164,   165,   166,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     0,
       0,     0,   161,   162,     0,   248,   163,   164,   165,   166,
     167,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,     0,     0,   161,   162,
       0,   186,   163,   164,   165,   166,   167,   168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,     0,     0,     0,   161,   162,     0,   202,   163,   164,
     165,   166,   167,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,     0,     0,
     161,   162,     0,   203,   163,   164,   165,   166,   167,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,     0,     0,   161,   162,     0,   205,
     163,   164,   165,   166,   167,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,     0,
       0,     0,   161,   162,     0,   247,   163,   164,   165,   166,
     167,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,     0,     0,   161,   162,
       0,   260,   163,   164,   165,   166,   167,   168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,     0,   161,   162,     0,   179,   163,   164,   165,   166,
     167,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     0,   161,   162,     0,   180,
     163,   164,   165,   166,   167,   168,   161,   162,     0,     0,
     163,     0,   165,   166,   167,   168,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   161,
     162,     0,     0,     0,     0,   165,   166,   167,   168,   161,
     162,     0,     0,     0,     0,   165,   166,   167,   168,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     0,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   161,   162,     0,     0,     0,     0,   165,   166,
     167,   168,   161,   162,     0,     0,     0,     0,   165,   166,
     167,   168,     0,     0,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,     0,     0,     0,   172,   173,
     174,   175,   176,   177,   178,   161,   162,     0,     0,     0,
       0,   165,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,   173,   174,   175,   176,   177,   178
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-185)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      26,    29,    23,    26,    78,    29,    26,    69,    42,    26,
      54,    41,    56,    26,     3,     4,    48,    49,    48,    49,
       5,     6,     7,     8,     9,    53,    11,    12,    13,    53,
      15,    16,    17,    18,    19,    69,    46,    31,    32,    69,
      50,    67,     5,     0,    67,   229,    68,    67,   232,    68,
      67,    69,    78,     5,    67,    78,    41,   241,    78,    48,
      68,    78,    50,    48,    49,    59,    60,    61,    62,    63,
      48,    99,    38,    70,    40,    99,    42,    67,    41,    77,
      46,    33,    34,    68,    69,    48,    49,    70,    71,    41,
      42,   119,    77,    78,    68,   119,    48,    49,    69,    73,
      74,    48,    41,    46,    47,     5,    76,    73,    41,    48,
      49,    77,    68,    79,    69,    48,    49,    69,    41,    42,
      69,    73,    74,    73,    74,    48,    49,    69,    94,    95,
      69,    97,    69,    33,    34,    59,    60,    61,    62,    63,
      68,    41,    61,    62,    63,    42,    69,    73,    48,    49,
      73,    74,    73,    74,    70,    71,    74,   123,    70,    71,
      68,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   246,    73,    74,    70,    71,   203,    68,   205,
     203,   202,   205,   203,    68,   205,   203,    74,   205,    68,
     203,    76,   205,    70,    71,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   203,    76,   205,    48,    48,    42,   245,
     246,   247,   245,   246,   247,   245,   246,   247,   245,   246,
     247,    48,   245,   259,   247,    48,   259,    48,   204,   259,
     206,    48,   259,   209,    14,    68,   259,    48,    48,    69,
      72,    69,    10,    69,    68,   245,     5,   247,    70,     5,
       5,     6,     7,     8,     9,   231,    11,    12,    13,   259,
      15,    16,    17,    18,    19,     5,    -1,     5,     6,     7,
       8,     9,   248,    11,    12,    13,     5,    15,    16,    17,
      18,    19,   246,    41,    -1,    -1,    41,    -1,    -1,    -1,
      48,    49,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      41,    42,    -1,    41,    33,    34,    -1,    48,    49,    -1,
      48,    49,    41,    68,    69,    73,    74,    -1,    -1,    48,
      49,    -1,    77,    78,    -1,    -1,    -1,    -1,    69,    -1,
      68,    69,    73,    74,    -1,    20,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    73,    74,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    41,    42,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    20,    -1,    63,    64,
      65,    41,    -1,    68,    69,    41,    -1,    -1,    48,    49,
      -1,    -1,    48,    49,    -1,    -1,    -1,    41,    42,    -1,
      75,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    73,    74,    -1,    60,    73,    74,    63,
      64,    65,    31,    32,    -1,    69,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    72,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    72,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    31,    32,    70,    71,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    31,    32,    -1,    71,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    31,    32,
      -1,    70,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    31,    32,    -1,    70,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      31,    32,    -1,    70,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    31,    32,    -1,    70,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    31,    32,    -1,    70,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    31,    32,
      -1,    70,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    31,    32,    -1,    68,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    31,    32,    -1,    68,
      35,    36,    37,    38,    39,    40,    31,    32,    -1,    -1,
      35,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    31,
      32,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    31,
      32,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    31,    32,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    31,    32,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    31,    32,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    48,    80,    81,    82,    83,    84,    48,
      49,    69,    69,     0,    82,    83,    84,    68,    68,    50,
      48,    85,    70,    70,    71,    68,    77,   111,    48,     5,
       6,     7,     8,     9,    11,    12,    13,    15,    16,    17,
      18,    19,    41,    48,    49,    68,    69,    78,    86,    88,
      89,    91,    92,    93,    94,    95,    96,    97,   100,   101,
     102,   103,   104,   105,   106,   110,   111,   112,   113,   114,
      48,    88,    89,    69,    46,    50,    76,    69,    69,    69,
      69,    68,    20,    42,    45,    46,    47,    48,    49,    50,
      51,    52,    60,    63,    64,    65,    68,    69,    91,    93,
      94,    96,    98,    99,   100,    68,    99,    68,    99,    33,
      34,    42,    69,    87,    42,    99,    68,    68,    68,     5,
      88,    89,    87,    73,    87,    74,    68,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    75,    78,   103,
      99,    76,    76,    99,    48,    91,    94,    96,   101,   107,
      99,    48,    48,    42,    42,    46,    47,    48,    99,    99,
      99,    31,    32,    35,    36,    37,    38,    39,    40,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    68,
      68,    72,    48,    90,    99,    48,    70,    88,    89,    99,
      48,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    70,    70,    68,    70,    14,    48,    48,    71,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    72,    69,
      70,    71,    69,    72,   111,   103,    99,   108,   103,    99,
      99,    69,    90,    99,    90,    10,    68,    70,    71,    90,
      70,    70,   103,    86,   101,   109,   103,    99,    70,    70,
      70,   103
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
    { OnParsingComplete((yyvsp[(1) - (1)].nodeArrayValue)); }
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
    { (yyval.nodeValue) = AllocFuncDefinition((yyvsp[(1) - (5)].stringValue), (yyvsp[(3) - (5)].stringArrayValue)/*, $5*/); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 95 "..\\..\\gsc_cod9.y"
    { (yyval.stringArrayValue) = 0; }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 96 "..\\..\\gsc_cod9.y"
    { (yyval.stringArrayValue) = new std::vector<char*>(1, (yyvsp[(1) - (1)].stringValue)); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 97 "..\\..\\gsc_cod9.y"
    { (yyval.stringArrayValue) = (yyvsp[(1) - (3)].stringArrayValue); (yyval.stringArrayValue)->push_back((yyvsp[(3) - (3)].stringValue)); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 102 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocIncDecExpression(IdentifierToNode((yyvsp[(1) - (2)].stringValue)), (yyvsp[(2) - (2)].intValue)); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 103 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocIncDecExpression((yyvsp[(1) - (2)].nodeValue), (yyvsp[(2) - (2)].intValue)); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 104 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocIncDecExpression((yyvsp[(1) - (2)].nodeValue), (yyvsp[(2) - (2)].intValue)); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 108 "..\\..\\gsc_cod9.y"
    { (yyval.intValue) = 0; }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 109 "..\\..\\gsc_cod9.y"
    { (yyval.intValue) = 1; }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 114 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncCall((yyvsp[(1) - (4)].stringValue), 0, (yyvsp[(3) - (4)].nodeArrayValue), 0, 0, 0, 0, 0); }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 115 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncCall((yyvsp[(3) - (6)].stringValue), (yyvsp[(1) - (6)].stringValue), (yyvsp[(5) - (6)].nodeArrayValue), 0, 0, 0, 0, 0); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 116 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncCall((yyvsp[(3) - (6)].stringValue), (yyvsp[(1) - (6)].stringValue), (yyvsp[(5) - (6)].nodeArrayValue), 0, 0, 0, 0, 0); }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 121 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncCall(0, 0, (yyvsp[(6) - (7)].nodeArrayValue), 1, (yyvsp[(2) - (7)].nodeValue), 0, 0, 0); }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 125 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = 0; }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 126 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = new std::vector<sNode*>(1, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 127 "..\\..\\gsc_cod9.y"
    { (yyval.nodeArrayValue) = (yyvsp[(1) - (3)].nodeArrayValue); (yyval.nodeArrayValue)->push_back((yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 132 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); (yyval.nodeValue)->funcCall->isThread = 0; }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 133 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); (yyval.nodeValue)->funcCall->isThread = 0; }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 134 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(2) - (2)].nodeValue); (yyval.nodeValue)->funcCall->isThread = 0; (yyval.nodeValue)->funcCall->isMethod = 1; (yyval.nodeValue)->funcCall->methodObject = (yyvsp[(1) - (2)].nodeValue); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 135 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(2) - (2)].nodeValue); (yyval.nodeValue)->funcCall->isThread = 0; (yyval.nodeValue)->funcCall->isMethod = 1; (yyval.nodeValue)->funcCall->methodObject = (yyvsp[(1) - (2)].nodeValue); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 140 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(2) - (2)].nodeValue); (yyval.nodeValue)->funcCall->isThread = 1; }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 141 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(2) - (2)].nodeValue); (yyval.nodeValue)->funcCall->isThread = 1; }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 142 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(3) - (3)].nodeValue); (yyval.nodeValue)->funcCall->isThread = 1; (yyval.nodeValue)->funcCall->isMethod = 1; (yyval.nodeValue)->funcCall->methodObject = (yyvsp[(1) - (3)].nodeValue); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 143 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(3) - (3)].nodeValue); (yyval.nodeValue)->funcCall->isThread = 1; (yyval.nodeValue)->funcCall->isMethod = 1; (yyval.nodeValue)->funcCall->methodObject = (yyvsp[(1) - (3)].nodeValue); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 148 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = IdentifierToNode((yyvsp[(1) - (1)].stringValue)); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 149 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 150 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 151 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 156 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocArraySubscriptingExpression((yyvsp[(1) - (4)].nodeValue), (yyvsp[(3) - (4)].nodeValue)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 161 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = IdentifierToNode((yyvsp[(1) - (1)].stringValue)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 162 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 163 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 164 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 165 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 170 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocElementSelectionExpression((yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].stringValue)); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 175 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = IdentifierToNode((yyvsp[(1) - (1)].stringValue)); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 176 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 177 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 178 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 179 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 183 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncRefExpression(0, (yyvsp[(2) - (2)].stringValue)); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 184 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncRefExpression((yyvsp[(1) - (3)].stringValue), (yyvsp[(3) - (3)].stringValue)); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 185 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocFuncRefExpression((yyvsp[(1) - (3)].stringValue), (yyvsp[(3) - (3)].stringValue)); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 189 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_IDENTIFIER, (yyvsp[(1) - (1)].stringValue)); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 190 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_INT, (yyvsp[(1) - (1)].intValue)); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 191 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_FLOAT, (yyvsp[(1) - (1)].floatValue)); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 192 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_STRING, (yyvsp[(1) - (1)].stringValue)); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 193 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_LOC_STRING, (yyvsp[(1) - (1)].stringValue)); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 194 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_HASH_STRING, (yyvsp[(1) - (1)].stringValue)); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 195 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_VECTOR, (yyvsp[(2) - (7)].nodeValue), (yyvsp[(4) - (7)].nodeValue), (yyvsp[(6) - (7)].nodeValue)); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 196 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_EMPTY_ARRAY); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 197 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_UNDEFINED); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 198 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_FUNC_CALL_NOTHRD, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 199 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_ARRAY_SUBSCRIPTING, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 200 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_ELEMENT_SELECTION, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 201 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_FUNC_REF, (yyvsp[(1) - (1)].nodeValue)); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 202 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_LOGICAL_OR_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 203 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_LOGICAL_AND_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 204 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_BIT_OR_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 205 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_BIT_EX_OR_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 206 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_BIT_AND_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 207 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_EQUALITY_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 208 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_INEQUALITY_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 209 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_LESS_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 210 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_GREATER_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 211 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_LESS_EQUAL_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 212 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_GREATER_EQUAL_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 213 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_SHIFT_LEFT_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 214 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_SHIFT_RIGHT_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 215 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_PLUS_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 216 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_MINUS_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 217 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_MULTIPLY_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 218 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_DIVIDE_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 219 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_MOD_OP, (yyvsp[(1) - (3)].nodeValue), (yyvsp[(3) - (3)].nodeValue)); }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 220 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_BOOL_NOT_OP, (yyvsp[(2) - (2)].nodeValue)); }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 221 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_BOOL_COMPLEMENT_OP, (yyvsp[(2) - (2)].nodeValue)); }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 222 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_UMINUS_INT_OP, (yyvsp[(2) - (2)].intValue)); }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 223 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_UMINUS_FLOAT_OP, (yyvsp[(2) - (2)].floatValue)); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 224 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = AllocExpression(TYPE_EXPR_UANIMREF_OP, (yyvsp[(2) - (2)].stringValue)); }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 225 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 229 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(2) - (3)].nodeValue); }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 247 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = IdentifierToNode((yyvsp[(1) - (1)].stringValue)); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 248 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 249 "..\\..\\gsc_cod9.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;


/* Line 1787 of yacc.c  */
#line 2381 "y.tab.h"
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
#line 328 "..\\..\\gsc_cod9.y"


void yyerror(char const *s)
{
	printf("error: %s\nat line %d\n", s, lineCount);
	system("pause");
}