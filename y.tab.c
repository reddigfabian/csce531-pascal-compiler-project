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
#include "encode.h"
#include "tree.h"
#include "types.h" //added this for use of TLIST
/* Cause the `yydebug' variable to be defined.  */
#define YYDEBUG 1

void set_yydebug(int);
void yyerror(const char *);

//Debugers
int myDebugPart1 = 0;
int myDebugPart2 = 1;
int myDebugPart3 = 1;


/*Globals*/
int myDump = 0;
int insideFunc = 0;
int block;
ST_ID funcST_ID;
INDEX_LIST rootOfUnRP;
/*END Globals*/

/* Like YYERROR but do call yyerror */
#define YYERROR1 { yyerror ("syntax error"); YYERROR; }

void initRootOfUnRP(TYPE type); //prototype

#line 98 "y.tab.c" /* yacc.c:339  */

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
#line 84 "gram.y" /* yacc.c:355  */

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

#line 536 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 551 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   1689

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  209
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  371
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  553

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
       0,   208,   208,   212,   216,   219,   221,   225,   226,   230,
     234,   238,   242,   244,   245,   246,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   262,
     263,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   276,   277,   279,   280,   281,   282,   283,   285,   286,
     287,   288,   289,   290,   291,   291,   292,   296,   297,   303,
     304,   310,   314,   318,   319,   320,   326,   330,   331,   335,
     339,   340,   341,   342,   346,   356,   369,   372,   378,   379,
     383,   384,   388,   389,   390,   394,   397,   401,   435,   436,
     440,   458,   473,   474,   475,   476,   480,   481,   485,   489,
     490,   494,   498,   509,   513,   514,   518,   536,   540,   541,
     567,   568,   572,   573,   577,   578,   579,   580,   584,   585,
     586,   592,   607,   608,   613,   614,   620,   624,   627,   629,
     630,   631,   635,   636,   640,   644,   648,   649,   653,   654,
     658,   659,   663,   664,   668,   672,   673,   677,   678,   686,
     691,   692,   696,   771,   803,   806,   803,   823,   828,   846,
     847,   851,   852,   856,   857,   870,   872,   876,   877,   881,
     882,   889,   893,   893,   904,   907,   913,   916,   922,   925,
     926,   929,   933,   937,   938,   942,   946,   952,   956,   962,
     965,   969,   973,   974,   978,   979,   983,   987,   988,   992,
     993,   997,  1001,  1005,  1011,  1015,  1016,  1020,  1022,  1028,
    1031,  1035,  1040,  1042,  1046,  1047,  1051,  1057,  1097,  1132,
    1134,  1141,  1145,  1151,  1152,  1153,  1154,  1155,  1156,  1157,
    1158,  1159,  1162,  1164,  1168,  1169,  1173,  1174,  1175,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1191,  1192,  1193,
    1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,
    1204,  1205,  1206,  1207,  1211,  1212,  1213,  1217,  1218,  1219,
    1220,  1224,  1228,  1232,  1233,  1237,  1238,  1242,  1243,  1249,
    1253,  1261,  1265,  1268,  1274,  1277,  1285,  1286,  1287,  1291,
    1294,  1309,  1313,  1316,  1328,  1331,  1334,  1337,  1343,  1346,
    1356,  1359,  1362,  1365,  1366,  1367,  1371,  1375,  1378,  1384,
    1422,  1426,  1427,  1428,  1429,  1432,  1435,  1436,  1439,  1445,
    1446,  1450,  1451,  1455,  1456,  1460,  1471,  1472,  1486,  1488,
    1492,  1493,  1497,  1498,  1499,  1500,  1501,  1502,  1503,  1504,
    1505,  1506,  1507,  1508,  1509,  1510,  1511,  1512,  1513,  1514,
    1515,  1516,  1517,  1518,  1519,  1523,  1524,  1528,  1529,  1530,
    1531,  1532,  1533,  1537,  1538,  1539,  1540,  1544,  1545,  1549,
    1552,  1554
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
  "variable_declaration", "function_declaration", "$@2", "$@3",
  "function_heading", "directive_list", "directive", "functiontype",
  "optional_par_formal_parameter_list", "formal_parameter_list",
  "formal_parameter", "statement_part", "compound_statement", "$@4",
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

#define YYPACT_NINF -462

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-462)))

#define YYTABLE_NINF -372

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,  1564,    45,  -113,   -98,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,   -52,
    -462,  -462,  -462,  -462,  -462,  -462,  1564,  -462,   306,  -109,
    -462,  -462,  1564,  1564,  1564,  1564,  1564,  -462,  -462,  -462,
    -462,  -462,  -462,   -98,  -462,  -462,  -462,  1564,   880,    13,
    1564,  -462,   -33,   -33,    40,   -98,  -462,   -75,  1564,  -462,
     -14,  -462,  -462,   631,  1066,   631,   880,   631,  1066,  -462,
    -462,  -462,  -462,  -462,  -462,   -16,   -10,   -16,   -10,   -10,
      20,    34,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,   631,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,   631,  -462,    95,  -462,    10,
    -462,  -462,  -462,  -462,   -17,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,    60,  -462,    59,    61,  -462,  -462,
    -462,  -462,  1066,  -132,    70,   187,  -462,    72,    74,    81,
     631,  -462,  1360,    35,  -462,   823,  1564,   823,  -462,  -462,
    -462,  -462,   -98,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,   631,   470,  -462,  -462,   631,  -462,  -462,   113,
     238,    86,    51,  -462,    64,  -462,   676,  -132,  -462,  -462,
     -92,   258,   413,   -13,   282,     8,  -462,  -132,   631,  -462,
     631,  -462,  -462,  -462,  -462,  1125,   631,   413,   -42,  -462,
     880,   880,   631,  -462,   631,   631,  -132,  1564,  -462,  -462,
     631,  -462,   631,   631,  -462,   631,   631,   -98,   413,  1564,
     -47,  -126,  -462,   291,  -462,   166,    96,   109,   109,  1408,
     294,  1564,  -462,  -462,   177,  -462,  -462,    44,  -462,  -462,
    -462,  -462,  -462,  -462,  1252,  -462,  -462,  -462,  -462,  -462,
    -462,   -98,   100,   -14,   631,  -462,  -462,  -462,   360,  -146,
    -462,  -462,  -462,   631,  -462,  -462,  -462,   631,  -462,  -462,
    -462,   631,  -462,  -462,   631,   631,   631,   631,  -462,  -462,
    -462,  -462,   631,   631,   676,   676,   291,  -462,   631,   880,
     631,   880,   880,  1066,   112,   -81,  -462,   413,   -76,  -462,
     124,   126,   131,   -66,  -462,  -462,  -462,   413,   133,   -45,
    -462,  -129,  -462,   370,    21,   135,   138,    67,  -462,   -26,
     291,  -462,  1360,  -462,  -462,     7,  1516,    35,  -462,  1009,
     -20,   333,   140,  -462,  -462,   823,  -462,   122,  -462,   338,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,   339,  -462,  -462,
     631,   631,  -462,    -8,  -462,  -151,  -462,   217,    86,    86,
      51,    51,    51,    51,  -462,  -462,  -462,  -462,  -462,    31,
    -462,  -462,  -462,  -462,  -462,   631,  -462,   631,  -462,   631,
    -462,  -462,   631,  -462,  -462,   631,  -462,   631,  -462,  -462,
    -462,  -462,   291,  -462,  -462,  -462,  -462,  -119,  -462,  1564,
      36,  -117,  -462,  -462,   -97,   218,   220,  -462,   153,  -462,
     340,  -462,   823,  -462,    18,  1408,  -462,  -462,  -462,  1564,
    -462,   -98,   413,  -462,   631,   880,  -462,   347,   880,   515,
    -462,   631,  -462,  -462,   631,   226,  -462,  -462,   129,  -462,
     413,  -462,     7,   341,    50,   291,  -462,  1516,     7,   631,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,   -98,  -462,
    -462,  -462,    23,   631,  -462,  -462,   823,   291,  -462,  -462,
    -462,  -151,  -462,    52,   880,   413,  -462,  -462,  -462,   170,
     515,  -462,   172,  -462,  1408,  -462,  1408,   181,   182,   176,
    -462,  -462,  -462
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
      11,     1,     2,   369,    57,    55,     0,     4,     0,     0,
       7,   172,     0,     0,     0,     0,     0,    58,    61,    63,
      64,    65,    62,     0,     3,   171,     6,     0,   211,     0,
      66,    67,   165,   165,     0,     0,    88,     0,   149,   150,
     154,     8,    10,     0,     0,     0,   211,     0,     0,   312,
     311,   247,   248,   239,   240,   232,   212,   232,   212,   212,
       0,     0,   332,   333,   334,   335,   336,   337,   338,   339,
     341,   342,   251,   252,   344,   345,   355,   356,   346,   330,
     331,   271,   272,   267,   269,   270,   243,   257,   259,   258,
     262,   263,   261,   260,   241,   242,   244,   245,   246,   249,
     250,   253,   254,   255,   256,   340,   343,   347,   348,   349,
     350,   351,   352,   353,   354,     0,   306,   218,   178,     0,
     174,   176,   179,   180,   190,   186,   187,   181,   199,   200,
     201,   177,   207,   208,   221,   209,     0,     0,   210,   264,
     266,   265,     0,     0,   307,   220,   308,   328,     0,     0,
       0,    68,     0,   163,   157,     0,    87,     0,   151,   161,
     162,    59,     0,   159,    78,    79,    82,    84,    83,    76,
      85,    77,     0,     0,   309,   302,     0,   301,    81,    80,
       0,   283,   284,   289,   292,   294,     0,   300,   310,   303,
       0,     0,   280,     0,     0,     0,   183,   185,     0,   225,
       0,   227,   226,   228,   229,     0,     0,   268,     0,   173,
     211,   211,     0,   217,     0,     0,   219,     0,   104,   105,
       0,   315,     0,     0,   326,     0,     0,     0,   279,     0,
       0,     0,   167,     0,   158,     9,     0,   110,   110,   128,
       0,     0,    91,    70,     0,    72,    75,     0,    73,    90,
      92,    96,    97,    93,     0,    94,    95,   118,   119,   120,
      89,     0,   155,   153,     0,   304,   298,   319,   323,     0,
     321,   293,    86,     0,   361,   360,   362,     0,   357,   359,
     358,     0,   368,   367,     0,     0,     0,     0,   365,   366,
     363,   364,     0,     0,     0,     0,     0,   305,     0,   211,
       0,   211,   211,     0,   236,     0,   234,   216,     0,   214,
      10,     0,   310,     0,   314,   175,   189,   222,     0,     0,
     313,     0,   275,   277,     0,     0,     0,     0,    69,     0,
       0,   166,     0,     9,   164,     0,     0,   163,   108,     0,
       0,     0,   370,   132,   131,     0,   101,     0,    99,     0,
      71,    74,   106,   103,   107,   152,    60,     0,   160,   299,
       0,     0,   320,     0,   145,   370,   194,   147,   282,   281,
     287,   288,   286,   285,   291,   290,   295,   296,   297,     0,
     188,   202,   203,   182,   184,     0,   233,     0,   213,     0,
     318,   230,     0,   223,   224,     0,   316,     0,   317,   329,
     325,   327,     0,   169,   168,   125,   124,     0,   122,     0,
     114,     0,   112,   109,     9,    15,    14,   140,     0,   141,
       0,   139,     0,   127,   369,     0,   129,   126,    98,     0,
     102,     0,   324,   322,     0,   211,   197,     0,   211,     0,
     192,     0,   206,   205,     0,   237,   235,   215,     0,   276,
     278,   170,     0,     0,   117,     0,   111,     0,     0,     0,
     134,   133,   130,   100,   156,   146,   196,   191,   193,   198,
     195,   148,     0,     0,   231,   123,     0,     0,   115,   113,
     138,   370,   142,     0,   211,   238,   121,   116,   135,     0,
       0,   136,     0,   204,   128,   143,   128,     0,     0,   370,
     144,   371,   137
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -462,  -462,  -462,  -462,  -462,   -53,  -252,   -73,     0,  -462,
    -462,  -462,  -462,    73,  -462,  -462,  -462,   312,    -2,  -462,
    -153,  -164,  -152,  -462,  -462,  -462,  -462,   189,  -179,  -319,
    -462,  -462,   -79,  -462,  -462,  -186,  -462,    97,   114,  -462,
    -104,  -462,  -462,  -462,   -95,  -462,  -462,  -442,  -462,   -71,
     -70,  -462,  -462,  -100,  -462,  -131,  -461,   -74,  -462,  -462,
     325,  -462,  -462,  -462,  -462,  -462,   101,    30,   335,  -462,
      38,    14,   -54,  -462,   -94,  -246,  -462,  -462,  -462,    69,
    -462,  -462,  -462,  -462,  -462,  -462,   -65,  -106,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,   103,  -225,  -188,  -462,  -462,
    -462,  -462,   320,  -462,    -9,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,   -15,  -194,   -90,    48,  -214,   -72,  -190,
    -462,   118,  -198,   -46,   -69,  -462,   -62,  -462,  -462,    22,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,    -4,  -407
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    57,   390,   292,   224,    60,    50,
      55,    58,   312,    67,    68,    69,    80,    81,   294,   295,
     225,   226,   227,   228,   229,    70,    85,    86,   299,   300,
     301,   397,   398,   302,   303,   271,   403,   305,   387,   461,
     462,   306,   307,   457,   458,   308,   309,   391,   392,   393,
     394,   538,   470,   471,   531,   532,   413,   414,    71,    88,
      89,    72,   211,   407,    73,   212,   213,   284,   203,   281,
     282,    74,   168,    78,   169,   170,   171,   172,   245,   246,
     173,   174,   175,   176,   487,   415,   416,   488,   177,   178,
     179,   180,   494,   181,   182,   251,   358,   359,   183,   184,
     263,   185,   249,   355,   356,   186,   187,   188,   189,   190,
     191,   361,   371,   372,   417,   241,   357,   231,   232,   233,
     234,   315,   235,   236,   237,   194,   238,   239,   319,   320,
     196,   274,   197,   198,   199,   331,   343,   337,   260,   476
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    49,   243,    59,    75,   167,   277,   244,   490,   193,
     214,   215,   285,    87,   365,   366,   195,   350,   352,   304,
     209,   304,   259,   167,   316,   240,   216,   193,   311,   247,
    -371,   384,   192,   534,   195,    87,   321,   -10,   347,     1,
     369,   297,   492,   297,   348,    51,   486,   374,   533,    92,
     192,   377,   296,   298,   296,   298,   411,   474,   314,   493,
     354,   412,    79,    82,    83,    84,   456,   267,   363,    90,
     469,   268,   269,   445,   270,   381,   368,    91,   446,   533,
      79,   206,    53,   502,   506,   375,    52,   376,   503,   332,
     333,    53,    76,    77,   428,   324,   325,   326,   327,   328,
     329,   330,   547,   430,   548,   432,   433,   267,   -12,    62,
      53,   268,   269,   418,   270,    63,   316,   419,   217,   218,
     436,   437,    64,   266,   541,   438,   439,    77,   453,    65,
     207,    66,   293,   455,   293,   441,   442,   467,   219,   220,
     221,   230,   552,   242,   401,   242,   426,   427,    56,   280,
     314,   200,   424,   425,   210,    77,   444,   439,   380,   364,
     324,   325,   326,   327,   328,   329,   330,   202,   324,   325,
     326,   327,   328,   329,   330,   219,    77,   221,   205,   452,
     261,   257,    77,   456,   248,   472,   193,   167,   167,   469,
     250,   193,   193,   362,   484,    53,   262,   485,   195,   195,
     501,   338,   339,   340,   341,   342,    84,   291,   313,   304,
     353,   253,   254,   258,   192,   192,   477,   498,    53,  -371,
     255,   297,   448,   439,   400,   297,   379,   344,   345,   346,
     334,   297,   296,   298,   256,   297,   296,   298,    77,   516,
     283,   505,   296,   298,   335,   322,   296,   298,   278,   354,
     455,   497,    77,   528,   484,   527,   467,   542,   323,   264,
     431,   265,   420,   421,   422,   423,   336,   370,   451,   439,
     272,   318,   273,   378,   275,   537,   167,   382,   167,   167,
     193,   276,   193,   193,   247,   349,   304,   195,   543,   195,
     195,   396,   351,   510,  -309,  -309,   383,   521,  -309,  -309,
     -10,  -309,   385,   192,   402,   192,   192,   405,   297,   386,
     367,   399,   293,    61,   395,    62,   293,   435,   373,   296,
     298,    63,   293,   478,   479,  -274,   293,   440,    64,   280,
     524,   439,  -273,   460,   443,    65,   449,    66,   297,   450,
     304,   214,   215,    92,   297,   473,    61,   536,   474,   296,
     298,   491,   -84,    75,   -83,   296,   298,   216,   508,   517,
     509,   526,   297,   324,   325,   326,   327,   328,   329,   330,
     544,   278,   546,   296,   298,   324,   325,   326,   327,   328,
     329,   330,   549,   550,   551,   406,  -310,  -310,   475,   468,
    -310,  -310,   201,  -310,   518,   310,   429,   480,   242,   293,
     513,   404,   388,   529,   511,   512,   504,   525,   530,   545,
     515,   489,   167,   208,   408,   167,   193,   463,   204,   193,
     454,   481,   434,   195,   520,   539,   195,   252,   496,   293,
     499,   523,   409,   483,     0,   293,     0,     0,     0,   192,
       0,     0,   192,     0,     0,     0,     0,     0,     0,   217,
     218,     0,     0,   293,   460,     0,     0,   507,   482,   318,
       0,   167,     0,     0,     0,   193,     0,     0,     0,   219,
     220,   221,   195,   214,   215,    92,     0,   514,     0,   396,
       0,     0,     0,   495,     0,     0,     0,     0,   192,   216,
       0,     0,     0,   373,   410,   500,     0,   324,   325,   326,
     327,   328,   329,   330,   447,     0,     0,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,   214,   215,
      92,     0,     0,     0,     0,     0,     0,   540,     0,     0,
       0,     0,   278,     0,   216,     0,     0,   278,     0,   278,
       0,     0,   522,     0,     0,     0,     0,     0,    99,   100,
     324,   325,   326,   327,   328,   329,   330,   278,     0,   110,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   535,     0,   124,   125,   126,   127,   128,   129,   130,
       0,   217,   218,     0,     0,     0,     0,     0,   278,     0,
       0,     0,     0,    99,   100,     0,     0,     0,     0,     0,
       0,   219,   220,   221,   110,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,     0,     0,   124,   125,
     126,   127,   128,   129,   130,     0,   217,   218,     0,     0,
       0,     0,     0,     0,   214,   215,    92,   222,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   220,   221,     0,
     216,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,     0,     0,   166,     0,   223,   317,     0,     0,
       0,    92,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   216,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     0,     0,     0,    99,
     100,     0,   519,     0,     0,   165,     0,     0,     0,   166,
     110,   223,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,     0,     0,   124,   125,   126,   127,   128,   129,
     130,     0,   217,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,   100,     0,     0,     0,     0,
       0,     0,   219,   220,   221,   110,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,   124,
     125,   126,   127,   128,   129,   130,     0,   217,   218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,     0,
       0,     0,     0,     0,     0,     0,     0,   219,   220,   221,
       0,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,     0,     0,     0,     0,   214,   215,   285,   286,
       0,   165,     0,     0,     0,   166,     0,   223,   287,     0,
       0,     0,   216,   222,     0,   288,     0,   289,     0,   290,
       0,     0,     0,     0,     0,     0,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,     0,     0,     0,
     166,     0,   223,     0,     0,    92,     0,    61,    93,     0,
       0,     0,     0,     0,    94,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,     0,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   217,   218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   219,   220,   221,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,     0,     0,   131,   132,   133,     0,   134,
     135,   136,     0,   137,     0,     0,     0,     0,     0,     0,
       0,     0,   214,   215,   464,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   138,     0,   268,   269,   216,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,     0,
       0,     0,     0,     0,     0,     0,     0,   143,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    92,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,     0,     0,   166,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
     465,   466,     0,     0,    41,    42,    43,    44,    45,    46,
     360,     0,     0,    47,    48,     0,     0,     0,     0,     0,
     219,   220,   221,     0,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   100,     0,     0,     0,     0,   291,
       0,     0,     0,     0,   110,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,     0,     0,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     5,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   287,     0,     0,
       0,     0,     0,     0,   288,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     5,     0,    41,    42,    43,
      44,    45,    46,     0,     0,     0,    47,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   279,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,   389,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,    41,    42,    43,    44,    45,
      46,     0,     0,     0,    47,    48,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     5,     0,    41,    42,    43,    44,    45,    46,     0,
       0,     0,    47,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   459,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
       0,    41,    42,    43,    44,    45,    46,     0,     0,     0,
      47,    48,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,     0,    41,
      42,    43,    44,    45,    46,     0,     0,     0,    47,    48
};

static const yytype_int16 yycheck[] =
{
       4,     1,    96,    56,    58,    78,   200,    97,   415,    78,
       3,     4,     5,    66,   260,   261,    78,    30,    10,   205,
      34,   207,    12,    96,   222,    94,    19,    96,   207,    98,
      12,   283,    78,    10,    96,    88,   226,   134,   236,    23,
     265,   205,    11,   207,   136,     0,   197,   272,   509,     5,
      96,   276,   205,   205,   207,   207,   202,   208,   222,    28,
     248,   207,    62,    63,    64,    65,   385,   199,   256,    73,
     389,   203,   204,   202,   206,   201,   264,    77,   207,   540,
      80,    85,   208,   202,   201,   273,   199,   275,   207,     3,
       4,   208,   201,   202,   346,   137,   138,   139,   140,   141,
     142,   143,   544,   349,   546,   351,   352,   199,   205,     9,
     208,   203,   204,   327,   206,    15,   314,   331,   111,   112,
     201,   202,    22,   192,   531,   201,   202,   202,   380,    29,
     205,    31,   205,   385,   207,   201,   202,   389,   131,   132,
     133,    93,   549,    95,   297,    97,   344,   345,   200,   202,
     314,   138,   342,   343,   168,   202,   201,   202,   205,   201,
     137,   138,   139,   140,   141,   142,   143,   200,   137,   138,
     139,   140,   141,   142,   143,   131,   202,   133,   138,   205,
     197,   133,   202,   502,   200,   205,   255,   260,   261,   508,
     200,   260,   261,   255,   202,   208,   136,   205,   260,   261,
     452,   150,   151,   152,   153,   154,   206,   200,   212,   395,
     202,   108,   109,   165,   260,   261,   395,   442,   208,   201,
     200,   385,   201,   202,   297,   389,   279,   163,   164,   165,
     144,   395,   385,   385,   200,   399,   389,   389,   202,   485,
     205,   205,   395,   395,   158,   132,   399,   399,   200,   437,
     502,   439,   202,   505,   202,   205,   508,   205,    20,   200,
     350,   200,   334,   335,   336,   337,   180,   267,   201,   202,
     200,   223,   200,   277,   200,   527,   349,   281,   351,   352,
     349,   200,   351,   352,   353,    27,   472,   349,   534,   351,
     352,   291,    10,   472,   199,   200,     5,   491,   203,   204,
     134,   206,   206,   349,   304,   351,   352,   311,   472,   200,
     262,   134,   385,     7,    20,     9,   389,   205,   270,   472,
     472,    15,   395,   201,   202,   201,   399,   201,    22,   382,
     201,   202,   201,   386,   201,    29,   201,    31,   502,   201,
     526,     3,     4,     5,   508,    12,     7,   526,   208,   502,
     502,   134,   134,   407,   134,   508,   508,    19,   205,    12,
      20,    20,   526,   137,   138,   139,   140,   141,   142,   143,
     200,   323,   200,   526,   526,   137,   138,   139,   140,   141,
     142,   143,   201,   201,   208,   312,   199,   200,   392,   389,
     203,   204,    80,   206,   488,   206,   348,   399,   350,   472,
     479,   304,   288,   507,   475,   475,   459,   502,   508,   540,
     484,   415,   485,    88,   313,   488,   485,   387,    83,   488,
     382,   407,   353,   485,   489,   531,   488,   107,   437,   502,
     445,   205,   314,   411,    -1,   508,    -1,    -1,    -1,   485,
      -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,    -1,    -1,   526,   507,    -1,    -1,   461,   410,   411,
      -1,   534,    -1,    -1,    -1,   534,    -1,    -1,    -1,   131,
     132,   133,   534,     3,     4,     5,    -1,   481,    -1,   479,
      -1,    -1,    -1,   435,    -1,    -1,    -1,    -1,   534,    19,
      -1,    -1,    -1,   445,   134,   447,    -1,   137,   138,   139,
     140,   141,   142,   143,   134,    -1,    -1,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,
      -1,    -1,   484,    -1,    19,    -1,    -1,   489,    -1,   491,
      -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,    78,    79,
     137,   138,   139,   140,   141,   142,   143,   509,    -1,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   523,    -1,   103,   104,   105,   106,   107,   108,   109,
      -1,   111,   112,    -1,    -1,    -1,    -1,    -1,   540,    -1,
      -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    89,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,    -1,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      19,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,    -1,    -1,   204,    -1,   206,   207,    -1,    -1,
      -1,     5,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    78,
      79,    -1,   197,    -1,    -1,   200,    -1,    -1,    -1,   204,
      89,   206,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,    -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,    89,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,    -1,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,   200,    -1,    -1,    -1,   204,    -1,   206,    15,    -1,
      -1,    -1,    19,   167,    -1,    22,    -1,    24,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,
     204,    -1,   206,    -1,    -1,     5,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,   115,   116,   117,    -1,   119,
     120,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   144,    -1,   203,   204,    19,    -1,
      -1,    -1,    -1,    -1,   154,    -1,   156,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,    -1,    -1,   204,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,    -1,   115,   116,   117,   118,   119,   120,
       5,    -1,    -1,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,    89,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     5,    -1,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,   125,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     5,    -1,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,   125,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,    -1,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,   125
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
     218,     0,   199,   208,   347,   219,   200,   213,   220,   214,
     217,     7,     9,    15,    22,    29,    31,   222,   223,   224,
     234,   267,   270,   273,   280,   281,   201,   202,   282,   217,
     225,   226,   217,   217,   217,   235,   236,   214,   268,   269,
     347,   217,     5,     8,    14,    17,    25,    32,    33,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   115,   116,   117,   119,   120,   121,   123,   144,   154,
     156,   157,   158,   167,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   200,   204,   216,   281,   283,
     284,   285,   286,   289,   290,   291,   292,   297,   298,   299,
     300,   302,   303,   307,   308,   310,   314,   315,   316,   317,
     318,   319,   332,   333,   334,   335,   339,   341,   342,   343,
     138,   226,   200,   277,   277,   138,   347,   205,   269,    34,
     168,   271,   274,   275,     3,     4,    19,   111,   112,   131,
     132,   133,   167,   206,   216,   229,   230,   231,   232,   233,
     325,   326,   327,   328,   329,   331,   332,   333,   335,   336,
     333,   324,   325,   283,   324,   287,   288,   333,   200,   311,
     200,   304,   311,   304,   304,   200,   200,   325,   325,    12,
     347,   197,   136,   309,   200,   200,   333,   199,   203,   204,
     206,   244,   200,   200,   340,   200,   200,   323,   325,    31,
     214,   278,   279,   205,   276,     5,     6,    15,    22,    24,
      26,   200,   215,   216,   227,   228,   229,   230,   231,   237,
     238,   239,   242,   243,   244,   246,   250,   251,   254,   255,
     236,   237,   221,   347,   230,   330,   331,   207,   325,   337,
     338,   328,   132,    20,   137,   138,   139,   140,   141,   142,
     143,   344,     3,     4,   144,   158,   180,   346,   150,   151,
     152,   153,   154,   345,   163,   164,   165,   331,   136,    27,
      30,    10,    10,   202,   306,   312,   313,   325,   305,   306,
       5,   320,   335,   306,   201,   284,   284,   325,   306,   305,
     217,   321,   322,   325,   305,   306,   306,   305,   347,   214,
     205,   201,   347,     5,   215,   206,   200,   247,   247,     8,
     214,   256,   257,   258,   259,    20,   217,   240,   241,   134,
     216,   229,   217,   245,   246,   347,   222,   272,   275,   330,
     134,   202,   207,   265,   266,   294,   295,   323,   326,   326,
     327,   327,   327,   327,   328,   328,   331,   331,   215,   325,
     284,   324,   284,   284,   288,   205,   201,   202,   201,   202,
     201,   201,   202,   201,   201,   202,   207,   134,   201,   201,
     201,   201,   205,   215,   279,   215,   238,   252,   253,    31,
     214,   248,   249,   276,     5,   111,   112,   215,   217,   238,
     261,   262,   205,    12,   208,   347,   348,   237,   201,   202,
     227,   280,   325,   338,   202,   205,   197,   293,   296,   347,
     348,   134,    11,    28,   301,   325,   313,   306,   305,   322,
     325,   215,   202,   207,   214,   205,   201,   347,   205,    20,
     237,   258,   259,   241,   347,   266,   284,    12,   283,   197,
     295,   323,   325,   205,   201,   253,    20,   205,   215,   249,
     262,   263,   264,   265,    10,   325,   237,   215,   260,   296,
     347,   348,   205,   284,   200,   264,   200,   256,   256,   201,
     201,   208,   348
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
     268,   268,   269,   270,   271,   272,   270,   273,   273,   274,
     274,   275,   275,   276,   276,   277,   277,   278,   278,   279,
     279,   280,   282,   281,   283,   283,   284,   284,   285,   285,
     285,   285,   286,   287,   287,   288,   289,   289,   290,   291,
     291,   292,   293,   293,   294,   294,   295,   296,   296,   297,
     297,   297,   298,   299,   300,   301,   301,   302,   302,   302,
     302,   303,   304,   304,   305,   305,   306,   307,   308,   308,
     308,   309,   309,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   311,   311,   312,   312,   313,   313,   313,   314,
     314,   314,   314,   314,   314,   314,   314,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   316,   316,   316,   317,   317,   317,
     317,   318,   319,   320,   320,   321,   321,   322,   322,   323,
     324,   325,   325,   325,   326,   326,   326,   326,   326,   327,
     327,   327,   328,   328,   329,   329,   329,   329,   330,   330,
     331,   331,   331,   331,   331,   331,   332,   333,   333,   334,
     334,   335,   335,   335,   335,   335,   335,   335,   335,   336,
     336,   337,   337,   338,   338,   339,   339,   339,   340,   340,
     341,   341,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   343,   343,   344,   344,   344,
     344,   344,   344,   345,   345,   345,   345,   346,   346,   347,
     348,   348
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
       1,     2,     4,     4,     0,     0,     7,     3,     4,     1,
       3,     1,     1,     0,     2,     0,     3,     1,     3,     3,
       4,     1,     0,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     1,     1,     4,     3,
       1,     6,     1,     2,     1,     3,     3,     1,     2,     1,
       1,     1,     4,     4,     8,     1,     1,     1,     1,     1,
       1,     0,     0,     3,     1,     3,     1,     2,     1,     2,
       1,     0,     2,     4,     4,     2,     2,     2,     2,     2,
       4,     6,     0,     3,     1,     3,     1,     3,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     3,     3,     1,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     2,     1,     3,     3,     3,     1,     2,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     4,     4,     4,     2,
       3,     1,     3,     1,     3,     4,     2,     4,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1
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
        case 3:
#line 212 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d main_program_declaration:1---line %d",block, sc_line());}}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 216 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d program_heading:1---%s",block,st_get_id_str((yyvsp[-1].y_ST_ID)));}}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 225 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in id_list:1---");} (yyval.y_listOfIDs) = addToList((yyvsp[0].y_ST_ID), NULL);}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 226 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in id_list:2---");} (yyval.y_listOfIDs) = addToList((yyvsp[0].y_ST_ID), (yyvsp[-2].y_listOfIDs));}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 230 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d Found in typename:LEX_ID---%s",block, (yyvsp[0].y_string));}(yyval.y_ST_ID) = st_enter_id((yyvsp[0].y_string));}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 234 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("\n %d identifier:LEX_ID---%s", block, (yyvsp[0].y_string));} (yyval.y_ST_ID) = st_enter_id((yyvsp[0].y_string));}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 238 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier:new_identifier_1---%s",block, st_get_id_str((yyvsp[0].y_ST_ID)));}  (yyval.y_ST_ID) = (yyvsp[0].y_ST_ID);}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 242 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:LEX_ID---%s",block,(yyvsp[0].y_string));} (yyval.y_ST_ID) = st_enter_id((yyvsp[0].y_string));}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 244 "gram.y" /* yacc.c:1646  */
    {}
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 245 "gram.y" /* yacc.c:1646  */
    {}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 246 "gram.y" /* yacc.c:1646  */
    {}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 248 "gram.y" /* yacc.c:1646  */
    {}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 249 "gram.y" /* yacc.c:1646  */
    {}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 250 "gram.y" /* yacc.c:1646  */
    {}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 251 "gram.y" /* yacc.c:1646  */
    {}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 252 "gram.y" /* yacc.c:1646  */
    {}
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 253 "gram.y" /* yacc.c:1646  */
    {}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 254 "gram.y" /* yacc.c:1646  */
    {}
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 255 "gram.y" /* yacc.c:1646  */
    {}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 256 "gram.y" /* yacc.c:1646  */
    {}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 257 "gram.y" /* yacc.c:1646  */
    {}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 258 "gram.y" /* yacc.c:1646  */
    {}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 259 "gram.y" /* yacc.c:1646  */
    {}
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 260 "gram.y" /* yacc.c:1646  */
    {}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 262 "gram.y" /* yacc.c:1646  */
    {}
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 263 "gram.y" /* yacc.c:1646  */
    {}
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 265 "gram.y" /* yacc.c:1646  */
    {}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 266 "gram.y" /* yacc.c:1646  */
    {}
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 267 "gram.y" /* yacc.c:1646  */
    {}
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 268 "gram.y" /* yacc.c:1646  */
    {}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 269 "gram.y" /* yacc.c:1646  */
    {}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 270 "gram.y" /* yacc.c:1646  */
    {}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 271 "gram.y" /* yacc.c:1646  */
    {}
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 272 "gram.y" /* yacc.c:1646  */
    {}
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 273 "gram.y" /* yacc.c:1646  */
    {}
#line 2579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 274 "gram.y" /* yacc.c:1646  */
    {}
#line 2585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 276 "gram.y" /* yacc.c:1646  */
    {}
#line 2591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 277 "gram.y" /* yacc.c:1646  */
    {}
#line 2597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 279 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:p_ORD---line %d",block, sc_line());};}
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 280 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:p_CHR---line %d",block, sc_line());};}
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 281 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:p_SUCC---line %d",block, sc_line());};}
#line 2615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 282 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:p_PRED---line %d",block, sc_line());};}
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 283 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:p_ODD---line %d",block, sc_line());};}
#line 2627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 285 "gram.y" /* yacc.c:1646  */
    {}
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 286 "gram.y" /* yacc.c:1646  */
    {}
#line 2639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 287 "gram.y" /* yacc.c:1646  */
    {}
#line 2645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 288 "gram.y" /* yacc.c:1646  */
    {}
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 289 "gram.y" /* yacc.c:1646  */
    {}
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 290 "gram.y" /* yacc.c:1646  */
    {}
#line 2663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 291 "gram.y" /* yacc.c:1646  */
    {}
#line 2669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 291 "gram.y" /* yacc.c:1646  */
    {}
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 292 "gram.y" /* yacc.c:1646  */
    {}
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 296 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d any_global_declaration_part:0---EMPTY",block);}}
#line 2687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 297 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d any_global_declaration_part:1---line %d",block, sc_line());}
  }
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 303 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d any_declaration_part:0---EMPTY",block);}}
#line 2700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 304 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d any_declaration_part:1---line %d",block, sc_line());}

                                    }
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 310 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d any_decl:simple_decl---line %d",block, sc_line());}
                                          //b_func_prologue("main");  //was our test
                                          /*this is called at the end of var section (main)*/
                                       }
#line 2717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 314 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d any_decl:function_declaration---line %d",block, sc_line());}}
#line 2723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 318 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d simple_decl:constant_definition_part---line %d",block, sc_line());}}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 319 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d simple_decl:type_definition_part---line %d",block, sc_line());}}
#line 2735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 320 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d simple_decl:variable_declaration_part---line %d",block, sc_line());}}
#line 2741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 326 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d constant_definition_part:LEX_CONST---line %d",block, sc_line());}}
#line 2747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 330 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d constant_definition_list:constant_definition---line %d",block, sc_line());}}
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 331 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d constant_definition_list:constant_definition_list---line %d",block, sc_line());}}
#line 2759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 335 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d constant_definition:new_identifier = ---line %d",block, sc_line());}}
#line 2765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 339 "gram.y" /* yacc.c:1646  */
    {}
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 340 "gram.y" /* yacc.c:1646  */
    {}
#line 2777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 341 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("constant:number---");} (yyval.y_int)=(yyvsp[0].y_int);}
#line 2783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 342 "gram.y" /* yacc.c:1646  */
    {}
#line 2789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 346 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("number:sign unsigned_number---");}
                                        long tempInt;
                                        if((yyvsp[0].y_TN)->tag == REALCONSTANT){
                                          tempInt = (long)(yyvsp[0].y_TN)->u.realconstant;
                                        }
                                        else{
                                          tempInt = (yyvsp[0].y_TN)->u.intconstant;
                                        }
                                        if((yyvsp[-1].y_int) == 1)(yyval.y_int)=-tempInt; else (yyval.y_int)=tempInt;
                                    }
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 356 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in number:2---");}
                                        long tempInt;
                                        if((yyvsp[0].y_TN)->tag == REALCONSTANT){
                                          tempInt = (long)(yyvsp[0].y_TN)->u.realconstant;
                                        }
                                        else{
                                          tempInt = (yyvsp[0].y_TN)->u.intconstant;
                                        }
                                        (yyval.y_int)= tempInt;
                                    }
#line 2819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 369 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d Found in unsigned_number:INT CONST:%ld---line %d",block, (yyvsp[0].y_int), sc_line());}
                                      (yyval.y_TN) = makeIntConstNode((yyvsp[0].y_int));
                                    }
#line 2827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 372 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d Found in unsigned_number:REAL CONST:%f---line %d",block, (yyvsp[0].y_real), sc_line());}
                                      (yyval.y_TN) = makeRealConstNode((yyvsp[0].y_real));
                                    }
#line 2835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 378 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d Found in sign:1---POSITIVE",block);} (yyval.y_int) = 0;}
#line 2841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 379 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d Found in sign:2---NEGATIVE",block);} (yyval.y_int) = 1;}
#line 2847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 383 "gram.y" /* yacc.c:1646  */
    {/*might be needed later*/}
#line 2853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 384 "gram.y" /* yacc.c:1646  */
    {(yyval.y_TN) = (yyvsp[0].y_TN);}
#line 2859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 388 "gram.y" /* yacc.c:1646  */
    {/*idk if used*/}
#line 2865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 389 "gram.y" /* yacc.c:1646  */
    {(yyval.y_TN) = makeBoolNode(0);}
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 390 "gram.y" /* yacc.c:1646  */
    {(yyval.y_TN) = makeBoolNode(1);}
#line 2877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 394 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d Found in string:1---line %d",block, sc_line());}
                                      (yyval.y_TN) = makeCharConstNode((yyvsp[0].y_string)[0]);
                                    }
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 397 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1 | myDebugPart2){msg("%d Found in string:2---line %d",block, sc_line());}}
#line 2891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 401 "gram.y" /* yacc.c:1646  */
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
#line 2927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 440 "gram.y" /* yacc.c:1646  */
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
#line 2947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 458 "gram.y" /* yacc.c:1646  */
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
#line 2967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 473 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in type_denoter:2---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 474 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in type_denoter:3---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 475 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in type_denoter:4---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 476 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in type_denoter:5---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 2991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 480 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_ordinal_type:1---");}}
#line 2997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 481 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_ordinal_type:2---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 3003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 485 "gram.y" /* yacc.c:1646  */
    {}
#line 3009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 494 "gram.y" /* yacc.c:1646  */
    {}
#line 3015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 498 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in subrange_type:1---");}
                                          if((yyvsp[-2].y_int) <= (yyvsp[0].y_int)){
                                            (yyval.y_type) = ty_build_subrange(ty_build_basic(TYSIGNEDLONGINT),(yyvsp[-2].y_int),(yyvsp[0].y_int));
                                          }else{
                                            error("Subrange values are invalid!");
                                            (yyval.y_type) = ty_build_basic(TYERROR);
                                          }
                                        }
#line 3028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 509 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_pointer_type:1---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 3034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 518 "gram.y" /* yacc.c:1646  */
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
#line 3057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 536 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in pointer_domain_type:2---");} (yyval.y_type) = ty_build_ptr((yyvsp[0].y_type));/*To our knowledge this is not tested in PROJECT 1 */}
#line 3063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 540 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_procedural_type:1---");} (yyval.y_type) = ty_build_func(ty_build_basic(TYVOID), NULL, TRUE);}
#line 3069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 541 "gram.y" /* yacc.c:1646  */
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
#line 3097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 567 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in optional_procedural_type_formal_parameter_list:0---");}}
#line 3103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 568 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in optional_procedural_type_formal_parameter_list:1---");}}
#line 3109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 572 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter_list:1---");}}
#line 3115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 573 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter_list:2---");}}
#line 3121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 577 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:1---");}}
#line 3127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 578 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:2---");}}
#line 3133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 579 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:3---");}}
#line 3139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 580 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:4---");}}
#line 3145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 584 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_structured_type:1---");} (yyval.y_type) = (yyvsp[0].y_type);}
#line 3151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 585 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_structured_type:2---");}}
#line 3157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 586 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in new_structured_type:3---");}}
#line 3163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 592 "gram.y" /* yacc.c:1646  */
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
#line 3180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 607 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in array_index_list:1---");} (yyval.y_index_list) = addToArraySubList((yyvsp[0].y_type), NULL);}
#line 3186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 608 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in array_index_list:2---");} (yyval.y_index_list) = addToArraySubList((yyvsp[0].y_type), (yyvsp[-2].y_index_list));}
#line 3192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 613 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in ordinal_index_type:1---");} (yyval.y_type) = (yyvsp[0].y_type); /*this is a subrange return (for now)*/}
#line 3198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 614 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("Found in ordinal_index_type:2---");} (yyval.y_type) = (yyvsp[0].y_ST_ID); /*ST_Id*/}
#line 3204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 672 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d case_constant_list:one_case_constant---line %d", block, sc_line());}}
#line 3210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 673 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d case_constant_list:case_constant_list---line %d", block, sc_line());}}
#line 3216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 686 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_declaration_part---line %d",block, sc_line());}}
#line 3222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 691 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_declaration_list:1---line %d",block, sc_line());}}
#line 3228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 692 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_declaration_list:2---line %d",block, sc_line());}}
#line 3234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 696 "gram.y" /* yacc.c:1646  */
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
                                                      b_global_decl(idName, alignment, size);
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
#line 3280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 771 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d function_declaration:directive_list---line %d",block, sc_line());}
                                                                        //EXTERNAL DECLARED FUNCTIONS/PARAMETERS
                                                                        //cant have params (inputs)
                                                                        int directive = (yyvsp[-1].y_int);
                                                                        TN tempFuncNode = (yyvsp[-3].y_TN);
                                                                        ST_ID funcName = tempFuncNode->u.func_node.funcName;
                                                                        TYPETAG funcTYPETAG = tempFuncNode->u.func_node.typeTag;
                                                                        TYPE funcTYPE = tempFuncNode->u.func_node.type;
                                                                        ST_DR IDtoInstall = st_lookup(funcName, &block);
                                                                        if(IDtoInstall == NULL){
                                                                          //install it
                                                                          ST_DR DRtoInstall = stdr_alloc();
                                                                          DRtoInstall->tag = GDECL;
                                                                          DRtoInstall->u.decl.sc = EXTERN_SC;
                                                                          DRtoInstall->u.decl.type = funcTYPE;
                                                                          if(!(st_install(funcName,DRtoInstall))){
                                                                            bug("st_install failed in external function declaration");
                                                                          }else{
                                                                            if(myDump) stdr_dump(DRtoInstall);
                                                                            }

                                                                        }else{
                                                                          if(IDtoInstall->tag == GDECL) error("Duplicate forward or external function declaration");
                                                                          if(IDtoInstall->tag == FDECL){
                                                                            if(IDtoInstall->u.decl.type != funcTYPE){
                                                                              error("symantic error: duplicate function name, differnt types");
                                                                            }else{
                                                                              if(IDtoInstall->u.decl.sc == EXTERN_SC) error("symantic error: duplicate function name");
                                                                            }
                                                                          }//END GDECL check
                                                                        }//END Already installed check
                                                                      }
#line 3317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 803 "gram.y" /* yacc.c:1646  */
    {
                            funcST_ID = (yyvsp[-1].y_TN)->u.func_node.funcName;
                          }
#line 3325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 806 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d function_declaration:any_declaration_part---line %d",block,sc_line());}
                            b_func_prologue(st_get_id_str(funcST_ID));
                            insideFunc = 1;
                         }
#line 3334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 810 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d function_declaration:statement_part---line %d",block,sc_line());}
                                                                          /* statement_part semi*/
                                                                          TN tempFuncNode = (yyvsp[-6].y_TN);
                                                                          ST_ID funcName = tempFuncNode->u.func_node.funcName;
                                                                          TYPETAG funcTYPETAG = tempFuncNode->u.func_node.typeTag;
                                                                          TYPE funcTYPE = tempFuncNode->u.func_node.type;
                                                                          //need to handle assignments to func names first (aka returns)
                                                                          //b_prepare_return(funcTYPETAG);  //TYVOID for procedures
                                                                          b_func_epilogue(st_get_id_str(funcName));
                                                                      }
#line 3349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 823 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d function_heading:LEX_PROCEDURE---line %d",block, sc_line());}
                                                                                      TYPETAG tempTYPETAG = TYVOID;
                                                                                      ST_ID tempSTID = (yyvsp[-1].y_ST_ID);
                                                                                      (yyval.y_TN) = makeFuncNode(tempSTID, tempTYPETAG, ty_build_basic(tempTYPETAG));
                                                                                   }
#line 3359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 828 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d function_heading:LEX_FUNCTION---line %d",block, sc_line());}
                                                                                      TYPETAG tempTYPETAG;
                                                                                      if(ty_query((yyvsp[0].y_type)) == TYERROR){
                                                                                        error("No return type for function");
                                                                                      }else{
                                                                                        tempTYPETAG = ty_query((yyvsp[0].y_type));
                                                                                      }
                                                                                      ST_ID tempSTID = (yyvsp[-2].y_ST_ID);
                                                                                      (yyval.y_TN) = makeFuncNode(tempSTID, tempTYPETAG, (yyvsp[0].y_type));
                                                                                      /*MAKE FUNCTION NODE - fill it
                                                                                        new identifier for name
                                                                                        optional_par_formal_parameter_list for parameters
                                                                                        functiontype for type
                                                                                      */
                                                                                   }
#line 3379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 846 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d directive_list:directive---line %d",block, sc_line());} (yyval.y_int) = (yyvsp[0].y_int);}
#line 3385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 847 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d directive_list:directive_list---line %d",block, sc_line());}/*assume not used for now*/}
#line 3391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 851 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d directive:LEX_FORWARD---line %d",block, sc_line());} (yyval.y_int) = 1;}
#line 3397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 852 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d directive:LEX_EXTERNAL---line %d",block, sc_line());} (yyval.y_int) = 0;}
#line 3403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 856 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("functiontype:0---EMPTY");} (yyval.y_type) = ty_build_basic(TYERROR);}
#line 3409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 857 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart1){msg("functiontype:1--- %s", st_get_id_str((yyvsp[0].y_ST_ID)));}
                                    ST_ID tempID = (yyvsp[0].y_ST_ID);
                                    ST_DR tempDR = st_lookup(tempID, &block);
                                    if(tempDR != NULL){
                                      (yyval.y_type) = tempDR->u.typename.type;
                                    }else{
                                      error("Function returnType invalid: \"%s\"", st_get_id_str((yyvsp[0].y_ST_ID)));
                                    }
                                    }
#line 3423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 889 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d statement_part:compound_statement---line %d", block, sc_line());}}
#line 3429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 893 "gram.y" /* yacc.c:1646  */
    {if(!insideFunc)b_func_prologue("main");}
#line 3435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 895 "gram.y" /* yacc.c:1646  */
    {/*everything withing begin and end, could be func/procedure def, or main*/
                                                        if(myDebugPart2){msg("%d compound_statement:BEGIN and END---line %d", block, sc_line());}
                                                        if(!insideFunc)b_func_epilogue("main");
                                                        insideFunc = 0;
                                                        (yyval.y_TN) = (yyvsp[-1].y_TN);
                                                      }
#line 3446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 904 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d statement_sequence:statement---line %d", block, sc_line());}
                                                        (yyval.y_TN) = makeStatementNode(NULL, (yyvsp[0].y_TN));
                                                      }
#line 3454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 907 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d statement_sequence:statement_sequence---line %d", block, sc_line());}
                                                        (yyval.y_TN) = makeStatementNode((yyvsp[-2].y_TN), (yyvsp[0].y_TN));
                                                      }
#line 3462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 913 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d statement:structured_statement---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN); //can have the BEGIN and END
                                                        }
#line 3470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 916 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d statement:simple_statement---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 3478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 922 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d structured_statement:compound_statement---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN); //has BEGIN and END
                                                        }
#line 3486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 925 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d structured_statement:with_statement---line %d", block, sc_line());}}
#line 3492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 926 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d structured_statement:conditional_statement---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 3500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 929 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d structured_statement:repetitive_statement---line %d", block, sc_line());}}
#line 3506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 933 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d structured_statement:compound_statement---line %d", block, sc_line());}}
#line 3512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 942 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d structured_variable:variable_or_function_access---line %d", block, sc_line());}}
#line 3518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 946 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d conditional_statement:if_statement---line %d", block, sc_line());}
                                                            //treeNodeToString($1, 1);
                                                            //do backend for if/else statement
                                                            //unless in a loop or other "local causing" thing (check block number) then pass up, NO BACKEND
                                                            (yyval.y_TN) = (yyvsp[0].y_TN);
                                                          }
#line 3529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 952 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d conditional_statement:case_statement---line %d", block, sc_line());}}
#line 3535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 956 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d simple_if:LEX_IF and LEX_THEN---line %d", block, sc_line());}
                                                              (yyval.y_TN) = makeIfNode((yyvsp[-2].y_TN),(yyvsp[0].y_TN));
                                                           }
#line 3543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 962 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d if_statement:LEX_ELSE---line %d", block, sc_line());}
                                                              (yyval.y_TN) = makeElseNode((yyvsp[-2].y_TN), (yyvsp[0].y_TN)); //passes up IF_NODE
                                                           }
#line 3551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 965 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d if_statement:2---line %d", block, sc_line());}}
#line 3557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 973 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d optional_semicolon_or_else_branch:optional_semicolon---line %d", block, sc_line());}}
#line 3563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 974 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d optional_semicolon_or_else_branch:case_default---line %d", block, sc_line());}}
#line 3569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 978 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d case_element_list:case_element---line %d", block, sc_line());}}
#line 3575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 979 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d case_element_list:case_element_list---line %d", block, sc_line());}}
#line 3581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 987 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d case_default:LEX_ELSE---line %d", block, sc_line());}}
#line 3587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 988 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d case_default:semi LEX_ELSE---line %d", block, sc_line());}}
#line 3593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 992 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d repetitive_statement:repeat_statement---line %d", block, sc_line());}}
#line 3599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 993 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d repetitive_statement:while_statement---line %d", block, sc_line());}
                                                              treeNodeToString((yyvsp[0].y_TN), 1);
                                                              (yyval.y_TN) = (yyvsp[0].y_TN);
                                                            }
#line 3608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 997 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d repetitive_statement:for_statement---line %d", block, sc_line());}}
#line 3614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1001 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d repeat_statement:LEX_REPEAT---line %d", block, sc_line());}}
#line 3620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1005 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d while_statement:LEX_WHILE---line %d", block, sc_line());}
                                                                  (yyval.y_TN) = makeWhileNode((yyvsp[-2].y_TN),(yyvsp[0].y_TN));
                                                                }
#line 3628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1020 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d simple_statement:1---EMPTY STATEMENT", block);}
                                          /*no return, if last stement has a semi, this is the filler to allow it*/}
#line 3635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1022 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d simple_statement:2---line %d", block, sc_line());}
                                          if(myDebugPart2){msg("Calling genBackendAssignment() on");treeNodeToString((yyvsp[0].y_TN), 1);}
                                          //always call an assigment with (node, 0, 0) from gramar
                                          if((yyvsp[0].y_TN)->tag != ERROR_NODE) genBackendAssignment((yyvsp[0].y_TN), 0, 0);

                                        }
#line 3646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1028 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d simple_statement:3---line %d", block, sc_line());}

                                        }
#line 3654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1031 "gram.y" /* yacc.c:1646  */
    {/*not used, not part of standard pascal*/}
#line 3660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1051 "gram.y" /* yacc.c:1646  */
    {(yyval.y_TN) = (yyvsp[0].y_TN);}
#line 3666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1057 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d assignment_or_call_statement:1---line %d", block, sc_line());}
                                                                        /*rest_of_statement can be empty, or :=*/
                                                                        TN tempTreeNode;
                                                                        if((yyvsp[-1].y_TN)->tag == VAR_NODE){
                                                                          if((yyvsp[0].y_TN)->tag == FUNC_NODE && (yyvsp[0].y_TN)->u.func_node.typeTag == TYVOID){
                                                                            error("Cannot convert between nondata types");
                                                                            (yyval.y_TN) = makeErrorNode();
                                                                          }else if((yyvsp[0].y_TN)->tag != ERROR_NODE){
                                                                          tempTreeNode = makeAssignNode((yyvsp[-1].y_TN), (yyvsp[0].y_TN));
                                                                          (yyval.y_TN) = tempTreeNode;
                                                                        }else{
                                                                            error("Expected procedure name, saw data");
                                                                            (yyval.y_TN) = (yyvsp[0].y_TN);
                                                                        }
                                                                      }else if((yyvsp[-1].y_TN)->tag == FUNC_NODE){
                                                                        if((yyvsp[0].y_TN)->tag == ERROR_NODE){
                                                                          //rest of statement is empty for function calls
                                                                          (yyval.y_TN) = (yyvsp[-1].y_TN);
                                                                        }else{ //assigning to a function name
                                                                          //error("not a return inside a function definition");
                                                                          error("Assignment requires l-value on the left");
                                                                          (yyval.y_TN) = makeErrorNode();
                                                                        }

                                                                      }else if((yyvsp[-1].y_TN)->tag == ERROR_NODE){
                                                                        //undeclared id
                                                                        (yyval.y_TN) = (yyvsp[-1].y_TN);

                                                                      }else if((yyvsp[-1].y_TN)->tag != VAR_NODE && (yyvsp[0].y_TN)->tag != ERROR_NODE){
                                                                        error("Assignment requires l-value on the left");
                                                                        (yyval.y_TN) = makeErrorNode();
                                                                      }else{
                                                                        error("Procedure call expected");
                                                                        (yyval.y_TN) = makeErrorNode();
                                                                      }

                                                                    }
#line 3708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1097 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_or_function_access_maybe_assignment:1--- %s",block, st_get_id_str((yyvsp[0].y_ST_ID)));}
                                                            ST_DR tempDR = st_lookup((yyvsp[0].y_ST_ID),&block);
                                                            STDR_TAG tempSTDR_TAG;
                                                            TYPE tempTYPE;
                                                            if(tempDR == NULL){
                                                              error("Undeclared identifier \"%s\" in expression",st_get_id_str((yyvsp[0].y_ST_ID)));
                                                              (yyval.y_TN) = makeErrorNode();
                                                            }else{
                                                              //ECONST, GDECL, LDECL, PDECL, FDECL, TYPENAME
                                                              tempSTDR_TAG = tempDR->tag;
                                                              tempTYPE = tempDR->u.decl.type;

                                                              if(tempSTDR_TAG == GDECL | tempSTDR_TAG == LDECL){
                                                                if(tempDR->u.decl.sc == EXTERN_SC){
                                                                  (yyval.y_TN) = makeFuncNode((yyvsp[0].y_ST_ID), ty_query(tempTYPE), tempTYPE);
                                                                }else if(tempDR->u.decl.sc == NO_SC){
                                                                  (yyval.y_TN) = makeVarNode((yyvsp[0].y_ST_ID));
                                                                }else{
                                                                  bug("unhandled storage class in variable_or_function_access_maybe_assignment:identifier");
                                                                }

                                                              }else if(tempSTDR_TAG == FDECL){
                                                                (yyval.y_TN) = makeFuncNode((yyvsp[0].y_ST_ID), ty_query(tempTYPE), tempTYPE);
                                                              }else{
                                                                bug("variable_or_function_access_maybe_assignment:identifier unhandled STDR_TAG");
                                                              }
                                                              /*check if function name of current function definition (for setting return value)
                                                                create function return node (or something)
                                                              */
                                                              /*check if a procedure call name (that has no parameters)
                                                                go get this procedures top node, or create it i guess
                                                              */
                                                          }//was found in the DR
                                                          }
#line 3747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1132 "gram.y" /* yacc.c:1646  */
    {/*not used*/if(myDebugPart2){msg("variable_or_function_access_maybe_assignment:2---OUT OF SCOPE?!?! ");}}
#line 3753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1134 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_or_function_access_maybe_assignment:3---line %d", block, sc_line());}
                                                            /*example:    foo(x)^ := 6  */
                                                              (yyval.y_TN) = (yyvsp[0].y_TN);
                                                          }
#line 3762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1141 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rest_of_statement:0---EMPTY", block);}
                                                            //Procedure or function call
                                                            (yyval.y_TN) = makeErrorNode();
                                                          }
#line 3771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1145 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rest_of_statement:1---line %d", block, sc_line());}
                                                             (yyval.y_TN) = (yyvsp[0].y_TN);
                                                          }
#line 3779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1232 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d variable_access_or_typename:variable_or_function_access_no_id---line %d", block, sc_line());}}
#line 3785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1233 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d variable_access_or_typename:LEX_ID---line %d", block, sc_line());}}
#line 3791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1253 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d boolean_expression:expression---line %d", block, sc_line());}
                                                            (yyval.y_TN) = (yyvsp[0].y_TN);
                                                            //check and make sure its a relop node
                                                            //else ERROR
                                                          }
#line 3801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1261 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d expression:1---line %d", block, sc_line());}
                                                            relationalType relType = (yyvsp[-1].y_int);
                                                            (yyval.y_TN) = makeRelopNode((yyvsp[-2].y_TN), relType, (yyvsp[0].y_TN));
                                                         }
#line 3810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1265 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d expression:2---line %d", block, sc_line());}
                                                          /* probably unused for part 2*/
                                                         }
#line 3818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1268 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d expression:3---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                         }
#line 3826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1274 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d simple_expression:1---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 3834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1277 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d simple_expression:2---line %d", block, sc_line());}
                                                          binopType tempBinopType;

                                                          if((yyvsp[-1].y_int) == 1) tempBinopType = ADD;
                                                          else tempBinopType = SUB;

                                                          (yyval.y_TN) = makeBinopNode((yyvsp[-2].y_TN), (yyvsp[0].y_TN), tempBinopType);
                                                        }
#line 3847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1285 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d simple_expression:3---line %d", block, sc_line());}}
#line 3853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1286 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d simple_expression:4---line %d", block, sc_line());}}
#line 3859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1287 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d simple_expression:5---line %d", block, sc_line());}}
#line 3865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1291 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d term:1---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 3873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1294 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d term:2---line %d", block, sc_line());}
                                                          binopType tempBinopType;
                                                          if((yyvsp[-1].y_int) == 0){//integer division
                                                            tempBinopType = INT_DIV;
                                                          }else if((yyvsp[-1].y_int) == 1){//modulus
                                                            tempBinopType = MOD;
                                                          }else if((yyvsp[-1].y_int) == 2){//real division
                                                            tempBinopType = REAL_DIV;
                                                          }else if((yyvsp[-1].y_int) == 3){//multiplication
                                                            tempBinopType = MULT;
                                                          }

                                                          (yyval.y_TN) = makeBinopNode((yyvsp[-2].y_TN), (yyvsp[0].y_TN), tempBinopType);

                                                        }
#line 3893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1309 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d term:3---line %d", block, sc_line());}}
#line 3899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1313 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d signed_primary:1---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 3907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1316 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msgn("%d signed_primary:", block);}
                                                          if((yyvsp[-1].y_int) == 1){
                                                            if(myDebugPart2){msg(" NEGATIVE---");}
                                                            (yyval.y_TN) = makeNegNumNode((yyvsp[0].y_TN));
                                                          }else{
                                                            if(myDebugPart2){msg(" POSITIVE---");}
                                                            (yyval.y_TN) = (yyvsp[0].y_TN);
                                                          }
                                                        }
#line 3921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1328 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d primary:1---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 3929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1331 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d primary:2---line %d", block, sc_line());}
                                                          /*idk what a LEX_POW is*/
                                                        }
#line 3937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1334 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d primary:3---line %d", block, sc_line());}
                                                          /*LEX_POWER  **   */
                                                        }
#line 3945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1337 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d primary:4---line %d", block, sc_line());}
                                                          /*NOT SURE IF leX_IS NEEDS TO BE HANDLED*/
                                                        }
#line 3953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1343 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d signed_factor:1---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 3961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1346 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d signed_factor:2---line %d", block, sc_line());}
                                                          if((yyvsp[-1].y_int) == '-'){
                                                            (yyval.y_TN) = makeNegNumNode((yyvsp[0].y_TN));
                                                          }else{
                                                            (yyval.y_TN) = (yyvsp[0].y_TN);
                                                          }
                                                        }
#line 3973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1356 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d factor:1---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 3981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1359 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d factor:2---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 3989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1362 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d factor:3---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);  //int or real node
                                                        }
#line 3997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1365 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d factor:4---line %d", block, sc_line());}}
#line 4003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1366 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d factor:5---line %d", block, sc_line());}}
#line 4009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1367 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d factor:6---line %d", block, sc_line());}}
#line 4015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1375 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_or_function_access:1---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 4023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1378 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_or_function_access:2---line %d", block, sc_line());}
                                                          (yyval.y_TN) = (yyvsp[0].y_TN);
                                                        }
#line 4031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1384 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_or_function_access_no_standard_function:1---line %d", block, sc_line());}


                                                          ST_DR tempDR = st_lookup((yyvsp[0].y_ST_ID),&block);
                                                          STDR_TAG tempSTDR_TAG;
                                                          TYPE tempTYPE;
                                                          if(tempDR == NULL){
                                                            error("Undeclared identifier \"%s\" in expression",st_get_id_str((yyvsp[0].y_ST_ID)));
                                                            (yyval.y_TN) = makeErrorNode();
                                                          }else{
                                                            //ECONST, GDECL, LDECL, PDECL, FDECL, TYPENAME
                                                            tempSTDR_TAG = tempDR->tag;
                                                            tempTYPE = tempDR->u.decl.type;

                                                            if(tempSTDR_TAG == GDECL | tempSTDR_TAG == LDECL){
                                                              if(tempDR->u.decl.sc == EXTERN_SC){
                                                                (yyval.y_TN) = makeFuncNode((yyvsp[0].y_ST_ID), ty_query(tempTYPE), tempTYPE);
                                                              }else if(tempDR->u.decl.sc == NO_SC){
                                                                (yyval.y_TN) = makeVarNode((yyvsp[0].y_ST_ID));
                                                              }else{
                                                                bug("unhandled storage class in variable_or_function_access_maybe_assignment:identifier");
                                                              }

                                                            }else if(tempSTDR_TAG == FDECL){
                                                              (yyval.y_TN) = makeFuncNode((yyvsp[0].y_ST_ID), ty_query(tempTYPE), tempTYPE);
                                                            }else{
                                                              bug("variable_or_function_access_maybe_assignment:identifier unhandled STDR_TAG");
                                                            }
                                                            // check if function name of current function definition (for setting return value)
                                                            //   create function return node (or something)
                                                            //
                                                            // check if a procedure call name (that has no parameters)
                                                            //   go get this procedures top node, or create it i guess

                                                        }//was found in the DR

                                                      }
#line 4073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1422 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_or_function_access_no_standard_function:2---line %d", block, sc_line());}}
#line 4079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1426 "gram.y" /* yacc.c:1646  */
    {/*not used*/}
#line 4085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1427 "gram.y" /* yacc.c:1646  */
    {/*not used*/}
#line 4091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1428 "gram.y" /* yacc.c:1646  */
    {/*not used*/}
#line 4097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1429 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_or_function_access_no_id:4---line %d", block, sc_line());}
                                                                                        (yyval.y_TN) = (yyvsp[-1].y_TN);
                                                                                      }
#line 4105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1432 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_or_function_access_no_id:5---line %d", block, sc_line());}
                                                                                        /*something ex:  p^ := 6*/
                                                                                      }
#line 4113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1435 "gram.y" /* yacc.c:1646  */
    {/*for project 3, not used in part 2. for array accesses*/}
#line 4119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1436 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_or_function_access_no_id:7---line %d", block, sc_line());}
                                                                                        /*function call, expr*/
                                                                                      }
#line 4127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1439 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d variable_or_function_access_no_id:8---line %d", block, sc_line());}
                                                                                        /*like a malloc but in pascal, continue on April 13th, monday*/
                                                                                      }
#line 4135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1455 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d member_designator:expression---line %d", block, sc_line());}}
#line 4141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1456 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart3){msg("%d member_designator:LEX_RANGE---line %d", block, sc_line());}}
#line 4147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1460 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d standard_functions:rts_fun_onepar(actual_parameter)---line %d",block, sc_line());}
                                                  unopType tempUnopType;
                                                  if((yyvsp[-3].y_int) == pas_ORD){
                                                    tempUnopType = ORD;
                                                  }else if((yyvsp[-3].y_int) == pas_CHR){
                                                    tempUnopType = CHR;
                                                  }else{
                                                    bug("Unexpected \"rts_fun_onepar\" value");
                                                  }
                                                  (yyval.y_TN) = makeUnopNode((yyvsp[-1].y_TN),tempUnopType);
                                                }
#line 4163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1471 "gram.y" /* yacc.c:1646  */
    {}
#line 4169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1472 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d standard_functions:rts_fun_parlist(actual_parameter_list)---line %d",block, sc_line());}
                                                    unopType tempUnopType;
                                                    if((yyvsp[-3].y_int) == pas_SUCC){
                                                      tempUnopType = SUCC;
                                                    }else if((yyvsp[-3].y_int) == pas_PRED){
                                                      tempUnopType = PRED;
                                                    }else{
                                                      bug("Unexpected \"rts_fun_onepar\" value");
                                                    }
                                                    (yyval.y_TN) = makeUnopNode((yyvsp[-1].y_TN),tempUnopType);
                                                  }
#line 4185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1497 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_ABS---line %d",block, sc_line());};}
#line 4191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1498 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_SQR---line %d",block, sc_line());};}
#line 4197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1499 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_SIN---line %d",block, sc_line());};}
#line 4203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1500 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_COS---line %d",block, sc_line());};}
#line 4209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1501 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_EXP---line %d",block, sc_line());};}
#line 4215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1502 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_LN---line %d",block, sc_line());};}
#line 4221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1503 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_SQRT---line %d",block, sc_line());};}
#line 4227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1504 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_ARCTAN---line %d",block, sc_line());};}
#line 4233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1505 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_ARG---line %d",block, sc_line());};}
#line 4239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1506 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_TRUNC---line %d",block, sc_line());};}
#line 4245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1507 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_ROUND---line %d",block, sc_line());};}
#line 4251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1508 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_CARD---line %d",block, sc_line());};}
#line 4257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1509 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_ORD---line %d",block, sc_line());}; (yyval.y_int) = pas_ORD;}
#line 4263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1510 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_CHR---line %d",block, sc_line());}; (yyval.y_int) = pas_CHR;}
#line 4269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1511 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_ODD---line %d",block, sc_line());};}
#line 4275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1512 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_EMPTY---line %d",block, sc_line());};}
#line 4281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1513 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_POSITION---line %d",block, sc_line());};}
#line 4287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1514 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_LASTPOSITION---line %d",block, sc_line());};}
#line 4293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1515 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_LENGTH---line %d",block, sc_line());};}
#line 4299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1516 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_TRIM---line %d",block, sc_line());};}
#line 4305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1517 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_BINDING---line %d",block, sc_line());};}
#line 4311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1518 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_DATE---line %d",block, sc_line());};}
#line 4317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1519 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_onepar:p_TIME---line %d",block, sc_line());};}
#line 4323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1523 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_parlist:p_SUCC---line %d",block, sc_line());}; (yyval.y_int) = pas_SUCC;}
#line 4329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1524 "gram.y" /* yacc.c:1646  */
    {if(myDebugPart2){msg("%d rts_fun_parlist:p_PRED---line %d",block, sc_line());}; (yyval.y_int) = pas_PRED;}
#line 4335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1528 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = NE;}
#line 4341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1529 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = LE;}
#line 4347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1530 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = GE;}
#line 4353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1531 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = EQ;}
#line 4359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1532 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = LT;}
#line 4365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1533 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = GT;}
#line 4371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1537 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = 0;}
#line 4377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1538 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = 1;}
#line 4383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1539 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = 2;}
#line 4389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1540 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = 3;}
#line 4395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1544 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = 0;}
#line 4401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1545 "gram.y" /* yacc.c:1646  */
    {(yyval.y_int) = 1;}
#line 4407 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4411 "y.tab.c" /* yacc.c:1646  */
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
#line 1557 "gram.y" /* yacc.c:1906  */


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
