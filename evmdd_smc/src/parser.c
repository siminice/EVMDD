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
     TIDENT = 258,
     TPRIME = 259,
     TNUM = 260,
     TPLUS = 261,
     TMINUS = 262,
     TMULT = 263,
     TTT = 264,
     TFF = 265,
     TLT = 266,
     TLE = 267,
     TGT = 268,
     TGE = 269,
     TEQ = 270,
     TNEQ = 271,
     TNOT = 272,
     TOR = 273,
     TAND = 274,
     TLPAR = 275,
     TRPAR = 276,
     TPOW = 277,
     TLBRA = 278,
     TRBRA = 279,
     TCOMMA = 280,
     TQMARK = 281,
     TTIL = 282,
     TNL = 283,
     TVAR = 284,
     TDEF = 285,
     TEQN = 286,
     TINIT = 287,
     TTRANS = 288,
     TSEMI = 289,
     TARROW = 290,
     TAX = 291,
     TAG = 292,
     TAF = 293,
     TA = 294,
     TEX = 295,
     TEG = 296,
     TEF = 297,
     TE = 298,
     TX = 299,
     TF = 300,
     TG = 301,
     TU = 302,
     TR = 303,
     TPROP = 304,
     TMOD = 305,
     TDIV = 306,
     TNEG = 307
   };
#endif
/* Tokens.  */
#define TIDENT 258
#define TPRIME 259
#define TNUM 260
#define TPLUS 261
#define TMINUS 262
#define TMULT 263
#define TTT 264
#define TFF 265
#define TLT 266
#define TLE 267
#define TGT 268
#define TGE 269
#define TEQ 270
#define TNEQ 271
#define TNOT 272
#define TOR 273
#define TAND 274
#define TLPAR 275
#define TRPAR 276
#define TPOW 277
#define TLBRA 278
#define TRBRA 279
#define TCOMMA 280
#define TQMARK 281
#define TTIL 282
#define TNL 283
#define TVAR 284
#define TDEF 285
#define TEQN 286
#define TINIT 287
#define TTRANS 288
#define TSEMI 289
#define TARROW 290
#define TAX 291
#define TAG 292
#define TAF 293
#define TA 294
#define TEX 295
#define TEG 296
#define TEF 297
#define TE 298
#define TX 299
#define TF 300
#define TG 301
#define TU 302
#define TR 303
#define TPROP 304
#define TMOD 305
#define TDIV 306
#define TNEG 307




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

  #include <stdlib.h>
  #include <stdio.h>
  #include "ast.h"
  #include "env.h"
  int yylex();
  extern int yylineno;
  extern char *yytext;
  void yyerror(char *);
  static struct ast *build_unode(ast_ops_t, struct ast*);
  static struct ast *build_node(ast_ops_t, struct ast*, struct ast*);
  extern void add_init_states(struct ast*);
  extern void add_equations(struct ast*);
  extern void add_event(struct ast*, char*);
  extern void check_property(struct ast*, char*);
  extern int build_model();
  extern int verbosity_level;


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
#line 20 "parser.y"
{
  int value;
  char *name;
  struct ast *ast;
}
/* Line 193 of yacc.c.  */
#line 225 "parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 238 "parser.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    12,    17,    22,    26,    30,    33,
      35,    38,    42,    44,    47,    51,    53,    56,    60,    62,
      65,    69,    71,    74,    78,    80,    83,    87,    94,    98,
     100,   104,   106,   110,   112,   116,   118,   120,   124,   128,
     132,   136,   140,   144,   146,   149,   153,   157,   161,   163,
     165,   169,   173,   177,   181,   185,   189,   192,   196,   197,
     199,   202,   204,   207,   209,   212,   216,   220,   224,   227,
     230,   237,   240,   243,   246,   249,   256,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    28,    54,    -1,    55,    56,    58,    59,
      60,    -1,    55,    56,    58,    59,    -1,    55,    58,    59,
      60,    -1,    55,    58,    59,    -1,    55,    56,    57,    -1,
      55,    57,    -1,    29,    -1,    55,    28,    -1,    55,    61,
      28,    -1,    30,    -1,    56,    28,    -1,    56,    62,    28,
      -1,    31,    -1,    57,    28,    -1,    57,    67,    28,    -1,
      32,    -1,    58,    28,    -1,    58,    67,    28,    -1,    33,
      -1,    59,    28,    -1,    59,    63,    28,    -1,    49,    -1,
      60,    28,    -1,    60,    65,    28,    -1,     3,    23,    71,
      25,    71,    24,    -1,     3,    15,    68,    -1,    64,    -1,
       3,    34,    64,    -1,    67,    -1,    67,    35,    67,    -1,
      72,    -1,     3,    34,    72,    -1,     9,    -1,    10,    -1,
      68,    11,    68,    -1,    68,    12,    68,    -1,    68,    13,
      68,    -1,    68,    14,    68,    -1,    68,    15,    68,    -1,
      68,    16,    68,    -1,    66,    -1,    17,    67,    -1,    67,
      18,    67,    -1,    67,    19,    67,    -1,    20,    67,    21,
      -1,    71,    -1,    70,    -1,    70,    22,    71,    -1,    68,
       6,    68,    -1,    68,     7,    68,    -1,    68,     8,    68,
      -1,    68,    51,    68,    -1,    68,    50,    68,    -1,     7,
      68,    -1,    20,    68,    21,    -1,    -1,     4,    -1,     3,
      69,    -1,     5,    -1,     7,     5,    -1,    66,    -1,    17,
      72,    -1,    72,    18,    72,    -1,    72,    19,    72,    -1,
      20,    72,    21,    -1,    40,    72,    -1,    41,    72,    -1,
      43,    23,    72,    47,    72,    24,    -1,    36,    72,    -1,
      42,    72,    -1,    37,    72,    -1,    38,    72,    -1,    39,
      23,    72,    47,    72,    24,    -1,    39,    23,    72,    48,
      72,    24,    -1,    43,    23,    72,    48,    72,    24,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    57,    58,    59,    60,    61,    62,    65,
      66,    67,    70,    71,    72,    75,    76,    77,    81,    82,
      83,    87,    88,    89,    92,    93,    94,    97,   107,   117,
     119,   123,   124,   134,   135,   138,   141,   144,   145,   146,
     147,   148,   149,   152,   153,   154,   155,   156,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   171,   174,   175,
     178,   196,   199,   205,   206,   207,   208,   209,   210,   211,
     212,   214,   217,   221,   228,   231,   242,   247
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "TPRIME", "TNUM", "TPLUS",
  "TMINUS", "TMULT", "TTT", "TFF", "TLT", "TLE", "TGT", "TGE", "TEQ",
  "TNEQ", "TNOT", "TOR", "TAND", "TLPAR", "TRPAR", "TPOW", "TLBRA",
  "TRBRA", "TCOMMA", "TQMARK", "TTIL", "TNL", "TVAR", "TDEF", "TEQN",
  "TINIT", "TTRANS", "TSEMI", "TARROW", "TAX", "TAG", "TAF", "TA", "TEX",
  "TEG", "TEF", "TE", "TX", "TF", "TG", "TU", "TR", "TPROP", "TMOD",
  "TDIV", "TNEG", "$accept", "input", "decls", "defs", "eqns", "inits",
  "events", "properties", "decl", "def", "event", "event_body", "property",
  "atom_bool_exp", "bool_exp", "int_exp", "prime", "var", "constant",
  "ctl", 0
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
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    55,    56,    56,    56,    57,    57,    57,    58,    58,
      58,    59,    59,    59,    60,    60,    60,    61,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     4,     4,     3,     3,     2,     1,
       2,     3,     1,     2,     3,     1,     2,     3,     1,     2,
       3,     1,     2,     3,     1,     2,     3,     6,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     2,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     2,     3,     0,     1,
       2,     1,     2,     1,     2,     3,     3,     3,     2,     2,
       6,     2,     2,     2,     2,     6,     6,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     9,     0,     0,     2,     1,     0,    10,    12,
      15,    18,     0,     8,     0,     0,     0,     0,    13,     7,
       0,     0,    58,    61,     0,    35,    36,     0,     0,    16,
      43,     0,     0,    49,    48,    19,    21,     6,     0,    11,
       0,     0,     0,     4,    14,    59,    60,    61,     0,    56,
      44,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    22,
      24,     5,     0,    29,    31,    20,    62,     0,    28,     3,
       0,    47,    57,    45,    46,    51,    52,    53,    37,    38,
      39,    40,    41,    42,    55,    54,    50,     0,    58,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    33,    23,     0,     0,    30,     0,    64,     0,
      71,    73,    74,     0,    68,    69,    72,     0,    26,     0,
       0,    32,    27,    34,    67,     0,     0,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,    70,
      77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    12,    13,    14,    37,    71,    15,    21,
      72,    73,   110,   111,    74,    32,    46,    33,    34,   112
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -17
static const yytype_int16 yypact[] =
{
     -16,   -16,   -17,     5,    96,   -17,   -17,     3,   -17,   -17,
     -17,   -17,   117,   255,   246,    16,    91,    32,   -17,   255,
     246,    22,    63,   -17,   165,   -17,   -17,   214,   214,   -17,
     -17,    10,   100,    52,   -17,   -17,   -17,    61,    54,   -17,
      78,    77,   191,    61,   -17,   -17,   -17,   -17,   191,   -17,
     -17,   161,    79,   214,   214,   -17,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,    91,     0,   -17,
     -17,   164,    49,   -17,    -8,   -17,   -17,    91,   111,   164,
      25,   -17,   -17,    69,   -17,    72,    72,   -17,   111,   111,
     111,   111,   111,   111,   -17,   -17,   -17,   214,    31,   205,
     205,   -17,   205,   205,   205,    98,   205,   205,   205,   102,
      81,   -17,    18,   -17,   214,   109,   -17,   205,   -17,   208,
     -17,   -17,   -17,   205,   -17,   -17,   -17,   205,   -17,   205,
     205,    86,   -17,    18,   -17,     1,     4,   115,   -17,   205,
     205,   205,   205,   113,   128,   136,   169,   -17,   -17,   -17,
     -17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -17,   140,   -17,   -17,   144,   145,   138,   121,   -17,   -17,
     -17,    89,   -17,   -13,   -11,    -3,   -17,   -17,     2,    36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      30,    30,    31,    38,    45,     6,    30,    30,    31,    38,
      53,    54,     1,     2,    30,    30,    50,    51,    41,   129,
     130,    49,   129,   130,    30,    52,    16,   114,    53,    54,
      30,    56,    57,    58,    97,    45,   129,   130,    55,    78,
      30,    30,    83,    84,    39,    80,    82,    42,   139,   140,
      44,   141,   142,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    68,   117,    23,    45,    24,    96,
      25,    26,    53,    54,    67,    65,    66,   113,    27,   115,
      58,    28,    75,    76,    30,    56,    57,    58,    54,    69,
      59,    60,    61,    62,    63,    64,    23,    52,    40,     7,
      82,    30,    77,   131,    53,    54,    56,    57,    58,   128,
      70,    59,    60,    61,    62,    63,    64,    56,    57,    58,
      17,   123,    65,    66,     8,   127,     9,    10,    11,    65,
      66,   129,   130,   132,   130,   118,   119,   147,   120,   121,
     122,     5,   124,   125,   126,    18,   129,   130,    10,    11,
      65,    66,   148,   133,   129,   130,    19,    20,    43,   135,
     149,    65,    66,   136,    79,   137,   138,    98,    22,    23,
      47,    24,    24,    25,    26,   143,   144,   145,   146,    53,
      54,    99,    81,     0,   100,    48,   116,   129,   130,     0,
       0,     0,   101,   150,    22,     0,    23,     0,    24,     0,
     102,   103,   104,   105,   106,   107,   108,   109,    22,     0,
      23,    48,    24,     0,    25,    26,     0,    22,     0,    23,
       0,    24,    99,    25,    26,   100,   129,   130,     0,   134,
       0,    27,     0,     0,    28,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,    22,
       0,    23,     0,    24,     0,    25,    26,     0,    22,     0,
      23,     0,    24,    27,    25,    26,    28,     0,     0,     0,
       0,     0,    27,     0,    35,    28,     0,     0,     0,    36,
       0,     0,     0,    29
};

static const yytype_int16 yycheck[] =
{
      13,    14,    13,    14,     4,     0,    19,    20,    19,    20,
      18,    19,    28,    29,    27,    28,    27,    28,    16,    18,
      19,    24,    18,    19,    37,    28,    23,    35,    18,    19,
      43,     6,     7,     8,    34,     4,    18,    19,    28,    42,
      53,    54,    53,    54,    28,    48,    21,    15,    47,    48,
      28,    47,    48,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     3,    34,     5,     4,     7,    67,
       9,    10,    18,    19,    22,    50,    51,    28,    17,    77,
       8,    20,    28,     5,    97,     6,     7,     8,    19,    28,
      11,    12,    13,    14,    15,    16,     5,   100,     7,     3,
      21,   114,    25,   114,    18,    19,     6,     7,     8,    28,
      49,    11,    12,    13,    14,    15,    16,     6,     7,     8,
       3,    23,    50,    51,    28,    23,    30,    31,    32,    50,
      51,    18,    19,    24,    19,    99,   100,    24,   102,   103,
     104,     1,   106,   107,   108,    28,    18,    19,    31,    32,
      50,    51,    24,   117,    18,    19,    12,    12,    20,   123,
      24,    50,    51,   127,    43,   129,   130,     3,     3,     5,
       5,     7,     7,     9,    10,   139,   140,   141,   142,    18,
      19,    17,    21,    -1,    20,    20,    97,    18,    19,    -1,
      -1,    -1,    28,    24,     3,    -1,     5,    -1,     7,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,     3,    -1,
       5,    20,     7,    -1,     9,    10,    -1,     3,    -1,     5,
      -1,     7,    17,     9,    10,    20,    18,    19,    -1,    21,
      -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,     3,
      -1,     5,    -1,     7,    -1,     9,    10,    -1,     3,    -1,
       5,    -1,     7,    17,     9,    10,    20,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    28,    20,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    29,    54,    55,    54,     0,     3,    28,    30,
      31,    32,    56,    57,    58,    61,    23,     3,    28,    57,
      58,    62,     3,     5,     7,     9,    10,    17,    20,    28,
      66,    67,    68,    70,    71,    28,    33,    59,    67,    28,
       7,    71,    15,    59,    28,     4,    69,     5,    20,    68,
      67,    67,    68,    18,    19,    28,     6,     7,     8,    11,
      12,    13,    14,    15,    16,    50,    51,    22,     3,    28,
      49,    60,    63,    64,    67,    28,     5,    25,    68,    60,
      68,    21,    21,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    71,    34,     3,    17,
      20,    28,    36,    37,    38,    39,    40,    41,    42,    43,
      65,    66,    72,    28,    35,    71,    64,    34,    72,    72,
      72,    72,    72,    23,    72,    72,    72,    23,    28,    18,
      19,    67,    24,    72,    21,    72,    72,    72,    72,    47,
      48,    47,    48,    72,    72,    72,    72,    24,    24,    24,
      24
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
        case 17:
#line 77 "parser.y"
    { equation_put(NULL, (yyvsp[(2) - (3)].ast)); }
    break;

  case 20:
#line 83 "parser.y"
    { init_put((yyvsp[(2) - (3)].ast)); }
    break;

  case 27:
#line 98 "parser.y"
    { int id;
                                         if (env_is_in((yyvsp[(1) - (6)].name), NULL, NULL)) {
                                           fprintf(stderr, "Error: variable \"%s\" already declared, skipping declaration.\n", (yyvsp[(1) - (6)].name));
                                           free((yyvsp[(1) - (6)].name));
                                         } else {
                                           id = env_put((yyvsp[(1) - (6)].name), (yyvsp[(3) - (6)].ast)->node_content.constant, (yyvsp[(5) - (6)].ast)->node_content.constant);
                                         } }
    break;

  case 28:
#line 108 "parser.y"
    { int id;
                                         if (mdf_is_in((yyvsp[(1) - (3)].name), NULL, NULL)) {
                                           fprintf(stderr, "Error: macro \"%s\" already declared, skipping declaration.\n", (yyvsp[(1) - (3)].name));
                                           free((yyvsp[(1) - (3)].name));
                                         } else {
                                         id = mdf_put((yyvsp[(1) - (3)].name), (yyvsp[(3) - (3)].ast));
                                         } }
    break;

  case 29:
#line 117 "parser.y"
    { event_put(NULL, (yyvsp[(1) - (1)].ast)); }
    break;

  case 30:
#line 119 "parser.y"
    { event_put((yyvsp[(1) - (3)].name), (yyvsp[(3) - (3)].ast)); }
    break;

  case 31:
#line 123 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 32:
#line 125 "parser.y"
    { if ((yyvsp[(1) - (3)].ast) && ast_contains_primed_var((yyvsp[(1) - (3)].ast))) {
                                           fprintf(stderr, "Error: guard (before '->') should not contain any primed variable.\n");
                                           free((yyvsp[(1) - (3)].ast));
                                           free((yyvsp[(3) - (3)].ast));
                                           (yyval.ast) = NULL;
                                         } else
                                           (yyval.ast) = build_node(AST_AND, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 33:
#line 134 "parser.y"
    { check_property((yyvsp[(1) - (1)].ast), NULL); }
    break;

  case 34:
#line 135 "parser.y"
    { check_property((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].name)); }
    break;

  case 35:
#line 138 "parser.y"
    { (yyval.ast) = malloc(sizeof(struct ast));
                                         (yyval.ast)->node_type = AST_CONST;
                                         (yyval.ast)->node_content.constant = 1; }
    break;

  case 36:
#line 141 "parser.y"
    { (yyval.ast) = malloc(sizeof(struct ast));
                                         (yyval.ast)->node_type = AST_CONST;
                                         (yyval.ast)->node_content.constant = 0; }
    break;

  case 37:
#line 144 "parser.y"
    { (yyval.ast) = build_node(AST_LT, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 38:
#line 145 "parser.y"
    { (yyval.ast) = build_unode(AST_NOT, build_node(AST_LT, (yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast))); }
    break;

  case 39:
#line 146 "parser.y"
    { (yyval.ast) = build_node(AST_LT, (yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); }
    break;

  case 40:
#line 147 "parser.y"
    { (yyval.ast) = build_unode(AST_NOT, build_node(AST_LT, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast))); }
    break;

  case 41:
#line 148 "parser.y"
    { (yyval.ast) = build_node(AST_EQ, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 42:
#line 149 "parser.y"
    { (yyval.ast) = build_unode(AST_NOT, build_node(AST_EQ, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast))); }
    break;

  case 43:
#line 152 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 44:
#line 153 "parser.y"
    { (yyval.ast) = build_unode(AST_NOT, (yyvsp[(2) - (2)].ast)); }
    break;

  case 45:
#line 154 "parser.y"
    { (yyval.ast) = build_node(AST_OR, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 46:
#line 155 "parser.y"
    { (yyval.ast) = build_node(AST_AND, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 47:
#line 156 "parser.y"
    { (yyval.ast) = (yyvsp[(2) - (3)].ast); }
    break;

  case 48:
#line 159 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 49:
#line 160 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 50:
#line 161 "parser.y"
    { (yyval.ast) = build_node(AST_POW, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 51:
#line 162 "parser.y"
    { (yyval.ast) = build_node(AST_ADD, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 52:
#line 163 "parser.y"
    { (yyval.ast) = build_node(AST_SUB, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 53:
#line 164 "parser.y"
    { (yyval.ast) = build_node(AST_MUL, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 54:
#line 165 "parser.y"
    { (yyval.ast) = build_node(AST_DIV, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 55:
#line 166 "parser.y"
    { (yyval.ast) = build_node(AST_MOD, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 56:
#line 167 "parser.y"
    { struct ast *n = malloc(sizeof(struct ast));
                                         n->node_type = AST_CONST;
                                         n->node_content.constant = -1;
                                         (yyval.ast) = build_node(AST_MUL, n, (yyvsp[(2) - (2)].ast)); }
    break;

  case 57:
#line 171 "parser.y"
    { (yyval.ast) = (yyvsp[(2) - (3)].ast); }
    break;

  case 58:
#line 174 "parser.y"
    { (yyval.value) = 0; }
    break;

  case 59:
#line 175 "parser.y"
    { (yyval.value) = 1; }
    break;

  case 60:
#line 178 "parser.y"
    { int vid = env_is_in((yyvsp[(1) - (2)].name), NULL, NULL);
					 int mid = mdf_is_in((yyvsp[(1) - (2)].name), NULL, NULL);
                                         if (vid==0 && mid==0) {
                                           fprintf(stderr, "Error: undeclared variable \"%s\", skipping expression.\n", (yyvsp[(1) - (2)].name));
                                           free((yyvsp[(1) - (2)].name));
                                           (yyval.ast) = NULL;
                                         } else if (vid>0) {
                                           (yyval.ast) = malloc(sizeof(struct ast));
                                           (yyval.ast)->node_type = AST_VAR;
                                           vid <<= 1;
                                           vid += (yyvsp[(2) - (2)].value);
                                           (yyval.ast)->node_content.var_id = vid;
					 } else if (mid>0) {
                                           struct ast *mb = (struct ast*) mdf_get_body(mid);
					   (yyval.ast) = mb;
                                         } }
    break;

  case 61:
#line 196 "parser.y"
    { (yyval.ast) = malloc(sizeof(struct ast));
                                         (yyval.ast)->node_type = AST_CONST;
                                         (yyval.ast)->node_content.constant = (yyvsp[(1) - (1)].value); }
    break;

  case 62:
#line 199 "parser.y"
    { (yyval.ast) = malloc(sizeof(struct ast));
                                         (yyval.ast)->node_type = AST_CONST;
                                         (yyval.ast)->node_content.constant = -(yyvsp[(2) - (2)].value);
                                        }
    break;

  case 63:
#line 205 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 64:
#line 206 "parser.y"
    { (yyval.ast) = build_unode(AST_NOT, (yyvsp[(2) - (2)].ast)); }
    break;

  case 65:
#line 207 "parser.y"
    { (yyval.ast) = build_node(AST_OR, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 66:
#line 208 "parser.y"
    { (yyval.ast) = build_node(AST_AND, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); }
    break;

  case 67:
#line 209 "parser.y"
    { (yyval.ast) = (yyvsp[(2) - (3)].ast); }
    break;

  case 68:
#line 210 "parser.y"
    { (yyval.ast) = build_unode(AST_EX, (yyvsp[(2) - (2)].ast)); }
    break;

  case 69:
#line 211 "parser.y"
    { (yyval.ast) = build_unode(AST_EG, (yyvsp[(2) - (2)].ast)); }
    break;

  case 70:
#line 213 "parser.y"
    { (yyval.ast) = build_node(AST_EU, (yyvsp[(3) - (6)].ast), (yyvsp[(5) - (6)].ast)); }
    break;

  case 71:
#line 214 "parser.y"
    { (yyval.ast) = build_unode(AST_NOT,
                                              build_unode(AST_EX,
                                              build_unode(AST_NOT, (yyvsp[(2) - (2)].ast)))); }
    break;

  case 72:
#line 217 "parser.y"
    { struct ast *n = malloc(sizeof(struct ast));
                                         n->node_type = AST_CONST;
                                         n->node_content.constant = 1;
                                         (yyval.ast) = build_node(AST_EU, n, (yyvsp[(2) - (2)].ast)); }
    break;

  case 73:
#line 221 "parser.y"
    { struct ast *n = malloc(sizeof(struct ast));
                                         n->node_type = AST_CONST;
                                         n->node_content.constant = 1;
                                         (yyval.ast) = build_unode(AST_NOT,
                                              build_node(AST_EU,
                                                         n,
                                                         build_unode(AST_NOT, (yyvsp[(2) - (2)].ast)))); }
    break;

  case 74:
#line 228 "parser.y"
    { (yyval.ast) = build_unode(AST_NOT,
                                              build_unode(AST_EG,
                                              build_unode(AST_NOT, (yyvsp[(2) - (2)].ast)))); }
    break;

  case 75:
#line 232 "parser.y"
    { (yyval.ast) = build_node(AST_AND,
                                                build_unode(AST_NOT,
                                                  build_node(AST_EU,
                                                    build_unode(AST_NOT, (yyvsp[(5) - (6)].ast)),
                                                    build_node(AST_AND,
                                                      build_unode(AST_NOT, (yyvsp[(3) - (6)].ast)),
                                                        build_unode(AST_NOT, ast_copy((yyvsp[(5) - (6)].ast)))))),
                                                build_unode(AST_NOT,
                                                  build_unode(AST_EG,
                                                    build_unode(AST_NOT, ast_copy((yyvsp[(5) - (6)].ast)))))); }
    break;

  case 76:
#line 243 "parser.y"
    { (yyval.ast) = build_unode(AST_NOT,
                                                build_node(AST_EU,
                                                  build_unode(AST_NOT, (yyvsp[(3) - (6)].ast)),
                                                  build_unode(AST_NOT, (yyvsp[(5) - (6)].ast)))); }
    break;

  case 77:
#line 248 "parser.y"
    { (yyval.ast) = build_node(AST_OR,
                                                build_node(AST_EU,
                                                  (yyvsp[(5) - (6)].ast),
                                                  build_node(AST_AND, (yyvsp[(3) - (6)].ast), (yyvsp[(5) - (6)].ast))),
                                                    build_unode(AST_EG, ast_copy((yyvsp[(5) - (6)].ast)))); }
    break;


/* Line 1267 of yacc.c.  */
#line 1931 "parser.c"
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


#line 254 "parser.y"


/* Called by yyparse on error.  */
void yyerror (char *s)
{
  fprintf(stderr, "Error, %s: \"%s\" on line %d\n", s, yytext, yylineno);
  exit(1);
}

/* build unary node of type op with children c */
static struct ast *build_unode(ast_ops_t op, struct ast *c)
{
  struct ast *n;

  if (c == NULL) {
     ast_free(c);
     return NULL;
  }

  n = malloc(sizeof(struct ast));
  n->node_type = op;
  n->node_content.child = c;

  return n;
}

/* build node of type op with two children l and r */
static struct ast *build_node(ast_ops_t op, struct ast *l, struct ast *r)
{
  struct ast *n;

  if (l == NULL || r == NULL) {
     ast_free(l);
     ast_free(r);
     return NULL;
  }

  n = malloc(sizeof(struct ast));
  n->node_type = op;
  n->node_content.node = malloc(sizeof(struct ast_node));
  n->node_content.node->l = l;
  n->node_content.node->r = r;

  return n;
}

