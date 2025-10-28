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
#line 3 "mycc.y"


#include "lex.yy.h"
#include "global.h"

#define MAXFUN 100
#define MAXFLD 100

static struct ClassFile cf;

/* stacks of symbol tables and offsets, depth is just 2 in C (global/local) */
static Table *tblptr[2];
static int offset[2];

/* stack pointers (index into tblptr[] and offset[]) */
static int tblsp = -1;
static int offsp = -1;

/* stack operations */
#define top_tblptr	(tblptr[tblsp])
#define top_offset	(offset[offsp])
#define snd_tblptr  (tblptr[tblsp - 1])
#define snd_offset  (offset[offsp - 1])
#define push_tblptr(t)	(tblptr[++tblsp] = t)
#define push_offset(n)	(offset[++offsp] = n)
#define pop_tblptr	(tblsp--)
#define pop_offset	(offsp--)

/* flag to indicate we are compiling main's body (to differentiate 'return') */
static int is_in_main = 0;

static Type ret_type;
static Type coerce1(Expr *expr, Type type);
static Type coerce2(Expr *expr, Type type);
static Expr circuit(Expr *expr);
static Type decircuit(Expr *expr);
static Type widen(Expr *expr1, Expr *expr2);
static Expr emitop(Expr *expr1, Expr *expr2, int iop, int fop);
static Expr emitas(Symbol *sym, Expr *expr, int iop, int fop);


#line 113 "mycc.c"

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
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_FLOAT = 13,                     /* FLOAT  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_INT = 16,                       /* INT  */
  YYSYMBOL_MAIN = 17,                      /* MAIN  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_VOID = 19,                      /* VOID  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_PA = 22,                        /* PA  */
  YYSYMBOL_NA = 23,                        /* NA  */
  YYSYMBOL_TA = 24,                        /* TA  */
  YYSYMBOL_DA = 25,                        /* DA  */
  YYSYMBOL_MA = 26,                        /* MA  */
  YYSYMBOL_AA = 27,                        /* AA  */
  YYSYMBOL_XA = 28,                        /* XA  */
  YYSYMBOL_OA = 29,                        /* OA  */
  YYSYMBOL_LA = 30,                        /* LA  */
  YYSYMBOL_RA = 31,                        /* RA  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_AN = 33,                        /* AN  */
  YYSYMBOL_34_ = 34,                       /* '|'  */
  YYSYMBOL_35_ = 35,                       /* '^'  */
  YYSYMBOL_36_ = 36,                       /* '&'  */
  YYSYMBOL_EQ = 37,                        /* EQ  */
  YYSYMBOL_NE = 38,                        /* NE  */
  YYSYMBOL_LE = 39,                        /* LE  */
  YYSYMBOL_40_ = 40,                       /* '<'  */
  YYSYMBOL_GE = 41,                        /* GE  */
  YYSYMBOL_42_ = 42,                       /* '>'  */
  YYSYMBOL_LS = 43,                        /* LS  */
  YYSYMBOL_RS = 44,                        /* RS  */
  YYSYMBOL_45_ = 45,                       /* '+'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_49_ = 49,                       /* '%'  */
  YYSYMBOL_50_ = 50,                       /* '!'  */
  YYSYMBOL_51_ = 51,                       /* '~'  */
  YYSYMBOL_PP = 52,                        /* PP  */
  YYSYMBOL_NN = 53,                        /* NN  */
  YYSYMBOL_54_ = 54,                       /* '.'  */
  YYSYMBOL_AR = 55,                        /* AR  */
  YYSYMBOL_56_ = 56,                       /* '('  */
  YYSYMBOL_57_ = 57,                       /* ')'  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_60_ = 60,                       /* ';'  */
  YYSYMBOL_61_ = 61,                       /* ','  */
  YYSYMBOL_62_ = 62,                       /* '$'  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_prog = 64,                      /* prog  */
  YYSYMBOL_Mprog = 65,                     /* Mprog  */
  YYSYMBOL_exts = 66,                      /* exts  */
  YYSYMBOL_func = 67,                      /* func  */
  YYSYMBOL_head = 68,                      /* head  */
  YYSYMBOL_Mmain = 69,                     /* Mmain  */
  YYSYMBOL_Margs = 70,                     /* Margs  */
  YYSYMBOL_block = 71,                     /* block  */
  YYSYMBOL_decls = 72,                     /* decls  */
  YYSYMBOL_decl = 73,                      /* decl  */
  YYSYMBOL_type = 74,                      /* type  */
  YYSYMBOL_args = 75,                      /* args  */
  YYSYMBOL_list = 76,                      /* list  */
  YYSYMBOL_stmts = 77,                     /* stmts  */
  YYSYMBOL_stmt = 78,                      /* stmt  */
  YYSYMBOL_exprs = 79,                     /* exprs  */
  YYSYMBOL_expr = 80,                      /* expr  */
  YYSYMBOL_K = 81,                         /* K  */
  YYSYMBOL_L = 82,                         /* L  */
  YYSYMBOL_M = 83,                         /* M  */
  YYSYMBOL_N = 84,                         /* N  */
  YYSYMBOL_Pexpr = 85                      /* Pexpr  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   522

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
       2,     2,     2,    50,     2,     2,    62,    49,    36,     2,
      56,    57,    47,    45,    61,    46,    54,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    60,
      40,    21,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    34,    59,    51,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    37,    38,
      39,    41,    43,    44,    52,    53,    55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   106,   111,   112,   113,   116,   175,   211,
     235,   276,   288,   291,   292,   295,   298,   299,   300,   303,
     307,   313,   326,   341,   342,   345,   346,   348,   361,   374,
     389,   402,   416,   435,   438,   439,   442,   444,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   459,
     489,   520,   521,   522,   524,   538,   557,   572,   588,   602,
     616,   617,   618,   619,   620,   621,   622,   625,   633,   637,
     640,   652,   654,   666,   686,   706,   726,   746,   764,   769,
     774,   780,   789,   801,   804,   807,   812,   817
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
  "INT32", "FLT", "STR", "BREAK", "CHAR", "DO", "ELSE", "FLOAT", "FOR",
  "IF", "INT", "MAIN", "RETURN", "VOID", "WHILE", "'='", "PA", "NA", "TA",
  "DA", "MA", "AA", "XA", "OA", "LA", "RA", "OR", "AN", "'|'", "'^'",
  "'&'", "EQ", "NE", "LE", "'<'", "GE", "'>'", "LS", "RS", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "'~'", "PP", "NN", "'.'", "AR", "'('", "')'",
  "'{'", "'}'", "';'", "','", "'$'", "$accept", "prog", "Mprog", "exts",
  "func", "head", "Mmain", "Margs", "block", "decls", "decl", "type",
  "args", "list", "stmts", "stmt", "exprs", "expr", "K", "L", "M", "N",
  "Pexpr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-157)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -157,    10,  -157,  -157,    -2,  -157,  -157,   -26,  -157,  -157,
      27,  -157,    41,    23,    31,  -157,  -157,    30,  -157,    86,
    -157,    29,  -157,  -157,    27,  -157,    89,   138,    29,  -157,
    -157,    35,    44,  -157,  -157,  -157,  -157,    39,  -157,    45,
      46,   234,    47,   234,   234,   234,   234,   102,   103,   234,
    -157,  -157,  -157,   104,  -157,   210,   108,   -45,  -157,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
    -157,  -157,   234,  -157,   216,   234,   234,   265,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,   294,   156,  -157,  -157,  -157,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,  -157,  -157,  -157,    29,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   -14,   398,    87,   398,    52,   320,  -157,   234,  -157,
    -157,   234,   234,   446,   460,   473,    33,    33,    33,    33,
      33,    33,    85,    85,   -11,   -11,  -157,  -157,  -157,   112,
    -157,   234,    60,  -157,  -157,   346,   415,   431,  -157,   398,
     234,   234,  -157,  -157,   372,   398,   216,  -157,  -157,  -157,
     105,   216,  -157,    61,  -157,  -157,    62,  -157,  -157,  -157,
    -157,   234,   216,  -157,  -157,    67,  -157,   216,  -157,  -157
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     6,     1,     2,    18,    17,     0,    16,     4,
       0,     5,     0,     0,     0,    14,     8,    22,    15,     0,
      10,    24,    11,    21,     0,    13,     0,     0,     0,     7,
      22,     0,    77,    78,    79,    80,    81,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    12,    25,     0,    23,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,    33,     0,     0,     0,     0,    84,    69,
      70,    67,    68,    73,    74,     0,     0,    72,    84,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    20,     9,     0,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,    37,     0,    87,     0,     0,    32,     0,    71,
      34,     0,     0,    51,    52,    53,    54,    55,    58,    56,
      59,    57,    60,    61,    62,    63,    64,    65,    66,     0,
      82,     0,     0,    84,    85,     0,    49,    50,    19,    36,
       0,     0,    84,    85,     0,    85,     0,    84,    83,    86,
      27,     0,    84,     0,    86,    86,     0,    84,    84,    29,
      30,     0,     0,    86,    28,     0,    84,     0,    86,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   101,  -157,
     106,   -15,  -157,  -157,    76,   -73,  -157,   -41,  -157,   -49,
    -156,  -142,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     9,    10,    24,    28,    16,    21,
      11,    12,    57,    13,    27,    54,   121,    55,   172,    74,
     162,   173,   125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      77,   123,    79,    80,    81,    82,    26,   167,    85,   169,
       3,     5,   108,    56,     6,     7,   109,     8,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   128,
      14,   122,   178,   179,   124,   126,   103,   104,   105,   131,
     132,   185,     5,   150,    17,     6,   189,   151,     8,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    99,   100,   101,   102,
     103,   104,   105,    18,    19,    15,    22,   155,    20,    23,
     156,   157,    30,   170,   149,    58,    70,    71,   175,    73,
      72,    75,    76,    78,   161,    83,    84,   152,    87,   184,
     159,   107,   153,   166,   188,   158,   160,   174,   171,   164,
     165,   177,   180,   176,   186,    29,    86,    25,   181,   182,
     101,   102,   103,   104,   105,   183,     0,   187,     0,    31,
     124,    32,    33,    34,    35,    36,     0,    37,     0,    38,
       0,     0,    39,    40,     0,     0,    41,    31,    42,    32,
      33,    34,    35,    36,     0,    37,     0,    38,     0,     0,
      39,    40,     0,     0,    41,     0,    42,     0,     0,     0,
       0,     0,     0,    43,    44,     0,     0,     0,    45,    46,
      47,    48,     0,     0,    49,     0,    50,    51,    52,     0,
      53,    43,    44,     0,     0,     0,    45,    46,    47,    48,
       0,     0,    49,     0,    50,   130,    52,    31,    53,    32,
      33,    34,    35,    36,     0,    37,     0,    38,     0,     0,
      39,    40,     0,     0,    41,     0,    42,    32,    33,    34,
      35,    36,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,    43,    44,     0,     0,     0,    45,    46,    47,    48,
     106,     0,    49,     0,    50,     0,    52,     0,    53,    43,
      44,     0,     0,     0,    45,    46,    47,    48,     0,     0,
      49,     0,     0,     0,     0,     0,    53,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,   129,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,   154,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   163,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   168,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105
};

static const yytype_int16 yycheck[] =
{
      41,    74,    43,    44,    45,    46,    21,   163,    49,   165,
       0,    13,    57,    28,    16,    17,    61,    19,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    78,
      56,    72,   174,   175,    75,    76,    47,    48,    49,    88,
      89,   183,    13,    57,     3,    16,   188,    61,    19,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    43,    44,    45,    46,
      47,    48,    49,    60,    61,    58,    56,   128,    57,     3,
     131,   132,     3,   166,   109,    60,    52,    53,   171,    60,
      56,    56,    56,    56,   153,     3,     3,    20,     4,   182,
     151,     3,    60,   162,   187,     3,    56,    12,   167,   160,
     161,    60,    60,   172,    57,    24,    50,    21,   177,   178,
      45,    46,    47,    48,    49,   181,    -1,   186,    -1,     1,
     181,     3,     4,     5,     6,     7,    -1,     9,    -1,    11,
      -1,    -1,    14,    15,    -1,    -1,    18,     1,    20,     3,
       4,     5,     6,     7,    -1,     9,    -1,    11,    -1,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    58,    59,    60,    -1,
      62,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      -1,    -1,    56,    -1,    58,    59,    60,     1,    62,     3,
       4,     5,     6,     7,    -1,     9,    -1,    11,    -1,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,     3,     4,     5,
       6,     7,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      60,    -1,    56,    -1,    58,    -1,    60,    -1,    62,    45,
      46,    -1,    -1,    -1,    50,    51,    52,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    62,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,     0,    66,    13,    16,    17,    19,    67,
      68,    73,    74,    76,    56,    58,    71,     3,    60,    61,
      57,    72,    56,     3,    69,    73,    74,    77,    70,    71,
       3,     1,     3,     4,     5,     6,     7,     9,    11,    14,
      15,    18,    20,    45,    46,    50,    51,    52,    53,    56,
      58,    59,    60,    62,    78,    80,    74,    75,    60,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      52,    53,    56,    60,    82,    56,    56,    80,    56,    80,
      80,    80,    80,     3,     3,    80,    77,     4,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    60,     3,    57,    61,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    79,    80,    78,    80,    85,    80,    60,    82,    57,
      59,    82,    82,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    74,
      57,    61,    20,    60,    57,    80,    80,    80,     3,    80,
      56,    82,    83,    57,    80,    80,    82,    83,    57,    83,
      78,    82,    81,    84,    12,    78,    82,    60,    84,    84,
      60,    82,    82,    85,    78,    84,    57,    82,    78,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    66,    66,    66,    67,    67,    68,
      69,    70,    71,    72,    72,    73,    74,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    82,    83,    84,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     0,     5,     2,     6,
       0,     0,     4,     2,     0,     2,     1,     1,     1,     4,
       2,     3,     2,     2,     0,     1,     2,     7,    11,     9,
      10,    16,     3,     2,     3,     2,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     4,     0,     0,     0,     0,     1
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
  case 2: /* prog: Mprog exts  */
#line 100 "mycc.y"
                        { addwidth(top_tblptr, top_offset);
			  pop_tblptr;
			  pop_offset;
			}
#line 1372 "mycc.c"
    break;

  case 3: /* Mprog: %empty  */
#line 106 "mycc.y"
                        { push_tblptr(mktable(NULL));
			  push_offset(0);
			}
#line 1380 "mycc.c"
    break;

  case 7: /* func: MAIN '(' ')' Mmain block  */
#line 118 "mycc.y"
            { 
	    // need a temporary table pointer
	    Table *table;

	    // the type of main is a JVM type descriptor
	    Type type = mkfun("[Ljava/lang/String;", "V");

	    // emit the epilogue part of main()
	    emit3(getstatic, constant_pool_add_Fieldref(&cf, "java/lang/System", "out", "Ljava/io/PrintStream;"));
	    emit(iload_2);
	    emit3(invokevirtual, constant_pool_add_Methodref(&cf, "java/io/PrintStream", "println", "(I)V"));
	    emit(return_);

	    // method has public access and is static
	    cf.methods[cf.method_count].access = (enum access_flags)(ACC_PUBLIC | ACC_STATIC);

	    // method name is "main"
	    cf.methods[cf.method_count].name = "main";

	    // method descriptor of "void main(String[] arg)"
	    cf.methods[cf.method_count].descriptor = type;

	    // local variables
	    cf.methods[cf.method_count].max_locals = top_offset;

	    // max operand stack size of this method
	    cf.methods[cf.method_count].max_stack = 100;

	    // length of bytecode is in the emitter's pc variable
	    cf.methods[cf.method_count].code_length = pc;

	    // must copy code to make it persistent
	    cf.methods[cf.method_count].code = copy_code();

	    if (!cf.methods[cf.method_count].code) {
		error("Out of memory");
	    }
	    // advance to next method to store in method array
	    cf.method_count++;
	    if (cf.method_count > MAXFUN) {
		error("Max number of functions exceeded");
	    }

	    // add width information to table
	    addwidth(top_tblptr, top_offset);

	    // need this table of locals for enterproc
	    table = top_tblptr;

	    // exit the local scope by popping
	    pop_tblptr;
	    pop_offset;

	    // enter the function in the global table
	    enterproc(top_tblptr, (yyvsp[-4].sym), type, table);
	    }
#line 1441 "mycc.c"
    break;

  case 8: /* func: head block  */
#line 176 "mycc.y"
            {
	    emit(return_);
	    // length of bytecode is in the emitter's pc variable
	    cf.methods[cf.method_count].code_length = pc;

	    // must copy code to make it persistent
	    cf.methods[cf.method_count].code = copy_code();

	    if (!cf.methods[cf.method_count].code)
	    error("Out of memory");
	    // max operand stack size of this method
	    cf.methods[cf.method_count].max_stack = 100;

	    // local variables
	    cf.methods[cf.method_count].max_locals = top_offset;

	    // advance to next method to store in method array
	    cf.method_count++;
	    if (cf.method_count > MAXFUN) {
		error("Max number of functions exceeded");
	    }
	    // complete the enterproc table pointer
	    (yyvsp[-1].ent)->table = top_tblptr;

	    // add width information to table
	    addwidth(top_tblptr, top_offset);

	    // exit the local scope by popping
	    pop_tblptr;
	    pop_offset;
	    }
#line 1477 "mycc.c"
    break;

  case 9: /* head: type ID '(' Margs args ')'  */
#line 213 "mycc.y"
            { 
	    // the type of the function is a JVM type descriptor
	    Type type = mkfun((yyvsp[-1].typ), (yyvsp[-5].typ));

	    // method has public access and is static
	    cf.methods[cf.method_count].access = ACC_PUBLIC | ACC_STATIC;

	    // method name (from symbol table)
	    cf.methods[cf.method_count].name = (yyvsp[-4].sym)->lexptr;

	    // method descriptor
	    cf.methods[cf.method_count].descriptor = type;

	    // enter the incomplete function in the global table
	    (yyval.ent) = enterproc(snd_tblptr, (yyvsp[-4].sym), type, NULL);

	    ret_type = (yyvsp[-5].typ);
	    }
#line 1500 "mycc.c"
    break;

  case 10: /* Mmain: %empty  */
#line 235 "mycc.y"
                        { 
				int label1, label2;
			  Table *table;
			  // create new table for local scope of main()
			  table = mktable(top_tblptr);
			  // push it to create new scope
			  push_tblptr(table);
			  // for main(), we must start with offset 3 in the local variables of the frame
			  push_offset(3);
			  // init code block to store stmts
			  init_code();
			  // emit the prologue part of main()
			  emit(aload_0);
			  emit(arraylength);
			  emit2(newarray, T_INT);
			  emit(astore_1);
			  emit(iconst_0);
			  emit(istore_2);
			  label1 = pc;
			  emit(iload_2);
			  emit(aload_0);
			  emit(arraylength);
			  label2 = pc;
			  emit3(if_icmpge, PAD);
			  emit(aload_1);
			  emit(iload_2);
			  emit(aload_0);
			  emit(iload_2);
			  emit(aaload);
			  emit3(invokestatic, constant_pool_add_Methodref(&cf, "java/lang/Integer", "parseInt", "(Ljava/lang/String;)I"));
			  emit(iastore);
			  emit32(iinc, 2, 1);
			  emit3(goto_, label1 - pc);
			  backpatch(label2, pc - label2);
			  // global flag to indicate we're in main()
			  is_in_main = 1;
			  ret_type = mkint();
				//fprintf(stderr, "finished Mmain\n");
			}
#line 1544 "mycc.c"
    break;

  case 11: /* Margs: %empty  */
#line 276 "mycc.y"
                        { /* flag */
			// SRW fleshed out the above
			Table *table = mktable(top_tblptr);

			push_tblptr(table);
			push_offset(0);

			init_code();
			is_in_main = 0;
			}
#line 1559 "mycc.c"
    break;

  case 16: /* type: VOID  */
#line 298 "mycc.y"
                        { (yyval.typ) = mkvoid(); }
#line 1565 "mycc.c"
    break;

  case 17: /* type: INT  */
#line 299 "mycc.y"
                        { (yyval.typ) = mkint(); }
#line 1571 "mycc.c"
    break;

  case 18: /* type: FLOAT  */
#line 300 "mycc.y"
                        { (yyval.typ) = mkfloat(); }
#line 1577 "mycc.c"
    break;

  case 19: /* args: args ',' type ID  */
#line 304 "mycc.y"
                        { enter(top_tblptr, (yyvsp[0].sym), (yyvsp[-1].typ), top_offset++);
			  (yyval.typ) = mkpair((yyvsp[-3].typ), (yyvsp[-1].typ));
			}
#line 1585 "mycc.c"
    break;

  case 20: /* args: type ID  */
#line 307 "mycc.y"
                        {
				enter(top_tblptr, (yyvsp[0].sym), (yyvsp[-1].typ), top_offset++);
			    (yyval.typ) = (yyvsp[-1].typ);
			}
#line 1594 "mycc.c"
    break;

  case 21: /* list: list ',' ID  */
#line 314 "mycc.y"
                        { 
				if (top_tblptr->level == 0) {
					cf.fields[cf.field_count].access = ACC_STATIC;
					cf.fields[cf.field_count].name = (yyvsp[0].sym)->lexptr;
					cf.fields[cf.field_count].descriptor = (yyvsp[-2].typ);
					cf.field_count++;
					enter(top_tblptr, (yyvsp[0].sym), (yyvsp[-2].typ), constant_pool_add_Fieldref(&cf, cf.name, (yyvsp[0].sym)->lexptr, (yyvsp[-2].typ)));
				} else {
					enter(top_tblptr, (yyvsp[0].sym), (yyvsp[-2].typ), top_offset++);
				}
				(yyval.typ) = (yyvsp[-2].typ);
			}
#line 1611 "mycc.c"
    break;

  case 22: /* list: type ID  */
#line 327 "mycc.y"
                        { 
				if (top_tblptr->level == 0) {
					cf.fields[cf.field_count].access = ACC_STATIC;
					cf.fields[cf.field_count].name = (yyvsp[0].sym)->lexptr;
					cf.fields[cf.field_count].descriptor = (yyvsp[-1].typ);
					cf.field_count++;
					enter(top_tblptr, (yyvsp[0].sym), (yyvsp[-1].typ), constant_pool_add_Fieldref(&cf, cf.name, (yyvsp[0].sym)->lexptr, (yyvsp[-1].typ)));
				} else {
					enter(top_tblptr, (yyvsp[0].sym), (yyvsp[-1].typ), top_offset++);
				}
				(yyval.typ) = (yyvsp[-1].typ);
			}
#line 1628 "mycc.c"
    break;

  case 26: /* stmt: expr ';'  */
#line 346 "mycc.y"
                        { emit(pop); /* do not leave a value on the stack */ }
#line 1634 "mycc.c"
    break;

  case 27: /* stmt: IF '(' expr ')' M L stmt  */
#line 349 "mycc.y"
                                { 
						fprintf(stderr, "starting if\n");
						if (!(yyvsp[-4].exp).type) {
							backpatchlist((yyvsp[-4].exp).truelist, (yyvsp[-1].loc));
							backpatchlist((yyvsp[-4].exp).falselist, pc);
						} else if (!isint((yyvsp[-4].exp).type)) {
							error("Type error");
						}
						backpatch((yyvsp[-2].loc), pc - (yyvsp[-2].loc));
						}
#line 1649 "mycc.c"
    break;

  case 28: /* stmt: IF '(' expr ')' M L stmt ELSE N L stmt  */
#line 362 "mycc.y"
                        { 
							if (!(yyvsp[-8].exp).type) {
								backpatchlist((yyvsp[-8].exp).truelist, (yyvsp[-5].loc));
								backpatchlist((yyvsp[-8].exp).falselist, (yyvsp[-1].loc));
							} else if (!isint((yyvsp[-8].exp).type)) {
								error("Type error");
							}
							backpatch((yyvsp[-6].loc), (yyvsp[-1].loc)-(yyvsp[-6].loc)); 
							backpatch((yyvsp[-2].loc), pc - (yyvsp[-2].loc));
						}
#line 1664 "mycc.c"
    break;

  case 29: /* stmt: WHILE '(' L expr ')' M L stmt N  */
#line 375 "mycc.y"
            {
	    // SRW: fixed the grammar and symmantic action
	    if (!(yyvsp[-5].exp).type) {
		backpatchlist((yyvsp[-5].exp).truelist, (yyvsp[-2].loc));
		backpatchlist((yyvsp[-5].exp).falselist, pc);
	    } else if (!isint((yyvsp[-5].exp).type)) {
		error("Type error");
	    }

	    backpatch((yyvsp[0].loc), (yyvsp[-6].loc) -(yyvsp[0].loc)); 
	    backpatch((yyvsp[-3].loc), pc - (yyvsp[-3].loc));
	    }
#line 1681 "mycc.c"
    break;

  case 30: /* stmt: DO L stmt WHILE '(' expr ')' K L ';'  */
#line 390 "mycc.y"
                        { 
							if (!(yyvsp[-4].exp).type) {
								backpatchlist((yyvsp[-4].exp).truelist, (yyvsp[-8].loc));
								backpatchlist((yyvsp[-4].exp).falselist, pc);
							} else if (!isint((yyvsp[-4].exp).type)) {
								error("Type error");
							}
							backpatch((yyvsp[-2].loc), (yyvsp[-8].loc) - (yyvsp[-2].loc)); 
						}
#line 1695 "mycc.c"
    break;

  case 31: /* stmt: FOR '(' Pexpr ';' L expr M N ';' L Pexpr N ')' L stmt N  */
#line 403 "mycc.y"
            { 
			    if (!(yyvsp[-10].exp).type) {	
					backpatchlist((yyvsp[-10].exp).truelist, (yyvsp[-2].loc));
					backpatchlist((yyvsp[-10].exp).falselist, pc);
			    } else if (!isint((yyvsp[-10].exp).type)) {
			  		error("Type error");
				}
				backpatch((yyvsp[-9].loc), pc - (yyvsp[-9].loc));
				backpatch((yyvsp[-8].loc), (yyvsp[-2].loc) - (yyvsp[-8].loc));
				backpatch((yyvsp[-4].loc), (yyvsp[-11].loc) - (yyvsp[-4].loc));
				backpatch((yyvsp[0].loc), (yyvsp[-6].loc) - (yyvsp[0].loc));
			}
#line 1712 "mycc.c"
    break;

  case 32: /* stmt: RETURN expr ';'  */
#line 417 "mycc.y"
            { 
						  fprintf(stderr, "c1 type 1 = %s type 2 = %s \n", (yyvsp[-1].exp).type, ret_type);

			  coerce1(&(yyvsp[-1].exp), ret_type);
			  fprintf(stderr, "c1 type 1 = %s type 2 = %s \n", (yyvsp[-1].exp).type, ret_type);
			  if (is_in_main) {
				emit(istore_2);
			  } else {
			  	if (isint(ret_type)) {
					emit(ireturn);
			  	} else if (isfloat(ret_type)) {
					emit(freturn);
			  	} else {
					error("Type error");
			    }
			  }
			}
#line 1734 "mycc.c"
    break;

  case 33: /* stmt: BREAK ';'  */
#line 435 "mycc.y"
                        { /* BREAK is optional to implement (see Pr3) */
			  error("break not implemented");
			}
#line 1742 "mycc.c"
    break;

  case 35: /* stmt: error ';'  */
#line 439 "mycc.y"
                        { yyerrok; }
#line 1748 "mycc.c"
    break;

  case 36: /* exprs: exprs ',' expr  */
#line 443 "mycc.y"
                        { decircuit(&(yyvsp[0].exp)); }
#line 1754 "mycc.c"
    break;

  case 37: /* exprs: expr  */
#line 444 "mycc.y"
                        { decircuit(&(yyvsp[0].exp)); }
#line 1760 "mycc.c"
    break;

  case 38: /* expr: ID '=' expr  */
#line 447 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), nop, nop); }
#line 1766 "mycc.c"
    break;

  case 39: /* expr: ID PA expr  */
#line 448 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), iadd, fadd); }
#line 1772 "mycc.c"
    break;

  case 40: /* expr: ID NA expr  */
#line 449 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), isub, fsub); }
#line 1778 "mycc.c"
    break;

  case 41: /* expr: ID TA expr  */
#line 450 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), imul, fmul); }
#line 1784 "mycc.c"
    break;

  case 42: /* expr: ID DA expr  */
#line 451 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), idiv, fdiv); }
#line 1790 "mycc.c"
    break;

  case 43: /* expr: ID MA expr  */
#line 452 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), irem, nop); }
#line 1796 "mycc.c"
    break;

  case 44: /* expr: ID AA expr  */
#line 453 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), iand, nop); }
#line 1802 "mycc.c"
    break;

  case 45: /* expr: ID XA expr  */
#line 454 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), ixor, nop); }
#line 1808 "mycc.c"
    break;

  case 46: /* expr: ID OA expr  */
#line 455 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), ior, nop); }
#line 1814 "mycc.c"
    break;

  case 47: /* expr: ID LA expr  */
#line 456 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), ishl, nop); }
#line 1820 "mycc.c"
    break;

  case 48: /* expr: ID RA expr  */
#line 457 "mycc.y"
                        { (yyval.exp) = emitas((yyvsp[-2].sym), &(yyvsp[0].exp), ishr, nop); }
#line 1826 "mycc.c"
    break;

  case 49: /* expr: expr OR L expr  */
#line 460 "mycc.y"
                        { 
			  if ((yyvsp[-3].exp).type && (yyvsp[0].exp).type)
			  {	// both operands are non-short-circuit
			  	if (isint((yyvsp[-3].exp).type) && isint((yyvsp[0].exp).type)) {
			  		emit3(ifeq, 5);
			  		emit(pop);
					emit(iconst_1);
					(yyval.exp) = circuit(&(yyvsp[0].exp));
			  	} else {
					error("Type error");
				}
			  } else if ((yyvsp[0].exp).type) {
			  	Expr e = circuit(&(yyvsp[0].exp));
			  	(yyval.exp).truelist = mergelist((yyvsp[-3].exp).truelist, e.truelist);
				backpatchlist((yyvsp[-3].exp).falselist, (yyvsp[-1].loc));
				(yyval.exp).falselist = e.falselist;
			  } else if ((yyvsp[-3].exp).type) {
			  	Expr e = circuit(&(yyvsp[-3].exp));
			  	(yyval.exp).truelist = mergelist(e.truelist, (yyvsp[0].exp).truelist);
				backpatchlist(e.falselist, (yyvsp[-1].loc));
				(yyval.exp).falselist = (yyvsp[0].exp).falselist;
			  } else {
			  	(yyval.exp).truelist = mergelist((yyvsp[-3].exp).truelist, (yyvsp[0].exp).truelist);
				backpatchlist((yyvsp[-3].exp).falselist, (yyvsp[-1].loc));
				(yyval.exp).falselist = (yyvsp[0].exp).falselist;
			  }
			  (yyval.exp).type = NULL;
			}
#line 1859 "mycc.c"
    break;

  case 50: /* expr: expr AN L expr  */
#line 490 "mycc.y"
                        {
				if ((yyvsp[-3].exp).type && (yyvsp[0].exp).type)
				{	// both operands are non-short-circuit
					if (isint((yyvsp[-3].exp).type) && isint((yyvsp[0].exp).type)) {
						emit3(ifne, 5);
						emit(pop);
						emit(iconst_0);
						(yyval.exp) = circuit(&(yyvsp[0].exp));
					} else {
						error("Type error");
					}
				} else if ((yyvsp[0].exp).type) {
					Expr e = circuit(&(yyvsp[0].exp));
					(yyval.exp).falselist = mergelist((yyvsp[-3].exp).falselist, e.falselist);
					backpatchlist((yyvsp[-3].exp).truelist, (yyvsp[-1].loc));
					(yyval.exp).truelist = e.truelist;
				} else if ((yyvsp[-3].exp).type) {
					Expr e = circuit(&(yyvsp[-3].exp));
					(yyval.exp).falselist = mergelist(e.falselist, (yyvsp[0].exp).falselist);
					backpatchlist(e.truelist, (yyvsp[-1].loc));
					(yyval.exp).truelist = (yyvsp[0].exp).truelist;
				} else {
					(yyval.exp).falselist = mergelist((yyvsp[-3].exp).falselist, (yyvsp[0].exp).falselist);
					backpatchlist((yyvsp[-3].exp).truelist, (yyvsp[-1].loc));
					(yyval.exp).truelist = (yyvsp[0].exp).truelist;
				}
				(yyval.exp).type = NULL;					
			}
#line 1892 "mycc.c"
    break;

  case 51: /* expr: expr '|' expr  */
#line 520 "mycc.y"
                        { (yyval.exp)=emitop(&(yyvsp[-2].exp), &(yyvsp[0].exp), ior, nop); }
#line 1898 "mycc.c"
    break;

  case 52: /* expr: expr '^' expr  */
#line 521 "mycc.y"
                        { (yyval.exp)=emitop(&(yyvsp[-2].exp), &(yyvsp[0].exp), ixor, nop); }
#line 1904 "mycc.c"
    break;

  case 53: /* expr: expr '&' expr  */
#line 522 "mycc.y"
                        { (yyval.exp)=emitop(&(yyvsp[-2].exp), &(yyvsp[0].exp), iand, nop); }
#line 1910 "mycc.c"
    break;

  case 54: /* expr: expr EQ expr  */
#line 524 "mycc.y"
                        { (yyval.exp).type = widen(&(yyvsp[-2].exp), &(yyvsp[0].exp));
			  if (isint((yyval.exp).type)) {
			  	(yyval.exp).truelist = makelist(pc);
			  	emit3(if_icmpeq, 0);
			  } else if (isfloat((yyval.exp).type)) {
			  	emit(nop);
			  	(yyval.exp).truelist = makelist(pc);
			  	emit3(ifeq, 0);
			  }
			  (yyval.exp).falselist = makelist(pc);
			  emit3(goto_, 0);
			  (yyval.exp).type = NULL;
			}
#line 1928 "mycc.c"
    break;

  case 55: /* expr: expr NE expr  */
#line 538 "mycc.y"
                       { (yyval.exp).type = widen(&(yyvsp[-2].exp), &(yyvsp[0].exp));
			  if (isint((yyval.exp).type)) {
			  	(yyval.exp).truelist = makelist(pc);
			  	emit3(if_icmpne, 0);
			  } else if (isfloat((yyval.exp).type)) {
				//SRW fixed this
			  	// emit nop
				emit(fsub);
			  	emit(f2i);
			  	(yyval.exp).truelist = makelist(pc);
				//SRW this next one is wrong; think about it
			  	emit3(ifeq, 0);
			  }
			  (yyval.exp).falselist = makelist(pc);
			  emit3(goto_, 0);
			  (yyval.exp).type = NULL;
			}
#line 1950 "mycc.c"
    break;

  case 56: /* expr: expr '<' expr  */
#line 557 "mycc.y"
                                { (yyval.exp).type = widen(&(yyvsp[-2].exp), &(yyvsp[0].exp));
			  if (isint((yyval.exp).type)) {
			  	(yyval.exp).truelist = makelist(pc);
			  	emit3(if_icmplt, 0);
			  } else if (isfloat((yyval.exp).type)) {
			  	emit(fcmpl);
			  	(yyval.exp).truelist = makelist(pc);
				//SRW this next one is wrong; think about it
			  	emit3(ifeq, 0);
			  }
			  (yyval.exp).falselist = makelist(pc);
			  emit3(goto_, 0);
			  (yyval.exp).type = NULL;
			}
#line 1969 "mycc.c"
    break;

  case 57: /* expr: expr '>' expr  */
#line 572 "mycc.y"
                                { (yyval.exp).type = widen(&(yyvsp[-2].exp), &(yyvsp[0].exp));
			fprintf(stderr, "starting greater than\n");
			  if (isint((yyval.exp).type)) {
			  	(yyval.exp).truelist = makelist(pc);
			  	emit3(if_icmpgt, 0);
			  } else if (isfloat((yyval.exp).type)) {
			  	emit(fcmpg);
			  	(yyval.exp).truelist = makelist(pc);
				//SRW this next one is wrong; think about it
			  	emit3(ifne, 0);
			  }
			  (yyval.exp).falselist = makelist(pc);
			  emit3(goto_, 0);
			  (yyval.exp).type = NULL;
			}
#line 1989 "mycc.c"
    break;

  case 58: /* expr: expr LE expr  */
#line 588 "mycc.y"
                        { (yyval.exp).type = widen(&(yyvsp[-2].exp), &(yyvsp[0].exp));
			  if (isint((yyval.exp).type)) {
			  	(yyval.exp).truelist = makelist(pc);
			  	emit3(if_icmple, 0);
			  } else if (isfloat((yyval.exp).type)) {
			  	emit(fcmpg);
			  	(yyval.exp).truelist = makelist(pc);
			  	emit3(ifeq, 0);
			  }
			  (yyval.exp).falselist = makelist(pc);
			  emit3(goto_, 0);
			  (yyval.exp).type = NULL;
			}
#line 2007 "mycc.c"
    break;

  case 59: /* expr: expr GE expr  */
#line 602 "mycc.y"
                        { (yyval.exp).type = widen(&(yyvsp[-2].exp), &(yyvsp[0].exp));
			  if (isint((yyval.exp).type)) {
			  	(yyval.exp).truelist = makelist(pc);
			  	emit3(if_icmpge, 0);
			  } else if (isfloat((yyval.exp).type)) {
			  	emit(fcmpg);
			  	(yyval.exp).truelist = makelist(pc);
			  	emit3(ifeq, 0);
			  }
			  (yyval.exp).falselist = makelist(pc);
			  emit3(goto_, 0);
			  (yyval.exp).type = NULL;
			}
#line 2025 "mycc.c"
    break;

  case 60: /* expr: expr LS expr  */
#line 616 "mycc.y"
                        { (yyval.exp)=emitop(&(yyvsp[-2].exp), &(yyvsp[0].exp), ishl, nop); }
#line 2031 "mycc.c"
    break;

  case 61: /* expr: expr RS expr  */
#line 617 "mycc.y"
                        { (yyval.exp)=emitop(&(yyvsp[-2].exp), &(yyvsp[0].exp), ishr, nop); }
#line 2037 "mycc.c"
    break;

  case 62: /* expr: expr '+' expr  */
#line 618 "mycc.y"
                         { (yyval.exp)=emitop(&(yyvsp[-2].exp), &(yyvsp[0].exp), iadd, fadd); }
#line 2043 "mycc.c"
    break;

  case 63: /* expr: expr '-' expr  */
#line 619 "mycc.y"
                         { (yyval.exp)=emitop(&(yyvsp[-2].exp), &(yyvsp[0].exp), isub, fsub); }
#line 2049 "mycc.c"
    break;

  case 64: /* expr: expr '*' expr  */
#line 620 "mycc.y"
                         { (yyval.exp)=emitop(&(yyvsp[-2].exp), &(yyvsp[0].exp), imul, fmul); }
#line 2055 "mycc.c"
    break;

  case 65: /* expr: expr '/' expr  */
#line 621 "mycc.y"
                         { (yyval.exp)=emitop(&(yyvsp[-2].exp), &(yyvsp[0].exp), idiv, fdiv); }
#line 2061 "mycc.c"
    break;

  case 66: /* expr: expr '%' expr  */
#line 622 "mycc.y"
                         { (yyval.exp)=emitop(&(yyvsp[-2].exp), &(yyvsp[0].exp), irem, nop); }
#line 2067 "mycc.c"
    break;

  case 67: /* expr: '!' expr  */
#line 625 "mycc.y"
                        {
			// SRW ADDED THIS
			(yyval.exp) = circuit(&(yyvsp[0].exp));
			Backpatchlist *t;
			t = (yyval.exp).truelist;
			(yyval.exp).truelist = (yyval.exp).falselist;
			(yyval.exp).falselist = t;
			}
#line 2080 "mycc.c"
    break;

  case 68: /* expr: '~' expr  */
#line 633 "mycc.y"
                        { //SRW you still need to do this
			}
#line 2087 "mycc.c"
    break;

  case 69: /* expr: '+' expr  */
#line 638 "mycc.y"
                        { (yyval.exp) = (yyvsp[0].exp); }
#line 2093 "mycc.c"
    break;

  case 70: /* expr: '-' expr  */
#line 641 "mycc.y"
                        { (yyval.exp).truelist = (yyval.exp).falselist = NULL;
			  (yyval.exp).type = decircuit(&(yyvsp[0].exp));
			  if (isint((yyval.exp).type))
				emit(ineg);
			  else if (isfloat((yyval.exp).type))
				emit(fneg);
			  else
			  	error("Type error");
			}
#line 2107 "mycc.c"
    break;

  case 71: /* expr: '(' expr ')'  */
#line 652 "mycc.y"
                       {(yyval.exp) = (yyvsp[-1].exp);}
#line 2113 "mycc.c"
    break;

  case 72: /* expr: '$' INT8  */
#line 654 "mycc.y"
                        { 
			  if (is_in_main) {	
				emit(aload_1);
			  	emit2(bipush, (yyvsp[0].num));
			  	emit(iaload);
			  } else {
			  	error("invalid use of $# in function");
			  }
			  (yyval.exp).truelist = (yyval.exp).falselist = NULL;
			  (yyval.exp).type = mkint();
			}
#line 2129 "mycc.c"
    break;

  case 73: /* expr: PP ID  */
#line 666 "mycc.y"
                        { 
						int place = getplace(top_tblptr, (yyvsp[0].sym));
						if (place < 0) {
							error("undefined variable.");
						} else if (!isint(gettype(top_tblptr, (yyvsp[0].sym)))) {
							error("type error");
						} else if (getlevel(top_tblptr, (yyvsp[0].sym)) == 0) {
							emit3(getstatic, place);
							emit(iconst_1);
							emit(iadd);
							emit(dup);
							emit3(putstatic, place);
						} else {
							emit32(iinc, place, 1);
							emit2(iload, place);
						}
						(yyval.exp).truelist = (yyval.exp).falselist = NULL;
						(yyval.exp).type = mkint();
		 				}
#line 2153 "mycc.c"
    break;

  case 74: /* expr: NN ID  */
#line 686 "mycc.y"
                        { 
						int place = getplace(top_tblptr, (yyvsp[0].sym));
						if (place < 0) {
							error("undefined variable.");
						} else if (!isint(gettype(top_tblptr, (yyvsp[0].sym)))) {
							error("type error");
						} else if (getlevel(top_tblptr, (yyvsp[0].sym)) == 0) {
							emit3(getstatic, place);
							emit(iconst_1);
							emit(isub);
							emit(dup);
							emit3(putstatic, place);
						} else {
							emit32(iinc, place, -1);
							emit2(iload, place);
						}
						(yyval.exp).truelist = (yyval.exp).falselist = NULL;
						(yyval.exp).type = mkint();
						}
#line 2177 "mycc.c"
    break;

  case 75: /* expr: ID PP  */
#line 706 "mycc.y"
                        { 
						int place = getplace(top_tblptr, (yyvsp[-1].sym));
						if (place < 0) {
							error("undefined variable.");
						} else if (!isint(gettype(top_tblptr, (yyvsp[-1].sym)))) {
							error("type error");
						} else if (getlevel(top_tblptr, (yyvsp[-1].sym)) == 0) {
							emit3(getstatic, place);
							emit(dup);
							emit(iconst_1);
							emit(iadd);
							emit3(putstatic, place);
						} else {
							emit2(iload, place);
							emit32(iinc, place, 1);
						}
						(yyval.exp).truelist = (yyval.exp).falselist = NULL;
						(yyval.exp).type = mkint();
						}
#line 2201 "mycc.c"
    break;

  case 76: /* expr: ID NN  */
#line 726 "mycc.y"
                        { 
						int place = getplace(top_tblptr, (yyvsp[-1].sym));
						if (place < 0) {
							error("undefined variable.");
						} else if (!isint(gettype(top_tblptr, (yyvsp[-1].sym)))) {
							error("type error");
						} else if (getlevel(top_tblptr, (yyvsp[-1].sym)) == 0) {
							emit3(getstatic, place);
							emit(dup);
							emit(iconst_m1);
							emit(iadd);
							emit3(putstatic, place);
						} else {
							emit2(iload, place);
							emit32(iinc, place, -1);
						}
						(yyval.exp).truelist = (yyval.exp).falselist = NULL;
						(yyval.exp).type = mkint();
		 				}
#line 2225 "mycc.c"
    break;

  case 77: /* expr: ID  */
#line 746 "mycc.y"
                        { 
						int place = getplace(top_tblptr, (yyvsp[0].sym));
						(yyval.exp).falselist = (yyval.exp).truelist = NULL;
						(yyval.exp).type = gettype(top_tblptr, (yyvsp[0].sym));

						if (place < 0) {
							error("undefined variable");
						} else if (getlevel(top_tblptr, (yyvsp[0].sym)) == 0) {
							emit3(getstatic, place);
						} else if (isint((yyval.exp).type)) {
							emit2(iload, place);
						} else if (isfloat((yyval.exp).type)) {
							emit2(fload, place);
						} else {
							error("type error");
						}
						}
#line 2247 "mycc.c"
    break;

  case 78: /* expr: INT8  */
#line 764 "mycc.y"
                        { 
						emit2(bipush, (yyvsp[0].num));
						(yyval.exp).truelist = (yyval.exp).falselist = NULL;
						(yyval.exp).type = mkint();
						 }
#line 2257 "mycc.c"
    break;

  case 79: /* expr: INT16  */
#line 769 "mycc.y"
                        { 
						emit3(sipush, (yyvsp[0].num)); 
						(yyval.exp).truelist = (yyval.exp).falselist = NULL;
						(yyval.exp).type = mkint();
						}
#line 2267 "mycc.c"
    break;

  case 80: /* expr: INT32  */
#line 774 "mycc.y"
                        { 
						emit2(ldc, constant_pool_add_Integer(&cf, (yyvsp[0].num)));
						(yyval.exp).truelist = (yyval.exp).falselist = NULL;
						(yyval.exp).type = mkint();
						 }
#line 2277 "mycc.c"
    break;

  case 81: /* expr: FLT  */
#line 781 "mycc.y"
            { 
	    emit2(ldc, constant_pool_add_Float(&cf, (yyvsp[0].flt))); 
	    (yyval.exp).truelist = (yyval.exp).falselist = NULL;
	    // SRW fixed mkint() ... should be mkfloat()
	    // old code $$.type = mkint();
	    (yyval.exp).type = mkfloat();
	    }
#line 2289 "mycc.c"
    break;

  case 82: /* expr: ID '(' exprs ')'  */
#line 790 "mycc.y"
            {
	    Type type = gettype(top_tblptr, (yyvsp[-3].sym));
	    (yyval.exp).type = mkret(type);
	    if ((yyval.exp).type && getlevel(top_tblptr, (yyvsp[-3].sym)) == 0) {
		    emit3(invokestatic, constant_pool_add_Methodref(&cf, cf.name, (yyvsp[-3].sym)->lexptr, type));
	    } else {
		    error("invalid function call");
	    }
	    }
#line 2303 "mycc.c"
    break;

  case 83: /* K: %empty  */
#line 801 "mycc.y"
                        { (yyval.loc) = pc; emit3(ifne, 0); }
#line 2309 "mycc.c"
    break;

  case 84: /* L: %empty  */
#line 804 "mycc.y"
                        { (yyval.loc) = pc; }
#line 2315 "mycc.c"
    break;

  case 85: /* M: %empty  */
#line 807 "mycc.y"
                        { (yyval.loc) = pc;	/* location of inst. to backpatch */
			  emit3(ifeq, 0);
			}
#line 2323 "mycc.c"
    break;

  case 86: /* N: %empty  */
#line 812 "mycc.y"
                        { (yyval.loc) = pc;	/* location of inst. to backpatch */
			  emit3(goto_, 0);
			}
#line 2331 "mycc.c"
    break;

  case 87: /* Pexpr: expr  */
#line 817 "mycc.y"
               { decircuit(&(yyvsp[0].exp)); emit(pop);  }
#line 2337 "mycc.c"
    break;


#line 2341 "mycc.c"

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

#line 821 "mycc.y"


int main(int argc, char **argv)
{
	// init the compiler
	init();

	// set up a new class file structure
	init_ClassFile(&cf);

	// class has public access
	cf.access = ACC_PUBLIC;

	// class name is "Code"
	cf.name = "Code";

	// field counter (incremented for each field we add)
	cf.field_count = 0;

	// method counter (incremented for each method we add)
	cf.method_count = 0;

	// allocate an array of MAXFLD fields
	cf.fields = (struct FieldInfo*)malloc(MAXFLD * sizeof(struct FieldInfo));

	// allocate an array of MAXFUN methods
	cf.methods = (struct MethodInfo*)malloc(MAXFUN * sizeof(struct MethodInfo));

	if (!cf.methods)
		error("Out of memory");

	if (argc > 1)
		if (!(yyin = fopen(argv[1], "r")))
			error("Cannot open file for reading");

	if (yyparse() || errnum > 0)
		error("Compilation errors: class file not saved");

	fprintf(stderr, "Compilation successful: saving %s.class\n", cf.name);

	// save class file
	save_classFile(&cf);

	return 0;
}

// everything else, including main(), goes above this

/* Coerce value on top of stack */
static Type coerce1(Expr *expr, Type type) {
    Type conv;
    Type rc;

    if (iseq(expr->type, type)) {
		rc = type;
    } else {
		conv = decircuit(expr);
		if (isint(conv) && isfloat(type)) {
	   	 	emit(i2f);
		} else if (isfloat(conv) && isint(type)) {
	    	emit(f2i);
		}
		rc = type;
    }

    return rc;
}

/* Coerce value under top of stack */
static Type coerce2(Expr *expr, Type type) {
    Type conv;
    Type rc;

    if (iseq(expr->type, type)) {
	rc = type;
    } else {
	if (expr->type) {
	    emit(swap);
	}
	conv = coerce1(expr, type);
	emit(swap);
	rc = conv;
    }

    return rc;
}

/* Convert integer to short-circuit, no change when already short circuit */
static Expr circuit(Expr *expr) {
    Expr result;

    if (!expr->type) {
	result = *expr;
    } else if (isint(expr->type)) {
	result.falselist = makelist(pc);
	emit3(ifeq, 0);
	result.truelist = makelist(pc);
	emit3(goto_, 0);
    } else {
	error("Type error");
    }

    result.type = expr->type;

    return result;
}

/* Convert short-circuit logic to push of int 0 or 1 by backpatching */
static Type decircuit(Expr *expr) {
    Type rc;
    if (expr->type) {
	rc = expr->type;
    } else {
	backpatchlist(expr->falselist, pc);
	emit(iconst_0);
	emit3(goto_, 4);
	backpatchlist(expr->truelist, pc);
	emit(iconst_1);

	rc = mkint();
    }

    return rc;
}

/* Coerce and return the wider type (int or float) of two types */
static Type widen(Expr *expr1, Expr *expr2) {
    Type type;

    if (isfloat(expr1->type)) {
	type = expr1->type;
    } else if (isfloat(expr2->type)) {
	type = expr2->type;
    } else {
	type = mkint();
    }

    coerce1(expr2, type);
    coerce2(expr1, type);

    return type;
}

/* Emit float/integer operation */
static Expr emitop(Expr *expr1, Expr *expr2, int iop, int fop) {
    Expr result;

    result.truelist = result.falselist = NULL;
    result.type = widen(expr1, expr2);

    if (isint(result.type)) {
	emit(iop);
    } else if (isfloat(result.type) && fop != nop) {
	emit(fop);
    } else {
	error("Type error");
    }

    return result;
}

/* Emit float/integer assignment operation */
static Expr emitas(Symbol *sym, Expr *expr, int iop, int fop) {
    Expr result;
    int place;
    Type type;

    result.truelist = result.falselist = NULL;

    place = getplace(top_tblptr, sym);
    type = gettype(top_tblptr, sym);
    result.type = coerce1(expr, type);
    if (getlevel(top_tblptr, sym) == 0) {
    	if (iop != nop) {
	    emit3(getstatic, place);
	    emit(swap);
	    if (isint(result.type)) {
		emit(iop);
	    } else if (isfloat(result.type) && fop != nop) {
		emit(fop);
	    } else {
		error("Type error");
	    }
	}
	emit(dup);
	emit3(putstatic, place);
    } else if (isint(result.type)) {
    	if (iop != nop) {
	    emit2(iload, place);
	    emit(swap);
	    emit(iop);
	}
	emit(dup);
	emit2(istore, place);
    } else if (isfloat(result.type) && (iop == nop || fop != nop)) {
    	if (iop != nop) {
	    emit2(fload, place);
	    emit(swap);
	    emit(fop);
	}
	emit(dup);
	emit2(fstore, place);
    } else {
	error("Type error");
    }

    return result;

}
