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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

#include <stdio.h> 
#include <string.h>
#include "CODE.H"

extern FILE *yyin;
extern FILE *yyout;

int yylex(void);
int yyerror(char* s);

enum tipoEnum {tipo_int, tipo_void};

char* tipos[] = {
  "tipo_int", "tipo_void"
};

/* TM location number for current instruction emission */
static int emitLoc = 0;

/* Highest TM location emitted so far
   For use in conjunction with emitSkip,
   emitBackup, and emitRestore */
static int highEmitLoc = 0;

int tipo = 0;

struct regTabSimb {
	char *nome;                 /* nome do simbolo */
	char *tipo;                 /* tipo_int ou tipo_cad ou nsa */
	char *natureza;             /* variavel ou procedimento */
	int usado;                  /* 1=sim ou 0=nao */
    int locMem;
	struct regTabSimb *prox;    /* ponteiro */
};
typedef struct regTabSimb regTabSimb;
regTabSimb *tabSimb = (regTabSimb *)0;
regTabSimb *colocaSimb();
int constaTabSimb(char *nomeSimb);
int HaWarningTabSimb();
void declaraUsadoTabSimb();
void imprimeTabSimb();
int recuperaLocMemId(char []);
int erroSemantico;

int proxLocMemVar = 0;
int locMemId = 0; /* para recuperacao na TS */
int store = 1;
int locMemIdStore;

int isAdd = 0;
int isMul = 0;


#line 125 "sintatico.tab.c"

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
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
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
    LEITURA = 258,
    ESCRITA = 259,
    WHILE = 260,
    IF = 261,
    ELSE = 262,
    RETURN = 263,
    LESSEQUAL = 264,
    LESS = 265,
    GREATER = 266,
    GREATEREQUAL = 267,
    EQUALEQUAL = 268,
    NOTEQUAL = 269,
    ADD = 270,
    MINUS = 271,
    MULTIPLIER = 272,
    DIVISION = 273,
    TYPEINT = 274,
    TYPEVOID = 275,
    FLOAT = 276,
    INT = 277,
    ID = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 56 "sintatico.y"

	int Uinteiro;
    float Uflutuante;
    char *Ucadeia;

#line 207 "sintatico.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  113

#define YYUNDEFTOK  2
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,   100,   101,   103,   104,   106,   111,   119,
     120,   122,   128,   129,   131,   132,   134,   139,   145,   147,
     148,   150,   151,   153,   154,   155,   156,   157,   159,   160,
     162,   163,   165,   167,   168,   170,   170,   175,   177,   197,
     205,   206,   208,   209,   210,   211,   212,   213,   216,   215,
     227,   229,   230,   233,   232,   243,   245,   246,   248,   249,
     250,   251,   253,   256,   261,   263,   265,   266,   268,   269
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEITURA", "ESCRITA", "WHILE", "IF",
  "ELSE", "RETURN", "LESSEQUAL", "LESS", "GREATER", "GREATEREQUAL",
  "EQUALEQUAL", "NOTEQUAL", "ADD", "MINUS", "MULTIPLIER", "DIVISION",
  "TYPEINT", "TYPEVOID", "FLOAT", "INT", "ID", "\"then\"", "';'", "'['",
  "']'", "'('", "')'", "','", "'{'", "'}'", "'='", "$accept", "programa",
  "declaracao_lista", "declaracao", "var_declaracao", "tipo_especificador",
  "fun_declaracao", "params", "params_lista", "param", "escopo_stmt",
  "declaracoes_locais", "statement_lista", "statement", "expressao_stmt",
  "selecao_stmt", "iteracao_stmt", "retorno_stmt", "expressao", "$@1",
  "var", "expressao_simples", "relop", "expressao_aditiva", "$@2", "addop",
  "termo", "$@3", "mulop", "fator", "call", "args", "args_lista", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    59,    91,    93,    40,    41,
      44,   123,   125,    61
};
# endif

#define YYPACT_NINF (-96)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      22,   -96,   -96,     3,    22,   -96,   -96,   -14,   -96,   -96,
     -96,   -24,   -96,    -8,    47,   -10,    25,    13,    35,    29,
     -96,   -96,    67,    59,    22,    68,   -96,   -96,   -96,   -96,
      22,   -96,    71,     7,    44,    69,    70,    72,    75,    30,
     -96,   -96,    21,   -96,    53,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,    76,    63,   -96,    73,    55,   -96,   -96,    53,
      53,    53,    53,   -96,    77,    53,    53,    78,   -96,    66,
     -96,   -96,   -96,   -96,   -96,   -96,    53,    62,    74,   -96,
      79,    80,    82,    83,    84,   -96,    87,    86,   -96,    53,
     -96,    64,   -96,   -96,    53,   -96,   -96,    53,   -96,    53,
     -96,    40,    40,   -96,   -96,   -96,    55,   -96,   -96,   -96,
      97,    40,   -96
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     7,     0,     0,     0,    10,     0,     0,    12,
      15,     8,    16,     0,     0,     0,    19,    11,    14,    17,
      21,    20,     0,     0,     0,     0,     0,     0,     0,     0,
      62,    61,    38,    29,     0,    18,    24,    22,    23,    25,
      26,    27,     0,    59,    37,    41,    50,    55,    60,    66,
      66,     0,     0,    33,     0,     0,    66,     0,    28,     0,
      42,    43,    44,    45,    46,    47,     0,     0,     0,    69,
       0,    67,     0,     0,     0,    34,     0,     0,    58,     0,
      59,    40,    51,    52,     0,    56,    57,     0,    64,     0,
      63,     0,     0,    39,    65,    36,    49,    54,    68,    32,
      30,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,   -96,   101,    88,    -6,   -96,   -96,   -96,    85,
      93,   -96,   -96,   -95,   -96,   -96,   -96,   -96,   -39,   -96,
     -57,   -96,   -96,    41,   -96,   -96,    12,   -96,   -96,    23,
     -96,   -35,   -96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      46,    30,    33,    47,    48,    49,    50,    51,    52,    69,
      53,    54,    76,    55,    77,    94,    56,    78,    97,    57,
      58,    80,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    12,    13,     9,    14,    67,   109,   110,    17,    11,
      35,    36,    37,    38,    15,    39,   112,    21,    17,    90,
      79,    79,    83,    84,    32,    82,    86,    79,    40,    41,
      42,    87,    43,    35,    36,    44,    22,    90,    26,    45,
      90,     1,     2,    35,    36,    37,    38,    65,    39,    66,
     105,    40,    41,    42,   -13,    63,    35,    36,    44,    24,
     108,    40,    41,    42,    23,    43,     1,    16,    44,    12,
      13,    26,   -53,   -53,    40,    41,    42,    92,    93,   -48,
     -48,    44,    70,    71,    72,    73,    74,    75,   -48,   -48,
      26,    95,    96,    25,    34,    29,   -35,    59,    60,    89,
      61,    68,    85,    62,   111,    10,   106,    88,    98,    28,
      99,   100,   101,   102,   103,   104,    27,    91,    31,     0,
     107
};

static const yytype_int8 yycheck[] =
{
      39,    25,    26,     0,    28,    44,   101,   102,    14,    23,
       3,     4,     5,     6,    22,     8,   111,    27,    24,    76,
      59,    60,    61,    62,    30,    60,    65,    66,    21,    22,
      23,    66,    25,     3,     4,    28,    23,    94,    31,    32,
      97,    19,    20,     3,     4,     5,     6,    26,     8,    28,
      89,    21,    22,    23,    29,    25,     3,     4,    28,    30,
      99,    21,    22,    23,    29,    25,    19,    20,    28,    25,
      26,    31,    17,    18,    21,    22,    23,    15,    16,    15,
      16,    28,     9,    10,    11,    12,    13,    14,    15,    16,
      31,    17,    18,    26,    23,    27,    33,    28,    28,    33,
      28,    25,    25,    28,     7,     4,    94,    29,    29,    24,
      30,    29,    29,    29,    27,    29,    23,    76,    30,    -1,
      97
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    20,    35,    36,    37,    38,    39,    40,     0,
      37,    23,    25,    26,    28,    22,    20,    39,    41,    42,
      43,    27,    23,    29,    30,    26,    31,    44,    43,    27,
      45,    38,    39,    46,    23,     3,     4,     5,     6,     8,
      21,    22,    23,    25,    28,    32,    44,    47,    48,    49,
      50,    51,    52,    54,    55,    57,    60,    63,    64,    28,
      28,    28,    28,    25,    52,    26,    28,    52,    25,    53,
       9,    10,    11,    12,    13,    14,    56,    58,    61,    52,
      65,    66,    65,    52,    52,    25,    52,    65,    29,    33,
      54,    57,    15,    16,    59,    17,    18,    62,    29,    30,
      29,    29,    29,    27,    29,    52,    60,    63,    52,    47,
      47,     7,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    38,    39,
      39,    40,    41,    41,    42,    42,    43,    43,    44,    45,
      45,    46,    46,    47,    47,    47,    47,    47,    48,    48,
      49,    49,    50,    51,    51,    53,    52,    52,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    58,    57,
      57,    59,    59,    61,    60,    60,    62,    62,    63,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     0,     4,     1,     1,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     1,     1,     0,     4,     1,     1,     1,     3,     1,
       1,     1,     1,     4,     4,     4,     0,     1,     3,     1
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 88 "sintatico.y"
                    { 
                        if (erroSemantico) {
                            printf("\n Sintaxe ok, mas erro semantico: esqueceu de declarar alguma variavel que usou...\n");
                        } else {
                            printf("Sintaxe e semantica ok!\n");
                            if (HaWarningTabSimb()) { 
                                printf("Aviso: alguma variavel declarada e nao usada!\n");
                                imprimeTabSimb();
                            };
                        }   
                    }
#line 1474 "sintatico.tab.c"
    break;

  case 3:
#line 100 "sintatico.y"
                                                                    {;}
#line 1480 "sintatico.tab.c"
    break;

  case 4:
#line 101 "sintatico.y"
                                                                    {;}
#line 1486 "sintatico.tab.c"
    break;

  case 5:
#line 103 "sintatico.y"
                                                                    {;}
#line 1492 "sintatico.tab.c"
    break;

  case 6:
#line 104 "sintatico.y"
                                                                    {;}
#line 1498 "sintatico.tab.c"
    break;

  case 7:
#line 107 "sintatico.y"
                    {
                        printf("VARIAVEL CRIADA: %s, com o tipo %s\n", (yyvsp[-1].Ucadeia), tipos[tipo]);
                        colocaSimb((yyvsp[-1].Ucadeia),tipos[tipo],"variavel",0, proxLocMemVar++);
                    }
#line 1507 "sintatico.tab.c"
    break;

  case 8:
#line 112 "sintatico.y"
                    {
                        {
                            printf("VARIAVEL CRIADA: %s, com o tipo %s\n", (yyvsp[-3].Ucadeia), tipos[tipo]);
                            colocaSimb((yyvsp[-3].Ucadeia),tipos[tipo],"variavel",0, proxLocMemVar++);
                        }
                    }
#line 1518 "sintatico.tab.c"
    break;

  case 9:
#line 119 "sintatico.y"
                                                            { tipo=0; }
#line 1524 "sintatico.tab.c"
    break;

  case 10:
#line 120 "sintatico.y"
                                                            { tipo=1; }
#line 1530 "sintatico.tab.c"
    break;

  case 11:
#line 123 "sintatico.y"
                    {
                        printf("FUNCAO CRIADA: %s, com o tipo %s\n", (yyvsp[-4].Ucadeia), tipos[tipo]);
                        colocaSimb((yyvsp[-4].Ucadeia),tipos[tipo],"funcao",0, -1);
                    }
#line 1539 "sintatico.tab.c"
    break;

  case 12:
#line 128 "sintatico.y"
                                                                    {;}
#line 1545 "sintatico.tab.c"
    break;

  case 13:
#line 129 "sintatico.y"
                                                                    {;}
#line 1551 "sintatico.tab.c"
    break;

  case 14:
#line 131 "sintatico.y"
                                                                    {;}
#line 1557 "sintatico.tab.c"
    break;

  case 16:
#line 135 "sintatico.y"
                    {   
                        printf("PARAMETRO CRIADO: %s, com o tipo %s\n", (yyvsp[0].Ucadeia), tipos[tipo]);
                        colocaSimb((yyvsp[0].Ucadeia), tipos[tipo], "variavel", 0, proxLocMemVar++);
                    }
#line 1566 "sintatico.tab.c"
    break;

  case 17:
#line 140 "sintatico.y"
                    {   
                        printf("PARAMETRO CRIADO: %s, com o tipo %s\n", (yyvsp[-2].Ucadeia), tipos[tipo]);
                        colocaSimb((yyvsp[-2].Ucadeia), tipos[tipo], "variavel", 0, proxLocMemVar++);
                    }
#line 1575 "sintatico.tab.c"
    break;

  case 18:
#line 145 "sintatico.y"
                                                                    {;}
#line 1581 "sintatico.tab.c"
    break;

  case 20:
#line 148 "sintatico.y"
                                                                    {;}
#line 1587 "sintatico.tab.c"
    break;

  case 22:
#line 151 "sintatico.y"
                                                                    {;}
#line 1593 "sintatico.tab.c"
    break;

  case 23:
#line 153 "sintatico.y"
                                                                    {;}
#line 1599 "sintatico.tab.c"
    break;

  case 24:
#line 154 "sintatico.y"
                                                                    {;}
#line 1605 "sintatico.tab.c"
    break;

  case 25:
#line 155 "sintatico.y"
                                                                    {;}
#line 1611 "sintatico.tab.c"
    break;

  case 26:
#line 156 "sintatico.y"
                                                                    {;}
#line 1617 "sintatico.tab.c"
    break;

  case 27:
#line 157 "sintatico.y"
                                                                    {;}
#line 1623 "sintatico.tab.c"
    break;

  case 28:
#line 159 "sintatico.y"
                                                                    {;}
#line 1629 "sintatico.tab.c"
    break;

  case 29:
#line 160 "sintatico.y"
                                                                    {;}
#line 1635 "sintatico.tab.c"
    break;

  case 30:
#line 162 "sintatico.y"
                                                                    {;}
#line 1641 "sintatico.tab.c"
    break;

  case 31:
#line 163 "sintatico.y"
                                                                    {;}
#line 1647 "sintatico.tab.c"
    break;

  case 32:
#line 165 "sintatico.y"
                                                                    {;}
#line 1653 "sintatico.tab.c"
    break;

  case 33:
#line 167 "sintatico.y"
                                                                    {;}
#line 1659 "sintatico.tab.c"
    break;

  case 34:
#line 168 "sintatico.y"
                                                                    {;}
#line 1665 "sintatico.tab.c"
    break;

  case 35:
#line 170 "sintatico.y"
                        {store=0;}
#line 1671 "sintatico.tab.c"
    break;

  case 36:
#line 171 "sintatico.y"
                    {
                        emitRM("ST",ac,locMemIdStore,gp,"atribuicao: armazena valor");
                        store = 1;
                    }
#line 1680 "sintatico.tab.c"
    break;

  case 37:
#line 175 "sintatico.y"
                                                                    {;}
#line 1686 "sintatico.tab.c"
    break;

  case 38:
#line 178 "sintatico.y"
                    {
                        if (!constaTabSimb((yyvsp[0].Ucadeia)))
			                erroSemantico=1;
                        else
                        {
                            declaraUsadoTabSimb((yyvsp[0].Ucadeia));                        
                            
                            locMemId = recuperaLocMemId((yyvsp[0].Ucadeia));
                            emitRM("LD",ac,locMemId,gp,"carrega valor de id em ac");
                            //printf("Load para %s\n", $1);

                            if(store == 1)
                            {
                                locMemIdStore = recuperaLocMemId((yyvsp[0].Ucadeia));
                                printf("Store para %s\n", (yyvsp[0].Ucadeia));
                            }   
                            
                        }
                    }
#line 1710 "sintatico.tab.c"
    break;

  case 39:
#line 198 "sintatico.y"
                    {
                        if (!constaTabSimb((yyvsp[-3].Ucadeia)))
			                erroSemantico=1;
                        else
                            declaraUsadoTabSimb((yyvsp[-3].Ucadeia));
                    }
#line 1721 "sintatico.tab.c"
    break;

  case 40:
#line 205 "sintatico.y"
                                                                    {;}
#line 1727 "sintatico.tab.c"
    break;

  case 41:
#line 206 "sintatico.y"
                                                                    {;}
#line 1733 "sintatico.tab.c"
    break;

  case 42:
#line 208 "sintatico.y"
                                                                    {;}
#line 1739 "sintatico.tab.c"
    break;

  case 43:
#line 209 "sintatico.y"
                                                                    {;}
#line 1745 "sintatico.tab.c"
    break;

  case 44:
#line 210 "sintatico.y"
                                                                    {;}
#line 1751 "sintatico.tab.c"
    break;

  case 45:
#line 211 "sintatico.y"
                                                                    {;}
#line 1757 "sintatico.tab.c"
    break;

  case 46:
#line 212 "sintatico.y"
                                                                    {;}
#line 1763 "sintatico.tab.c"
    break;

  case 47:
#line 213 "sintatico.y"
                                                                    {;}
#line 1769 "sintatico.tab.c"
    break;

  case 48:
#line 216 "sintatico.y"
                    {
                        emitRM("LDC",ac1,0,0,"load const");
                        emitRO("ADD",ac1,ac,ac1,"move register");
                    }
#line 1778 "sintatico.tab.c"
    break;

  case 49:
#line 221 "sintatico.y"
                    {
                        if(isAdd == 1)
                            emitRO("ADD",ac,ac1,ac,"add a+b");
                        else
                            emitRO("SUB",ac,ac1,ac,"sub a-b");
                    }
#line 1789 "sintatico.tab.c"
    break;

  case 50:
#line 227 "sintatico.y"
                                                                    {;}
#line 1795 "sintatico.tab.c"
    break;

  case 51:
#line 229 "sintatico.y"
                                                                    {isAdd = 1;}
#line 1801 "sintatico.tab.c"
    break;

  case 52:
#line 230 "sintatico.y"
                                                                    {isAdd = 0;}
#line 1807 "sintatico.tab.c"
    break;

  case 53:
#line 233 "sintatico.y"
                    {
                        emitRM("LDC",ac1,0,0,"load const");
                        emitRO("ADD",ac1,ac,ac1,"move register");
                    }
#line 1816 "sintatico.tab.c"
    break;

  case 54:
#line 237 "sintatico.y"
                    {
                        if(isMul == 1)
                            emitRO("MUL",ac,ac1,ac,"mul a*b");
                        else
                            emitRO("DIV",ac,ac1,ac,"div a/b");
                    }
#line 1827 "sintatico.tab.c"
    break;

  case 55:
#line 243 "sintatico.y"
                                                                    {;}
#line 1833 "sintatico.tab.c"
    break;

  case 56:
#line 245 "sintatico.y"
                                                                    {isMul = 1;}
#line 1839 "sintatico.tab.c"
    break;

  case 57:
#line 246 "sintatico.y"
                                                                    {isMul = 0;}
#line 1845 "sintatico.tab.c"
    break;

  case 58:
#line 248 "sintatico.y"
                                                                    {;}
#line 1851 "sintatico.tab.c"
    break;

  case 59:
#line 249 "sintatico.y"
                                                                    {;}
#line 1857 "sintatico.tab.c"
    break;

  case 60:
#line 250 "sintatico.y"
                                                                    {;}
#line 1863 "sintatico.tab.c"
    break;

  case 61:
#line 252 "sintatico.y"
                    {emitRM("LDC",ac,(yyvsp[0].Uinteiro),0,"load const");}
#line 1869 "sintatico.tab.c"
    break;

  case 62:
#line 254 "sintatico.y"
                    {emitRM("LDC",ac,(yyvsp[0].Uflutuante),0,"load const");}
#line 1875 "sintatico.tab.c"
    break;

  case 63:
#line 257 "sintatico.y"
                    {
                        printf("FEZ UMA ESCRITA\n");
                        emitRO("OUT",ac,0,0,"write ac");
                    }
#line 1884 "sintatico.tab.c"
    break;

  case 64:
#line 262 "sintatico.y"
                    { printf("FEZ UMA LEITURA\n"); }
#line 1890 "sintatico.tab.c"
    break;

  case 65:
#line 263 "sintatico.y"
                                                                    {;}
#line 1896 "sintatico.tab.c"
    break;

  case 67:
#line 266 "sintatico.y"
                                                                    {;}
#line 1902 "sintatico.tab.c"
    break;

  case 68:
#line 268 "sintatico.y"
                                                                    {;}
#line 1908 "sintatico.tab.c"
    break;

  case 69:
#line 269 "sintatico.y"
                                                                    {;}
#line 1914 "sintatico.tab.c"
    break;


#line 1918 "sintatico.tab.c"

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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 271 "sintatico.y"


regTabSimb *colocaSimb(char *nomeSimb, char *tipoSimb, char *naturezaSimb, int usadoSimb, int loc){
	regTabSimb *ptr;
	ptr = (regTabSimb *) malloc (sizeof(regTabSimb));

	ptr->nome= (char *) malloc(strlen(nomeSimb)+1);
	ptr->tipo= (char *) malloc(strlen(tipoSimb)+1);
	ptr->natureza= (char *) malloc(strlen(naturezaSimb)+1);

	strcpy (ptr->nome,nomeSimb);
	strcpy (ptr->tipo,tipoSimb);
	strcpy (ptr->natureza,naturezaSimb);
	ptr->usado = usadoSimb;
    ptr->locMem = loc;

	ptr->prox= (struct regTabSimb *)tabSimb;
	tabSimb= ptr;
	return ptr;
}
int constaTabSimb(char *nomeSimb) {
	regTabSimb *ptr;
	for (ptr=tabSimb; ptr!=(regTabSimb *)0; ptr=(regTabSimb *)ptr->prox)
	  if (strcmp(ptr->nome,nomeSimb)==0) return 1;
    printf("VARIAVEL NAO DECLARADA USADA: %s\n", nomeSimb);
	return 0;
}
int HaWarningTabSimb() {
	regTabSimb *ptr;
	for (ptr=tabSimb; ptr!=(regTabSimb *)0; ptr=(regTabSimb *)ptr->prox)
	  if ((ptr->usado==0) && (strcmp(ptr->natureza,"variavel")==0)) return 1;
	return 0;
}
void declaraUsadoTabSimb(char *nomeSimb) {
	regTabSimb *ptr;
	for (ptr=tabSimb; ptr!=(regTabSimb *)0; ptr=(regTabSimb *)ptr->prox)
	  if (strcmp(ptr->nome,nomeSimb)==0) {
        ptr->usado = 1; return;
      }
}
void imprimeTabSimb() {
	regTabSimb *ptr;
	for (ptr=tabSimb; ptr!=(regTabSimb *)0; ptr=(regTabSimb *)ptr->prox)  
        if (strcmp(ptr->natureza,"variavel")==0)
            printf("%s usado: %d\n", ptr->nome, ptr->usado);      
}

// recupera locacao de memoria de um id cujo nome eh passado em parametro
int recuperaLocMemId(char *nomeSimb) {
	regTabSimb *ptr;
	for (ptr=tabSimb; ptr!=(regTabSimb *)0; ptr=(regTabSimb *)ptr->prox)
	  if (strcmp(ptr->nome,nomeSimb)==0) return ptr->locMem;
	return -1;
}

void emitRO( char *op, int r, int s, int t, char *c)
{ fprintf(yyout,"%3d:  %5s  %d,%d,%d ",emitLoc++,op,r,s,t);
//  if (TraceCode) fprintf(code,"\t%s",c) ;
  fprintf(yyout,"\n") ;
//  if (highEmitLoc < emitLoc) highEmitLoc = emitLoc ;
} /* emitRO */

/* Procedure emitRM emits a register-to-memory
 * TM instruction
 * op = the opcode
 * r = target register
 * d = the offset
 * s = the base register
 * c = a comment to be printed if TraceCode is TRUE
 */
void emitRM( char * op, int r, int d, int s, char *c)
{ fprintf(yyout,"%3d:  %5s  %d,%d(%d) ",emitLoc++,op,r,d,s);
//  if (TraceCode) fprintf(code,"\t%s",c) ;
  fprintf(yyout,"\n") ;
//  if (highEmitLoc < emitLoc)  highEmitLoc = emitLoc ;
} /* emitRM */

int main (int argc, char* argv[]) 
{
    if (argc <= 0) return 0;
    yyin = fopen(argv[1], "rt");
    yyout = fopen("out.tm", "wt");

    //emitComment("Standard prelude:");
    emitRM("LD",mp,0,ac,"load maxaddress from location 0");
    emitRM("ST",ac,0,ac,"clear location 0");
    //emitComment("End of standard prelude.");

    erroSemantico=0;

	yyparse ();
    
    //emitComment("End of execution.");
    emitRO("HALT",0,0,0,"");

    fclose(yyin);
    fclose(yyout);
    return 0;
}
int yyerror (s) /* Called by yyparse on error */
	char *s;
{
	printf ("Problema com a analise sintatica!\n%s\n", s);
}
