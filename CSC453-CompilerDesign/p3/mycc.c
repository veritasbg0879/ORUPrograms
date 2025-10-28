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
#line 7 "mycc.y"


#include "lex.yy.h"
#include "global.h"
static struct ClassFile cf;


#line 79 "mycc.c"

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

#include "mycc.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT8 = 4,                       /* INT8  */
  YYSYMBOL_INT16 = 5,                      /* INT16  */
  YYSYMBOL_INT32 = 6,                      /* INT32  */
  YYSYMBOL_FLT = 7,                        /* FLT  */
  YYSYMBOL_STR = 8,                        /* STR  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_DO = 10,                        /* DO  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_LA = 16,                        /* LA  */
  YYSYMBOL_RA = 17,                        /* RA  */
  YYSYMBOL_XA = 18,                        /* XA  */
  YYSYMBOL_OA = 19,                        /* OA  */
  YYSYMBOL_MA = 20,                        /* MA  */
  YYSYMBOL_AA = 21,                        /* AA  */
  YYSYMBOL_TA = 22,                        /* TA  */
  YYSYMBOL_DA = 23,                        /* DA  */
  YYSYMBOL_PA = 24,                        /* PA  */
  YYSYMBOL_NA = 25,                        /* NA  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_AN = 27,                        /* AN  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_GE = 30,                        /* GE  */
  YYSYMBOL_LE = 31,                        /* LE  */
  YYSYMBOL_LS = 32,                        /* LS  */
  YYSYMBOL_RS = 33,                        /* RS  */
  YYSYMBOL_PP = 34,                        /* PP  */
  YYSYMBOL_NN = 35,                        /* NN  */
  YYSYMBOL_AR = 36,                        /* AR  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_43_ = 43,                       /* '|'  */
  YYSYMBOL_44_ = 44,                       /* '^'  */
  YYSYMBOL_45_ = 45,                       /* '&'  */
  YYSYMBOL_46_ = 46,                       /* '<'  */
  YYSYMBOL_47_ = 47,                       /* '>'  */
  YYSYMBOL_48_ = 48,                       /* '+'  */
  YYSYMBOL_49_ = 49,                       /* '-'  */
  YYSYMBOL_50_ = 50,                       /* '*'  */
  YYSYMBOL_51_ = 51,                       /* '/'  */
  YYSYMBOL_52_ = 52,                       /* '%'  */
  YYSYMBOL_53_ = 53,                       /* '!'  */
  YYSYMBOL_54_ = 54,                       /* '~'  */
  YYSYMBOL_55_ = 55,                       /* '$'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_stmts = 57,                     /* stmts  */
  YYSYMBOL_stmt = 58,                      /* stmt  */
  YYSYMBOL_expr = 59,                      /* expr  */
  YYSYMBOL_L = 60,                         /* L  */
  YYSYMBOL_M = 61,                         /* M  */
  YYSYMBOL_N = 62,                         /* N  */
  YYSYMBOL_P = 63                          /* P  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   581

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
       2,     2,     2,    53,     2,     2,    55,    52,    45,     2,
      38,    39,    50,    48,     2,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      46,    42,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    43,    41,    54,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    62,    66,    67,    68,    70,    72,    74,
      76,    83,    85,    87,    88,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   124,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     140,   143,   148,   153
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT8", "INT16",
  "INT32", "FLT", "STR", "BREAK", "DO", "ELSE", "FOR", "IF", "RETURN",
  "WHILE", "LA", "RA", "XA", "OA", "MA", "AA", "TA", "DA", "PA", "NA",
  "OR", "AN", "EQ", "NE", "GE", "LE", "LS", "RS", "PP", "NN", "AR", "';'",
  "'('", "')'", "'{'", "'}'", "'='", "'|'", "'^'", "'&'", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "'$'", "$accept",
  "stmts", "stmt", "expr", "L", "M", "N", "P", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -117,   105,  -117,   -35,   113,  -117,  -117,  -117,  -117,  -117,
     -33,  -117,   -32,   -24,   237,   -12,    25,    39,  -117,   237,
    -117,   237,   237,   237,   237,    47,  -117,   250,  -117,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,  -117,
    -117,   237,  -117,   215,   237,   237,   277,  -117,  -117,  -117,
     304,   160,   412,   412,   412,   412,  -117,   237,   237,   237,
     237,   237,   237,   237,   237,  -117,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,    48,   412,   331,
    -117,   237,  -117,  -117,   438,   463,   486,   486,   508,   529,
     -11,   -11,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,    26,    28,  -117,   358,   237,  -117,   215,  -117,
     385,   237,    55,   215,  -117,   412,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,    32,   215,    33,  -117,  -117,  -117,   237,
     412,  -117,    34,  -117,   215,  -117,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,     0,    54,    55,    56,    57,    58,    59,
       0,    60,     0,     0,     0,     0,     0,     0,     4,     0,
       3,     0,     0,     0,     0,     0,     2,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,     0,    12,     0,     0,     0,     0,    60,    50,    51,
       0,     0,    46,    47,    44,    45,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,    22,    23,
      20,    21,    18,    19,    16,    17,    15,     0,    63,     0,
      11,     0,    48,    13,    26,    27,    31,    32,    36,    35,
      37,    38,    28,    29,    30,    33,    34,    39,    40,    41,
      42,    43,     0,     0,    61,     0,     0,    60,     0,    61,
       0,     0,     6,     0,    61,    61,    62,    62,    62,    62,
      60,     8,    60,     0,     0,     0,    60,     7,     9,     0,
      63,    62,     0,    60,     0,    62,    10
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -117,    52,   -40,   -14,   -46,   -57,  -116,   -66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    26,    27,    43,   118,   130,   113
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    91,    28,    87,    42,    50,    44,    52,    53,    54,
      55,   131,   132,   133,    45,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   142,    47,    86,    48,   146,
      88,    89,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    49,    94,    95,    96,    97,    98,    99,   100,
     101,    56,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   123,   112,   116,   117,   126,   128,   129,   136,
     138,   121,    51,   143,   141,     0,     0,   115,   122,     0,
       0,     0,     0,   127,   134,     0,   135,     0,     0,     0,
     139,     0,     0,     0,   137,     0,     0,   144,     0,     0,
       0,     0,   120,     0,   145,     2,     3,   125,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,    13,    14,
      15,     0,     0,     0,     0,   140,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    16,
      17,     0,    18,    19,     0,    20,     0,    39,    40,     0,
       0,     0,     0,    21,    22,    41,     0,     0,    23,    24,
      25,     3,     0,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,    18,    19,     0,
      20,    93,     0,     0,     0,     0,     0,     0,    21,    22,
       0,     0,     0,    23,    24,    25,     3,     0,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    16,
      17,     0,    18,    19,     0,    20,     0,     0,     0,     0,
       0,     0,     0,    21,    22,     0,     0,     0,    23,    24,
      25,    16,    17,     0,     0,    19,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    21,    22,    65,     0,     0,
      23,    24,    25,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,    90,     0,     0,     0,     0,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,    92,     0,     0,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
     114,     0,     0,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,   119,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,   124,     0,     0,     0,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    63,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75
};

static const yytype_int16 yycheck[] =
{
      14,    47,    37,    43,    37,    19,    38,    21,    22,    23,
      24,   127,   128,   129,    38,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,   141,    38,    41,     3,   145,
      44,    45,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     3,    57,    58,    59,    60,    61,    62,    63,
      64,     4,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,   119,    15,    38,    37,    11,   124,   125,    37,
      37,   117,    20,    39,   140,    -1,    -1,    91,   118,    -1,
      -1,    -1,    -1,   123,   130,    -1,   132,    -1,    -1,    -1,
     136,    -1,    -1,    -1,   134,    -1,    -1,   143,    -1,    -1,
      -1,    -1,   116,    -1,   144,     0,     1,   121,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    34,
      35,    -1,    37,    38,    -1,    40,    -1,    34,    35,    -1,
      -1,    -1,    -1,    48,    49,    42,    -1,    -1,    53,    54,
      55,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    53,    54,    55,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    53,    54,
      55,    34,    35,    -1,    -1,    38,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    48,    49,    37,    -1,    -1,
      53,    54,    55,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    57,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    12,    13,    14,    15,    34,    35,    37,    38,
      40,    48,    49,    53,    54,    55,    58,    59,    37,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    34,
      35,    42,    37,    60,    38,    38,    59,    38,     3,     3,
      59,    57,    59,    59,    59,    59,     4,    26,    27,    28,
      29,    30,    31,    32,    33,    37,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    58,    59,    59,
      37,    60,    39,    41,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    15,    63,    39,    59,    38,    37,    61,    39,
      59,    60,    58,    61,    39,    59,    11,    58,    61,    61,
      62,    62,    62,    62,    60,    60,    37,    58,    37,    60,
      59,    63,    62,    39,    60,    58,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    61,    62,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     6,    10,     8,    11,
      18,     3,     2,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       0,     0,     0,     0
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
  case 5: /* stmt: expr ';'  */
#line 67 "mycc.y"
                        { emit(pop); /* do not leave a value on the stack */ }
#line 1300 "mycc.c"
    break;

  case 6: /* stmt: IF '(' expr ')' M stmt  */
#line 69 "mycc.y"
                        { backpatch((yyvsp[-1].loc), pc-(yyvsp[-1].loc)); }
#line 1306 "mycc.c"
    break;

  case 7: /* stmt: IF '(' expr ')' M stmt ELSE N L stmt  */
#line 71 "mycc.y"
                        { backpatch((yyvsp[-5].loc), (yyvsp[-1].loc)-(yyvsp[-5].loc)); backpatch((yyvsp[-2].loc), pc - (yyvsp[-2].loc)); }
#line 1312 "mycc.c"
    break;

  case 8: /* stmt: WHILE '(' L expr ')' M stmt N  */
#line 73 "mycc.y"
                        { backpatch((yyvsp[0].loc), (yyvsp[-5].loc) - (yyvsp[0].loc)); backpatch((yyvsp[-2].loc), pc - (yyvsp[-2].loc));}
#line 1318 "mycc.c"
    break;

  case 9: /* stmt: DO L stmt WHILE '(' expr ')' M N L ';'  */
#line 75 "mycc.y"
                        { backpatch((yyvsp[-3].loc), (yyvsp[-1].loc) - (yyvsp[-3].loc)); backpatch((yyvsp[-2].loc), (yyvsp[-9].loc) - (yyvsp[-2].loc)); }
#line 1324 "mycc.c"
    break;

  case 10: /* stmt: FOR '(' expr P ';' L expr M N ';' L expr P N ')' L stmt N  */
#line 77 "mycc.y"
                        {
                        backpatch((yyvsp[-10].loc), pc - (yyvsp[-10].loc)); //if the middle condition is false jump out of the entire loop
                        backpatch((yyvsp[0].loc), (yyvsp[-12].loc) - (yyvsp[0].loc)); //go back and check the conditions at the end of the statement
                        backpatch((yyvsp[-4].loc), (yyvsp[-2].loc) - (yyvsp[-4].loc)); //if we get all the way to n go to the statement
                        backpatch((yyvsp[-9].loc), (yyvsp[-7].loc) - (yyvsp[-9].loc)); 
                        }
#line 1335 "mycc.c"
    break;

  case 11: /* stmt: RETURN expr ';'  */
#line 84 "mycc.y"
                        { emit(istore_2); /* return val goes in local var 2 */ }
#line 1341 "mycc.c"
    break;

  case 12: /* stmt: BREAK ';'  */
#line 86 "mycc.y"
                        { /* TODO: BONUS!!! */ error("break not implemented"); }
#line 1347 "mycc.c"
    break;

  case 14: /* stmt: error ';'  */
#line 88 "mycc.y"
                        { yyerrok; }
#line 1353 "mycc.c"
    break;

  case 15: /* expr: ID '=' expr  */
#line 91 "mycc.y"
                        { emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1359 "mycc.c"
    break;

  case 16: /* expr: ID PA expr  */
#line 92 "mycc.y"
                        { emit2(iload, (yyvsp[-2].sym)->localvar); emit(iadd); emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1365 "mycc.c"
    break;

  case 17: /* expr: ID NA expr  */
#line 93 "mycc.y"
                        { emit2(iload, (yyvsp[-2].sym)->localvar); emit(swap); emit(isub); emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1371 "mycc.c"
    break;

  case 18: /* expr: ID TA expr  */
#line 94 "mycc.y"
                        { emit2(iload, (yyvsp[-2].sym)->localvar); emit(imul); emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1377 "mycc.c"
    break;

  case 19: /* expr: ID DA expr  */
#line 95 "mycc.y"
                        { emit2(iload, (yyvsp[-2].sym)->localvar); emit(swap); emit(idiv); emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1383 "mycc.c"
    break;

  case 20: /* expr: ID MA expr  */
#line 96 "mycc.y"
                        { emit2(iload, (yyvsp[-2].sym)->localvar); emit(swap); emit(irem); emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1389 "mycc.c"
    break;

  case 21: /* expr: ID AA expr  */
#line 97 "mycc.y"
                        { emit2(iload, (yyvsp[-2].sym)->localvar); emit(swap); emit(iand); emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1395 "mycc.c"
    break;

  case 22: /* expr: ID XA expr  */
#line 98 "mycc.y"
                        { emit2(iload, (yyvsp[-2].sym)->localvar); emit(swap); emit(ixor); emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1401 "mycc.c"
    break;

  case 23: /* expr: ID OA expr  */
#line 99 "mycc.y"
                        { emit2(iload, (yyvsp[-2].sym)->localvar); emit(ior); emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1407 "mycc.c"
    break;

  case 24: /* expr: ID LA expr  */
#line 100 "mycc.y"
                        { emit2(iload, (yyvsp[-2].sym)->localvar); emit(swap); emit(ishl); emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1413 "mycc.c"
    break;

  case 25: /* expr: ID RA expr  */
#line 101 "mycc.y"
                        { emit2(iload, (yyvsp[-2].sym)->localvar); emit(swap); emit(iushr); emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1419 "mycc.c"
    break;

  case 26: /* expr: expr OR expr  */
#line 102 "mycc.y"
                        { emit3(ifne, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1425 "mycc.c"
    break;

  case 27: /* expr: expr AN expr  */
#line 103 "mycc.y"
                        { emit3(ifne, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1431 "mycc.c"
    break;

  case 28: /* expr: expr '|' expr  */
#line 104 "mycc.y"
                        { emit(ior); }
#line 1437 "mycc.c"
    break;

  case 29: /* expr: expr '^' expr  */
#line 105 "mycc.y"
                        { emit(ixor); }
#line 1443 "mycc.c"
    break;

  case 30: /* expr: expr '&' expr  */
#line 106 "mycc.y"
                        { emit(iand); }
#line 1449 "mycc.c"
    break;

  case 31: /* expr: expr EQ expr  */
#line 107 "mycc.y"
                        { emit3(ifeq, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1455 "mycc.c"
    break;

  case 32: /* expr: expr NE expr  */
#line 108 "mycc.y"
                        { emit3(if_icmpne, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1461 "mycc.c"
    break;

  case 33: /* expr: expr '<' expr  */
#line 109 "mycc.y"
                        { emit3(if_icmplt, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1467 "mycc.c"
    break;

  case 34: /* expr: expr '>' expr  */
#line 110 "mycc.y"
                        { emit3(if_icmpgt, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1473 "mycc.c"
    break;

  case 35: /* expr: expr LE expr  */
#line 111 "mycc.y"
                        { emit3(if_icmple, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1479 "mycc.c"
    break;

  case 36: /* expr: expr GE expr  */
#line 112 "mycc.y"
                        { emit3(if_icmpge, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1485 "mycc.c"
    break;

  case 37: /* expr: expr LS expr  */
#line 113 "mycc.y"
                        { emit(ishl); }
#line 1491 "mycc.c"
    break;

  case 38: /* expr: expr RS expr  */
#line 114 "mycc.y"
                        { emit(iushr); }
#line 1497 "mycc.c"
    break;

  case 39: /* expr: expr '+' expr  */
#line 115 "mycc.y"
                        { emit(iadd); }
#line 1503 "mycc.c"
    break;

  case 40: /* expr: expr '-' expr  */
#line 116 "mycc.y"
                        { emit(isub); }
#line 1509 "mycc.c"
    break;

  case 41: /* expr: expr '*' expr  */
#line 117 "mycc.y"
                        { emit(imul); }
#line 1515 "mycc.c"
    break;

  case 42: /* expr: expr '/' expr  */
#line 118 "mycc.y"
                        { emit(idiv); }
#line 1521 "mycc.c"
    break;

  case 43: /* expr: expr '%' expr  */
#line 119 "mycc.y"
                        { emit(irem); }
#line 1527 "mycc.c"
    break;

  case 44: /* expr: '!' expr  */
#line 120 "mycc.y"
                        { emit3(ifeq, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1533 "mycc.c"
    break;

  case 45: /* expr: '~' expr  */
#line 121 "mycc.y"
                        { emit(iconst_m1); emit(ixor); }
#line 1539 "mycc.c"
    break;

  case 46: /* expr: '+' expr  */
#line 123 "mycc.y"
                        { emit3(ifge, 6); emit(ineg); emit3(goto_, 2); emit(ireturn); }
#line 1545 "mycc.c"
    break;

  case 47: /* expr: '-' expr  */
#line 125 "mycc.y"
                        { emit3(ifge, 6); emit(ireturn); emit3(goto_, 2); emit(ineg); }
#line 1551 "mycc.c"
    break;

  case 49: /* expr: '$' INT8  */
#line 127 "mycc.y"
                        { emit(aload_1); emit2(bipush, (yyvsp[0].num)); emit(iaload); }
#line 1557 "mycc.c"
    break;

  case 50: /* expr: PP ID  */
#line 128 "mycc.y"
                        { emit2(iload, (yyvsp[0].sym)->localvar); emit(iconst_1); emit(iadd); emit(dup); emit2(istore, (yyvsp[0].sym)->localvar); }
#line 1563 "mycc.c"
    break;

  case 51: /* expr: NN ID  */
#line 129 "mycc.y"
                        { emit2(iload, (yyvsp[0].sym)->localvar); emit(iconst_1); emit(isub); emit(dup); emit2(istore, (yyvsp[0].sym)->localvar); }
#line 1569 "mycc.c"
    break;

  case 52: /* expr: ID PP  */
#line 130 "mycc.y"
                        { emit2(iload, (yyvsp[-1].sym)->localvar); emit(dup); emit(iconst_1); emit(iadd); emit2(istore, (yyvsp[-1].sym)->localvar); }
#line 1575 "mycc.c"
    break;

  case 53: /* expr: ID NN  */
#line 131 "mycc.y"
                        { emit2(iload, (yyvsp[-1].sym)->localvar); emit(dup); emit(iconst_1); emit(isub); emit2(istore, (yyvsp[-1].sym)->localvar); }
#line 1581 "mycc.c"
    break;

  case 54: /* expr: ID  */
#line 132 "mycc.y"
                        { emit2(iload, (yyvsp[0].sym)->localvar); }
#line 1587 "mycc.c"
    break;

  case 55: /* expr: INT8  */
#line 133 "mycc.y"
                        { emit2(bipush, (yyvsp[0].num)); }
#line 1593 "mycc.c"
    break;

  case 56: /* expr: INT16  */
#line 134 "mycc.y"
                        { emit3(sipush, (yyvsp[0].num)); }
#line 1599 "mycc.c"
    break;

  case 57: /* expr: INT32  */
#line 135 "mycc.y"
                        { emit2(ldc, constant_pool_add_Integer(&cf, (yyvsp[0].num))); }
#line 1605 "mycc.c"
    break;

  case 58: /* expr: FLT  */
#line 136 "mycc.y"
                        { error("float constant not supported in Pr3"); }
#line 1611 "mycc.c"
    break;

  case 59: /* expr: STR  */
#line 137 "mycc.y"
                        { error("string constant not supported in Pr3"); }
#line 1617 "mycc.c"
    break;

  case 60: /* L: %empty  */
#line 140 "mycc.y"
                        { (yyval.loc) = pc; }
#line 1623 "mycc.c"
    break;

  case 61: /* M: %empty  */
#line 143 "mycc.y"
                        { (yyval.loc) = pc;	/* location of inst. to backpatch */
			  emit3(ifeq, 0);
			}
#line 1631 "mycc.c"
    break;

  case 62: /* N: %empty  */
#line 148 "mycc.y"
                        { (yyval.loc) = pc;	/* location of inst. to backpatch */
			  emit3(goto_, 0);
			}
#line 1639 "mycc.c"
    break;

  case 63: /* P: %empty  */
#line 153 "mycc.y"
                        {emit(pop);}
#line 1645 "mycc.c"
    break;


#line 1649 "mycc.c"

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

#line 157 "mycc.y"


int main(int argc, char **argv)
{
	int index1, index2, index3;
	int label1, label2;

	// set up new class file structure
	init_ClassFile(&cf);

	// class has public access
	cf.access = ACC_PUBLIC;

	// class name is "Code"
	cf.name = "Code";

	// no fields
	cf.field_count = 0;

	// one method
	cf.method_count = 1;

	// allocate array of methods (just one "main" in our example)
	cf.methods = (struct MethodInfo*)malloc(cf.method_count * sizeof(struct MethodInfo));

	if (!cf.methods)
		error("Out of memory");

	// method has public access and is static
	cf.methods[0].access = (enum access_flags)(ACC_PUBLIC | ACC_STATIC);

	// method name is "main"
	cf.methods[0].name = "main";

	// method descriptor of "void main(String[] arg)"
	cf.methods[0].descriptor = "([Ljava/lang/String;)V";

	// max operand stack size of this method
	cf.methods[0].max_stack = 100;

	// the number of local variables in the local variable array
	//   local variable 0 contains "arg"
	//   local variable 1 contains "val"
	//   local variable 2 contains "i" and "result"
	cf.methods[0].max_locals = 100;

	// set up new bytecode buffer
	init_code();
	
	// generate prologue code

/*LOC*/ /*CODE*/			/*SOURCE*/
/*000*/	emit(aload_0);
/*001*/	emit(arraylength);		// arg.length
/*002*/	emit2(newarray, T_INT);
/*004*/	emit(astore_1);			// val = new int[arg.length]
/*005*/	emit(iconst_0);
/*006*/	emit(istore_2);			// i = 0
	label1 = pc;			// label1:
/*007*/	emit(iload_2);
/*008*/	emit(aload_0);
/*009*/	emit(arraylength);
	label2 = pc;
/*010*/	emit3(if_icmpge, PAD);		// if i >= arg.length then goto label2
/*013*/	emit(aload_1);
/*014*/	emit(iload_2);
/*015*/	emit(aload_0);
/*016*/	emit(iload_2);
/*017*/	emit(aaload);			// push arg[i] parameter for parseInt
	index1 = constant_pool_add_Methodref(&cf, "java/lang/Integer", "parseInt", "(Ljava/lang/String;)I");
/*018*/	emit3(invokestatic, index1);	// invoke Integer.parseInt(arg[i])
/*021*/	emit(iastore);			// val[i] = Integer.parseInt(arg[i])
/*022*/	emit32(iinc, 2, 1);		// i++
/*025*/	emit3(goto_, label1 - pc);	// goto label1
	backpatch(label2, pc - label2);	// label2:

	// end of prologue code

	init();

	if (argc > 1)
		if (!(yyin = fopen(argv[1], "r")))
			error("Cannot open file for reading");

	if (yyparse() || errnum > 0)
		error("Compilation errors: class file not saved");

	fprintf(stderr, "Compilation successful: saving %s.class\n", cf.name);

	// generate epilogue code

	index2 = constant_pool_add_Fieldref(&cf, "java/lang/System", "out", "Ljava/io/PrintStream;");
/*036*/	emit3(getstatic, index2);	// get static field System.out of type PrintStream
/*039*/	emit(iload_2);			// push parameter for println()
	index3 = constant_pool_add_Methodref(&cf, "java/io/PrintStream", "println", "(I)V");
/*040*/	emit3(invokevirtual, index3);	// invoke System.out.println(result)
/*043*/	emit(return_);			// return

	// end of epilogue code

	// length of bytecode is in the emitter's pc variable
	cf.methods[0].code_length = pc;
	
	// must copy code to make it persistent
	cf.methods[0].code = copy_code();

	if (!cf.methods[0].code)
		error("Out of memory");

	// save class file to "Calc.class"
	save_classFile(&cf);

	return 0;
}

