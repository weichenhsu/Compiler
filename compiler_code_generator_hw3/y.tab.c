/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol();
    static void insert_symbol();
    static char* lookup_symbol();
    static void dump_symbol();
    static void store_symbol();
    static char* lookup_assign_symbol();

    int HAS_ERROR = 0;
    int compare = 1, label = 0;
    FILE *fp;

#line 93 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    INT = 259,
    FLOAT = 260,
    BOOL = 261,
    STRING = 262,
    NEWLINE = 263,
    INC = 264,
    DEC = 265,
    GEQ = 266,
    LEQ = 267,
    EQL = 268,
    NEQ = 269,
    GTR = 270,
    LSS = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    MUL_ASSIGN = 274,
    QUO_ASSIGN = 275,
    REM_ASSIGN = 276,
    LAND = 277,
    LOR = 278,
    PRINT = 279,
    PRINTLN = 280,
    IF = 281,
    ELSE = 282,
    FOR = 283,
    TRUE = 284,
    FALSE = 285,
    INT_LIT = 286,
    FLOAT_LIT = 287,
    STRING_LIT = 288,
    BOOL_LIT = 289,
    IDENT = 290
  };
#endif
/* Tokens.  */
#define VAR 258
#define INT 259
#define FLOAT 260
#define BOOL 261
#define STRING 262
#define NEWLINE 263
#define INC 264
#define DEC 265
#define GEQ 266
#define LEQ 267
#define EQL 268
#define NEQ 269
#define GTR 270
#define LSS 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define MUL_ASSIGN 274
#define QUO_ASSIGN 275
#define REM_ASSIGN 276
#define LAND 277
#define LOR 278
#define PRINT 279
#define PRINTLN 280
#define IF 281
#define ELSE 282
#define FOR 283
#define TRUE 284
#define FALSE 285
#define INT_LIT 286
#define FLOAT_LIT 287
#define STRING_LIT 288
#define BOOL_LIT 289
#define IDENT 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 34 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *s_val;

#line 209 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   298

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,    40,     2,     2,    49,     2,     2,
      38,    39,    47,    45,     2,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    75,    76,    80,    81,    82,    83,    84,
      85,    86,    90,    97,    98,    99,   103,   106,   109,   110,
     116,   117,   122,   123,   124,   125,   129,   133,   146,   151,
     160,   161,   162,   163,   167,   177,   192,   207,   222,   237,
     249,   260,   268,   276,   284,   292,   303,   309,   316,   324,
     335,   336,   337,   338,   339,   340,   344,   351,   360,   365,
     366,   370,   374,   378,   385,   394,   398,   402,   406,   410,
     415,   423,   434,   448,   452,   464,   468,   476,   484,   492,
     500,   508,   516,   520,   531,   543,   547,   558,   569,   583,
     584,   588,   589,   595,   596,   597,   601,   602,   608
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "INT", "FLOAT", "BOOL", "STRING",
  "NEWLINE", "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ", "GTR", "LSS",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN",
  "LAND", "LOR", "PRINT", "PRINTLN", "IF", "ELSE", "FOR", "TRUE", "FALSE",
  "INT_LIT", "FLOAT_LIT", "STRING_LIT", "BOOL_LIT", "IDENT", "'{'", "'}'",
  "'('", "')'", "'\"'", "'['", "']'", "'='", "';'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "$accept", "Program", "StatementList", "Statement",
  "Block", "Operand", "Literal", "ConversionExpr", "TypeName", "ArrayType",
  "DeclarationStmt", "SimpleStmt", "AssignmentStmt", "Identifier",
  "Identifier_assign", "IncDecStmt", "ErrorStmt", "IfStmt", "Ifcomp",
  "ElseStmt", "Iftemp", "Elsetemp", "ForStmt", "Fortemp", "ForComp",
  "ForComp2", "Forsimp", "Forsimp2", "PrintStmt", "LogiLOR", "LogiLAND",
  "Comparison", "Expression", "Term", "Factor", "UnaryExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   123,   125,    40,    41,
      34,    91,    93,    61,    59,    43,    45,    42,    47,    37,
      33
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     167,   -29,   -14,    11,   -68,    14,    38,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,    10,   167,   204,    -7,   248,   248,
     248,    85,   167,   -68,   -68,   -68,    23,   -68,    78,    90,
     -68,    59,    40,   -68,   -68,   -68,   204,   -68,   226,    95,
      88,    91,   174,   -12,    75,   -68,   -68,     6,   204,   204,
     204,   204,   -68,   -68,   128,   -68,   -68,    73,    45,    76,
     -68,   -68,   -68,   -68,   -68,   204,   204,   204,   204,   204,
     204,   -68,   -68,   204,   100,   204,   204,   204,   204,   204,
     204,    99,   174,   -68,    99,   106,   133,   -68,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   248,   248,
     248,   -68,   -68,   -68,   -68,   204,    96,    58,    60,    63,
      -2,     9,   -68,   204,   -68,   -68,   -12,   -12,   -12,   -12,
     -12,   -12,    92,   204,   204,   204,   204,   204,   204,   -12,
     -12,   -12,   -12,   -12,   -12,   124,   -68,   204,    91,   174,
     -12,   -12,   -12,   -12,   -12,   -12,    75,    75,   -68,   -68,
     -68,   169,   248,   -68,   -68,   -68,   -68,   -68,   176,   163,
     -12,   -12,   -12,   -12,   -12,   -12,   -68,   -68,    -1,   111,
     174,   -68,   -68,   -68,   -68,   204,   226,    99,   -68,    99,
     124,   -68,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    11,     0,     0,    61,    65,    93,
      94,    16,    17,    18,    46,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     7,    91,    13,    90,     0,     0,
      30,    14,     0,    31,    33,     8,     0,     9,     0,     0,
      32,    73,    75,    82,    85,    89,    95,     0,     0,     0,
       0,     0,    48,    49,     0,    46,    13,    14,     0,     0,
      96,    97,    98,     1,     3,     0,     0,     0,     0,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    68,     0,     0,    75,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,    25,    24,     0,    27,     0,     0,     0,
       0,     0,    12,     0,    15,    19,    51,    52,    53,    54,
      55,    50,     0,     0,     0,     0,     0,     0,     0,    35,
      36,    37,    38,    39,    34,    56,    63,     0,    72,    74,
      78,    79,    80,    81,    76,    77,    83,    84,    86,    87,
      88,     0,     0,    29,    20,    21,    70,    71,     0,    92,
      41,    42,    43,    44,    45,    40,    62,    57,     0,     0,
      67,    26,    28,    92,    60,     0,     0,     0,    69,     0,
       0,    64,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   146,   -18,   -67,   -68,     0,   -68,    72,   120,
     -68,   -36,   -68,     1,   -68,   -68,   -68,   -68,    19,    20,
      36,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,    -5,
     122,   -33,     2,   -23,   -11,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,    23,    24,    25,    56,    27,   106,    74,
      28,    29,    30,    57,    32,    33,    34,    35,    81,   167,
      36,   168,    37,    38,    84,   169,    85,   179,    39,    40,
      41,    42,    43,    44,    45,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    31,    83,    82,    64,    86,    47,    60,    61,    62,
     101,   102,   103,   104,   135,    26,    31,   136,    58,    52,
      53,    88,    26,    31,    48,     7,    59,   -47,   -47,   -47,
     -47,   -47,    88,    96,    97,    15,    64,   156,    26,    31,
      65,    66,    67,    68,    69,   110,   111,   105,   157,    49,
     108,   109,    50,   -47,    26,    31,   139,    75,    76,    77,
      78,    79,   101,   102,   103,   104,    70,   116,   117,   118,
     119,   120,   121,   146,   147,   122,    51,   129,   130,   131,
     132,   133,   134,    80,   114,    63,    71,   148,   149,   150,
      96,    97,   140,   141,   142,   143,   144,   145,    72,   154,
      73,   174,   155,    87,   170,    96,    97,   151,    96,    97,
     180,    88,   181,    89,   113,   158,   115,   123,   124,   125,
     126,   127,    98,    99,   100,   160,   161,   162,   163,   164,
     165,     1,     2,     3,   159,    15,     4,    96,    97,   152,
     178,   172,    82,   128,    90,    91,    92,    93,    94,    95,
     137,   166,     5,     6,     7,   176,     8,     9,    10,    11,
      12,    54,    13,    14,    15,   112,    16,   107,    17,   -66,
       1,     2,     3,    18,    19,     4,    26,    31,    20,   153,
     -26,   -26,   -26,   -26,   -26,    90,    91,    92,    93,    94,
      95,     5,     6,     7,   177,     8,     9,    10,    11,    12,
     182,    13,    14,    15,   175,    16,   -26,    17,     2,     3,
     138,   171,    18,    19,    96,    97,     0,    20,   173,     0,
       0,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     9,    10,    11,    12,     0,    13,    55,
       0,     0,    16,     0,    17,     0,     0,     0,     0,    18,
      19,     0,     0,     0,    20,     9,    10,    11,    12,     0,
      13,    14,     0,     0,    16,     0,    17,     0,     0,     0,
       0,    18,    19,     0,     0,     0,    20,     9,    10,    11,
      12,     0,    13,    55,     0,     0,    16,     0,    17,     0,
       0,     0,     0,    18,    19,     0,     0,     0,    20
};

static const yytype_int16 yycheck[] =
{
       0,     0,    38,    36,    22,    38,    35,    18,    19,    20,
       4,     5,     6,     7,    81,    15,    15,    84,    16,     9,
      10,    23,    22,    22,    38,    26,    33,    17,    18,    19,
      20,    21,    23,    45,    46,    36,    54,    39,    38,    38,
      17,    18,    19,    20,    21,    50,    51,    41,    39,    38,
      48,    49,    38,    43,    54,    54,    89,    17,    18,    19,
      20,    21,     4,     5,     6,     7,    43,    65,    66,    67,
      68,    69,    70,    96,    97,    73,    38,    75,    76,    77,
      78,    79,    80,    43,    39,     0,     8,    98,    99,   100,
      45,    46,    90,    91,    92,    93,    94,    95,     8,    39,
      41,   168,    39,     8,   137,    45,    46,   105,    45,    46,
     177,    23,   179,    22,    41,   113,    40,    17,    18,    19,
      20,    21,    47,    48,    49,   123,   124,   125,   126,   127,
     128,     3,     4,     5,    42,    36,     8,    45,    46,    43,
     176,   152,   175,    43,    11,    12,    13,    14,    15,    16,
      44,    27,    24,    25,    26,    44,    28,    29,    30,    31,
      32,    15,    34,    35,    36,    37,    38,    47,    40,    36,
       3,     4,     5,    45,    46,     8,   176,   176,    50,   107,
      17,    18,    19,    20,    21,    11,    12,    13,    14,    15,
      16,    24,    25,    26,   175,    28,    29,    30,    31,    32,
     180,    34,    35,    36,   168,    38,    43,    40,     4,     5,
      88,    42,    45,    46,    45,    46,    -1,    50,    42,    -1,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    29,    30,    31,    32,    -1,    34,    35,
      -1,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    50,    29,    30,    31,    32,    -1,
      34,    35,    -1,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    29,    30,    31,
      32,    -1,    34,    35,    -1,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     8,    24,    25,    26,    28,    29,
      30,    31,    32,    34,    35,    36,    38,    40,    45,    46,
      50,    52,    53,    54,    55,    56,    57,    58,    61,    62,
      63,    64,    65,    66,    67,    68,    71,    73,    74,    79,
      80,    81,    82,    83,    84,    85,    86,    35,    38,    38,
      38,    38,     9,    10,    53,    35,    57,    64,    83,    33,
      85,    85,    85,     0,    54,    17,    18,    19,    20,    21,
      43,     8,     8,    41,    60,    17,    18,    19,    20,    21,
      43,    69,    82,    62,    75,    77,    82,     8,    23,    22,
      11,    12,    13,    14,    15,    16,    45,    46,    47,    48,
      49,     4,     5,     6,     7,    41,    59,    60,    83,    83,
      80,    80,    37,    41,    39,    40,    83,    83,    83,    83,
      83,    83,    83,    17,    18,    19,    20,    21,    43,    83,
      83,    83,    83,    83,    83,    55,    55,    44,    81,    82,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    83,    43,    59,    39,    39,    39,    39,    83,    42,
      83,    83,    83,    83,    83,    83,    27,    70,    72,    76,
      82,    42,    85,    42,    55,    71,    44,    69,    62,    78,
      55,    55,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    55,    56,    56,    56,    57,    57,    57,    57,
      58,    58,    59,    59,    59,    59,    60,    61,    61,    61,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    68,    68,    69,    70,
      70,    71,    72,    73,    73,    74,    75,    76,    77,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    84,    84,    84,    84,
      84,    85,    85,    85,    85,    85,    86,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     1,     1,
       2,     1,     3,     1,     1,     3,     1,     1,     1,     3,
       4,     4,     1,     1,     1,     1,     3,     3,     5,     4,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     4,     1,     1,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     4,     1,     5,
       2,     1,     1,     3,     7,     1,     1,     1,     1,     1,
       4,     4,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       1,     1,     4,     1,     1,     1,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 71 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol();}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 80 "compiler_hw3.y" /* yacc.c:1646  */
    { lineno++; }
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 81 "compiler_hw3.y" /* yacc.c:1646  */
    { lineno++; }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 85 "compiler_hw3.y" /* yacc.c:1646  */
    { lineno++; }
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 86 "compiler_hw3.y" /* yacc.c:1646  */
    { lineno++; }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 90 "compiler_hw3.y" /* yacc.c:1646  */
    {   if(scope >= scope_com){
                                    scope_com = scope + 1;
                                }
                                dump_symbol(); }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 97 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 98 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val);}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 99 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-1].s_val); }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 103 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = "int32";
                    fprintf(fp, "ldc %d\n", yylval.i_val); 
                }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 106 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = "float32";
                    fprintf(fp, "ldc %-6f\n", yylval.f_val); 
                }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 109 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 110 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = "string";
                                fprintf(fp, "ldc \"%s\"\n", yylval.s_val); 
                            }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "f2i\n"); (yyval.s_val) = "int32"; }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "i2f\n"); (yyval.s_val) = "float32"; }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 122 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "int32"; }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 123 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "float32"; }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 124 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "string"; }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 125 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 133 "compiler_hw3.y" /* yacc.c:1646  */
    { if(scope != scope_com){
                            scope_com = scope;
                            create_symbol();
                            } 
                            if(strcmp((yyvsp[0].s_val), "int32") == 0)
                                fprintf(fp, "ldc 0\n");
                            else if(strcmp((yyvsp[0].s_val), "float32") == 0)
                                fprintf(fp, "ldc 0.0\n");
                            else if(strcmp((yyvsp[0].s_val), "string") == 0)
                                fprintf(fp, "ldc \"\"\n");

                            insert_symbol((yyvsp[-1].s_val), 1);
                        }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 146 "compiler_hw3.y" /* yacc.c:1646  */
    {   if(scope != scope_com){
                                            scope_com = scope;
                                            create_symbol();
                                        }
                                        insert_symbol((yyvsp[-3].s_val), 2); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 151 "compiler_hw3.y" /* yacc.c:1646  */
    {    if(scope != scope_com){
                                            scope_com = scope;
                                            create_symbol();
                                        }
                                        insert_symbol((yyvsp[-2].s_val), 3);
                                    }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 167 "compiler_hw3.y" /* yacc.c:1646  */
    {   
                                            char *tmp = strtok((yyvsp[-2].s_val), "_");
                                            char *id = strtok(NULL, "\n");
                                            if((yyvsp[-2].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0){
                                                    fprintf(fp, "error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
                                                    HAS_ERROR = 1;
                                                }  
                                            store_symbol(id);                                 
                                        }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 177 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                                    char *tmp = strtok((yyvsp[-2].s_val), "_");
                                                    char *id = strtok(NULL, "\n");
                                                    if((yyvsp[-2].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                        if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0){
                                                            fprintf(fp, "error:%d: invalid operation: ADD_ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
                                                            HAS_ERROR = 1;
                                                        }
                                                    lookup_symbol(id);
                                                    if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                                        fprintf(fp, "iadd\n");
                                                    else
                                                        fprintf(fp, "fadd\n"); 
                                                    store_symbol(id);
                                                }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 192 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                                    char *tmp = strtok((yyvsp[-2].s_val), "_");
                                                    char *id = strtok(NULL, "\n");
                                                    if((yyvsp[-2].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                        if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0){
                                                            fprintf(fp, "error:%d: invalid operation: SUB_ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
                                                            HAS_ERROR = 1;
                                                        }
                                                    lookup_symbol(id);
                                                    if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                                        fprintf(fp, "swap\nisub\n");
                                                    else
                                                        fprintf(fp, "swap\nfsub\n");  
                                                    store_symbol(id);
                                                }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 207 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                                    char *tmp = strtok((yyvsp[-2].s_val), "_");
                                                    char *id = strtok(NULL, "\n");
                                                    if((yyvsp[-2].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                        if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0){
                                                            fprintf(fp, "error:%d: invalid operation: MUL_ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
                                                            HAS_ERROR = 1;
                                                        }
                                                    lookup_symbol(id);
                                                    if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                                        fprintf(fp, "imul\n");
                                                    else
                                                        fprintf(fp, "fmul\n");  
                                                    store_symbol(id); 
                                                }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 222 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                                    char *tmp = strtok((yyvsp[-2].s_val), "_");
                                                    char *id = strtok(NULL, "\n");
                                                    if((yyvsp[-2].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                        if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0){
                                                            fprintf(fp, "error:%d: invalid operation: QUO_ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
                                                            HAS_ERROR = 1;
                                                        }
                                                    lookup_symbol(id);
                                                    if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                                        fprintf(fp, "swap\nidiv\n");
                                                    else
                                                        fprintf(fp, "swap\nfdiv\n");  
                                                    store_symbol(id);
                                                }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 237 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                                    char *tmp = strtok((yyvsp[-2].s_val), "_");
                                                    char *id = strtok(NULL, "\n");
                                                    if((yyvsp[-2].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                        if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0){
                                                            fprintf(fp, "error:%d: invalid operation: REM_ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
                                                            HAS_ERROR = 1;
                                                        }
                                                    lookup_symbol(id);
                                                    fprintf(fp, "swap\nirem\n"); 
                                                    store_symbol(id); 
                                                }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 249 "compiler_hw3.y" /* yacc.c:1646  */
    {   
                                                if((yyvsp[-3].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                    if(strcmp((yyvsp[-3].s_val), (yyvsp[0].s_val)) != 0){
                                                        fprintf(fp, "error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-3].s_val), (yyvsp[0].s_val));
                                                        HAS_ERROR = 1;
                                                    }
                                                if(strcmp((yyvsp[-3].s_val), "int32") == 0)
                                                    fprintf(fp, "iastore\n");
                                                else
                                                    fprintf(fp, "fastore\n");                                    
                                            }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 260 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                                        if((yyvsp[-3].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                            if(strcmp((yyvsp[-3].s_val), (yyvsp[0].s_val)) != 0){
                                                                fprintf(fp, "error:%d: invalid operation: ADD_ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-3].s_val), (yyvsp[0].s_val));
                                                                HAS_ERROR = 1;
                                                            }
                                                        fprintf(fp, "ADD_ASSIGN\n"); 
                                                    }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 268 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                                        if((yyvsp[-3].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                            if(strcmp((yyvsp[-3].s_val), (yyvsp[0].s_val)) != 0){
                                                                fprintf(fp, "error:%d: invalid operation: SUB_ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-3].s_val), (yyvsp[0].s_val));
                                                                HAS_ERROR = 1;
                                                            }
                                                        fprintf(fp, "SUB_ASSIGN\n"); 
                                                    }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 276 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                                        if((yyvsp[-3].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                            if(strcmp((yyvsp[-3].s_val), (yyvsp[0].s_val)) != 0){
                                                                fprintf(fp, "error:%d: invalid operation: MUL_ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-3].s_val), (yyvsp[0].s_val));
                                                                HAS_ERROR = 1;
                                                            }
                                                        fprintf(fp, "MUL_ASSIGN\n"); 
                                                    }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 284 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                                        if((yyvsp[-3].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                            if(strcmp((yyvsp[-3].s_val), (yyvsp[0].s_val)) != 0){
                                                                fprintf(fp, "error:%d: invalid operation: QUO_ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-3].s_val), (yyvsp[0].s_val));
                                                                HAS_ERROR = 1;
                                                            }
                                                        fprintf(fp, "QUO_ASSIGN\n"); 
                                                    }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 292 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                                        if((yyvsp[-3].s_val) != NULL && (yyvsp[0].s_val) != NULL)
                                                            if(strcmp((yyvsp[-3].s_val), (yyvsp[0].s_val)) != 0){
                                                                fprintf(fp, "error:%d: invalid operation: REM_ASSIGN (mismatched types %s and %s)\n", lineno+1, (yyvsp[-3].s_val), (yyvsp[0].s_val));
                                                                HAS_ERROR = 1;
                                                            }
                                                        fprintf(fp, "REM_ASSIGN\n"); 
                                                    }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 303 "compiler_hw3.y" /* yacc.c:1646  */
    {   
                (yyval.s_val) = lookup_symbol(yylval);
            }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 309 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = lookup_assign_symbol(yylval);
                strcat((yyval.s_val), "_");
                strcat((yyval.s_val), (yyvsp[0].s_val));
            }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 316 "compiler_hw3.y" /* yacc.c:1646  */
    {   char* ptr = strtok((yyvsp[-1].s_val), "++");
                    char* type = lookup_symbol(ptr);
                    if(strcmp(type, "int32") == 0)
                        fprintf(fp, "ldc 1\niadd\n");
                    else
                        fprintf(fp, "ldc 1.0\nfadd\n");    
                    store_symbol(ptr);    
                }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 324 "compiler_hw3.y" /* yacc.c:1646  */
    {   char* ptr = strtok((yyvsp[-1].s_val), "--");
                    char* type = lookup_symbol(ptr);
                    if(strcmp(type, "int32") == 0)
                        fprintf(fp, "ldc 1\nisub\n");
                    else
                        fprintf(fp, "ldc 1.0\nfsub\n"); 
                    store_symbol(ptr);    
                }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 335 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "error:%d: cannot assign to %s\nASSIGN\n", lineno+1, (yyvsp[-2].s_val)); HAS_ERROR = 1; }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 336 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "error:%d: cannot assign to %s\nADD_ASSIGN\n", lineno+1, (yyvsp[-2].s_val)); HAS_ERROR = 1; }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 337 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "error:%d: cannot assign to %s\nSUB_ASSIGN\n", lineno+1, (yyvsp[-2].s_val)); HAS_ERROR = 1; }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 338 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "error:%d: cannot assign to %s\nMUL_ASSIGN\n", lineno+1, (yyvsp[-2].s_val)); HAS_ERROR = 1; }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 339 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "error:%d: cannot assign to %s\nQUO_ASSIGN\n", lineno+1, (yyvsp[-2].s_val)); HAS_ERROR = 1; }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 340 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "error:%d: cannot assign to %s\nREM_ASSIGN\n", lineno+1, (yyvsp[-2].s_val)); HAS_ERROR = 1; }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 344 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                fprintf(fp, "L_if_false%d:\n", (yyvsp[-2].i_val));
                                if(strcmp((yyvsp[-1].s_val), "bool") != 0){
                                    fprintf(fp, "error:%d: non-bool (type %s) used as for condition\n", lineno+1, (yyvsp[-1].s_val));
                                    HAS_ERROR = 1;
                                }
                            }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 351 "compiler_hw3.y" /* yacc.c:1646  */
    {    
                                //fprintf(fp, "L_if_false%d:\n", $1);
                                if(strcmp((yyvsp[-2].s_val), "bool") != 0){
                                    fprintf(fp, "error:%d: non-bool (type %s) used as for condition\n", lineno+1, (yyvsp[-2].s_val));
                                    HAS_ERROR = 1;
                                }
                            }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 360 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); fprintf(fp, "ifeq L_if_false%d\n", label); label++; }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 365 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "L_if_exit%d:\n", (yyvsp[-4].i_val)); }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 366 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "L_if_exit%d:\n", (yyvsp[-1].i_val)); }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = label; }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 374 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "goto L_if_exit%d\nL_if_false%d:\n", label-1, label-1); (yyval.i_val) = label-1; }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 378 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                        if(strcmp((yyvsp[-1].s_val), "bool") != 0){
                            fprintf(fp, "error:%d: non-bool (type %s) used as for condition\n", lineno+1, (yyvsp[-1].s_val));
                            HAS_ERROR = 1;
                        }
                        fprintf(fp, "goto L_for_begin%d\nL_for_exit%d:\n", (yyvsp[-2].i_val), (yyvsp[-2].i_val));
                    }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 385 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-3].s_val), "bool") != 0){
                                                            fprintf(fp, "error:%d: non-bool (type %s) used as for condition\n", lineno+1, (yyvsp[-3].s_val));
                                                            HAS_ERROR = 1;
                                                        }
                                                        fprintf(fp, "goto L_for_post%d\nL_for_exit%d:\n", (yyvsp[-5].i_val), (yyvsp[-5].i_val));
                                                    }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 394 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "L_for_begin%d:\n", label); (yyval.i_val) = label; }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 398 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "ifeq L_for_exit%d\n", label);  (yyval.s_val) = (yyvsp[0].s_val); label++; }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 402 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "goto L_for_pre%d\nL_for_post%d:\n", label, label);  (yyval.s_val) = (yyvsp[0].s_val); }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 406 "compiler_hw3.y" /* yacc.c:1646  */
    { label++; fprintf(fp, "L_for_begin%d:\n", label); (yyval.i_val) = label; }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 410 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "goto L_for_begin%d\nL_for_pre%d:\nifeq L_for_exit%d\n", label, label, label); label++; }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 415 "compiler_hw3.y" /* yacc.c:1646  */
    {   fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print" ); 
                                if(strcmp((yyvsp[-1].s_val), "int32") == 0)
                                    fprintf(fp, "(I)V\n");
                                else if(strcmp((yyvsp[-1].s_val), "float32") == 0)
                                    fprintf(fp, "(F)V\n");
                                else
                                    fprintf(fp, "(Ljava/lang/String;)V\n");
                            }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 423 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println" ); 
                                if(strcmp((yyvsp[-1].s_val), "int32") == 0)
                                    fprintf(fp, "(I)V\n");
                                else if(strcmp((yyvsp[-1].s_val), "float32") == 0)
                                    fprintf(fp, "(F)V\n");
                                else
                                    fprintf(fp, "(Ljava/lang/String;)V\n");
                            }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 434 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val), "bool") != 0 || strcmp((yyvsp[0].s_val), "bool") != 0){
                                if(strcmp((yyvsp[-2].s_val), "bool") != 0){
                                    fprintf(fp, "error:%d: invalid operation: (operator LOR not defined on %s)\n", lineno+1, (yyvsp[-2].s_val));
                                    HAS_ERROR = 1;
                                }
                                else{
                                    fprintf(fp, "error:%d: invalid operation: (operator LOR not defined on %s)\n", lineno+1, (yyvsp[0].s_val));
                                    HAS_ERROR = 1;
                                }
                            }
                            (yyval.s_val) = "bool"; 
                            fprintf(fp, "ior\nifne L_cmp_%d\nldc \"false\"\ngoto L_cmp_%d\nL_cmp_%d:\nldc \"true\"\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                            compare += 2; 
                        }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 448 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 452 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val), "bool") != 0 || strcmp((yyvsp[0].s_val), "bool") != 0){
                                    if(strcmp((yyvsp[-2].s_val), "bool") != 0){
                                        fprintf(fp, "error:%d: invalid operation: (operator LAND not defined on %s)\n", lineno+1, (yyvsp[-2].s_val));
                                        HAS_ERROR = 1;
                                    }
                                    else{
                                        fprintf(fp, "error:%d: invalid operation: (operator LAND not defined on %s)\n", lineno+1, (yyvsp[0].s_val));
                                        HAS_ERROR = 1;
                                    }
                                }
                                    (yyval.s_val) = "bool"; fprintf(fp, "iand\n"); 
                                }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 464 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 468 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = "bool"; 
                                    if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else if(strcmp((yyvsp[-2].s_val), "float32") == 0)
                                        fprintf(fp, "fcmpl\n");
                                    fprintf(fp, "ifgt L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 476 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = "bool"; 
                                    if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else
                                        fprintf(fp, "fcmpl\n");
                                    fprintf(fp, "iflt L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 484 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = "bool"; 
                                    if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else if(strcmp((yyvsp[-2].s_val), "float32") == 0)
                                        fprintf(fp, "fcmpl\n");
                                    fprintf(fp, "ifge L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 492 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = "bool"; 
                                    if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else if(strcmp((yyvsp[-2].s_val), "float32") == 0)
                                        fprintf(fp, "fcmpl\n");
                                    fprintf(fp, "ifle L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 500 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = "bool"; 
                                    if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else
                                        fprintf(fp, "fsub\n");
                                    fprintf(fp, "ifeq L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 508 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = "bool"; 
                                    if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                        fprintf(fp, "isub\n");
                                    else
                                        fprintf(fp, "fsub\n");
                                    fprintf(fp, "ifne L_cmp_%d\niconst_0\ngoto L_cmp_%d\nL_cmp_%d:\niconst_1\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                                    compare += 2; 
                                }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 516 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 520 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0){
                                fprintf(fp, "error:%d: invalid operation: ADD (mismatched types %s and %s)\n", lineno+1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
                                HAS_ERROR = 1;
                            }
                            else{
                                if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                    fprintf(fp, "iadd\n");
                                else
                                    fprintf(fp, "fadd\n");
                            } 
                        }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 531 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                            if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0){
                                fprintf(fp, "error:%d: invalid operation: SUB (mismatched types %s and %s)\n", lineno+1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
                                HAS_ERROR = 1;
                            }
                            else{
                                if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                    fprintf(fp, "isub\n");
                                else
                                    fprintf(fp, "fsub\n");
                            } 
                        }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 543 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 547 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0){
                            fprintf(fp, "error:%d: invalid operation: MUL (mismatched types %s and %s)\n", lineno+1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
                            HAS_ERROR = 1;
                        }
                        else{
                            if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                fprintf(fp, "imul\n");
                            else
                                    fprintf(fp, "fmul\n");
                        }         
                    }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 558 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0){
                            fprintf(fp, "error:%d: invalid operation: DIV (mismatched types %s and %s)\n", lineno+1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
                            HAS_ERROR = 1;
                        }
                        else{
                            if(strcmp((yyvsp[-2].s_val), "int32") == 0)
                                fprintf(fp, "idiv\n");
                            else
                                    fprintf(fp, "fdiv\n");
                        }         
                    }
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 569 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val), "int32") !=0 || strcmp((yyvsp[0].s_val), "int32") !=0 ){
                            if(strcmp((yyvsp[-2].s_val), "int32") !=0){
                                fprintf(fp, "error:%d: invalid operation: (operator REM not defined on %s)\n", lineno+1, (yyvsp[-2].s_val));
                                HAS_ERROR = 1;
                            }
                            else{
                                fprintf(fp, "error:%d: invalid operation: (operator REM not defined on %s)\n", lineno+1, (yyvsp[0].s_val));
                                HAS_ERROR = 1;
                            }
                            fprintf(fp, "REM\n");
                        }
                        else
                            fprintf(fp, "irem\n");
                    }
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 583 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 584 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 588 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 589 "compiler_hw3.y" /* yacc.c:1646  */
    {   (yyval.s_val) = (yyvsp[-3].s_val);
                                        if(strcmp((yyvsp[-3].s_val), "int32") == 0)
                                            fprintf(fp, "iaload\n");
                                        else
                                            fprintf(fp, "faload\n");
                                    }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 595 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "iconst_1\n"); (yyval.s_val) = "bool"; }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 596 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "iconst_0\n"); (yyval.s_val) = "bool"; }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 597 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 601 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 602 "compiler_hw3.y" /* yacc.c:1646  */
    {  if(strcmp((yyvsp[0].s_val), "int32") == 0)
                        fprintf(fp, "ineg\n");
                    else
                        fprintf(fp, "fneg\n"); 
                    (yyval.s_val) = (yyvsp[0].s_val); 
                }
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 608 "compiler_hw3.y" /* yacc.c:1646  */
    {  fprintf(fp, "iconst_1\nixor\n"); 
                    (yyval.s_val) = (yyvsp[0].s_val); 
                }
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2315 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 614 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    scope = 0;
    scope_com = 0;
    address = 0;
    current = NULL;
    current_head = NULL;
    create_symbol();
    fp = fopen("hw3.j", "w");
    fprintf(fp, ".source hw3.j\n.class public Main\n.super java/lang/Object\n.method public static main([Ljava/lang/String;)V\n.limit stack 100\n.limit locals 100 ;\n");

    yyparse();
    
    fprintf(fp, "return\n.end method\n");
    fclose(fp);
	//printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    if (HAS_ERROR) {
        remove("hw3.j");
    }
    return 0;
}

static void create_symbol() {
    struct table *new = malloc(sizeof(*new));
    new->prev_head = current_head;
    new->prev = current;    
    new->index = 0;
    new->name = NULL;
    new->type = NULL;
    new->scope_level = scope;
    current_head = new; 
    current = new;
    return;
}

static void insert_symbol(char* id, int kind) {
    //printf("insert %s, scope: %d, scope_com: %d\n", id, scope, scope_com);
    //printf("current_head: %s, id %s\n", current_head->name, id);
    char* ptr = strtok(id, " ");
    int insert = 1;
    // some variable is in table, search repeat declaration or not
    if(current_head->name != NULL){
        struct table *tmp = current_head;
        while(tmp != NULL){
            if(strcmp(tmp->name, id) == 0){
                insert = 0;
                fprintf(fp, "error:%d: %s redeclared in this block. previous declaration at line %d\n", lineno+1, id, tmp->lineno);
                HAS_ERROR = 1;
                break;
            }
            else{
                tmp = tmp->next;
            }
        }
    }


    if(insert){
        struct table *new;
        if(current->name == NULL){ // first variable in table
            new = current;
            new->next = NULL;
        }
        else{ // not the first variable in the table
            new = malloc(sizeof(*new));
            current->next = new;
            new->index = current->index +1;
        }
        new->address = address;
        address++;
        new->lineno = lineno+1;    
        new->name = ptr;
        // split input data
        if(kind == 1){
            ptr = strtok(NULL, "\n");
            new->type = ptr;
            new->element_type = "-";
        }
        else if(kind == 2){
            ptr = strtok(NULL, " ");
            new->type = ptr;
            new->element_type = "-";
        }
        else if(kind == 3){
            ptr = strtok(NULL, "\]");
            ptr = strtok(NULL, "\n");   
            new->type = "array";
            new->element_type = ptr;   
        }
        current = new;
        if(strcmp(current->type, "float32") == 0)
            fprintf(fp, "fstore %d\n", current->address);
        else if(strcmp(current->type, "string") == 0 || strcmp(current->element_type, "string") == 0)
            fprintf(fp, "astore %d\n", current->address);
        else if(strcmp(current->type, "array") == 0){
            if(strcmp(current->element_type, "float32") == 0)
                fprintf(fp, "newarray float\n");
            else
                fprintf(fp, "newarray int\n");
            fprintf(fp, "astore %d\n", current->address);
        }
        else
            fprintf(fp, "istore %d\n", current->address);
    }
    return;
}

static char* lookup_symbol(char* id) {
    char* ptr = strtok(id, "\[");
    ptr = strtok(id, " ");
    //printf("id :%s\n", id);
    struct table *search = current_head;
    struct table *search_head = current_head;
    int error = 1;
    char *type;
    while(search != NULL){
        if(strcmp(search->name, id) == 0){
            if(strcmp(search->type, "int32") == 0)
                fprintf(fp, "iload %d\n", search->address);
            else if(strcmp(search->type, "float32") == 0)
                fprintf(fp, "fload %d\n", search->address);
            else if(strcmp(search->type, "string") == 0)
                fprintf(fp, "aload %d\n", search->address);
            else if(strcmp(search->type, "array") == 0){
                fprintf(fp, "aload %d\n", search->address);
            }
            else{
                fprintf(fp, "iload %d\n", search->address);
                fprintf(fp, "ifne L_cmp_%d\nldc \"false\"\ngoto L_cmp_%d\nL_cmp_%d:\n ldc \"true\"\nL_cmp_%d:\n", compare-1, compare, compare-1, compare);
                compare += 2;
            }
            type = search->type;
            if(strcmp(type, "array") == 0){
                type = search->element_type;
                type = strtok(type, "\n");
                search->element_type = type;
            }
            search = NULL;
            error = 0;
        }
        else{
            search = search->next; 
            if(search == NULL && search_head->prev_head != NULL){
                search_head = search_head->prev_head;
                search = search_head;
            }           
        }
    }
    if(error){
        fprintf(fp, "error:%d: undefined: %s\n", lineno+1, id);
        HAS_ERROR = 1;
    }
    
    if(strlen(type) > 8){
        type = strtok(type, "_");
    }

    return type;
}

static void dump_symbol() {
    /*printf("> Dump symbol table (scope level: %d)\n", scope_com); 

    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");*/
    //printf("current: %d , scope_com %d\n", current_head->scope_level, scope_com);
    if(scope_com == current_head->scope_level){
        struct table *tmp = current_head;
        current = current_head->prev;
        current_head = current_head->prev_head;

        //printf("current: %s, pre: %s\n", tmp->name, current_head->name);
        while(tmp != NULL && tmp->name != NULL){
            /*printf("%-10d%-10s%-10s%-10d%-10d%s\n",
                tmp->index, tmp->name, tmp->type, tmp->address, tmp->lineno, tmp->element_type);*/
            struct table *delete = tmp;
            tmp = tmp->next;
            free(delete);
        }
    }
    scope_com--;
    return;
}


static void store_symbol(char* id){
    struct table *search = current_head;
    struct table *search_head = current_head;
    while(search != NULL){
        if(strcmp(search->name, id) == 0){
            if(strcmp(search->type, "int32") == 0)
                fprintf(fp, "istore %d\n", search->address);
            else if(strcmp(search->type, "float32") == 0)
                fprintf(fp, "fstore %d\n", search->address);
            else if(strcmp(search->type, "array") == 0)
                fprintf(fp, "iastore\n");
            else
                fprintf(fp, "astore %d\n", search->address);
            search = NULL;
        }
        else{
            search = search->next;
            if(search == NULL && search_head->prev_head != NULL){
                search_head = search_head->prev_head;
                search = search_head;
            }  
        }
    }
    return;
}

static char* lookup_assign_symbol(char* id) {
    char* ptr = strtok(id, "\[");
    ptr = strtok(id, " ");
    struct table *search = current_head;
    struct table *search_head = current_head;
    int error = 1;
    char *type;
    while(search != NULL){
        if(strcmp(search->name, id) == 0){
            type = search->type;
            if(strcmp(type, "array") == 0){
                type = search->element_type;
                type = strtok(type, "\n");
                search->element_type = type;
            }
            search = NULL;
            error = 0;
        }
        else{
            search = search->next; 
            if(search == NULL && search_head->prev_head != NULL){
                search_head = search_head->prev_head;
                search = search_head;
            }           
        }
    }
    if(error){
        fprintf(fp, "error:%d: undefined: %s\n", lineno+1, id);
        HAS_ERROR = 1;
    }
    
    if(strlen(type) > 8){
        type = strtok(type, "_");
    }

    return type;
}
