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
#line 8 "grammar.y"

#include "ast.h" 
#include <string>
#include <iostream>
#include <vector>

void yyerror(const char *s) {
    std::printf("Error: %s\n", s);
    std::exit(1); 
}

int yylex(void);

ast::ProgramAST *root;

#line 87 "grammar.cpp"

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

#include "grammar.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COMMA = 3,                      /* COMMA  */
  YYSYMBOL_DOT = 4,                        /* DOT  */
  YYSYMBOL_SEMICOLON = 5,                  /* SEMICOLON  */
  YYSYMBOL_ELLIPSES = 6,                   /* ELLIPSES  */
  YYSYMBOL_SINGLEQUOTE = 7,                /* SINGLEQUOTE  */
  YYSYMBOL_DOUBLEQUOTE = 8,                /* DOUBLEQUOTE  */
  YYSYMBOL_LEFTBRACE = 9,                  /* LEFTBRACE  */
  YYSYMBOL_RIGHTBRACE = 10,                /* RIGHTBRACE  */
  YYSYMBOL_LEFTBRACKET = 11,               /* LEFTBRACKET  */
  YYSYMBOL_RIGHTBRACKET = 12,              /* RIGHTBRACKET  */
  YYSYMBOL_LEFTPAREN = 13,                 /* LEFTPAREN  */
  YYSYMBOL_RIGHTPAREN = 14,                /* RIGHTPAREN  */
  YYSYMBOL_SHIFTL = 15,                    /* SHIFTL  */
  YYSYMBOL_SHIFTR = 16,                    /* SHIFTR  */
  YYSYMBOL_EQUAL = 17,                     /* EQUAL  */
  YYSYMBOL_GREATER = 18,                   /* GREATER  */
  YYSYMBOL_LESSTHAN = 19,                  /* LESSTHAN  */
  YYSYMBOL_GORE = 20,                      /* GORE  */
  YYSYMBOL_LORE = 21,                      /* LORE  */
  YYSYMBOL_NOEQUAL = 22,                   /* NOEQUAL  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_ASSIGN = 24,                    /* ASSIGN  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_ARW = 27,                       /* ARW  */
  YYSYMBOL_ADD = 28,                       /* ADD  */
  YYSYMBOL_SUB = 29,                       /* SUB  */
  YYSYMBOL_MUL = 30,                       /* MUL  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_MOD = 32,                       /* MOD  */
  YYSYMBOL_DOUBLEADD = 33,                 /* DOUBLEADD  */
  YYSYMBOL_DOUBLESUB = 34,                 /* DOUBLESUB  */
  YYSYMBOL_ADDEQUAL = 35,                  /* ADDEQUAL  */
  YYSYMBOL_SUBEQUAL = 36,                  /* SUBEQUAL  */
  YYSYMBOL_MULEQUAL = 37,                  /* MULEQUAL  */
  YYSYMBOL_DIVEQUAL = 38,                  /* DIVEQUAL  */
  YYSYMBOL_MODEQUAL = 39,                  /* MODEQUAL  */
  YYSYMBOL_COLON = 40,                     /* COLON  */
  YYSYMBOL_STRUCT = 41,                    /* STRUCT  */
  YYSYMBOL_PTR = 42,                       /* PTR  */
  YYSYMBOL_ARRAY = 43,                     /* ARRAY  */
  YYSYMBOL_IF = 44,                        /* IF  */
  YYSYMBOL_ELSE = 45,                      /* ELSE  */
  YYSYMBOL_FOR = 46,                       /* FOR  */
  YYSYMBOL_WHILE = 47,                     /* WHILE  */
  YYSYMBOL_SWITCH = 48,                    /* SWITCH  */
  YYSYMBOL_CASE = 49,                      /* CASE  */
  YYSYMBOL_DEFAULT = 50,                   /* DEFAULT  */
  YYSYMBOL_RETURN = 51,                    /* RETURN  */
  YYSYMBOL_TRUE = 52,                      /* TRUE  */
  YYSYMBOL_FALSE = 53,                     /* FALSE  */
  YYSYMBOL_BREAK = 54,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 55,                  /* CONTINUE  */
  YYSYMBOL_SIZEOF = 56,                    /* SIZEOF  */
  YYSYMBOL_BOOL = 57,                      /* BOOL  */
  YYSYMBOL_INT = 58,                       /* INT  */
  YYSYMBOL_LONG = 59,                      /* LONG  */
  YYSYMBOL_CHAR = 60,                      /* CHAR  */
  YYSYMBOL_FLOAT = 61,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 62,                    /* DOUBLE  */
  YYSYMBOL_VOID = 63,                      /* VOID  */
  YYSYMBOL_INTEGER = 64,                   /* INTEGER  */
  YYSYMBOL_REAL = 65,                      /* REAL  */
  YYSYMBOL_CHARACTER = 66,                 /* CHARACTER  */
  YYSYMBOL_IDENTIFIER = 67,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 68,                    /* STRING  */
  YYSYMBOL_FUNC_CALL_ARG_LIST = 69,        /* FUNC_CALL_ARG_LIST  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_ProgramAST = 71,                /* ProgramAST  */
  YYSYMBOL_DeclsAST = 72,                  /* DeclsAST  */
  YYSYMBOL_DeclAST = 73,                   /* DeclAST  */
  YYSYMBOL_FuncDeclAST = 74,               /* FuncDeclAST  */
  YYSYMBOL_FuncBodyAST = 75,               /* FuncBodyAST  */
  YYSYMBOL_VarDeclAST = 76,                /* VarDeclAST  */
  YYSYMBOL_VarListAST = 77,                /* VarListAST  */
  YYSYMBOL__VarListAST = 78,               /* _VarListAST  */
  YYSYMBOL_VarInitAST = 79,                /* VarInitAST  */
  YYSYMBOL_VarTypeAST = 80,                /* VarTypeAST  */
  YYSYMBOL__VarTypeAST = 81,               /* _VarTypeAST  */
  YYSYMBOL_BuiltInTypeAST = 82,            /* BuiltInTypeAST  */
  YYSYMBOL_FieldDeclsAST = 83,             /* FieldDeclsAST  */
  YYSYMBOL_FieldDeclAST = 84,              /* FieldDeclAST  */
  YYSYMBOL_MemListsAST = 85,               /* MemListsAST  */
  YYSYMBOL__MemListsAST = 86,              /* _MemListsAST  */
  YYSYMBOL_ArgListAST = 87,                /* ArgListAST  */
  YYSYMBOL__ArgListAST = 88,               /* _ArgListAST  */
  YYSYMBOL_ArgAST = 89,                    /* ArgAST  */
  YYSYMBOL_BlockAST = 90,                  /* BlockAST  */
  YYSYMBOL_StmtsAST = 91,                  /* StmtsAST  */
  YYSYMBOL_StmtAST = 92,                   /* StmtAST  */
  YYSYMBOL_IfStmtAST = 93,                 /* IfStmtAST  */
  YYSYMBOL_ForStmtAST = 94,                /* ForStmtAST  */
  YYSYMBOL_WhileStmtAST = 95,              /* WhileStmtAST  */
  YYSYMBOL_SwitchStmtAST = 96,             /* SwitchStmtAST  */
  YYSYMBOL_CaseList = 97,                  /* CaseList  */
  YYSYMBOL_CaseStmAST = 98,                /* CaseStmAST  */
  YYSYMBOL_ContinueStmtAST = 99,           /* ContinueStmtAST  */
  YYSYMBOL_BreakStmtAST = 100,             /* BreakStmtAST  */
  YYSYMBOL_ReturnStmtAST = 101,            /* ReturnStmtAST  */
  YYSYMBOL_ExprAST = 102,                  /* ExprAST  */
  YYSYMBOL_ExprList = 103,                 /* ExprList  */
  YYSYMBOL__ExprList = 104,                /* _ExprList  */
  YYSYMBOL_ConstantAST = 105               /* ConstantAST  */
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
#define YYLAST   1284

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   154,   157,   160,   161,   164,   165,   168,
     171,   174,   176,   178,   181,   183,   187,   188,   191,   194,
     195,   196,   197,   198,   199,   202,   203,   204,   205,   206,
     207,   208,   211,   214,   217,   218,   221,   223,   225,   228,
     230,   234,   236,   238,   239,   241,   244,   246,   250,   251,
     254,   257,   260,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   276,   277,   280,   281,   284,   287,
     290,   292,   295,   296,   299,   302,   305,   306,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   352,
     354,   356,   359,   361,   365,   366,   367,   368,   369,   370
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
  "\"end of file\"", "error", "\"invalid token\"", "COMMA", "DOT",
  "SEMICOLON", "ELLIPSES", "SINGLEQUOTE", "DOUBLEQUOTE", "LEFTBRACE",
  "RIGHTBRACE", "LEFTBRACKET", "RIGHTBRACKET", "LEFTPAREN", "RIGHTPAREN",
  "SHIFTL", "SHIFTR", "EQUAL", "GREATER", "LESSTHAN", "GORE", "LORE",
  "NOEQUAL", "NOT", "ASSIGN", "AND", "OR", "ARW", "ADD", "SUB", "MUL",
  "DIV", "MOD", "DOUBLEADD", "DOUBLESUB", "ADDEQUAL", "SUBEQUAL",
  "MULEQUAL", "DIVEQUAL", "MODEQUAL", "COLON", "STRUCT", "PTR", "ARRAY",
  "IF", "ELSE", "FOR", "WHILE", "SWITCH", "CASE", "DEFAULT", "RETURN",
  "TRUE", "FALSE", "BREAK", "CONTINUE", "SIZEOF", "BOOL", "INT", "LONG",
  "CHAR", "FLOAT", "DOUBLE", "VOID", "INTEGER", "REAL", "CHARACTER",
  "IDENTIFIER", "STRING", "FUNC_CALL_ARG_LIST", "$accept", "ProgramAST",
  "DeclsAST", "DeclAST", "FuncDeclAST", "FuncBodyAST", "VarDeclAST",
  "VarListAST", "_VarListAST", "VarInitAST", "VarTypeAST", "_VarTypeAST",
  "BuiltInTypeAST", "FieldDeclsAST", "FieldDeclAST", "MemListsAST",
  "_MemListsAST", "ArgListAST", "_ArgListAST", "ArgAST", "BlockAST",
  "StmtsAST", "StmtAST", "IfStmtAST", "ForStmtAST", "WhileStmtAST",
  "SwitchStmtAST", "CaseList", "CaseStmAST", "ContinueStmtAST",
  "BreakStmtAST", "ReturnStmtAST", "ExprAST", "ExprList", "_ExprList",
  "ConstantAST", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-138)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-124)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -138,    32,   -34,  -138,    27,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,   -25,    -8,  -138,  -138,
      -3,    34,    43,    44,  -138,    35,   313,   326,   502,  -138,
     -15,     8,  -138,  -138,    11,  -138,  -138,    12,    68,    87,
      88,   390,   502,   502,   502,   502,   502,   502,  -138,  -138,
      79,  -138,  -138,  -138,    80,  -138,  1152,  -138,    71,    94,
    -138,    93,    99,   105,   108,  -138,    -4,   349,    -2,   106,
     598,   171,   171,   171,   171,   171,   171,   446,   502,   502,
      54,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,    55,   502,   502,   502,   502,   502,  -138,
    -138,   502,   502,   502,   502,   502,  -138,  -138,    56,  -138,
    -138,  -138,  -138,   121,   502,  -138,    -5,   111,   635,  1079,
     115,   127,  1152,  -138,   672,   433,   433,  1250,    85,    85,
      85,    85,  1250,  1152,  1219,  1188,  -138,   489,   489,   171,
     171,   171,  1152,  1152,  1152,  1152,  1152,   129,   155,   171,
    -138,  -138,  -138,  -138,   502,  -138,  -138,  -138,  -138,   120,
     123,   124,   125,    75,   139,   140,  -138,   -15,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,   709,  1116,   219,
     502,   390,   502,   502,  -138,   746,  -138,  -138,  -138,  -138,
     783,   502,   820,   857,   894,  -138,   283,   931,   502,   283,
     137,    89,   502,   968,  -138,  -138,   283,  1005,   502,    -6,
    -138,   283,  1042,  -138,   502,   107,  -138,  -138,   283,   560,
    -138,  -138,  -138,   283,   283
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,    25,    26,    27,    28,    29,
      30,    31,    24,     3,     5,     6,    13,    18,    19,    33,
      16,     0,     0,    12,    21,     0,     0,    45,     0,    10,
       0,     0,    35,    20,    38,    32,    44,    49,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,   124,   125,
       0,   127,   128,   126,   116,   129,    17,   117,    16,    11,
      23,     0,    37,     0,     0,    48,     0,     0,   116,     0,
       0,    93,    85,    86,    92,    88,    90,     0,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      91,     0,     0,     0,     0,     0,    22,    34,     0,     7,
      52,     8,    43,    41,     0,   115,   116,     0,     0,   120,
       0,     0,   118,    83,     0,    99,   100,   105,   101,   103,
     102,   104,   106,   109,   107,   108,    84,    97,    98,    95,
      94,    96,   113,   114,   111,   110,   112,    36,     0,    87,
      79,    81,    80,    82,     0,    78,    63,    52,     9,     0,
       0,     0,     0,     0,     0,     0,    62,    13,    61,    51,
      54,    55,    56,    57,    59,    58,    60,     0,   119,     0,
       0,     0,     0,     0,    76,     0,    75,    74,    53,    50,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,    65,     0,     0,    68,    71,     0,     0,     0,     0,
      64,     0,     0,    69,     0,     0,    70,    67,     0,     0,
      52,    66,    52,    73,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,  -138,  -138,  -138,     0,  -138,  -138,   118,
       4,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,    82,
    -138,  -137,  -112,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,   -28,  -138,  -138,  -138
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    13,    14,   111,   166,    21,    22,    23,
     167,    17,    18,    26,    35,    63,    64,    38,    39,    40,
     168,   148,   169,   170,   171,   172,   173,   209,   216,   174,
     175,   176,   177,   120,   121,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   109,    15,   -24,   213,   110,    16,     4,    78,   150,
      27,    78,   -24,    70,    71,    72,    73,    74,    75,    76,
     179,    28,    60,     5,     6,     7,     8,     9,    10,    11,
      34,    37,     3,    12,    24,    25,    19,   -24,   -24,    29,
     -24,   -24,    20,   214,   215,    69,    30,   -15,    31,   118,
     119,   122,    58,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   -24,   137,   138,   139,   140,
     141,    37,    61,   142,   143,   144,   145,   146,    62,    65,
     184,   117,    66,   223,   201,   224,   149,   204,    41,    80,
      67,   -47,    77,    78,   210,    28,    81,   -14,    42,   217,
      82,    83,   -40,    43,    44,    45,   221,   106,    46,    47,
     107,   108,    93,    94,    95,    96,    97,    98,    99,   100,
     114,   123,   136,   147,   -46,   151,   178,    48,    49,   153,
     154,    50,   -39,   180,   206,   185,   181,   182,   183,    51,
      52,    53,    54,    55,   186,   187,   205,   220,    59,   113,
       0,     0,   190,   192,   193,   194,     0,     0,     0,     0,
     156,     0,     0,   197,   157,   158,     0,     0,    41,     0,
     203,     0,     0,     0,   207,    80,     0,     0,    42,     0,
     212,   191,    81,    43,    44,    45,   219,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     4,     0,    93,   159,
       0,   160,   161,   162,    99,   100,   163,    48,    49,   164,
     165,    50,     5,     6,     7,     8,     9,    10,    11,    51,
      52,    53,    68,    55,   156,     0,     0,     0,   157,   189,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,     0,    43,    44,    45,
       0,     0,    46,    47,     0,     0,     0,     0,     0,     0,
       4,     0,     0,   159,     0,   160,   161,   162,     0,     0,
     163,    48,    49,   164,   165,    50,     5,     6,     7,     8,
       9,    10,    11,    51,    52,    53,    68,    55,   156,     0,
       0,     0,   157,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
       0,    43,    44,    45,     0,     0,    46,    47,    32,     0,
       0,     0,     0,    33,     4,     0,     0,   159,     0,   160,
     161,   162,    36,     0,   163,    48,    49,   164,   165,    50,
       5,     6,     7,     8,     9,    10,    11,    51,    52,    53,
      68,    55,     0,     0,     4,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       5,     6,     7,     8,     9,    10,    11,     0,     0,     0,
      12,     0,     0,     5,     6,     7,     8,     9,    10,    11,
       4,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    42,     0,     0,    12,     0,    43,    44,
      45,     0,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     0,    80,     0,     0,
       0,     0,    48,    49,    81,     0,    50,     5,     6,     7,
       8,     9,    10,    11,    51,    52,    53,    68,    55,    41,
      93,    94,    95,    96,    97,    98,    99,   100,     0,    42,
       0,     0,     0,     0,    43,    44,    45,     0,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,    48,    49,
      81,     0,    50,     5,     6,     7,     8,     9,    10,    11,
      51,    52,    53,   116,    55,    41,    93,     0,     0,    96,
      97,    98,    99,   100,     0,    42,     0,     0,     0,     0,
      43,    44,    45,     0,     0,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,     0,     0,    50,     0,
       0,     0,     0,    79,    80,     0,    51,    52,    53,    54,
      55,    81,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     222,    79,    80,     0,     0,     0,     0,     0,     0,    81,
       0,     0,   115,    82,    83,    84,    85,    86,    87,    88,
      89,     0,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    79,    80,
       0,     0,     0,     0,     0,     0,    81,     0,     0,   152,
      82,    83,    84,    85,    86,    87,    88,    89,     0,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    79,    80,     0,     0,     0,
       0,     0,     0,    81,   155,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,     0,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    79,    80,   188,     0,     0,     0,     0,     0,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    79,
      80,   195,     0,     0,     0,     0,     0,    81,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    79,    80,     0,     0,
       0,     0,     0,     0,    81,     0,     0,   196,    82,    83,
      84,    85,    86,    87,    88,    89,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,    79,    80,   198,     0,     0,     0,     0,
       0,    81,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      79,    80,     0,     0,     0,     0,     0,     0,    81,     0,
       0,   199,    82,    83,    84,    85,    86,    87,    88,    89,
       0,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    79,    80,     0,
       0,     0,     0,     0,     0,    81,     0,     0,   200,    82,
      83,    84,    85,    86,    87,    88,    89,     0,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    79,    80,   202,     0,     0,     0,
       0,     0,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,    79,    80,   208,     0,     0,     0,     0,     0,    81,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,     0,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    79,    80,
       0,     0,     0,     0,     0,     0,    81,     0,     0,   211,
      82,    83,    84,    85,    86,    87,    88,    89,     0,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    79,    80,     0,     0,     0,
       0,     0,     0,    81,     0,     0,   218,    82,    83,    84,
      85,    86,    87,    88,    89,     0,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,  -123,    80,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,  -122,
      80,     0,     0,     0,     0,     0,     0,    81,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    80,     0,     0,     0,
       0,     0,     0,    81,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,     0,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    80,     0,     0,     0,     0,     0,     0,    81,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,    91,     0,    93,    94,    95,    96,    97,
      98,    99,   100,    80,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,    93,    94,    95,    96,
      97,    98,    99,   100,    80,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,    82,    83,     0,    85,    86,
      87,    88,     0,     0,     0,     0,     0,    93,    94,    95,
      96,    97,    98,    99,   100
};

static const yytype_int16 yycheck[] =
{
      28,     5,     2,     5,    10,     9,     2,    41,    13,    14,
      13,    13,    14,    41,    42,    43,    44,    45,    46,    47,
     157,    24,    14,    57,    58,    59,    60,    61,    62,    63,
      26,    27,     0,    67,    42,    43,     9,    42,    43,     5,
      42,    43,    67,    49,    50,    41,     3,     3,    13,    77,
      78,    79,    67,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    67,    94,    95,    96,    97,
      98,    67,    64,   101,   102,   103,   104,   105,    67,    67,
       5,    77,    14,   220,   196,   222,   114,   199,    13,     4,
       3,     3,    13,    13,   206,    24,    11,     3,    23,   211,
      15,    16,     3,    28,    29,    30,   218,    14,    33,    34,
       5,     3,    27,    28,    29,    30,    31,    32,    33,    34,
      14,    67,    67,    67,     3,    14,   154,    52,    53,    14,
       3,    56,     3,    13,    45,   163,    13,    13,    13,    64,
      65,    66,    67,    68,     5,     5,     9,    40,    30,    67,
      -1,    -1,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
       5,    -1,    -1,   191,     9,    10,    -1,    -1,    13,    -1,
     198,    -1,    -1,    -1,   202,     4,    -1,    -1,    23,    -1,
     208,   181,    11,    28,    29,    30,   214,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    27,    44,
      -1,    46,    47,    48,    33,    34,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     5,    -1,    -1,    -1,     9,    10,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    44,    -1,    46,    47,    48,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     5,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    -1,    -1,    33,    34,     5,    -1,
      -1,    -1,    -1,    10,    41,    -1,    -1,    44,    -1,    46,
      47,    48,     6,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    41,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      41,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    23,    -1,    -1,    67,    -1,    28,    29,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    52,    53,    11,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    13,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    52,    53,
      11,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    13,    27,    -1,    -1,    30,
      31,    32,    33,    34,    -1,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    56,    -1,
      -1,    -1,    -1,     3,     4,    -1,    64,    65,    66,    67,
      68,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    71,    72,     0,    41,    57,    58,    59,    60,    61,
      62,    63,    67,    73,    74,    76,    80,    81,    82,     9,
      67,    77,    78,    79,    42,    43,    83,    13,    24,     5,
       3,    13,     5,    10,    80,    84,     6,    80,    87,    88,
      89,    13,    23,    28,    29,    30,    33,    34,    52,    53,
      56,    64,    65,    66,    67,    68,   102,   105,    67,    79,
      14,    64,    67,    85,    86,    67,    14,     3,    67,    80,
     102,   102,   102,   102,   102,   102,   102,    13,    13,     3,
       4,    11,    15,    16,    17,    18,    19,    20,    21,    22,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    14,     5,     3,     5,
       9,    75,     6,    89,    14,    14,    67,    80,   102,   102,
     103,   104,   102,    67,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,    67,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,    67,    91,   102,
      14,    14,    14,    14,     3,    12,     5,     9,    10,    44,
      46,    47,    48,    51,    54,    55,    76,    80,    90,    92,
      93,    94,    95,    96,    99,   100,   101,   102,   102,    91,
      13,    13,    13,    13,     5,   102,     5,     5,     5,    10,
     102,    76,   102,   102,   102,     5,    14,   102,     5,    14,
      14,    92,     5,   102,    92,     9,    45,   102,     5,    97,
      92,    14,   102,    10,    49,    50,    98,    92,    14,   102,
      40,    92,    40,    91,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    74,    74,    75,
      76,    77,    77,    77,    78,    78,    79,    79,    80,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    85,    85,    85,    86,
      86,    87,    87,    87,    87,    87,    88,    88,    89,    89,
      90,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    94,    94,    95,    96,
      97,    97,    98,    98,    99,   100,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   103,
     103,   103,   104,   104,   105,   105,   105,   105,   105,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     6,     6,     3,
       3,     3,     1,     0,     3,     1,     1,     3,     1,     1,
       4,     2,     5,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     3,     1,     3,     1,     0,     3,
       1,     3,     1,     3,     1,     0,     3,     1,     2,     1,
       3,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     5,     9,     8,     5,     7,
       2,     0,     4,     3,     2,     2,     2,     3,     4,     4,
       4,     4,     4,     3,     3,     2,     2,     4,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* ProgramAST: DeclsAST  */
#line 150 "grammar.y"
                             {  (yyval.Program) = new ast::ProgramAST((yyvsp[0].Decls)); 
                                root = (yyval.Program); }
#line 1554 "grammar.cpp"
    break;

  case 3: /* DeclsAST: DeclsAST DeclAST  */
#line 154 "grammar.y"
                                 {  (yyval.Decls) = (yyvsp[-1].Decls); 
                                (yyval.Decls)->push_back((yyvsp[0].Decl)); }
#line 1561 "grammar.cpp"
    break;

  case 4: /* DeclsAST: %empty  */
#line 157 "grammar.y"
                                          {  (yyval.Decls) = new ast::DeclsAST(); }
#line 1567 "grammar.cpp"
    break;

  case 5: /* DeclAST: FuncDeclAST  */
#line 160 "grammar.y"
                                {  (yyval.Decl) = (yyvsp[0].FuncDecl);   }
#line 1573 "grammar.cpp"
    break;

  case 6: /* DeclAST: VarDeclAST  */
#line 161 "grammar.y"
                                    {  (yyval.Decl) = (yyvsp[0].VarDecl);   }
#line 1579 "grammar.cpp"
    break;

  case 7: /* FuncDeclAST: VarTypeAST IDENTIFIER LEFTPAREN ArgListAST RIGHTPAREN SEMICOLON  */
#line 164 "grammar.y"
                                                                              {  (yyval.FuncDecl) = new ast::FuncDeclAST((yyvsp[-5].VarType), *(yyvsp[-4].string_Val), (yyvsp[-2].ArgList));   }
#line 1585 "grammar.cpp"
    break;

  case 8: /* FuncDeclAST: VarTypeAST IDENTIFIER LEFTPAREN ArgListAST RIGHTPAREN FuncBodyAST  */
#line 165 "grammar.y"
                                                                                                {  (yyval.FuncDecl) = new ast::FuncDeclAST((yyvsp[-5].VarType), *(yyvsp[-4].string_Val), (yyvsp[-2].ArgList), (yyvsp[0].FuncBody));   }
#line 1591 "grammar.cpp"
    break;

  case 9: /* FuncBodyAST: LEFTBRACE StmtsAST RIGHTBRACE  */
#line 168 "grammar.y"
                                                {  (yyval.FuncBody) = new ast::FuncBodyAST((yyvsp[-1].Statements));   }
#line 1597 "grammar.cpp"
    break;

  case 10: /* VarDeclAST: VarTypeAST VarListAST SEMICOLON  */
#line 171 "grammar.y"
                                                {  (yyval.VarDecl) = new ast::VarDeclAST((yyvsp[-2].VarType),(yyvsp[-1].VarList));   }
#line 1603 "grammar.cpp"
    break;

  case 11: /* VarListAST: _VarListAST COMMA VarInitAST  */
#line 174 "grammar.y"
                                                {  (yyval.VarList) = (yyvsp[-2].VarList); 
                                               (yyval.VarList) -> push_back((yyvsp[0].VarInit));   }
#line 1610 "grammar.cpp"
    break;

  case 12: /* VarListAST: VarInitAST  */
#line 176 "grammar.y"
                                                                    {  (yyval.VarList) = new ast::VarListAST(); 
			                                   (yyval.VarList) -> push_back((yyvsp[0].VarInit));   }
#line 1617 "grammar.cpp"
    break;

  case 13: /* VarListAST: %empty  */
#line 178 "grammar.y"
                                                                                {  (yyval.VarList) = new ast::VarListAST();   }
#line 1623 "grammar.cpp"
    break;

  case 14: /* _VarListAST: _VarListAST COMMA VarInitAST  */
#line 181 "grammar.y"
                                                {  (yyval.VarList) = (yyvsp[-2].VarList); 
                                               (yyval.VarList)->push_back((yyvsp[0].VarInit));   }
#line 1630 "grammar.cpp"
    break;

  case 15: /* _VarListAST: VarInitAST  */
#line 183 "grammar.y"
                                                                    {  (yyval.VarList) = new ast::VarListAST();
			                                   (yyval.VarList)->push_back((yyvsp[0].VarInit));   }
#line 1637 "grammar.cpp"
    break;

  case 16: /* VarInitAST: IDENTIFIER  */
#line 187 "grammar.y"
                                                           {  (yyval.VarInit) = new ast::VarInitAST(*(yyvsp[0].string_Val));   }
#line 1643 "grammar.cpp"
    break;

  case 17: /* VarInitAST: IDENTIFIER ASSIGN ExprAST  */
#line 188 "grammar.y"
                                                   {  (yyval.VarInit) = new ast::VarInitAST(*(yyvsp[-2].string_Val), (yyvsp[0].Expr));   }
#line 1649 "grammar.cpp"
    break;

  case 18: /* VarTypeAST: _VarTypeAST  */
#line 191 "grammar.y"
                                {  (yyval.VarType) = (yyvsp[0].VarType); }
#line 1655 "grammar.cpp"
    break;

  case 19: /* _VarTypeAST: BuiltInTypeAST  */
#line 194 "grammar.y"
                            {  (yyval.VarType) = (yyvsp[0].BuiltInType);   }
#line 1661 "grammar.cpp"
    break;

  case 20: /* _VarTypeAST: STRUCT LEFTBRACE FieldDeclsAST RIGHTBRACE  */
#line 195 "grammar.y"
                                                                        {  (yyval.VarType) = new ast::StructTypeAST((yyvsp[-1].FieldDecls));   }
#line 1667 "grammar.cpp"
    break;

  case 21: /* _VarTypeAST: _VarTypeAST PTR  */
#line 196 "grammar.y"
                                          {  (yyval.VarType) = new ast::PointerTypeAST((yyvsp[-1].VarType));   }
#line 1673 "grammar.cpp"
    break;

  case 22: /* _VarTypeAST: _VarTypeAST ARRAY LEFTPAREN INTEGER RIGHTPAREN  */
#line 197 "grammar.y"
                                                                         {  (yyval.VarType) = new ast::ArrayTypeAST((yyvsp[-4].VarType),(yyvsp[-1].int_Val));   }
#line 1679 "grammar.cpp"
    break;

  case 23: /* _VarTypeAST: _VarTypeAST ARRAY LEFTPAREN RIGHTPAREN  */
#line 198 "grammar.y"
                                                                 {  (yyval.VarType) = new ast::ArrayTypeAST((yyvsp[-3].VarType));   }
#line 1685 "grammar.cpp"
    break;

  case 24: /* _VarTypeAST: IDENTIFIER  */
#line 199 "grammar.y"
                                     {  (yyval.VarType) = new ast::DefinedTypeAST(*(yyvsp[0].string_Val));   }
#line 1691 "grammar.cpp"
    break;

  case 25: /* BuiltInTypeAST: BOOL  */
#line 202 "grammar.y"
                        {  (yyval.BuiltInType) = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_bool_);   }
#line 1697 "grammar.cpp"
    break;

  case 26: /* BuiltInTypeAST: INT  */
#line 203 "grammar.y"
                                        {  (yyval.BuiltInType) = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_int_);   }
#line 1703 "grammar.cpp"
    break;

  case 27: /* BuiltInTypeAST: LONG  */
#line 204 "grammar.y"
                                        {  (yyval.BuiltInType) = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_long_);   }
#line 1709 "grammar.cpp"
    break;

  case 28: /* BuiltInTypeAST: CHAR  */
#line 205 "grammar.y"
                                        {  (yyval.BuiltInType) = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_char_);   }
#line 1715 "grammar.cpp"
    break;

  case 29: /* BuiltInTypeAST: FLOAT  */
#line 206 "grammar.y"
                                        {  (yyval.BuiltInType) = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_float_);   }
#line 1721 "grammar.cpp"
    break;

  case 30: /* BuiltInTypeAST: DOUBLE  */
#line 207 "grammar.y"
                                        {  (yyval.BuiltInType) = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_double_);   }
#line 1727 "grammar.cpp"
    break;

  case 31: /* BuiltInTypeAST: VOID  */
#line 208 "grammar.y"
                                        {  (yyval.BuiltInType) = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_void_);   }
#line 1733 "grammar.cpp"
    break;

  case 32: /* FieldDeclsAST: FieldDeclsAST FieldDeclAST  */
#line 211 "grammar.y"
                                          {  (yyval.FieldDecls) = (yyvsp[-1].FieldDecls); 
                                              if ((yyvsp[0].FieldDecl) != NULL) 
									             (yyval.FieldDecls)->push_back((yyvsp[0].FieldDecl));   }
#line 1741 "grammar.cpp"
    break;

  case 33: /* FieldDeclsAST: %empty  */
#line 214 "grammar.y"
                                                                          {  (yyval.FieldDecls) = new ast::FieldDeclsAST();   }
#line 1747 "grammar.cpp"
    break;

  case 34: /* FieldDeclAST: VarTypeAST MemListsAST SEMICOLON  */
#line 217 "grammar.y"
                                               {  (yyval.FieldDecl) = new ast::FieldDeclAST((yyvsp[-2].VarType),(yyvsp[-1].MemList));   }
#line 1753 "grammar.cpp"
    break;

  case 35: /* FieldDeclAST: SEMICOLON  */
#line 218 "grammar.y"
                                                                           {  (yyval.FieldDecl) = NULL;   }
#line 1759 "grammar.cpp"
    break;

  case 36: /* MemListsAST: _MemListsAST COMMA IDENTIFIER  */
#line 221 "grammar.y"
                                           {  (yyval.MemList) = (yyvsp[-2].MemList); 
                                              (yyval.MemList)->push_back(*(yyvsp[0].string_Val));   }
#line 1766 "grammar.cpp"
    break;

  case 37: /* MemListsAST: IDENTIFIER  */
#line 223 "grammar.y"
                                                               {  (yyval.MemList) = new ast::MemListsAST(); 
			                                  (yyval.MemList)->push_back(*(yyvsp[0].string_Val));   }
#line 1773 "grammar.cpp"
    break;

  case 38: /* MemListsAST: %empty  */
#line 225 "grammar.y"
                                                                               {  (yyval.MemList) = new ast::MemListsAST();   }
#line 1779 "grammar.cpp"
    break;

  case 39: /* _MemListsAST: _MemListsAST COMMA IDENTIFIER  */
#line 228 "grammar.y"
                                            {  (yyval.MemList) = (yyvsp[-2].MemList); 
                                               (yyval.MemList)->push_back(*(yyvsp[0].string_Val));   }
#line 1786 "grammar.cpp"
    break;

  case 40: /* _MemListsAST: IDENTIFIER  */
#line 230 "grammar.y"
                                                                {  (yyval.MemList) = new ast::MemListsAST(); 
			                                   (yyval.MemList)->push_back(*(yyvsp[0].string_Val));   }
#line 1793 "grammar.cpp"
    break;

  case 41: /* ArgListAST: _ArgListAST COMMA ArgAST  */
#line 234 "grammar.y"
                                          {  (yyval.ArgList) = (yyvsp[-2].ArgList); 
                                         (yyval.ArgList)->push_back((yyvsp[0].Arg));   }
#line 1800 "grammar.cpp"
    break;

  case 42: /* ArgListAST: ArgAST  */
#line 236 "grammar.y"
                                                                  {  (yyval.ArgList) = new ast::ArgListAST(); 
			                             (yyval.ArgList)->push_back((yyvsp[0].Arg));   }
#line 1807 "grammar.cpp"
    break;

  case 43: /* ArgListAST: _ArgListAST COMMA ELLIPSES  */
#line 238 "grammar.y"
                                                     { (yyval.ArgList) = (yyvsp[-2].ArgList); (yyval.ArgList)->has_dot(); }
#line 1813 "grammar.cpp"
    break;

  case 44: /* ArgListAST: ELLIPSES  */
#line 239 "grammar.y"
                                                                  { (yyval.ArgList) = new ast::ArgListAST();
										(yyval.ArgList)->has_dot();            }
#line 1820 "grammar.cpp"
    break;

  case 45: /* ArgListAST: %empty  */
#line 241 "grammar.y"
                                                                          {  (yyval.ArgList) = new ast::ArgListAST();   }
#line 1826 "grammar.cpp"
    break;

  case 46: /* _ArgListAST: _ArgListAST COMMA ArgAST  */
#line 244 "grammar.y"
                                      {  (yyval.ArgList) = (yyvsp[-2].ArgList); 
                                         (yyval.ArgList)->push_back((yyvsp[0].Arg));   }
#line 1833 "grammar.cpp"
    break;

  case 47: /* _ArgListAST: ArgAST  */
#line 246 "grammar.y"
                                                                  {  (yyval.ArgList) = new ast::ArgListAST(); 
			                             (yyval.ArgList)->push_back((yyvsp[0].Arg));   }
#line 1840 "grammar.cpp"
    break;

  case 48: /* ArgAST: VarTypeAST IDENTIFIER  */
#line 250 "grammar.y"
                                                  {  (yyval.Arg) = new ast::ArgAST((yyvsp[-1].VarType), *(yyvsp[0].string_Val));   }
#line 1846 "grammar.cpp"
    break;

  case 49: /* ArgAST: VarTypeAST  */
#line 251 "grammar.y"
                                                                  {  (yyval.Arg) = new ast::ArgAST((yyvsp[0].VarType));   }
#line 1852 "grammar.cpp"
    break;

  case 50: /* BlockAST: LEFTBRACE StmtsAST RIGHTBRACE  */
#line 254 "grammar.y"
                                              {  (yyval.Block) = new ast::BlockAST((yyvsp[-1].Statements));   }
#line 1858 "grammar.cpp"
    break;

  case 51: /* StmtsAST: StmtsAST StmtAST  */
#line 257 "grammar.y"
                                                  {  (yyval.Statements) = (yyvsp[-1].Statements); 
                                             if ((yyvsp[0].Statement) != NULL) 
										       (yyval.Statements)->push_back((yyvsp[0].Statement));   }
#line 1866 "grammar.cpp"
    break;

  case 52: /* StmtsAST: %empty  */
#line 260 "grammar.y"
                                                                              {  (yyval.Statements) = new ast::StmtsAST();   }
#line 1872 "grammar.cpp"
    break;

  case 53: /* StmtAST: ExprAST SEMICOLON  */
#line 263 "grammar.y"
                                                  {  (yyval.Statement) = (yyvsp[-1].Expr);   }
#line 1878 "grammar.cpp"
    break;

  case 54: /* StmtAST: IfStmtAST  */
#line 264 "grammar.y"
                                                                  {  (yyval.Statement) = (yyvsp[0].IfStatement);   }
#line 1884 "grammar.cpp"
    break;

  case 55: /* StmtAST: ForStmtAST  */
#line 265 "grammar.y"
                                                          {  (yyval.Statement) = (yyvsp[0].ForStatement);   }
#line 1890 "grammar.cpp"
    break;

  case 56: /* StmtAST: WhileStmtAST  */
#line 266 "grammar.y"
                                                          {  (yyval.Statement) = (yyvsp[0].WhileStatement);   }
#line 1896 "grammar.cpp"
    break;

  case 57: /* StmtAST: SwitchStmtAST  */
#line 267 "grammar.y"
                                                          {  (yyval.Statement) = (yyvsp[0].SwitchStatement);   }
#line 1902 "grammar.cpp"
    break;

  case 58: /* StmtAST: BreakStmtAST  */
#line 268 "grammar.y"
                                                          {  (yyval.Statement) = (yyvsp[0].BreakStatement);   }
#line 1908 "grammar.cpp"
    break;

  case 59: /* StmtAST: ContinueStmtAST  */
#line 269 "grammar.y"
                                                          {  (yyval.Statement) = (yyvsp[0].ContinueStatement);   }
#line 1914 "grammar.cpp"
    break;

  case 60: /* StmtAST: ReturnStmtAST  */
#line 270 "grammar.y"
                                                          {  (yyval.Statement) = (yyvsp[0].ReturnStatement);   }
#line 1920 "grammar.cpp"
    break;

  case 61: /* StmtAST: BlockAST  */
#line 271 "grammar.y"
                                                                  {  (yyval.Statement) = (yyvsp[0].Block);   }
#line 1926 "grammar.cpp"
    break;

  case 62: /* StmtAST: VarDeclAST  */
#line 272 "grammar.y"
                                                          {  (yyval.Statement) = (yyvsp[0].VarDecl);   }
#line 1932 "grammar.cpp"
    break;

  case 63: /* StmtAST: SEMICOLON  */
#line 273 "grammar.y"
                                                                  {  (yyval.Statement) = NULL;   }
#line 1938 "grammar.cpp"
    break;

  case 64: /* IfStmtAST: IF LEFTPAREN ExprAST RIGHTPAREN StmtAST ELSE StmtAST  */
#line 276 "grammar.y"
                                                                        {  (yyval.IfStatement) = new ast::IfStmtAST((yyvsp[-4].Expr), (yyvsp[-2].Statement), (yyvsp[0].Statement));   }
#line 1944 "grammar.cpp"
    break;

  case 65: /* IfStmtAST: IF LEFTPAREN ExprAST RIGHTPAREN StmtAST  */
#line 277 "grammar.y"
                                                                                    {  (yyval.IfStatement) = new ast::IfStmtAST((yyvsp[-2].Expr), (yyvsp[0].Statement));   }
#line 1950 "grammar.cpp"
    break;

  case 66: /* ForStmtAST: FOR LEFTPAREN ExprAST SEMICOLON ExprAST SEMICOLON ExprAST RIGHTPAREN StmtAST  */
#line 280 "grammar.y"
                                                                                                {  (yyval.ForStatement) = new ast::ForStmtAST((yyvsp[-6].Expr), (yyvsp[-4].Expr), (yyvsp[-2].Expr), (yyvsp[0].Statement));   }
#line 1956 "grammar.cpp"
    break;

  case 67: /* ForStmtAST: FOR LEFTPAREN VarDeclAST ExprAST SEMICOLON ExprAST RIGHTPAREN StmtAST  */
#line 281 "grammar.y"
                                                                                    {  (yyval.ForStatement) = new ast::ForStmtAST((yyvsp[-5].VarDecl), (yyvsp[-4].Expr), (yyvsp[-2].Expr), (yyvsp[0].Statement));   }
#line 1962 "grammar.cpp"
    break;

  case 68: /* WhileStmtAST: WHILE LEFTPAREN ExprAST RIGHTPAREN StmtAST  */
#line 284 "grammar.y"
                                                         {  (yyval.WhileStatement) = new ast::WhileStmtAST((yyvsp[-2].Expr), (yyvsp[0].Statement));   }
#line 1968 "grammar.cpp"
    break;

  case 69: /* SwitchStmtAST: SWITCH LEFTPAREN ExprAST RIGHTPAREN LEFTBRACE CaseList RIGHTBRACE  */
#line 287 "grammar.y"
                                                                                 {  (yyval.SwitchStatement) = new ast::SwitchStmtAST((yyvsp[-4].Expr), (yyvsp[-1].CaseList));   }
#line 1974 "grammar.cpp"
    break;

  case 70: /* CaseList: CaseList CaseStmAST  */
#line 290 "grammar.y"
                                    {  (yyval.CaseList) = (yyvsp[-1].CaseList); 
                                   (yyval.CaseList)->push_back((yyvsp[0].CaseStatement));   }
#line 1981 "grammar.cpp"
    break;

  case 71: /* CaseList: %empty  */
#line 292 "grammar.y"
                                                            {  (yyval.CaseList) = new ast::CaseList();   }
#line 1987 "grammar.cpp"
    break;

  case 72: /* CaseStmAST: CASE ExprAST COLON StmtsAST  */
#line 295 "grammar.y"
                                            {  (yyval.CaseStatement) = new ast::CaseStmAST((yyvsp[-2].Expr), (yyvsp[0].Statements));   }
#line 1993 "grammar.cpp"
    break;

  case 73: /* CaseStmAST: DEFAULT COLON StmtsAST  */
#line 296 "grammar.y"
                                                    {  (yyval.CaseStatement) = new ast::CaseStmAST(NULL, (yyvsp[0].Statements));   }
#line 1999 "grammar.cpp"
    break;

  case 74: /* ContinueStmtAST: CONTINUE SEMICOLON  */
#line 299 "grammar.y"
                                                {  (yyval.ContinueStatement) = new ast::ContinueStmtAST();   }
#line 2005 "grammar.cpp"
    break;

  case 75: /* BreakStmtAST: BREAK SEMICOLON  */
#line 302 "grammar.y"
                                                {  (yyval.BreakStatement) = new ast::BreakStmtAST();   }
#line 2011 "grammar.cpp"
    break;

  case 76: /* ReturnStmtAST: RETURN SEMICOLON  */
#line 305 "grammar.y"
                                                {  (yyval.ReturnStatement) = new ast::ReturnStmtAST();   }
#line 2017 "grammar.cpp"
    break;

  case 77: /* ReturnStmtAST: RETURN ExprAST SEMICOLON  */
#line 306 "grammar.y"
                                                        {  (yyval.ReturnStatement) = new ast::ReturnStmtAST((yyvsp[-1].Expr));   }
#line 2023 "grammar.cpp"
    break;

  case 78: /* ExprAST: ExprAST LEFTBRACKET ExprAST RIGHTBRACKET  */
#line 309 "grammar.y"
                                                                        {  (yyval.Expr) = new ast::SubscriptAST((yyvsp[-3].Expr), (yyvsp[-1].Expr));   }
#line 2029 "grammar.cpp"
    break;

  case 79: /* ExprAST: SIZEOF LEFTPAREN IDENTIFIER RIGHTPAREN  */
#line 310 "grammar.y"
                                                                                {  (yyval.Expr) = new ast::SizeOfAST(*(yyvsp[-1].string_Val));   }
#line 2035 "grammar.cpp"
    break;

  case 80: /* ExprAST: SIZEOF LEFTPAREN ExprAST RIGHTPAREN  */
#line 311 "grammar.y"
                                                                                {  (yyval.Expr) = new ast::SizeOfAST((yyvsp[-1].Expr));   }
#line 2041 "grammar.cpp"
    break;

  case 81: /* ExprAST: SIZEOF LEFTPAREN VarTypeAST RIGHTPAREN  */
#line 312 "grammar.y"
                                                                                {  (yyval.Expr) = new ast::SizeOfAST((yyvsp[-1].VarType));   }
#line 2047 "grammar.cpp"
    break;

  case 82: /* ExprAST: IDENTIFIER LEFTPAREN ExprList RIGHTPAREN  */
#line 313 "grammar.y"
                                                                                {  (yyval.Expr) = new ast::FunctionCallAST(*(yyvsp[-3].string_Val), (yyvsp[-1].ExprList));   }
#line 2053 "grammar.cpp"
    break;

  case 83: /* ExprAST: ExprAST DOT IDENTIFIER  */
#line 314 "grammar.y"
                                                                                            {  (yyval.Expr) = new ast::StructReferenceAST((yyvsp[-2].Expr), *(yyvsp[0].string_Val));   }
#line 2059 "grammar.cpp"
    break;

  case 84: /* ExprAST: ExprAST ARW IDENTIFIER  */
#line 315 "grammar.y"
                                                                                            {  (yyval.Expr) = new ast::StructDereferenceAST((yyvsp[-2].Expr), *(yyvsp[0].string_Val));   }
#line 2065 "grammar.cpp"
    break;

  case 85: /* ExprAST: ADD ExprAST  */
#line 316 "grammar.y"
                                                                                        {  (yyval.Expr) = new ast::UnaryPlusAST((yyvsp[0].Expr));   }
#line 2071 "grammar.cpp"
    break;

  case 86: /* ExprAST: SUB ExprAST  */
#line 317 "grammar.y"
                                                                                        {  (yyval.Expr) = new ast::UnaryMinusAST((yyvsp[0].Expr));   }
#line 2077 "grammar.cpp"
    break;

  case 87: /* ExprAST: LEFTPAREN VarTypeAST RIGHTPAREN ExprAST  */
#line 318 "grammar.y"
                                                                                {  (yyval.Expr) = new ast::TypeCastAST((yyvsp[-2].VarType), (yyvsp[0].Expr));   }
#line 2083 "grammar.cpp"
    break;

  case 88: /* ExprAST: DOUBLEADD ExprAST  */
#line 319 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::PrefixIncAST((yyvsp[0].Expr));   }
#line 2089 "grammar.cpp"
    break;

  case 89: /* ExprAST: ExprAST DOUBLEADD  */
#line 320 "grammar.y"
                                                                                        {  (yyval.Expr) = new ast::PostfixIncAST((yyvsp[-1].Expr));   }
#line 2095 "grammar.cpp"
    break;

  case 90: /* ExprAST: DOUBLESUB ExprAST  */
#line 321 "grammar.y"
                                                                                        {  (yyval.Expr) = new ast::PrefixDecAST((yyvsp[0].Expr));   }
#line 2101 "grammar.cpp"
    break;

  case 91: /* ExprAST: ExprAST DOUBLESUB  */
#line 322 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::PostfixDecAST((yyvsp[-1].Expr));   }
#line 2107 "grammar.cpp"
    break;

  case 92: /* ExprAST: MUL ExprAST  */
#line 323 "grammar.y"
                                                                                        {  (yyval.Expr) = new ast::IndirectionAST((yyvsp[0].Expr));   }
#line 2113 "grammar.cpp"
    break;

  case 93: /* ExprAST: NOT ExprAST  */
#line 324 "grammar.y"
                                                                                                    {  (yyval.Expr) = new ast::LogicNotAST((yyvsp[0].Expr));   }
#line 2119 "grammar.cpp"
    break;

  case 94: /* ExprAST: ExprAST DIV ExprAST  */
#line 325 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::DivAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2125 "grammar.cpp"
    break;

  case 95: /* ExprAST: ExprAST MUL ExprAST  */
#line 326 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::MulAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2131 "grammar.cpp"
    break;

  case 96: /* ExprAST: ExprAST MOD ExprAST  */
#line 327 "grammar.y"
                                                                                            {  (yyval.Expr) = new ast::ModuloAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2137 "grammar.cpp"
    break;

  case 97: /* ExprAST: ExprAST ADD ExprAST  */
#line 328 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::AddAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2143 "grammar.cpp"
    break;

  case 98: /* ExprAST: ExprAST SUB ExprAST  */
#line 329 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::SubAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2149 "grammar.cpp"
    break;

  case 99: /* ExprAST: ExprAST SHIFTL ExprAST  */
#line 330 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::LeftShiftAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2155 "grammar.cpp"
    break;

  case 100: /* ExprAST: ExprAST SHIFTR ExprAST  */
#line 331 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::RightShiftAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2161 "grammar.cpp"
    break;

  case 101: /* ExprAST: ExprAST GREATER ExprAST  */
#line 332 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::LogicGTAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2167 "grammar.cpp"
    break;

  case 102: /* ExprAST: ExprAST GORE ExprAST  */
#line 333 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::LogicGEAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2173 "grammar.cpp"
    break;

  case 103: /* ExprAST: ExprAST LESSTHAN ExprAST  */
#line 334 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::LogicLTAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2179 "grammar.cpp"
    break;

  case 104: /* ExprAST: ExprAST LORE ExprAST  */
#line 335 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::LogicLEAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2185 "grammar.cpp"
    break;

  case 105: /* ExprAST: ExprAST EQUAL ExprAST  */
#line 336 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::LogicEQAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2191 "grammar.cpp"
    break;

  case 106: /* ExprAST: ExprAST NOEQUAL ExprAST  */
#line 337 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::LogicNEQAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2197 "grammar.cpp"
    break;

  case 107: /* ExprAST: ExprAST AND ExprAST  */
#line 338 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::LogicANDAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2203 "grammar.cpp"
    break;

  case 108: /* ExprAST: ExprAST OR ExprAST  */
#line 339 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::LogicORAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2209 "grammar.cpp"
    break;

  case 109: /* ExprAST: ExprAST ASSIGN ExprAST  */
#line 340 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::DirectAssignAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2215 "grammar.cpp"
    break;

  case 110: /* ExprAST: ExprAST DIVEQUAL ExprAST  */
#line 341 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::DivAssignAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2221 "grammar.cpp"
    break;

  case 111: /* ExprAST: ExprAST MULEQUAL ExprAST  */
#line 342 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::MulAssignAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2227 "grammar.cpp"
    break;

  case 112: /* ExprAST: ExprAST MODEQUAL ExprAST  */
#line 343 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::ModAssignAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2233 "grammar.cpp"
    break;

  case 113: /* ExprAST: ExprAST ADDEQUAL ExprAST  */
#line 344 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::AddAssignAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2239 "grammar.cpp"
    break;

  case 114: /* ExprAST: ExprAST SUBEQUAL ExprAST  */
#line 345 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::SubAssignAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2245 "grammar.cpp"
    break;

  case 115: /* ExprAST: LEFTPAREN ExprAST RIGHTPAREN  */
#line 346 "grammar.y"
                                                                                        {  (yyval.Expr) = (yyvsp[-1].Expr);   }
#line 2251 "grammar.cpp"
    break;

  case 116: /* ExprAST: IDENTIFIER  */
#line 347 "grammar.y"
                                                                                                {  (yyval.Expr) = new ast::VariableAST(*(yyvsp[0].string_Val));   }
#line 2257 "grammar.cpp"
    break;

  case 117: /* ExprAST: ConstantAST  */
#line 348 "grammar.y"
                                                                                                    {  (yyval.Expr) = (yyvsp[0].Constant);   }
#line 2263 "grammar.cpp"
    break;

  case 118: /* ExprAST: ExprAST COMMA ExprAST  */
#line 349 "grammar.y"
                                                                                            {  (yyval.Expr) = new ast::CommaExprAST((yyvsp[-2].Expr), (yyvsp[0].Expr));   }
#line 2269 "grammar.cpp"
    break;

  case 119: /* ExprList: _ExprList COMMA ExprAST  */
#line 352 "grammar.y"
                                                                        {  (yyval.ExprList) = (yyvsp[-2].ExprList); 
                                                       (yyval.ExprList)->push_back((yyvsp[0].Expr));   }
#line 2276 "grammar.cpp"
    break;

  case 120: /* ExprList: ExprAST  */
#line 354 "grammar.y"
                                                                        {  (yyval.ExprList) = new ast::ExprList(); 
			                                           (yyval.ExprList)->push_back((yyvsp[0].Expr));   }
#line 2283 "grammar.cpp"
    break;

  case 121: /* ExprList: %empty  */
#line 356 "grammar.y"
                                                                                                        {  (yyval.ExprList) = new ast::ExprList();   }
#line 2289 "grammar.cpp"
    break;

  case 122: /* _ExprList: _ExprList COMMA ExprAST  */
#line 359 "grammar.y"
                                                                        {  (yyval.ExprList) = (yyvsp[-2].ExprList); 
                                                       (yyval.ExprList)->push_back((yyvsp[0].Expr));   }
#line 2296 "grammar.cpp"
    break;

  case 123: /* _ExprList: ExprAST  */
#line 361 "grammar.y"
                                                                        {  (yyval.ExprList) = new ast::ExprList(); 
			                                           (yyval.ExprList)->push_back((yyvsp[0].Expr));   }
#line 2303 "grammar.cpp"
    break;

  case 124: /* ConstantAST: TRUE  */
#line 365 "grammar.y"
                                        {  (yyval.Constant) =  new ast::ConstantAST(true);   }
#line 2309 "grammar.cpp"
    break;

  case 125: /* ConstantAST: FALSE  */
#line 366 "grammar.y"
                                                {  (yyval.Constant) =  new ast::ConstantAST(false);   }
#line 2315 "grammar.cpp"
    break;

  case 126: /* ConstantAST: CHARACTER  */
#line 367 "grammar.y"
                                                {  (yyval.Constant) =  new ast::ConstantAST((yyvsp[0].char_Val));   }
#line 2321 "grammar.cpp"
    break;

  case 127: /* ConstantAST: INTEGER  */
#line 368 "grammar.y"
                                                {  (yyval.Constant) =  new ast::ConstantAST((yyvsp[0].int_Val));   }
#line 2327 "grammar.cpp"
    break;

  case 128: /* ConstantAST: REAL  */
#line 369 "grammar.y"
                                                {  (yyval.Constant) =  new ast::ConstantAST((yyvsp[0].double_Val));   }
#line 2333 "grammar.cpp"
    break;

  case 129: /* ConstantAST: STRING  */
#line 370 "grammar.y"
                                                {  (yyval.Constant) =  new ast::GlobalStringAST(*(yyvsp[0].str_Val));   }
#line 2339 "grammar.cpp"
    break;


#line 2343 "grammar.cpp"

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

#line 372 "grammar.y"
