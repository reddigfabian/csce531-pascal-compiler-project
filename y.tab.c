/* A Bison parser, made by GNU Bison 3.0.2.  */

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 47 "gram.y" /* yacc.c:339  */


#include <stdlib.h>
#include "tree.h"
#include "types.h" //added this for use of TLIST
/* Cause the `yydebug' variable to be defined.  */
#define YYDEBUG 1

void set_yydebug(int);
void yyerror(const char *);

int myDebugPart1 = 0;
int myDebugPart2 = 1;
int myDump = 0;
int block;
INDEX_LIST rootOfUnRP;

/* Like YYERROR but do call yyerror */
#define YYERROR1 { yyerror ("syntax error"); YYERROR; }

#line 87 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
    LEX_ID = 258,
    LEX_ARRAY = 259,
    LEX_BEGIN = 260,
    LEX_CASE = 261,
    LEX_CONST = 262,
    LEX_DO = 263,
    LEX_DOWNTO = 264,
    LEX_END = 265,
    LEX_FILE = 266,
    LEX_FOR = 267,
    LEX_FUNCTION = 268,
    LEX_GOTO = 269,
    LEX_IF = 270,
    LEX_LABEL = 271,
    LEX_NIL = 272,
    LEX_OF = 273,
    LEX_PACKED = 274,
    LEX_PROCEDURE = 275,
    LEX_PROGRAM = 276,
    LEX_RECORD = 277,
    LEX_REPEAT = 278,
    LEX_SET = 279,
    LEX_THEN = 280,
    LEX_TO = 281,
    LEX_TYPE = 282,
    LEX_UNTIL = 283,
    LEX_VAR = 284,
    LEX_WHILE = 285,
    LEX_WITH = 286,
    LEX_FORWARD = 287,
    pp_SIN = 288,
    pp_COS = 289,
    pp_EXP = 290,
    pp_LN = 291,
    pp_SQRT = 292,
    pp_ARCTAN = 293,
    rr_POW = 294,
    rr_EXPON = 295,
    r_WRITE = 296,
    r_READ = 297,
    r_INITFDR = 298,
    r_LAZYTRYGET = 299,
    r_LAZYGET = 300,
    r_LAZYUNGET = 301,
    r_POW = 302,
    r_EXPON = 303,
    z_ABS = 304,
    z_ARCTAN = 305,
    z_COS = 306,
    z_EXP = 307,
    z_LN = 308,
    z_SIN = 309,
    z_SQRT = 310,
    z_POW = 311,
    z_EXPON = 312,
    set_card = 313,
    set_isempty = 314,
    set_equal = 315,
    set_le = 316,
    set_less = 317,
    set_in = 318,
    set_clear = 319,
    set_include = 320,
    set_exclude = 321,
    set_include_range = 322,
    set_copy = 323,
    set_intersection = 324,
    set_union = 325,
    set_diff = 326,
    set_symdiff = 327,
    p_DONEFDR = 328,
    gpc_IOCHECK = 329,
    gpc_RUNTIME_ERROR = 330,
    p_INPUT = 331,
    p_OUTPUT = 332,
    p_REWRITE = 333,
    p_RESET = 334,
    p_PUT = 335,
    p_GET = 336,
    p_WRITE = 337,
    p_READ = 338,
    p_WRITELN = 339,
    p_READLN = 340,
    p_PAGE = 341,
    p_NEW = 342,
    p_DISPOSE = 343,
    p_ABS = 344,
    p_SQR = 345,
    p_SIN = 346,
    p_COS = 347,
    p_EXP = 348,
    p_LN = 349,
    p_SQRT = 350,
    p_ARCTAN = 351,
    p_TRUNC = 352,
    p_ROUND = 353,
    p_PACK = 354,
    p_UNPACK = 355,
    p_ORD = 356,
    p_CHR = 357,
    p_SUCC = 358,
    p_PRED = 359,
    p_ODD = 360,
    p_EOF = 361,
    p_EOLN = 362,
    p_MAXINT = 363,
    p_TRUE = 364,
    p_FALSE = 365,
    bp_RANDOM = 366,
    bp_RANDOMIZE = 367,
    BREAK = 368,
    CONTINUE = 369,
    RETURN_ = 370,
    RESULT = 371,
    EXIT = 372,
    FAIL = 373,
    p_CLOSE = 374,
    CONJUGATE = 375,
    p_DEFINESIZE = 376,
    SIZEOF = 377,
    BITSIZEOF = 378,
    ALIGNOF = 379,
    TYPEOF = 380,
    gpc_RETURNADDRESS = 381,
    gpc_FRAMEADDRESS = 382,
    LEX_LABEL_ADDR = 383,
    LEX_INTCONST = 384,
    LEX_STRCONST = 385,
    LEX_REALCONST = 386,
    LEX_RANGE = 387,
    LEX_ELLIPSIS = 388,
    LEX_ASSIGN = 389,
    LEX_IN = 390,
    LEX_NE = 391,
    LEX_GE = 392,
    LEX_LE = 393,
    LEX_OR = 394,
    LEX_OR_ELSE = 395,
    LEX_CEIL_PLUS = 396,
    LEX_CEIL_MINUS = 397,
    LEX_FLOOR_PLUS = 398,
    LEX_FLOOR_MINUS = 399,
    LEX_DIV = 400,
    LEX_MOD = 401,
    LEX_AND = 402,
    LEX_AND_THEN = 403,
    LEX_SHL = 404,
    LEX_SHR = 405,
    LEX_XOR = 406,
    LEX_CEIL_MULT = 407,
    LEX_CEIL_DIV = 408,
    LEX_FLOOR_MULT = 409,
    LEX_FLOOR_DIV = 410,
    LEX_POW = 411,
    LEX_POWER = 412,
    LEX_IS = 413,
    LEX_AS = 414,
    LEX_NOT = 415,
    LEX_EXTERNAL = 416,
    p_MARK = 417,
    p_RELEASE = 418,
    p_UPDATE = 419,
    p_GETTIMESTAMP = 420,
    p_UNBIND = 421,
    p_EXTEND = 422,
    bp_APPEND = 423,
    p_BIND = 424,
    p_SEEKREAD = 425,
    p_SEEKWRITE = 426,
    p_SEEKUPDATE = 427,
    LEX_SYMDIFF = 428,
    p_ARG = 429,
    p_CARD = 430,
    p_EMPTY = 431,
    p_POSITION = 432,
    p_LASTPOSITION = 433,
    p_LENGTH = 434,
    p_TRIM = 435,
    p_BINDING = 436,
    p_DATE = 437,
    p_TIME = 438,
    LEX_RENAME = 439,
    LEX_IMPORT = 440,
    LEX_USES = 441,
    LEX_QUALIFIED = 442,
    LEX_ONLY = 443,
    prec_if = 444,
    LEX_ELSE = 445,
    lower_than_error = 446
  };
#endif
/* Tokens.  */
#define LEX_ID 258
#define LEX_ARRAY 259
#define LEX_BEGIN 260
#define LEX_CASE 261
#define LEX_CONST 262
#define LEX_DO 263
#define LEX_DOWNTO 264
#define LEX_END 265
#define LEX_FILE 266
#define LEX_FOR 267
#define LEX_FUNCTION 268
#define LEX_GOTO 269
#define LEX_IF 270
#define LEX_LABEL 271
#define LEX_NIL 272
#define LEX_OF 273
#define LEX_PACKED 274
#define LEX_PROCEDURE 275
#define LEX_PROGRAM 276
#define LEX_RECORD 277
#define LEX_REPEAT 278
#define LEX_SET 279
#define LEX_THEN 280
#define LEX_TO 281
#define LEX_TYPE 282
#define LEX_UNTIL 283
#define LEX_VAR 284
#define LEX_WHILE 285
#define LEX_WITH 286
#define LEX_FORWARD 287
#define pp_SIN 288
#define pp_COS 289
#define pp_EXP 290
#define pp_LN 291
#define pp_SQRT 292
#define pp_ARCTAN 293
#define rr_POW 294
#define rr_EXPON 295
#define r_WRITE 296
#define r_READ 297
#define r_INITFDR 298
#define r_LAZYTRYGET 299
#define r_LAZYGET 300
#define r_LAZYUNGET 301
#define r_POW 302
#define r_EXPON 303
#define z_ABS 304
#define z_ARCTAN 305
#define z_COS 306
#define z_EXP 307
#define z_LN 308
#define z_SIN 309
#define z_SQRT 310
#define z_POW 311
#define z_EXPON 312
#define set_card 313
#define set_isempty 314
#define set_equal 315
#define set_le 316
#define set_less 317
#define set_in 318
#define set_clear 319
#define set_include 320
#define set_exclude 321
#define set_include_range 322
#define set_copy 323
#define set_intersection 324
#define set_union 325
#define set_diff 326
#define set_symdiff 327
#define p_DONEFDR 328
#define gpc_IOCHECK 329
#define gpc_RUNTIME_ERROR 330
#define p_INPUT 331
#define p_OUTPUT 332
#define p_REWRITE 333
#define p_RESET 334
#define p_PUT 335
#define p_GET 336
#define p_WRITE 337
#define p_READ 338
#define p_WRITELN 339
#define p_READLN 340
#define p_PAGE 341
#define p_NEW 342
#define p_DISPOSE 343
#define p_ABS 344
#define p_SQR 345
#define p_SIN 346
#define p_COS 347
#define p_EXP 348
#define p_LN 349
#define p_SQRT 350
#define p_ARCTAN 351
#define p_TRUNC 352
#define p_ROUND 353
#define p_PACK 354
#define p_UNPACK 355
#define p_ORD 356
#define p_CHR 357
#define p_SUCC 358
#define p_PRED 359
#define p_ODD 360
#define p_EOF 361
#define p_EOLN 362
#define p_MAXINT 363
#define p_TRUE 364
#define p_FALSE 365
#define bp_RANDOM 366
#define bp_RANDOMIZE 367
#define BREAK 368
#define CONTINUE 369
#define RETURN_ 370
#define RESULT 371
#define EXIT 372
#define FAIL 373
#define p_CLOSE 374
#define CONJUGATE 375
#define p_DEFINESIZE 376
#define SIZEOF 377
#define BITSIZEOF 378
#define ALIGNOF 379
#define TYPEOF 380
#define gpc_RETURNADDRESS 381
#define gpc_FRAMEADDRESS 382
#define LEX_LABEL_ADDR 383
#define LEX_INTCONST 384
#define LEX_STRCONST 385
#define LEX_REALCONST 386
#define LEX_RANGE 387
#define LEX_ELLIPSIS 388
#define LEX_ASSIGN 389
#define LEX_IN 390
#define LEX_NE 391
#define LEX_GE 392
#define LEX_LE 393
#define LEX_OR 394
#define LEX_OR_ELSE 395
#define LEX_CEIL_PLUS 396
#define LEX_CEIL_MINUS 397
#define LEX_FLOOR_PLUS 398
#define LEX_FLOOR_MINUS 399
#define LEX_DIV 400
#define LEX_MOD 401
#define LEX_AND 402
#define LEX_AND_THEN 403
#define LEX_SHL 404
#define LEX_SHR 405
#define LEX_XOR 406
#define LEX_CEIL_MULT 407
#define LEX_CEIL_DIV 408
#define LEX_FLOOR_MULT 409
#define LEX_FLOOR_DIV 410
#define LEX_POW 411
#define LEX_POWER 412
#define LEX_IS 413
#define LEX_AS 414
#define LEX_NOT 415
#define LEX_EXTERNAL 416
#define p_MARK 417
#define p_RELEASE 418
#define p_UPDATE 419
#define p_GETTIMESTAMP 420
#define p_UNBIND 421
#define p_EXTEND 422
#define bp_APPEND 423
#define p_BIND 424
#define p_SEEKREAD 425
#define p_SEEKWRITE 426
#define p_SEEKUPDATE 427
#define LEX_SYMDIFF 428
#define p_ARG 429
#define p_CARD 430
#define p_EMPTY 431
#define p_POSITION 432
#define p_LASTPOSITION 433
#define p_LENGTH 434
#define p_TRIM 435
#define p_BINDING 436
#define p_DATE 437
#define p_TIME 438
#define LEX_RENAME 439
#define LEX_IMPORT 440
#define LEX_USES 441
#define LEX_QUALIFIED 442
#define LEX_ONLY 443
#define prec_if 444
#define LEX_ELSE 445
#define lower_than_error 446

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 73 "gram.y" /* yacc.c:355  */

    char *        y_string;
    int	          y_cint;
    long          y_int;
    double        y_real;

    float         y_single;
    unsigned char y_char;
    signed char   y_bool;
    ST_ID         y_ST_ID;
    LD            y_listOfIDs;
    TYPE          y_type;
    INDEX_LIST    y_index_list;
    TN            y_TN;

#line 525 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 540 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1682

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  209
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  137
/* YYNRULES -- Number of rules.  */
#define YYNRULES  368
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  550

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   446

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     200,   201,   151,     3,   202,     4,   199,   150,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   205,   208,
     137,   138,   139,     2,   204,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   206,     2,   207,   203,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   189,   193,   196,   198,   202,   203,   207,
     211,   215,   219,   221,   222,   223,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   239,
     240,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   253,   254,   256,   257,   258,   259,   260,   262,   263,
     264,   265,   266,   267,   268,   268,   269,   272,   274,   277,
     279,   283,   284,   288,   289,   290,   296,   300,   301,   305,
     309,   310,   311,   312,   316,   317,   321,   322,   326,   327,
     331,   332,   336,   337,   338,   342,   343,   347,   381,   382,
     386,   404,   419,   420,   421,   422,   426,   427,   431,   435,
     436,   440,   444,   455,   459,   460,   464,   482,   486,   487,
     513,   514,   518,   519,   523,   524,   525,   526,   530,   531,
     532,   538,   553,   554,   559,   560,   566,   570,   573,   575,
     576,   577,   581,   582,   586,   590,   594,   595,   599,   600,
     604,   605,   609,   610,   614,   618,   619,   623,   624,   632,
     638,   639,   643,   712,   713,   717,   718,   722,   723,   727,
     728,   732,   733,   746,   748,   752,   753,   757,   758,   765,
     769,   773,   774,   778,   779,   783,   784,   785,   786,   790,
     794,   795,   799,   803,   804,   808,   812,   813,   817,   821,
     822,   826,   827,   831,   835,   836,   840,   841,   842,   846,
     850,   854,   858,   859,   863,   864,   865,   866,   870,   875,
     877,   881,   882,   886,   892,   896,   900,   901,   904,   906,
     910,   911,   912,   913,   914,   915,   916,   917,   918,   921,
     923,   927,   928,   932,   933,   934,   939,   940,   941,   942,
     943,   944,   945,   946,   950,   951,   952,   953,   954,   955,
     956,   957,   958,   959,   960,   961,   962,   963,   964,   965,
     966,   970,   971,   972,   976,   977,   978,   979,   983,   987,
     991,   992,   996,   997,  1001,  1002,  1008,  1012,  1016,  1017,
    1018,  1022,  1023,  1024,  1025,  1026,  1030,  1031,  1032,  1036,
    1037,  1041,  1042,  1043,  1044,  1048,  1049,  1053,  1054,  1055,
    1056,  1057,  1058,  1062,  1066,  1067,  1071,  1072,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1087,  1088,  1092,  1093,
    1097,  1098,  1102,  1103,  1104,  1107,  1109,  1113,  1114,  1118,
    1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,
    1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1138,
    1139,  1140,  1144,  1145,  1149,  1150,  1151,  1152,  1153,  1154,
    1158,  1159,  1160,  1161,  1165,  1166,  1170,  1173,  1175
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'+'", "'-'", "LEX_ID", "LEX_ARRAY",
  "LEX_BEGIN", "LEX_CASE", "LEX_CONST", "LEX_DO", "LEX_DOWNTO", "LEX_END",
  "LEX_FILE", "LEX_FOR", "LEX_FUNCTION", "LEX_GOTO", "LEX_IF", "LEX_LABEL",
  "LEX_NIL", "LEX_OF", "LEX_PACKED", "LEX_PROCEDURE", "LEX_PROGRAM",
  "LEX_RECORD", "LEX_REPEAT", "LEX_SET", "LEX_THEN", "LEX_TO", "LEX_TYPE",
  "LEX_UNTIL", "LEX_VAR", "LEX_WHILE", "LEX_WITH", "LEX_FORWARD", "pp_SIN",
  "pp_COS", "pp_EXP", "pp_LN", "pp_SQRT", "pp_ARCTAN", "rr_POW",
  "rr_EXPON", "r_WRITE", "r_READ", "r_INITFDR", "r_LAZYTRYGET",
  "r_LAZYGET", "r_LAZYUNGET", "r_POW", "r_EXPON", "z_ABS", "z_ARCTAN",
  "z_COS", "z_EXP", "z_LN", "z_SIN", "z_SQRT", "z_POW", "z_EXPON",
  "set_card", "set_isempty", "set_equal", "set_le", "set_less", "set_in",
  "set_clear", "set_include", "set_exclude", "set_include_range",
  "set_copy", "set_intersection", "set_union", "set_diff", "set_symdiff",
  "p_DONEFDR", "gpc_IOCHECK", "gpc_RUNTIME_ERROR", "p_INPUT", "p_OUTPUT",
  "p_REWRITE", "p_RESET", "p_PUT", "p_GET", "p_WRITE", "p_READ",
  "p_WRITELN", "p_READLN", "p_PAGE", "p_NEW", "p_DISPOSE", "p_ABS",
  "p_SQR", "p_SIN", "p_COS", "p_EXP", "p_LN", "p_SQRT", "p_ARCTAN",
  "p_TRUNC", "p_ROUND", "p_PACK", "p_UNPACK", "p_ORD", "p_CHR", "p_SUCC",
  "p_PRED", "p_ODD", "p_EOF", "p_EOLN", "p_MAXINT", "p_TRUE", "p_FALSE",
  "bp_RANDOM", "bp_RANDOMIZE", "BREAK", "CONTINUE", "RETURN_", "RESULT",
  "EXIT", "FAIL", "p_CLOSE", "CONJUGATE", "p_DEFINESIZE", "SIZEOF",
  "BITSIZEOF", "ALIGNOF", "TYPEOF", "gpc_RETURNADDRESS",
  "gpc_FRAMEADDRESS", "LEX_LABEL_ADDR", "LEX_INTCONST", "LEX_STRCONST",
  "LEX_REALCONST", "LEX_RANGE", "LEX_ELLIPSIS", "LEX_ASSIGN", "'<'", "'='",
  "'>'", "LEX_IN", "LEX_NE", "LEX_GE", "LEX_LE", "LEX_OR", "LEX_OR_ELSE",
  "LEX_CEIL_PLUS", "LEX_CEIL_MINUS", "LEX_FLOOR_PLUS", "LEX_FLOOR_MINUS",
  "'/'", "'*'", "LEX_DIV", "LEX_MOD", "LEX_AND", "LEX_AND_THEN", "LEX_SHL",
  "LEX_SHR", "LEX_XOR", "LEX_CEIL_MULT", "LEX_CEIL_DIV", "LEX_FLOOR_MULT",
  "LEX_FLOOR_DIV", "LEX_POW", "LEX_POWER", "LEX_IS", "LEX_AS", "LEX_NOT",
  "LEX_EXTERNAL", "p_MARK", "p_RELEASE", "p_UPDATE", "p_GETTIMESTAMP",
  "p_UNBIND", "p_EXTEND", "bp_APPEND", "p_BIND", "p_SEEKREAD",
  "p_SEEKWRITE", "p_SEEKUPDATE", "LEX_SYMDIFF", "p_ARG", "p_CARD",
  "p_EMPTY", "p_POSITION", "p_LASTPOSITION", "p_LENGTH", "p_TRIM",
  "p_BINDING", "p_DATE", "p_TIME", "LEX_RENAME", "LEX_IMPORT", "LEX_USES",
  "LEX_QUALIFIED", "LEX_ONLY", "prec_if", "LEX_ELSE", "lower_than_error",
  "'.'", "'('", "')'", "','", "'^'", "'@'", "':'", "'['", "']'", "';'",
  "$accept", "pascal_program", "main_program_declaration",
  "program_heading", "optional_par_id_list", "id_list", "typename",
  "identifier", "new_identifier", "new_identifier_1", "$@1",
  "any_global_declaration_part", "any_declaration_part", "any_decl",
  "simple_decl", "constant_definition_part", "constant_definition_list",
  "constant_definition", "constant", "number", "unsigned_number", "sign",
  "constant_literal", "predefined_literal", "string",
  "type_definition_part", "type_definition_list", "type_definition",
  "type_denoter", "new_ordinal_type", "enumerated_type", "enum_list",
  "enumerator", "subrange_type", "new_pointer_type", "pointer_char",
  "pointer_domain_type", "new_procedural_type",
  "optional_procedural_type_formal_parameter_list",
  "procedural_type_formal_parameter_list",
  "procedural_type_formal_parameter", "new_structured_type", "array_type",
  "array_index_list", "ordinal_index_type", "set_type", "record_type",
  "record_field_list", "fixed_part", "record_section", "variant_part",
  "rest_of_variant", "variant_selector", "variant_type", "variant_list",
  "variant", "case_constant_list", "one_case_constant",
  "variable_declaration_part", "variable_declaration_list",
  "variable_declaration", "function_declaration", "function_heading",
  "directive_list", "directive", "functiontype",
  "optional_par_formal_parameter_list", "formal_parameter_list",
  "formal_parameter", "statement_part", "compound_statement",
  "statement_sequence", "statement", "structured_statement",
  "with_statement", "structured_variable_list", "structured_variable",
  "conditional_statement", "simple_if", "if_statement", "case_statement",
  "optional_semicolon_or_else_branch", "case_element_list", "case_element",
  "case_default", "repetitive_statement", "repeat_statement",
  "while_statement", "for_statement", "for_direction", "simple_statement",
  "empty_statement", "optional_par_actual_parameter_list",
  "actual_parameter_list", "actual_parameter",
  "assignment_or_call_statement",
  "variable_or_function_access_maybe_assignment", "rest_of_statement",
  "standard_procedure_statement", "optional_par_write_parameter_list",
  "write_actual_parameter_list", "write_actual_parameter",
  "rts_proc_onepar", "rts_proc_parlist", "statement_extensions",
  "return_statement", "break_statement", "continue_statement",
  "variable_access_or_typename", "index_expression_list",
  "index_expression_item", "static_expression", "boolean_expression",
  "expression", "simple_expression", "term", "signed_primary", "primary",
  "signed_factor", "factor", "address_operator",
  "variable_or_function_access",
  "variable_or_function_access_no_standard_function",
  "variable_or_function_access_no_id", "set_constructor",
  "set_constructor_element_list", "member_designator",
  "standard_functions", "optional_par_actual_parameter", "rts_fun_optpar",
  "rts_fun_onepar", "rts_fun_parlist", "relational_operator",
  "multiplying_operator", "adding_operator", "semi", "optional_semicolon", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    43,    45,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,    60,    61,    62,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
      47,    42,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,    46,
      40,    41,    44,    94,    64,    58,    91,    93,    59
};
# endif

#define YYPACT_NINF -473

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-473)))

#define YYTABLE_NINF -369

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      38,  1557,    72,  -151,  -121,  -473,  -473,  -473,  -473,  -473,
    -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,
    -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,
    -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,
    -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,   -82,
    -473,  -473,  -473,  -473,  -473,  -473,  1557,  -473,   102,   -19,
    -473,   873,  1557,  1557,  1557,  1557,  1557,  -473,  -473,  -473,
    -473,  -473,  -473,  -121,  -473,  -473,  -473,  1557,  -473,   627,
    1059,   627,   873,   627,  1059,  -473,  -473,  -473,  -473,  -473,
    -473,   -78,   -72,   -78,   -72,   -72,   -59,   -57,  -473,  -473,
    -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,
    -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,   627,
    -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,
    -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,
    -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,
    -473,   627,  -473,  -125,  -473,    -5,  -473,  -473,  -473,  -473,
     -50,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,
      17,  -473,   -45,   -38,  -473,  -473,  -473,  -473,  1059,   -83,
     -31,  -106,  -473,   -26,   -22,    -7,    57,  1557,  -473,     1,
       1,    69,  -121,  -473,  -119,  1557,  -473,   -20,  -473,  -473,
    -473,  -473,  -473,  -473,  -473,  -473,  -473,   627,   438,  -473,
    -473,   627,  -473,  -473,    77,   208,   136,   156,  -473,   158,
    -473,   673,   -83,  -473,  -473,   -96,   188,   461,   -12,   225,
       2,  -473,   -83,   627,  -473,   627,  -473,  -473,  -473,  -473,
    1117,   627,   461,   307,  -473,   873,   873,   627,  -473,   627,
     627,   -83,  1557,  -473,  -473,   627,  -473,   627,   627,  -473,
     627,   627,   627,  -473,  1353,    70,  -473,   815,  1557,   815,
    -473,  -473,  -473,   102,  -121,  -473,   627,  -473,  -473,  -473,
     381,  -101,  -473,  -473,  -473,   627,  -473,  -473,  -473,   627,
    -473,  -473,  -473,   627,  -473,  -473,   627,   627,   627,   627,
    -473,  -473,  -473,  -473,   627,   627,   673,   673,   248,  -473,
     627,   873,   627,   873,   873,  1059,    82,    95,  -473,   461,
     111,  -473,    76,    89,   114,   117,  -473,  -473,  -473,   461,
     137,   123,  -473,   -53,  -473,   414,   126,   138,   140,   129,
    -121,   461,  1557,  -100,  -152,  -473,   248,  -473,   203,   146,
     142,   142,  1401,   323,  1557,  -473,  -473,   210,  -473,  -473,
      33,  -473,  -473,  -473,  -473,  -473,  -473,  1245,  -473,  -473,
    -473,  -473,  -473,  -473,  -121,  -473,  -121,   -20,  -473,   627,
     627,  -473,   -76,  -473,  -154,  -473,   219,   136,   136,   156,
     156,   156,   156,  -473,  -473,  -473,  -473,  -473,  -473,   161,
    -473,  -473,  -473,  -473,  -473,   627,  -473,   627,  -473,   627,
    -473,  -473,   627,  -473,  -473,   627,  -473,   627,  -473,  -473,
    -473,  -473,  -473,   -70,   248,  -473,  1353,  -473,    48,  1509,
      70,  -473,  1001,   -34,   352,   157,  -473,  -473,   815,  -473,
     131,  -473,    25,  -473,  -473,  -473,  -473,  -473,  -473,  -473,
    -473,   461,  -473,   627,   873,  -473,    -2,   354,   873,   485,
    -473,   627,  -473,  -473,   627,   220,  -473,  -473,   133,  -473,
     461,   248,  -473,  -473,  -473,  -473,   -37,  -473,  1557,    39,
    -109,  -473,  -473,  -114,   234,   235,  -473,   166,  -473,   356,
    -473,   815,  -473,  1401,  -473,  -473,  -473,  1557,  -473,  -473,
    -473,  -473,  -121,  -473,  -473,  -473,    79,   627,  -473,  -473,
      48,   362,    52,   248,  -473,  1509,    48,   627,  -473,  -473,
    -473,  -473,   873,   461,  -473,   815,   248,  -473,  -473,  -473,
    -154,  -473,    67,  -473,  -473,  -473,  -473,   174,   485,  -473,
     184,  1401,  -473,  1401,   185,   187,   177,  -473,  -473,  -473
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,    12,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    27,    28,    13,    15,
      14,    48,    49,    50,    51,    52,    54,    53,    56,     5,
      11,     1,     2,   366,    57,    55,     0,     4,     0,     0,
       7,   208,     0,     0,     0,     0,     0,    58,    61,    63,
      64,    65,    62,     0,     3,   169,     6,     0,    10,     0,
       0,     0,   208,     0,     0,   309,   308,   244,   245,   236,
     237,   229,   209,   229,   209,   209,     0,     0,   329,   330,
     331,   332,   333,   334,   335,   336,   338,   339,   248,   249,
     341,   342,   352,   353,   343,   327,   328,   268,   269,   264,
     266,   267,   240,   254,   256,   255,   259,   260,   258,   257,
     238,   239,   241,   242,   243,   246,   247,   250,   251,   252,
     253,   337,   340,   344,   345,   346,   347,   348,   349,   350,
     351,     0,   303,   215,   175,     0,   171,   173,   176,   177,
     187,   183,   184,   178,   196,   197,   198,   174,   204,   205,
     218,   206,     0,     0,   207,   261,   263,   262,     0,     0,
     304,   217,   305,   325,     0,     0,     0,    66,    67,   163,
     163,     0,     0,    88,     0,   149,   150,    59,     8,    78,
      79,    82,    84,    83,    76,    85,    77,     0,     0,   306,
     299,     0,   298,    81,    80,     0,   280,   281,   286,   289,
     291,     0,   297,   307,   300,     0,     0,   277,     0,     0,
       0,   180,   182,     0,   222,     0,   224,   223,   225,   226,
       0,     0,   265,     0,   170,   208,   208,     0,   214,     0,
       0,   216,     0,   104,   105,     0,   312,     0,     0,   323,
       0,     0,     0,    68,     0,   161,   155,     0,    87,     0,
     151,   159,   160,     0,     0,   157,     0,   301,   295,   316,
     320,     0,   318,   290,    86,     0,   358,   357,   359,     0,
     354,   356,   355,     0,   365,   364,     0,     0,     0,     0,
     362,   363,   360,   361,     0,     0,     0,     0,     0,   302,
       0,   208,     0,   208,   208,     0,   233,     0,   231,   213,
       0,   211,    10,     0,   307,     0,   311,   172,   186,   219,
       0,     0,   310,     0,   272,   274,     0,     0,     0,     0,
       0,   276,     0,     0,     0,   165,     0,   156,     9,     0,
     110,   110,   128,     0,     0,    91,    70,     0,    72,    75,
       0,    73,    90,    92,    96,    97,    93,     0,    94,    95,
     118,   119,   120,    89,     0,    60,     0,   153,   296,     0,
       0,   317,     0,   145,   367,   191,   147,   279,   278,   284,
     285,   283,   282,   288,   287,   292,   293,     9,   294,     0,
     185,   199,   200,   179,   181,     0,   230,     0,   210,     0,
     315,   227,     0,   220,   221,     0,   313,     0,   314,   326,
     322,   324,    69,     0,     0,   164,     0,   162,     0,     0,
     161,   108,     0,     0,     0,   367,   132,   131,     0,   101,
       0,    99,     0,    71,    74,   106,   103,   107,   152,   154,
     158,   321,   319,     0,   208,   194,   366,     0,   208,     0,
     189,     0,   203,   202,     0,   234,   232,   212,     0,   273,
     275,     0,   167,   166,   125,   124,     0,   122,     0,   114,
       0,   112,   109,     9,    15,    14,   140,     0,   141,     0,
     139,     0,   127,     0,   129,   126,    98,     0,   102,   146,
     193,   188,   190,   195,   192,   148,     0,     0,   228,   168,
       0,     0,   117,     0,   111,     0,     0,     0,   134,   133,
     130,   100,   208,   235,   123,     0,     0,   115,   113,   138,
     367,   142,     0,   201,   121,   116,   135,     0,     0,   136,
       0,   128,   143,   128,     0,     0,   367,   144,   368,   137
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -473,  -473,  -473,  -473,  -473,   -51,  -286,   -55,     0,  -473,
    -473,  -473,  -473,   116,  -473,  -473,  -473,   205,   -52,  -473,
    -199,  -196,  -265,  -473,  -473,  -473,  -473,   127,  -236,  -391,
    -473,  -473,  -103,  -473,  -473,  -244,  -473,    29,    46,  -473,
    -117,  -473,  -473,  -473,  -110,  -473,  -473,  -429,  -473,   -92,
     -91,  -473,  -473,  -112,  -473,  -133,  -472,   -46,  -473,  -473,
     213,  -473,  -473,  -473,    32,   -18,   221,  -473,   -13,   143,
     -39,   -79,  -229,  -473,  -473,  -473,   100,  -473,  -473,  -473,
    -473,  -473,  -473,   -42,  -108,  -473,  -473,  -473,  -473,  -473,
    -473,  -473,   155,  -226,  -145,  -473,  -473,  -473,  -473,   327,
    -473,    14,  -473,  -473,  -473,  -473,  -473,  -473,  -473,  -473,
       9,  -253,   -75,   -24,  -243,   -14,  -153,  -473,   150,  -131,
     -35,   -48,  -473,   -40,  -473,  -473,    50,  -473,  -473,  -473,
    -473,  -473,  -473,  -473,  -473,    -4,  -396
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    57,   433,   355,   209,    60,    50,
      55,    58,   273,    67,    68,    69,   187,   188,   357,   358,
     210,   211,   212,   213,   214,    70,   192,   193,   362,   363,
     364,   440,   441,   365,   366,   256,   446,   368,   430,   480,
     481,   369,   370,   476,   477,   371,   372,   434,   435,   436,
     437,   536,   489,   490,   530,   531,   382,   383,    71,   195,
     196,    72,    73,   274,   275,   347,   265,   344,   345,    74,
     154,   155,   156,   157,   158,   230,   231,   159,   160,   161,
     162,   457,   384,   385,   458,   163,   164,   165,   166,   464,
     167,   168,   236,   320,   321,   169,   170,   248,   171,   234,
     317,   318,   172,   173,   174,   175,   176,   177,   323,   333,
     334,   386,   226,   319,   216,   217,   218,   219,   277,   220,
     221,   222,   180,   223,   224,   281,   282,   182,   259,   183,
     184,   185,   293,   305,   299,   245,   460
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    49,   361,   228,   361,    59,   153,   244,   229,   340,
    -368,   276,   314,   179,   271,   194,   327,   328,   312,    75,
     -10,   181,   398,   367,   331,   367,   178,   153,   199,   200,
      78,   336,   225,   374,   179,   339,   232,   475,    78,   494,
     310,   488,   181,   455,   201,   532,   387,   178,    52,   425,
     388,   199,   200,   348,   456,   215,    53,   227,   283,   227,
     427,     1,   186,   189,   190,   191,   532,   201,   359,   197,
     359,   360,    51,   360,  -306,  -306,   278,   198,  -306,  -306,
     276,  -306,   400,    77,   402,   403,   269,    53,   316,   522,
     309,   -12,   514,  -307,  -307,   242,   325,  -307,  -307,    53,
    -307,   380,    77,   252,   330,   424,   381,   253,   254,    61,
     255,    62,   544,   337,   545,   338,   252,    63,    56,   475,
     253,   254,   233,   255,    64,   488,   453,   243,   235,   454,
     251,    65,    77,    66,   539,   471,   202,   203,   472,   294,
     295,   240,   474,   241,   194,   278,   486,   246,   272,   415,
     549,   393,   394,   247,   416,   249,   204,   205,   206,   202,
     203,   444,   250,   361,   204,   510,   206,   361,    77,   257,
     511,   491,   462,   361,   258,   395,   396,   361,   260,   204,
     205,   206,    76,    77,   280,   509,   468,   186,   268,   463,
     153,   153,   179,   261,   367,   262,    53,   179,   179,  -368,
     324,   264,   495,    53,   315,   181,   181,   267,   505,   284,
     178,   178,   356,   343,   356,   311,   286,   287,   288,   289,
     290,   291,   292,   329,   474,   500,   361,   527,   285,   359,
     486,   335,   360,   359,    75,   313,   360,   401,   341,   359,
     535,    77,   360,   359,   513,   361,   360,   367,   354,   238,
     239,   361,   332,   397,    77,   518,   153,   526,   153,   153,
     361,   341,   316,   179,   467,   179,   179,   232,   191,   453,
     377,   181,   540,   181,   181,   346,   178,  -271,   178,   178,
     296,   367,   389,   390,   391,   392,   399,   405,   227,   534,
     410,   423,   359,   533,   297,   360,   406,   407,   286,   287,
     288,   289,   290,   291,   292,   443,   300,   301,   302,   303,
     304,   359,   408,   409,   360,  -270,   298,   359,   411,   412,
     360,   306,   307,   308,   414,   409,   359,   418,   409,   360,
     421,   409,   496,   497,   508,   409,   422,   -10,   413,   419,
     426,   420,   429,   438,   442,   286,   287,   288,   289,   290,
     291,   292,   428,   461,   439,   451,   280,   286,   287,   288,
     289,   290,   291,   292,   492,   456,   501,   445,   -84,   -83,
     448,   516,   449,   356,   541,   343,   517,   356,   479,   502,
     459,   465,   525,   356,   543,   548,   546,   356,   547,   375,
     498,   335,   263,   470,   521,   373,   447,   431,   528,   153,
     524,   519,   520,   153,   529,   542,   179,   499,   270,   450,
     179,   266,   482,   473,   181,   404,   376,   504,   181,   178,
     237,   466,   537,   178,   469,   507,   378,   512,     0,   341,
     452,   493,   487,     0,     0,   341,   356,   341,     0,     0,
     506,   199,   200,    78,   286,   287,   288,   289,   290,   291,
     292,     0,     0,     0,     0,   356,     0,   201,     0,     0,
       0,   356,     0,     0,   479,     0,     0,   153,     0,     0,
     356,     0,     0,     0,   179,     0,   515,     0,     0,     0,
       0,     0,   181,   523,     0,     0,     0,   178,   199,   200,
      78,     0,     0,   341,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,   201,     0,     0,     0,   326,     0,
       0,     0,     0,     0,   341,   379,    85,    86,   286,   287,
     288,   289,   290,   291,   292,     0,   538,    96,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   417,   202,
     203,   286,   287,   288,   289,   290,   291,   292,     0,     0,
       0,     0,     0,    85,    86,     0,     0,     0,     0,   204,
     205,   206,     0,     0,    96,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,   110,   111,
     112,   113,   114,   115,   116,     0,   202,   203,   286,   287,
     288,   289,   290,   291,   292,   207,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   205,   206,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
     199,   200,    78,     0,     0,     0,     0,     0,   151,     0,
       0,     0,   152,     0,   208,   279,   201,     0,     0,     0,
       0,     0,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,    78,     0,
       0,     0,   503,     0,     0,   151,     0,     0,     0,   152,
       0,   208,   201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
     110,   111,   112,   113,   114,   115,   116,     0,   202,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,     0,     0,     0,     0,     0,   204,   205,
     206,     0,    96,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,     0,   110,   111,   112,   113,
     114,   115,   116,     0,   202,   203,     0,     0,     0,     0,
       0,     0,     0,     0,   207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   204,   205,   206,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   199,   200,
     348,   349,     0,     0,     0,     0,     0,   151,     0,     0,
     350,   152,     0,   208,   201,     0,     0,   351,     0,   352,
     207,   353,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   151,     0,     0,     0,   152,    78,   208,
      61,    79,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   202,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   205,   206,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,   117,   118,
     119,     0,   120,   121,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   199,   200,   483,     0,     0,     0,
       0,     0,     0,     0,     0,   354,     0,   124,   253,   254,
     201,     0,     0,     0,     0,     0,     0,   125,     0,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    78,     0,     0,     0,     0,     0,
       0,     0,     0,   151,     0,     0,     0,   152,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,   484,   485,     0,     0,    41,    42,    43,    44,
      45,    46,   322,     0,     0,    47,    48,     0,     0,     0,
       0,     0,   204,   205,   206,     0,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
       0,   354,     0,     0,     0,     0,    96,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
     110,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       5,     0,     0,     0,     0,     0,     0,     0,     0,   151,
     350,     0,     0,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,     0,     0,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     5,     0,
      41,    42,    43,    44,    45,    46,     0,     0,     0,    47,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   342,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     0,   432,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,    41,    42,
      43,    44,    45,    46,     0,     0,     0,    47,    48,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     5,     0,    41,    42,    43,    44,
      45,    46,     0,     0,     0,    47,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     478,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     0,    41,    42,    43,    44,    45,    46,
       0,     0,     0,    47,    48,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,     0,    41,    42,    43,    44,    45,    46,     0,     0,
       0,    47,    48
};

static const yytype_int16 yycheck[] =
{
       4,     1,   267,    82,   269,    56,    61,    12,    83,   262,
      12,   207,    10,    61,    34,    66,   245,   246,    30,    58,
     134,    61,   308,   267,   250,   269,    61,    82,     3,     4,
       5,   257,    80,   269,    82,   261,    84,   428,     5,   435,
     136,   432,    82,   197,    19,   517,   289,    82,   199,   201,
     293,     3,     4,     5,   208,    79,   208,    81,   211,    83,
     346,    23,    62,    63,    64,    65,   538,    19,   267,    73,
     269,   267,     0,   269,   199,   200,   207,    77,   203,   204,
     276,   206,   311,   202,   313,   314,   205,   208,   233,    10,
     221,   205,   201,   199,   200,   119,   241,   203,   204,   208,
     206,   202,   202,   199,   249,   205,   207,   203,   204,     7,
     206,     9,   541,   258,   543,   260,   199,    15,   200,   510,
     203,   204,   200,   206,    22,   516,   202,   151,   200,   205,
     178,    29,   202,    31,   530,   205,   111,   112,   424,     3,
       4,   200,   428,   200,   195,   276,   432,   197,   168,   202,
     546,   304,   305,   136,   207,   200,   131,   132,   133,   111,
     112,   360,   200,   428,   131,   202,   133,   432,   202,   200,
     207,   205,    11,   438,   200,   306,   307,   442,   200,   131,
     132,   133,   201,   202,   208,   471,   412,   187,   192,    28,
     245,   246,   240,   200,   438,   138,   208,   245,   246,   201,
     240,   200,   438,   208,   202,   245,   246,   138,   461,   132,
     245,   246,   267,   264,   269,    27,   137,   138,   139,   140,
     141,   142,   143,   247,   510,   454,   491,   513,    20,   428,
     516,   255,   428,   432,   273,    10,   432,   312,   262,   438,
     526,   202,   438,   442,   205,   510,   442,   491,   200,    94,
      95,   516,   252,     5,   202,   491,   311,   205,   313,   314,
     525,   285,   407,   311,   409,   313,   314,   315,   268,   202,
     274,   311,   205,   313,   314,   205,   311,   201,   313,   314,
     144,   525,   296,   297,   298,   299,   310,   205,   312,   525,
     201,   342,   491,   522,   158,   491,   201,   202,   137,   138,
     139,   140,   141,   142,   143,   360,   150,   151,   152,   153,
     154,   510,   201,   202,   510,   201,   180,   516,   201,   202,
     516,   163,   164,   165,   201,   202,   525,   201,   202,   525,
     201,   202,   201,   202,   201,   202,   340,   134,   201,   201,
     344,   201,   200,    20,   134,   137,   138,   139,   140,   141,
     142,   143,   206,   134,   354,   379,   380,   137,   138,   139,
     140,   141,   142,   143,    12,   208,    12,   367,   134,   134,
     374,   205,   376,   428,   200,   426,    20,   432,   429,   458,
     384,   405,    20,   438,   200,   208,   201,   442,   201,   273,
     442,   415,   187,   417,   497,   268,   367,   351,   515,   454,
     510,   493,   493,   458,   516,   538,   454,   453,   195,   377,
     458,   190,   430,   426,   454,   315,   273,   459,   458,   454,
      93,   407,   530,   458,   415,   205,   276,   478,    -1,   453,
     380,   435,   432,    -1,    -1,   459,   491,   461,    -1,    -1,
     464,     3,     4,     5,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   510,    -1,    19,    -1,    -1,
      -1,   516,    -1,    -1,   515,    -1,    -1,   522,    -1,    -1,
     525,    -1,    -1,    -1,   522,    -1,   480,    -1,    -1,    -1,
      -1,    -1,   522,   507,    -1,    -1,    -1,   522,     3,     4,
       5,    -1,    -1,   517,    -1,    -1,    -1,   497,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,   538,   134,    78,    79,   137,   138,
     139,   140,   141,   142,   143,    -1,   530,    89,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   134,   111,
     112,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    89,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,    -1,   111,   112,   137,   138,
     139,   140,   141,   142,   143,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,    -1,   206,   207,    19,    -1,    -1,    -1,
      -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,     5,    -1,
      -1,    -1,   197,    -1,    -1,   200,    -1,    -1,    -1,   204,
      -1,   206,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      15,   204,    -1,   206,    19,    -1,    -1,    22,    -1,    24,
     167,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,     5,   206,
       7,     8,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,   115,   116,
     117,    -1,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,   144,   203,   204,
      19,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,
     157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,    -1,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,    -1,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,    -1,   115,   116,   117,   118,
     119,   120,     5,    -1,    -1,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,   200,    -1,    -1,    -1,    -1,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     5,    -1,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
     125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,    -1,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,   125,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     5,    -1,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,    -1,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,   125,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,    -1,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,   125
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    23,   210,   211,   212,     5,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   115,   116,   117,   118,   119,   120,   124,   125,   217,
     218,     0,   199,   208,   344,   219,   200,   213,   220,   214,
     217,     7,     9,    15,    22,    29,    31,   222,   223,   224,
     234,   267,   270,   271,   278,   279,   201,   202,     5,     8,
      14,    17,    25,    32,    33,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   115,   116,   117,
     119,   120,   121,   123,   144,   154,   156,   157,   158,   167,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   200,   204,   216,   279,   280,   281,   282,   283,   286,
     287,   288,   289,   294,   295,   296,   297,   299,   300,   304,
     305,   307,   311,   312,   313,   314,   315,   316,   329,   330,
     331,   332,   336,   338,   339,   340,   217,   225,   226,   217,
     217,   217,   235,   236,   214,   268,   269,   344,   217,     3,
       4,    19,   111,   112,   131,   132,   133,   167,   206,   216,
     229,   230,   231,   232,   233,   322,   323,   324,   325,   326,
     328,   329,   330,   332,   333,   330,   321,   322,   280,   321,
     284,   285,   330,   200,   308,   200,   301,   308,   301,   301,
     200,   200,   322,   322,    12,   344,   197,   136,   306,   200,
     200,   330,   199,   203,   204,   206,   244,   200,   200,   337,
     200,   200,   138,   226,   200,   275,   275,   138,   344,   205,
     269,    34,   168,   221,   272,   273,   230,   327,   328,   207,
     322,   334,   335,   325,   132,    20,   137,   138,   139,   140,
     141,   142,   143,   341,     3,     4,   144,   158,   180,   343,
     150,   151,   152,   153,   154,   342,   163,   164,   165,   328,
     136,    27,    30,    10,    10,   202,   303,   309,   310,   322,
     302,   303,     5,   317,   332,   303,   201,   281,   281,   322,
     303,   302,   217,   318,   319,   322,   302,   303,   303,   302,
     320,   322,    31,   214,   276,   277,   205,   274,     5,     6,
      15,    22,    24,    26,   200,   215,   216,   227,   228,   229,
     230,   231,   237,   238,   239,   242,   243,   244,   246,   250,
     251,   254,   255,   236,   237,   222,   278,   344,   327,   134,
     202,   207,   265,   266,   291,   292,   320,   323,   323,   324,
     324,   324,   324,   325,   325,   328,   328,     5,   215,   322,
     281,   321,   281,   281,   285,   205,   201,   202,   201,   202,
     201,   201,   202,   201,   201,   202,   207,   134,   201,   201,
     201,   201,   344,   214,   205,   201,   344,   215,   206,   200,
     247,   247,     8,   214,   256,   257,   258,   259,    20,   217,
     240,   241,   134,   216,   229,   217,   245,   246,   344,   344,
     273,   322,   335,   202,   205,   197,   208,   290,   293,   344,
     345,   134,    11,    28,   298,   322,   310,   303,   302,   319,
     322,   205,   215,   277,   215,   238,   252,   253,    31,   214,
     248,   249,   274,     5,   111,   112,   215,   217,   238,   261,
     262,   205,    12,   344,   345,   237,   201,   202,   227,   266,
     281,    12,   280,   197,   292,   320,   322,   205,   201,   215,
     202,   207,   214,   205,   201,   344,   205,    20,   237,   258,
     259,   241,    10,   322,   253,    20,   205,   215,   249,   262,
     263,   264,   265,   281,   237,   215,   260,   293,   344,   345,
     205,   200,   264,   200,   256,   256,   201,   201,   208,   345
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   209,   210,   211,   212,   213,   213,   214,   214,   215,
     216,   217,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   219,   218,   218,   220,   220,   221,
     221,   222,   222,   223,   223,   223,   224,   225,   225,   226,
     227,   227,   227,   227,   228,   228,   229,   229,   230,   230,
     231,   231,   232,   232,   232,   233,   233,   234,   235,   235,
     236,   237,   237,   237,   237,   237,   238,   238,   239,   240,
     240,   241,   242,   243,   244,   244,   245,   245,   246,   246,
     247,   247,   248,   248,   249,   249,   249,   249,   250,   250,
     250,   251,   252,   252,   253,   253,   254,   255,   256,   256,
     256,   256,   257,   257,   258,   259,   260,   260,   261,   261,
     262,   262,   263,   263,   264,   265,   265,   266,   266,   267,
     268,   268,   269,   270,   270,   271,   271,   272,   272,   273,
     273,   274,   274,   275,   275,   276,   276,   277,   277,   278,
     279,   280,   280,   281,   281,   282,   282,   282,   282,   283,
     284,   284,   285,   286,   286,   287,   288,   288,   289,   290,
     290,   291,   291,   292,   293,   293,   294,   294,   294,   295,
     296,   297,   298,   298,   299,   299,   299,   299,   300,   301,
     301,   302,   302,   303,   304,   305,   305,   305,   306,   306,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   308,
     308,   309,   309,   310,   310,   310,   311,   311,   311,   311,
     311,   311,   311,   311,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   313,   313,   313,   314,   314,   314,   314,   315,   316,
     317,   317,   318,   318,   319,   319,   320,   321,   322,   322,
     322,   323,   323,   323,   323,   323,   324,   324,   324,   325,
     325,   326,   326,   326,   326,   327,   327,   328,   328,   328,
     328,   328,   328,   329,   330,   330,   331,   331,   332,   332,
     332,   332,   332,   332,   332,   332,   333,   333,   334,   334,
     335,   335,   336,   336,   336,   337,   337,   338,   338,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   340,   340,   341,   341,   341,   341,   341,   341,
     342,   342,   342,   342,   343,   343,   344,   345,   345
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     3,     0,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     1,     0,     2,     0,
       2,     1,     1,     1,     1,     1,     2,     1,     2,     4,
       1,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     2,     1,     1,     1,     1,     2,     3,
       0,     3,     1,     3,     1,     3,     4,     2,     1,     1,
       1,     6,     1,     3,     1,     1,     3,     3,     0,     2,
       3,     1,     1,     3,     3,     5,     1,     5,     3,     1,
       1,     1,     1,     3,     5,     1,     3,     1,     3,     2,
       1,     2,     4,     4,     5,     3,     4,     1,     3,     1,
       1,     0,     2,     0,     3,     1,     3,     3,     4,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     1,     1,     1,     4,     3,     1,     6,     1,
       2,     1,     3,     3,     1,     2,     1,     1,     1,     4,
       4,     8,     1,     1,     1,     1,     1,     1,     0,     0,
       3,     1,     3,     1,     2,     1,     2,     1,     0,     2,
       4,     4,     2,     2,     2,     2,     2,     4,     6,     0,
       3,     1,     3,     1,     3,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       2,     1,     3,     3,     3,     1,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     4,     4,     4,     2,     3,     1,     3,
       1,     3,     4,     2,     4,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1
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
        case 7:
#line 202 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in id_list:1---");} (yyval.y_listOfIDs) = addToList((yyvsp[0].y_ST_ID), NULL);}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 203 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in id_list:2---");} (yyval.y_listOfIDs) = addToList((yyvsp[0].y_ST_ID), (yyvsp[-2].y_listOfIDs));}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 207 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in typename:1---");}(yyval.y_ST_ID) = st_enter_id((yyvsp[0].y_string));}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 211 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("Found in identifier:1---");}(yyval.y_ST_ID) = st_enter_id((yyvsp[0].y_string));}
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 215 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_identifier:1---");}  (yyval.y_ST_ID) = (yyvsp[0].y_ST_ID);}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 219 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_identifier_1:1---");} (yyval.y_ST_ID) = st_enter_id((yyvsp[0].y_string));}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 221 "gram.y" /* yacc.c:1646  */
    {}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 222 "gram.y" /* yacc.c:1646  */
    {}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 223 "gram.y" /* yacc.c:1646  */
    {}
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 225 "gram.y" /* yacc.c:1646  */
    {}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 226 "gram.y" /* yacc.c:1646  */
    {}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 227 "gram.y" /* yacc.c:1646  */
    {}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 228 "gram.y" /* yacc.c:1646  */
    {}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 229 "gram.y" /* yacc.c:1646  */
    {}
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 230 "gram.y" /* yacc.c:1646  */
    {}
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 231 "gram.y" /* yacc.c:1646  */
    {}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 232 "gram.y" /* yacc.c:1646  */
    {}
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 233 "gram.y" /* yacc.c:1646  */
    {}
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 234 "gram.y" /* yacc.c:1646  */
    {}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 235 "gram.y" /* yacc.c:1646  */
    {}
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 236 "gram.y" /* yacc.c:1646  */
    {}
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 237 "gram.y" /* yacc.c:1646  */
    {}
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 239 "gram.y" /* yacc.c:1646  */
    {}
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 240 "gram.y" /* yacc.c:1646  */
    {}
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 242 "gram.y" /* yacc.c:1646  */
    {}
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 243 "gram.y" /* yacc.c:1646  */
    {}
#line 2508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 244 "gram.y" /* yacc.c:1646  */
    {}
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 245 "gram.y" /* yacc.c:1646  */
    {}
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 246 "gram.y" /* yacc.c:1646  */
    {}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 247 "gram.y" /* yacc.c:1646  */
    {}
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 248 "gram.y" /* yacc.c:1646  */
    {}
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 249 "gram.y" /* yacc.c:1646  */
    {}
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 250 "gram.y" /* yacc.c:1646  */
    {}
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 251 "gram.y" /* yacc.c:1646  */
    {}
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 253 "gram.y" /* yacc.c:1646  */
    {}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 254 "gram.y" /* yacc.c:1646  */
    {}
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 256 "gram.y" /* yacc.c:1646  */
    {}
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 257 "gram.y" /* yacc.c:1646  */
    {}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 258 "gram.y" /* yacc.c:1646  */
    {}
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 259 "gram.y" /* yacc.c:1646  */
    {}
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 260 "gram.y" /* yacc.c:1646  */
    {}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 262 "gram.y" /* yacc.c:1646  */
    {}
#line 2604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 263 "gram.y" /* yacc.c:1646  */
    {}
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 264 "gram.y" /* yacc.c:1646  */
    {}
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 265 "gram.y" /* yacc.c:1646  */
    {}
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 266 "gram.y" /* yacc.c:1646  */
    {}
#line 2628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 267 "gram.y" /* yacc.c:1646  */
    {}
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 268 "gram.y" /* yacc.c:1646  */
    {}
#line 2640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 268 "gram.y" /* yacc.c:1646  */
    {}
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 269 "gram.y" /* yacc.c:1646  */
    {}
#line 2652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 288 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in simple_decl:1---");}}
#line 2658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 289 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in simple_decl:2---");}}
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 290 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in simple_decl:3---");}}
#line 2670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 309 "gram.y" /* yacc.c:1646  */
    {}
#line 2676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 310 "gram.y" /* yacc.c:1646  */
    {}
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 311 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in constant:3---");} (yyval.y_int)=(yyvsp[0].y_int);}
#line 2688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 312 "gram.y" /* yacc.c:1646  */
    {}
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 316 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in number:1---");} if((yyvsp[-1].y_char) == '-')(yyval.y_int)=-(yyvsp[0].y_int); else (yyval.y_int)=(yyvsp[0].y_int);}
#line 2700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 317 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in number:2---");} (yyval.y_int)=(yyvsp[0].y_int);}
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 321 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in unsigned_number:1---");} (yyval.y_int) = (yyvsp[0].y_int);}
#line 2712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 322 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in unsigned_number:2---");} (yyval.y_int) = (yyvsp[0].y_real);}
#line 2718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 326 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in sign:1---");} (yyval.y_char) = (yyvsp[0].y_char);}
#line 2724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 327 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in sign:2---");} (yyval.y_char) = (yyvsp[0].y_char);}
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 347 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found type_definition_part:1 resolving pointers---");}
                                              INDEX_LIST tempUnRP = rootOfUnRP;

                                              do{
                                                ST_ID tempID;
                                                TYPE tempTYPE;
                                                if(tempUnRP == NULL){
                                                  break;
                                                }else{
                                                  tempTYPE = tempUnRP->type;
                                                  if(ty_query(tempTYPE) != TYERROR){
                                                    ty_query_ptr(tempTYPE, &tempID);
                                                    ST_DR ptrToResolve = st_lookup(tempID, &block);
                                                    if(ptrToResolve != NULL){
                                                      ty_resolve_ptr(tempUnRP->type, ptrToResolve->u.decl.type);
                                                    }else{
                                                      if(myDebugPart1){
                                                        msg("Something got into the pointer list that isn't in the symtab *#_#");
                                                      }
                                                    }

                                                  }

                                                }
                                                if(ty_query_ptr(tempTYPE, &tempID) == NULL){
                                                  error("Unresolved Pointer: \"%s\"", st_get_id_str(tempID));
                                                }
                                                tempUnRP = tempUnRP->next;
                                              }while(tempUnRP != NULL);

                                              }
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 386 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msgn("type_definition:1---"); ty_print_typetag(ty_query((yyvsp[0].y_type))); msg("");}


                                                ST_ID IDtoInstall = st_lookup((yyvsp[-2].y_ST_ID), &block);
                                                if(IDtoInstall == NULL){
                                                  ST_DR DRtoInstall = stdr_alloc();
                                                  DRtoInstall->tag = TYPENAME;
                                                  DRtoInstall->u.typename.type = (yyvsp[0].y_type);
                                                  if(!(st_install((yyvsp[-2].y_ST_ID),DRtoInstall))){
                                                    bug("st_install failed in type_definition");
                                                  }else{
                                                    //if(myDump)stdr_dump(DRtoInstall);
                                                  }
                                                }else error("Duplicate variable declaration: \"%s\"", st_get_id_str(IDtoInstall));
                                              }
#line 2786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 404 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in type_denoter:1---");}
                                          if((yyvsp[0].y_ST_ID) != NULL){
                                            ST_DR testTemp = st_lookup((yyvsp[0].y_ST_ID),&block);
                                            if(testTemp != NULL){
                                              (yyval.y_type) = testTemp->u.typename.type;
                                            }else{
                                               error("Undeclared type name: \"%s\"", st_get_id_str((yyvsp[0].y_ST_ID)));
                                               (yyval.y_type) = ty_build_basic(TYERROR);
                                             }

                                          }else{
                                             //this shouldnt ever happen *hopefully*
                                             bug("ST_ID from typename in type_denoter is NULL!");
                                           }
                                        }
#line 2806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 419 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in type_denoter:2---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 420 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in type_denoter:3---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 421 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in type_denoter:4---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 422 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in type_denoter:5---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 426 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_ordinal_type:1---");}}
#line 2836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 427 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_ordinal_type:2---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 431 "gram.y" /* yacc.c:1646  */
    {}
#line 2848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 440 "gram.y" /* yacc.c:1646  */
    {}
#line 2854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 444 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in subrange_type:1---");}
                                          if((yyvsp[-2].y_int) <= (yyvsp[0].y_int)){
                                            (yyval.y_type) = ty_build_subrange(ty_build_basic(TYSIGNEDLONGINT),(yyvsp[-2].y_int),(yyvsp[0].y_int));
                                          }else{
                                            error("Subrange values are invalid!");
                                            (yyval.y_type) = ty_build_basic(TYERROR);
                                          }
                                        }
#line 2867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 455 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_pointer_type:1---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 464 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in pointer_domain_type:1---");}
                                        ST_DR tempDR = st_lookup((yyvsp[0].y_ST_ID),&block);
                                        TYPE tempType;
                                          if(tempDR == NULL){
                                            tempType = ty_build_unresolved_ptr((yyvsp[0].y_ST_ID));
                                            //add to list of unresloved
                                            if(rootOfUnRP == NULL){
                                              initRootOfUnRP(tempType);
                                            }else{
                                              addToUnresolvedPtrs(tempType, rootOfUnRP);
                                            }
                                          }else{
                                            tempType = tempDR->u.typename.type;
                                            tempType = ty_build_ptr(tempType);
                                          }
                                          (yyval.y_type) = tempType;

                                      }
#line 2896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 482 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in pointer_domain_type:2---");} (yyval.y_type) = ty_build_ptr((yyvsp[0].y_type));/*To our knowledge this is not tested in PROJECT 1 */}
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 486 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_procedural_type:1---");} (yyval.y_type) = ty_build_func(ty_build_basic(TYVOID), NULL, TRUE);}
#line 2908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 487 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_procedural_type:2---");}
                                                                                TYPE tempTYPE = (yyvsp[0].y_type);
                                                                                TYPETAG tempTAG = ty_query(tempTYPE);
                                                                                if(TYFLOAT == tempTAG |
                                                                                   TYDOUBLE == tempTAG |
                                                                                   TYLONGDOUBLE == tempTAG |
                                                                                   TYUNSIGNEDINT == tempTAG |
                                                                                   TYUNSIGNEDCHAR == tempTAG |
                                                                                   TYUNSIGNEDSHORTINT == tempTAG |
                                                                                   TYUNSIGNEDLONGINT == tempTAG |
                                                                                   TYSIGNEDCHAR == tempTAG |
                                                                                   TYSIGNEDINT == tempTAG |
                                                                                   TYSIGNEDLONGINT == tempTAG |
                                                                                   TYSIGNEDSHORTINT == tempTAG |
                                                                                   TYVOID == tempTAG |
                                                                                   TYPTR == tempTAG){
                                                                                  (yyval.y_type) = ty_build_func(tempTYPE, NULL, TRUE);

                                                                                }else{
                                                                                  error("Function type invalid");
                                                                                  (yyval.y_type) = ty_build_basic(TYERROR);
                                                                                }
                                                                              }
#line 2936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 513 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in optional_procedural_type_formal_parameter_list:0---");}}
#line 2942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 514 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in optional_procedural_type_formal_parameter_list:1---");}}
#line 2948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 518 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter_list:1---");}}
#line 2954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 519 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter_list:2---");}}
#line 2960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 523 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:1---");}}
#line 2966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 524 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:2---");}}
#line 2972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 525 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:3---");}}
#line 2978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 526 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:4---");}}
#line 2984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 530 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_structured_type:1---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 531 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_structured_type:2---");}}
#line 2996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 532 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_structured_type:3---");}}
#line 3002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 538 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("array_type:1---"); ty_print_typetag(ty_query((yyvsp[0].y_type))); msg("");}
                                                                    if(ty_query((yyvsp[0].y_type)) != TYERROR && ty_query((yyvsp[-3].y_index_list)->type) != TYERROR){
                                                                      if(ty_query((yyvsp[0].y_type)) != TYFUNC){
                                                                        (yyval.y_type) = ty_build_array((yyvsp[0].y_type),(yyvsp[-3].y_index_list));
                                                                      }else{
                                                                        error("Data type expected for array elements");
                                                                        (yyval.y_type) = ty_build_basic(TYERROR);
                                                                      }
                                                                    }else{ // keep passing the error type up
                                                                      (yyval.y_type) = (yyvsp[0].y_type);
                                                                    }
                                                                  }
#line 3019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 553 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in array_index_list:1---");} (yyval.y_index_list) = addToArraySubList((yyvsp[0].y_type), NULL);}
#line 3025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 554 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in array_index_list:2---");} (yyval.y_index_list) = addToArraySubList((yyvsp[0].y_type), (yyvsp[-2].y_index_list));}
#line 3031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 559 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in ordinal_index_type:1---");} (yyval.y_type) = (yyvsp[0].y_type); /*this is a subrange return (for now)*/}
#line 3037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 560 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in ordinal_index_type:2---");} (yyval.y_type) = (yyvsp[0].y_ST_ID); /*ST_Id*/}
#line 3043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 632 "gram.y" /* yacc.c:1646  */
    {
      //for each, get the id by calling ty_query_ptr(), then look up the id in the symbol table to get the stdr (which must be a TYPENAME), then call ty_resolve_ptr()
                                            }
#line 3051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 643 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("variable_declaration:1---"); ty_print_typetag(ty_query((yyvsp[-1].y_type))); msg("");}
                                            LD tempLD = (yyvsp[-3].y_listOfIDs);
                                            if(tempLD != NULL){
                                              do{
                                                ST_ID IDtoInstall = st_lookup(tempLD->data, &block);
                                                char *idName = st_get_id_str(tempLD->data);
                                                TYPE typeToInstall = (yyvsp[-1].y_type);

                                                if(ty_query((yyvsp[-1].y_type)) != TYFUNC){
                                                  if(IDtoInstall == NULL){
                                                    ST_DR DRtoInstall = stdr_alloc();
                                                    DRtoInstall->tag = GDECL;
                                                    DRtoInstall->u.decl.sc = NO_SC;
                                                    DRtoInstall->u.decl.type = typeToInstall;
                                                    if(!(st_install(tempLD->data,DRtoInstall))){
                                                      bug("st_install failed in variable declaration");
                                                    }else{
                                                      if(myDump){
                                                        stdr_dump(DRtoInstall);
                                                      }
                                                      int alignment = getAlignmentSize(typeToInstall);
                                                      int size = getSize(typeToInstall, alignment);
                                                      int amount = size;
                                                      b_global_decl (idName, alignment, size);
                                                      b_skip(amount);
                                                    }
                                                  }else{
                                                    error("Duplicate declaration: \"%s\"", idName);
                                                  }
                                                }else{//cant set var to function
                                                  error("Var can not be set to a Function or Procedure: \"%s\"",idName);
                                                }


                                                tempLD = tempLD->next;
                                              }while(tempLD != NULL);

                                            }else{
                                              bug("Issue occured while calling id_list in variable_declaration. (id_list == NULL)");
                                            }
                                              }
#line 3097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 732 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("functiontype:0---");}}
#line 3103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 733 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("functiontype:1--- %s", st_get_id_str((yyvsp[0].y_ST_ID)));}
                                    ST_ID tempID = (yyvsp[0].y_ST_ID);
                                    ST_DR tempDR = st_lookup(tempID, &block);
                                    if(tempDR != NULL){
                                      (yyval.y_type) = tempDR->u.typename.type;
                                    }else{
                                      error("Function returnType invalid: \"%s\"", st_get_id_str((yyvsp[0].y_ST_ID)));
                                    }
                                    }
#line 3117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 769 "gram.y" /* yacc.c:1646  */
    {/*everything withing begin and end*/}
#line 3123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 773 "gram.y" /* yacc.c:1646  */
    {/*possibly last stement in Pascal doesnt need a semi*/}
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 896 "gram.y" /* yacc.c:1646  */
    {/*ST_ID*/
                                                            if(myDebugPart2){msg("variable_or_function_access_maybe_assignment:1--- %s", st_get_id_str((yyvsp[0].y_ST_ID)));}
                                                            (yyval.y_TN) = (yyvsp[0].y_ST_ID);
                                                          }
#line 3138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 900 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("variable_or_function_access_maybe_assignment:2--- ");}}
#line 3144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 901 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("variable_or_function_access_maybe_assignment:3--- ");}}
#line 3150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 906 "gram.y" /* yacc.c:1646  */
    {/*LEX_ASSIGN  is := */}
#line 3156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1042 "gram.y" /* yacc.c:1646  */
    {/*idk what a LEX_POW is*/}
#line 3162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1043 "gram.y" /* yacc.c:1646  */
    {/*LEX_POWER  **   */}
#line 3168 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3172 "y.tab.c" /* yacc.c:1646  */
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
#line 1178 "gram.y" /* yacc.c:1906  */


void yyerror(const char *msg)
{
    error(msg);
}

/* Sets the value of the 'yydebug' variable to VALUE.
   This is a function so we don't have to have YYDEBUG defined
   in order to build the compiler.  */
void
set_yydebug (int value)
{
#if YYDEBUG != 0
  yydebug = value;
#else
  warning ("YYDEBUG not defined.");
#endif
}

int getSize(TYPE type, int baseTypeSize){
  INDEX_LIST currList;
  long low;
  long high;
  TYPETAG typeTag = ty_query(type);
  TYPE tempSubRange;
  switch(typeTag){
    TYPE tempTYPE;
    int indexSize;
    case TYARRAY:
      tempTYPE = ty_query_array(type, &currList);
      indexSize = 0;
      do{
        tempSubRange = currList->type;
        ty_query_subrange(tempSubRange, &low, &high);
        if(indexSize == 0){
          indexSize = high - low + 1;
        }else{
          indexSize = indexSize * (high - low + 1);
        }
        currList = currList->next;
      }while(currList != NULL);

      if(ty_query(tempTYPE) == TYARRAY){
        return indexSize * getSize(tempTYPE, baseTypeSize);
      }
      return indexSize * baseTypeSize;

    case TYSUBRANGE:
      ty_query_subrange(type, &low, &high);
      return 4; //Assumption: In Part 1 of the project we believe we are only dealing with Integer values of subranges and so we return the size value of integers

   default:
      return baseTypeSize;
  }
}

/*
Alignment required for and array is the same
as its element type align requirement
    (if element is another array, recursive call)

Size of an array equals
    (size of the element type) * (product of index type ranges)
    range 4..6 = 3
    low..high = high - low + 1
*/

int getAlignmentSize(TYPE type){
  INDEX_LIST list;
  long low;
  long high;
  TYPETAG typeTag = ty_query(type);
  switch(typeTag){
    case TYSIGNEDLONGINT:
      return 4;

    case TYSIGNEDSHORTINT:
      return 4;

    case TYSIGNEDINT:
      return 4;

    case TYUNSIGNEDLONGINT:
      return 4;

    case TYUNSIGNEDSHORTINT:
      return 4;

    case TYUNSIGNEDINT:
      return 4;

    case TYUNSIGNEDCHAR:
      return 1;

    case TYSIGNEDCHAR:
      return 1;

    case TYARRAY:
      return getAlignmentSize(ty_query_array(type, &list));

    case TYPTR:
      return 4;

    case TYSUBRANGE:
      return getAlignmentSize(ty_query_subrange(type, &low, &high));

    case TYDOUBLE:
      return 8;

   case TYFLOAT:
      return 4;

   case TYLONGDOUBLE:
      return 8;

  }
}

void initRootOfUnRP(TYPE type){
  rootOfUnRP = (INDEX_LIST)malloc(sizeof(INDEX));
  rootOfUnRP->type = type;
  rootOfUnRP->next = NULL;
  rootOfUnRP->prev = NULL;
}
