/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
	struct regTabSimb *prox;    /* ponteiro */
};
typedef struct regTabSimb regTabSimb;
regTabSimb *tabSimb = (regTabSimb *)0;
regTabSimb *colocaSimb();
int constaTabSimb(char *nomeSimb);
int HaWarningTabSimb();
void declaraUsadoTabSimb();
void imprimeTabSimb();
int erroSemantico;



#line 117 "sintatico.tab.c"

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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LEITURA = 3,                    /* LEITURA  */
  YYSYMBOL_ESCRITA = 4,                    /* ESCRITA  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_LESSEQUAL = 9,                  /* LESSEQUAL  */
  YYSYMBOL_LESS = 10,                      /* LESS  */
  YYSYMBOL_GREATER = 11,                   /* GREATER  */
  YYSYMBOL_GREATEREQUAL = 12,              /* GREATEREQUAL  */
  YYSYMBOL_EQUALEQUAL = 13,                /* EQUALEQUAL  */
  YYSYMBOL_NOTEQUAL = 14,                  /* NOTEQUAL  */
  YYSYMBOL_ADD = 15,                       /* ADD  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_MULTIPLIER = 17,                /* MULTIPLIER  */
  YYSYMBOL_DIVISION = 18,                  /* DIVISION  */
  YYSYMBOL_TYPEINT = 19,                   /* TYPEINT  */
  YYSYMBOL_TYPEVOID = 20,                  /* TYPEVOID  */
  YYSYMBOL_FLOAT = 21,                     /* FLOAT  */
  YYSYMBOL_INT = 22,                       /* INT  */
  YYSYMBOL_ID = 23,                        /* ID  */
  YYSYMBOL_24_then_ = 24,                  /* "then"  */
  YYSYMBOL_25_ = 25,                       /* ';'  */
  YYSYMBOL_26_ = 26,                       /* '['  */
  YYSYMBOL_27_ = 27,                       /* ']'  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_programa = 35,                  /* programa  */
  YYSYMBOL_declaracao_lista = 36,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 37,                /* declaracao  */
  YYSYMBOL_var_declaracao = 38,            /* var_declaracao  */
  YYSYMBOL_tipo_especificador = 39,        /* tipo_especificador  */
  YYSYMBOL_fun_declaracao = 40,            /* fun_declaracao  */
  YYSYMBOL_params = 41,                    /* params  */
  YYSYMBOL_params_lista = 42,              /* params_lista  */
  YYSYMBOL_param = 43,                     /* param  */
  YYSYMBOL_escopo_stmt = 44,               /* escopo_stmt  */
  YYSYMBOL_declaracoes_locais = 45,        /* declaracoes_locais  */
  YYSYMBOL_statement_lista = 46,           /* statement_lista  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_expressao_stmt = 48,            /* expressao_stmt  */
  YYSYMBOL_selecao_stmt = 49,              /* selecao_stmt  */
  YYSYMBOL_iteracao_stmt = 50,             /* iteracao_stmt  */
  YYSYMBOL_retorno_stmt = 51,              /* retorno_stmt  */
  YYSYMBOL_expressao = 52,                 /* expressao  */
  YYSYMBOL_var = 53,                       /* var  */
  YYSYMBOL_expressao_simples = 54,         /* expressao_simples  */
  YYSYMBOL_relop = 55,                     /* relop  */
  YYSYMBOL_expressao_aditiva = 56,         /* expressao_aditiva  */
  YYSYMBOL_addop = 57,                     /* addop  */
  YYSYMBOL_termo = 58,                     /* termo  */
  YYSYMBOL_mulop = 59,                     /* mulop  */
  YYSYMBOL_fator = 60,                     /* fator  */
  YYSYMBOL_call = 61,                      /* call  */
  YYSYMBOL_args = 62,                      /* args  */
  YYSYMBOL_args_lista = 63                 /* args_lista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
static const yytype_uint8 yyrline[] =
{
       0,    78,    78,    91,    92,    94,    95,    97,   102,   110,
     111,   113,   119,   120,   122,   123,   125,   130,   136,   138,
     139,   141,   142,   144,   145,   146,   147,   148,   150,   151,
     153,   154,   156,   158,   159,   161,   162,   164,   171,   179,
     180,   182,   183,   184,   185,   186,   187,   189,   190,   192,
     193,   195,   196,   198,   199,   201,   202,   203,   204,   206,
     209,   214,   216,   218,   219,   221,   222
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LEITURA", "ESCRITA",
  "WHILE", "IF", "ELSE", "RETURN", "LESSEQUAL", "LESS", "GREATER",
  "GREATEREQUAL", "EQUALEQUAL", "NOTEQUAL", "ADD", "MINUS", "MULTIPLIER",
  "DIVISION", "TYPEINT", "TYPEVOID", "FLOAT", "INT", "ID", "\"then\"",
  "';'", "'['", "']'", "'('", "')'", "','", "'{'", "'}'", "'='", "$accept",
  "programa", "declaracao_lista", "declaracao", "var_declaracao",
  "tipo_especificador", "fun_declaracao", "params", "params_lista",
  "param", "escopo_stmt", "declaracoes_locais", "statement_lista",
  "statement", "expressao_stmt", "selecao_stmt", "iteracao_stmt",
  "retorno_stmt", "expressao", "var", "expressao_simples", "relop",
  "expressao_aditiva", "addop", "termo", "mulop", "fator", "call", "args",
  "args_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      17,  -100,  -100,     7,    17,  -100,  -100,   -11,  -100,  -100,
    -100,    24,  -100,    -3,    47,     2,     5,    28,    18,    23,
    -100,  -100,    30,    59,    17,    48,  -100,  -100,  -100,  -100,
      17,  -100,    68,    10,    44,    64,    65,    66,    67,    51,
    -100,  -100,   -20,  -100,    36,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,    72,    63,  -100,    71,    60,  -100,  -100,    36,
      36,    36,    36,  -100,    74,    36,    36,    69,  -100,    36,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,    36,    36,
    -100,  -100,    36,  -100,    75,    70,    76,    77,    78,  -100,
      81,    80,  -100,  -100,  -100,    73,    60,  -100,  -100,    36,
    -100,    40,    40,  -100,  -100,  -100,  -100,    94,    40,  -100
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
      59,    58,    37,    29,     0,    18,    24,    22,    23,    25,
      26,    27,     0,    56,    36,    40,    48,    52,    57,    63,
      63,     0,     0,    33,     0,     0,    63,     0,    28,     0,
      41,    42,    43,    44,    45,    46,    49,    50,     0,     0,
      53,    54,     0,    66,     0,    64,     0,     0,     0,    34,
       0,     0,    55,    35,    56,    39,    47,    51,    61,     0,
      60,     0,     0,    38,    62,    65,    32,    30,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,  -100,    98,    82,   -13,  -100,  -100,  -100,    79,
      87,  -100,  -100,   -99,  -100,  -100,  -100,  -100,   -39,   -54,
    -100,  -100,    33,  -100,    34,  -100,    32,  -100,   -56,  -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      46,    30,    33,    47,    48,    49,    50,    51,    52,    53,
      54,    78,    55,    79,    56,    82,    57,    58,    84,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    17,   106,   107,    86,    67,    65,     9,    66,   109,
      91,    17,    11,    35,    36,    37,    38,    32,    39,    15,
      83,    83,    87,    88,    94,    94,    90,    83,    94,    21,
      93,    40,    41,    42,   -13,    43,     1,     2,    44,    35,
      36,    26,    45,    35,    36,    37,    38,    23,    39,    12,
      13,    22,    14,    24,    35,    36,    25,    40,    41,    42,
     105,    40,    41,    42,    44,    43,     1,    16,    44,    12,
      13,    26,    40,    41,    42,    29,    63,    80,    81,    44,
      70,    71,    72,    73,    74,    75,    76,    77,    76,    77,
      26,    34,    59,    60,    61,    62,    69,    68,    92,    89,
      99,   108,    10,    28,    98,   100,   101,   102,   103,   104,
      27,    95,    31,    96,    97
};

static const yytype_int8 yycheck[] =
{
      39,    14,   101,   102,    60,    44,    26,     0,    28,   108,
      66,    24,    23,     3,     4,     5,     6,    30,     8,    22,
      59,    60,    61,    62,    78,    79,    65,    66,    82,    27,
      69,    21,    22,    23,    29,    25,    19,    20,    28,     3,
       4,    31,    32,     3,     4,     5,     6,    29,     8,    25,
      26,    23,    28,    30,     3,     4,    26,    21,    22,    23,
      99,    21,    22,    23,    28,    25,    19,    20,    28,    25,
      26,    31,    21,    22,    23,    27,    25,    17,    18,    28,
       9,    10,    11,    12,    13,    14,    15,    16,    15,    16,
      31,    23,    28,    28,    28,    28,    33,    25,    29,    25,
      30,     7,     4,    24,    29,    29,    29,    29,    27,    29,
      23,    78,    30,    79,    82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    20,    35,    36,    37,    38,    39,    40,     0,
      37,    23,    25,    26,    28,    22,    20,    39,    41,    42,
      43,    27,    23,    29,    30,    26,    31,    44,    43,    27,
      45,    38,    39,    46,    23,     3,     4,     5,     6,     8,
      21,    22,    23,    25,    28,    32,    44,    47,    48,    49,
      50,    51,    52,    53,    54,    56,    58,    60,    61,    28,
      28,    28,    28,    25,    52,    26,    28,    52,    25,    33,
       9,    10,    11,    12,    13,    14,    15,    16,    55,    57,
      17,    18,    59,    52,    62,    63,    62,    52,    52,    25,
      52,    62,    29,    52,    53,    56,    58,    60,    29,    30,
      29,    29,    29,    27,    29,    52,    47,    47,     7,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    38,    39,
      39,    40,    41,    41,    42,    42,    43,    43,    44,    45,
      45,    46,    46,    47,    47,    47,    47,    47,    48,    48,
      49,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      61,    61,    61,    62,    62,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       4,     4,     4,     0,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* programa: declaracao_lista  */
#line 79 "sintatico.y"
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
#line 1249 "sintatico.tab.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 91 "sintatico.y"
                                                                    {;}
#line 1255 "sintatico.tab.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 92 "sintatico.y"
                                                                    {;}
#line 1261 "sintatico.tab.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 94 "sintatico.y"
                                                                    {;}
#line 1267 "sintatico.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 95 "sintatico.y"
                                                                    {;}
#line 1273 "sintatico.tab.c"
    break;

  case 7: /* var_declaracao: tipo_especificador ID ';'  */
#line 98 "sintatico.y"
                    {
                        printf("VARIAVEL CRIADA: %s, com o tipo %s\n", (yyvsp[-1].Ucadeia), tipos[tipo]);
                        colocaSimb((yyvsp[-1].Ucadeia),tipos[tipo],"variavel",0);
                    }
#line 1282 "sintatico.tab.c"
    break;

  case 8: /* var_declaracao: tipo_especificador ID '[' INT ']'  */
#line 103 "sintatico.y"
                    {
                        {
                            printf("VARIAVEL CRIADA: %s, com o tipo %s\n", (yyvsp[-3].Ucadeia), tipos[tipo]);
                            colocaSimb((yyvsp[-3].Ucadeia),tipos[tipo],"variavel",0);
                        }
                    }
#line 1293 "sintatico.tab.c"
    break;

  case 9: /* tipo_especificador: TYPEINT  */
#line 110 "sintatico.y"
                                                            { tipo=0; }
#line 1299 "sintatico.tab.c"
    break;

  case 10: /* tipo_especificador: TYPEVOID  */
#line 111 "sintatico.y"
                                                            { tipo=1; }
#line 1305 "sintatico.tab.c"
    break;

  case 11: /* fun_declaracao: tipo_especificador ID '(' params ')' escopo_stmt  */
#line 114 "sintatico.y"
                    {
                        printf("FUNCAO CRIADA: %s, com o tipo %s\n", (yyvsp[-4].Ucadeia), tipos[tipo]);
                        colocaSimb((yyvsp[-4].Ucadeia),tipos[tipo],"funcao",0);
                    }
#line 1314 "sintatico.tab.c"
    break;

  case 12: /* params: params_lista  */
#line 119 "sintatico.y"
                                                                    {;}
#line 1320 "sintatico.tab.c"
    break;

  case 13: /* params: TYPEVOID  */
#line 120 "sintatico.y"
                                                                    {;}
#line 1326 "sintatico.tab.c"
    break;

  case 14: /* params_lista: params_lista ',' param  */
#line 122 "sintatico.y"
                                                                    {;}
#line 1332 "sintatico.tab.c"
    break;

  case 16: /* param: tipo_especificador ID  */
#line 126 "sintatico.y"
                    {   
                        printf("PARAMETRO CRIADO: %s, com o tipo %s\n", (yyvsp[0].Ucadeia), tipos[tipo]);
                        colocaSimb((yyvsp[0].Ucadeia), tipos[tipo], "variavel", 0);
                    }
#line 1341 "sintatico.tab.c"
    break;

  case 17: /* param: tipo_especificador ID '[' ']'  */
#line 131 "sintatico.y"
                    {   
                        printf("PARAMETRO CRIADO: %s, com o tipo %s\n", (yyvsp[-2].Ucadeia), tipos[tipo]);
                        colocaSimb((yyvsp[-2].Ucadeia), tipos[tipo], "variavel", 0);
                    }
#line 1350 "sintatico.tab.c"
    break;

  case 18: /* escopo_stmt: '{' declaracoes_locais statement_lista '}'  */
#line 136 "sintatico.y"
                                                                    {;}
#line 1356 "sintatico.tab.c"
    break;

  case 20: /* declaracoes_locais: declaracoes_locais var_declaracao  */
#line 139 "sintatico.y"
                                                                    {;}
#line 1362 "sintatico.tab.c"
    break;

  case 22: /* statement_lista: statement_lista statement  */
#line 142 "sintatico.y"
                                                                    {;}
#line 1368 "sintatico.tab.c"
    break;

  case 23: /* statement: expressao_stmt  */
#line 144 "sintatico.y"
                                                                    {;}
#line 1374 "sintatico.tab.c"
    break;

  case 24: /* statement: escopo_stmt  */
#line 145 "sintatico.y"
                                                                    {;}
#line 1380 "sintatico.tab.c"
    break;

  case 25: /* statement: selecao_stmt  */
#line 146 "sintatico.y"
                                                                    {;}
#line 1386 "sintatico.tab.c"
    break;

  case 26: /* statement: iteracao_stmt  */
#line 147 "sintatico.y"
                                                                    {;}
#line 1392 "sintatico.tab.c"
    break;

  case 27: /* statement: retorno_stmt  */
#line 148 "sintatico.y"
                                                                    {;}
#line 1398 "sintatico.tab.c"
    break;

  case 28: /* expressao_stmt: expressao ';'  */
#line 150 "sintatico.y"
                                                                    {;}
#line 1404 "sintatico.tab.c"
    break;

  case 29: /* expressao_stmt: ';'  */
#line 151 "sintatico.y"
                                                                    {;}
#line 1410 "sintatico.tab.c"
    break;

  case 30: /* selecao_stmt: IF '(' expressao ')' statement  */
#line 153 "sintatico.y"
                                                                    {;}
#line 1416 "sintatico.tab.c"
    break;

  case 31: /* selecao_stmt: IF '(' expressao ')' statement ELSE statement  */
#line 154 "sintatico.y"
                                                                    {;}
#line 1422 "sintatico.tab.c"
    break;

  case 32: /* iteracao_stmt: WHILE '(' expressao ')' statement  */
#line 156 "sintatico.y"
                                                                    {;}
#line 1428 "sintatico.tab.c"
    break;

  case 33: /* retorno_stmt: RETURN ';'  */
#line 158 "sintatico.y"
                                                                    {;}
#line 1434 "sintatico.tab.c"
    break;

  case 34: /* retorno_stmt: RETURN expressao ';'  */
#line 159 "sintatico.y"
                                                                    {;}
#line 1440 "sintatico.tab.c"
    break;

  case 35: /* expressao: var '=' expressao  */
#line 161 "sintatico.y"
                                                                    {;}
#line 1446 "sintatico.tab.c"
    break;

  case 36: /* expressao: expressao_simples  */
#line 162 "sintatico.y"
                                                                    {;}
#line 1452 "sintatico.tab.c"
    break;

  case 37: /* var: ID  */
#line 165 "sintatico.y"
                    {
                        if (!constaTabSimb((yyvsp[0].Ucadeia)))
			                erroSemantico=1;
                        else
                            declaraUsadoTabSimb((yyvsp[0].Ucadeia));
                    }
#line 1463 "sintatico.tab.c"
    break;

  case 38: /* var: ID '[' expressao ']'  */
#line 172 "sintatico.y"
                    {
                        if (!constaTabSimb((yyvsp[-3].Ucadeia)))
			                erroSemantico=1;
                        else
                            declaraUsadoTabSimb((yyvsp[-3].Ucadeia));
                    }
#line 1474 "sintatico.tab.c"
    break;

  case 39: /* expressao_simples: expressao_aditiva relop expressao_aditiva  */
#line 179 "sintatico.y"
                                                                    {;}
#line 1480 "sintatico.tab.c"
    break;

  case 40: /* expressao_simples: expressao_aditiva  */
#line 180 "sintatico.y"
                                                                    {;}
#line 1486 "sintatico.tab.c"
    break;

  case 41: /* relop: LESSEQUAL  */
#line 182 "sintatico.y"
                                                                    {;}
#line 1492 "sintatico.tab.c"
    break;

  case 42: /* relop: LESS  */
#line 183 "sintatico.y"
                                                                    {;}
#line 1498 "sintatico.tab.c"
    break;

  case 43: /* relop: GREATER  */
#line 184 "sintatico.y"
                                                                    {;}
#line 1504 "sintatico.tab.c"
    break;

  case 44: /* relop: GREATEREQUAL  */
#line 185 "sintatico.y"
                                                                    {;}
#line 1510 "sintatico.tab.c"
    break;

  case 45: /* relop: EQUALEQUAL  */
#line 186 "sintatico.y"
                                                                    {;}
#line 1516 "sintatico.tab.c"
    break;

  case 46: /* relop: NOTEQUAL  */
#line 187 "sintatico.y"
                                                                    {;}
#line 1522 "sintatico.tab.c"
    break;

  case 47: /* expressao_aditiva: expressao_aditiva addop termo  */
#line 189 "sintatico.y"
                                                                    {;}
#line 1528 "sintatico.tab.c"
    break;

  case 48: /* expressao_aditiva: termo  */
#line 190 "sintatico.y"
                                                                    {;}
#line 1534 "sintatico.tab.c"
    break;

  case 49: /* addop: ADD  */
#line 192 "sintatico.y"
                                                                    {;}
#line 1540 "sintatico.tab.c"
    break;

  case 50: /* addop: MINUS  */
#line 193 "sintatico.y"
                                                                    {;}
#line 1546 "sintatico.tab.c"
    break;

  case 51: /* termo: termo mulop fator  */
#line 195 "sintatico.y"
                                                                    {;}
#line 1552 "sintatico.tab.c"
    break;

  case 52: /* termo: fator  */
#line 196 "sintatico.y"
                                                                    {;}
#line 1558 "sintatico.tab.c"
    break;

  case 53: /* mulop: MULTIPLIER  */
#line 198 "sintatico.y"
                                                                    {;}
#line 1564 "sintatico.tab.c"
    break;

  case 54: /* mulop: DIVISION  */
#line 199 "sintatico.y"
                                                                    {;}
#line 1570 "sintatico.tab.c"
    break;

  case 55: /* fator: '(' expressao ')'  */
#line 201 "sintatico.y"
                                                                    {;}
#line 1576 "sintatico.tab.c"
    break;

  case 56: /* fator: var  */
#line 202 "sintatico.y"
                                                                    {;}
#line 1582 "sintatico.tab.c"
    break;

  case 57: /* fator: call  */
#line 203 "sintatico.y"
                                                                    {;}
#line 1588 "sintatico.tab.c"
    break;

  case 58: /* fator: INT  */
#line 205 "sintatico.y"
                    { emitRM("LDC",ac,(yyvsp[0].Uinteiro),0,"load const"); }
#line 1594 "sintatico.tab.c"
    break;

  case 59: /* fator: FLOAT  */
#line 207 "sintatico.y"
                    { emitRM("LDC",ac,(yyvsp[0].Uflutuante),0,"load const"); }
#line 1600 "sintatico.tab.c"
    break;

  case 60: /* call: ESCRITA '(' args ')'  */
#line 210 "sintatico.y"
                    {
                        printf("FEZ UMA ESCRITA\n");
                        emitRO("OUT",ac,0,0,"write ac");
                    }
#line 1609 "sintatico.tab.c"
    break;

  case 61: /* call: LEITURA '(' args ')'  */
#line 215 "sintatico.y"
                    { printf("FEZ UMA LEITURA\n"); }
#line 1615 "sintatico.tab.c"
    break;

  case 62: /* call: ID '(' args ')'  */
#line 216 "sintatico.y"
                                                                    {;}
#line 1621 "sintatico.tab.c"
    break;

  case 64: /* args: args_lista  */
#line 219 "sintatico.y"
                                                                    {;}
#line 1627 "sintatico.tab.c"
    break;

  case 65: /* args_lista: args_lista ',' expressao  */
#line 221 "sintatico.y"
                                                                    {;}
#line 1633 "sintatico.tab.c"
    break;

  case 66: /* args_lista: expressao  */
#line 222 "sintatico.y"
                                                                    {;}
#line 1639 "sintatico.tab.c"
    break;


#line 1643 "sintatico.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 224 "sintatico.y"


regTabSimb *colocaSimb(char *nomeSimb, char *tipoSimb, char *naturezaSimb, int usadoSimb){
	regTabSimb *ptr;
	ptr = (regTabSimb *) malloc (sizeof(regTabSimb));

	ptr->nome= (char *) malloc(strlen(nomeSimb)+1);
	ptr->tipo= (char *) malloc(strlen(tipoSimb)+1);
	ptr->natureza= (char *) malloc(strlen(naturezaSimb)+1);

	strcpy (ptr->nome,nomeSimb);
	strcpy (ptr->tipo,tipoSimb);
	strcpy (ptr->natureza,naturezaSimb);
	ptr->usado = usadoSimb;

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
