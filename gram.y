/*A Bison parser for the programming language Pascal.
  Copyright (C) 1989-2002 Free Software Foundation, Inc.

  Authors: Jukka Virtanen <jtv@hut.fi>
           Helsinki University of Technology
           Computing Centre
           Finland

           Peter Gerwinski <peter@gerwinski.de>
           Essen, Germany

           Bill Cox <bill@cygnus.com> (error recovery rules)

           Frank Heckenbach <frank@pascal.gnu.de>

  This file is part of GNU Pascal.

  GNU Pascal is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published
  by the Free Software Foundation; either version 1, or (at your
  option) any later version.

  GNU Pascal is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with GNU Pascal; see the file COPYING. If not, write to the
  Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
  02111-1307, USA. */

/* Bison parser for ISO 7185 Pascal originally written on
 * 3 Feb 1987 by Jukka Virtanen <jtv@hut.fi>
 *
 * Modified for use at the University of South Carolina's CSCE 531
 * (Compiler Construction) course (Spring 2005) by Stephen Fenner
 * <fenner@cse.sc.edu>
 * Simplified (Spring 2015) by Stephen Fenner
 *
 * SHIFT/REDUCE CONFLICTS
 *
 * The dangling else will not cause a shift/reduce conflict - it's
 * solved by precedence rules.
 */

%{

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
%}

/* Start symbol for the grammar */

%start pascal_program

/* The union representing a semantic stack entry */
%union {
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
}

/*OUR ADDED ONES*/
%type <y_index_list> array_index_list
%type <y_listOfIDs> id_list
%type <y_ST_ID> new_identifier new_identifier_1 typename identifier
%type <y_type> type_denoter new_ordinal_type subrange_type array_type ordinal_index_type new_pointer_type new_procedural_type
    new_structured_type pointer_domain_type functiontype
%type <y_int> constant number LEX_INTCONST sign adding_operator multiplying_operator directive_list directive rts_fun_onepar
                  rts_fun_parlist relational_operator
%type <y_real> LEX_REALCONST
//%type <y_single>
%type <y_char> '+' '-'
%type <y_string> LEX_STRCONST
//s%type <y_bool>

%type <y_TN> variable_or_function_access_maybe_assignment expression variable_or_function_access_no_id string
    simple_expression rest_of_statement unsigned_number factor signed_factor primary standard_functions
    signed_primary term assignment_or_call_statement constant_literal predefined_literal actual_parameter
    variable_or_function_access variable_or_function_access_no_standard_function function_heading actual_parameter_list




/*END OUR ADDED*/


%token <y_string> LEX_ID
//%token <y_int> LEX_INTCONST

/* Reserved words. */

/* Reserved words in Standard Pascal */
%token LEX_ARRAY LEX_BEGIN LEX_CASE LEX_CONST LEX_DO LEX_DOWNTO LEX_END
%token LEX_FILE LEX_FOR LEX_FUNCTION LEX_GOTO LEX_IF LEX_LABEL LEX_NIL
%token LEX_OF LEX_PACKED LEX_PROCEDURE LEX_PROGRAM LEX_RECORD LEX_REPEAT
%token LEX_SET LEX_THEN LEX_TO LEX_TYPE LEX_UNTIL LEX_VAR LEX_WHILE LEX_WITH
%token LEX_FORWARD

/* The following ones are not tokens used in the parser.
 * However they are used in the same context as some tokens,
 * so assign unique numbers to them.
 */
%token pp_SIN pp_COS pp_EXP pp_LN pp_SQRT pp_ARCTAN rr_POW rr_EXPON
%token r_WRITE r_READ r_INITFDR r_LAZYTRYGET r_LAZYGET r_LAZYUNGET r_POW r_EXPON
%token z_ABS z_ARCTAN z_COS z_EXP z_LN z_SIN z_SQRT z_POW z_EXPON
%token set_card set_isempty set_equal set_le set_less set_in set_clear
%token set_include set_exclude set_include_range set_copy
%token set_intersection set_union set_diff set_symdiff
%token p_DONEFDR gpc_IOCHECK gpc_RUNTIME_ERROR

/* Redefinable identifiers. */

/* Redefinable identifiers in Standard Pascal */
%token p_INPUT p_OUTPUT p_REWRITE p_RESET p_PUT p_GET p_WRITE p_READ
%token p_WRITELN p_READLN p_PAGE p_NEW p_DISPOSE
%token p_ABS p_SQR p_SIN p_COS p_EXP p_LN p_SQRT p_ARCTAN
%token p_TRUNC p_ROUND p_PACK p_UNPACK p_ORD p_CHR p_SUCC p_PRED
%token p_ODD p_EOF p_EOLN p_MAXINT p_TRUE p_FALSE

/* Additional redefinable identifiers for Borland Pascal */
%token bp_RANDOM bp_RANDOMIZE BREAK CONTINUE

/* redefinable keyword extensions */
%token RETURN_ RESULT EXIT FAIL p_CLOSE CONJUGATE p_DEFINESIZE SIZEOF
%token BITSIZEOF ALIGNOF TYPEOF gpc_RETURNADDRESS gpc_FRAMEADDRESS
%token LEX_LABEL_ADDR

/* GPC internal tokens */
%token LEX_INTCONST LEX_STRCONST LEX_REALCONST
%token LEX_RANGE LEX_ELLIPSIS

/* We don't declare precedences for operators etc. We don't need
   them since our rules define precedence implicitly, and too many
   precedences increase the chances of real conflicts going unnoticed. */
%token LEX_ASSIGN
%token '<' '=' '>' LEX_IN LEX_NE LEX_GE LEX_LE
%token '-' '+' LEX_OR LEX_OR_ELSE LEX_CEIL_PLUS LEX_CEIL_MINUS LEX_FLOOR_PLUS LEX_FLOOR_MINUS
%token '/' '*' LEX_DIV LEX_MOD LEX_AND LEX_AND_THEN LEX_SHL LEX_SHR LEX_XOR LEX_CEIL_MULT LEX_CEIL_DIV LEX_FLOOR_MULT LEX_FLOOR_DIV
%token LEX_POW LEX_POWER LEX_IS LEX_AS
%token LEX_NOT

/* Various extra tokens */
%token LEX_EXTERNAL p_MARK p_RELEASE p_UPDATE p_GETTIMESTAMP p_UNBIND
%token p_EXTEND bp_APPEND p_BIND p_SEEKREAD p_SEEKWRITE p_SEEKUPDATE LEX_SYMDIFF
%token p_ARG p_CARD p_EMPTY p_POSITION p_LASTPOSITION p_LENGTH p_TRIM p_BINDING
%token p_DATE p_TIME LEX_RENAME LEX_IMPORT LEX_USES LEX_QUALIFIED LEX_ONLY

/* Precedence rules */

/* The following precedence declarations are just to avoid the dangling
   else shift-reduce conflict. We use prec_if rather than LEX_IF to
   avoid possible conflicts elsewhere involving LEX_IF going unnoticed. */
%nonassoc prec_if
%nonassoc LEX_ELSE

/* These tokens help avoid S/R conflicts from error recovery rules. */
%nonassoc lower_than_error
%nonassoc error




%%

/* Pascal parser starts here */

pascal_program:
    main_program_declaration '.'
  ;

main_program_declaration:
    program_heading semi any_global_declaration_part statement_part  {if(myDebugPart2){msg("%d main_program_declaration:1---line %d",block, sc_line());}}
  ;

program_heading:
    LEX_PROGRAM new_identifier optional_par_id_list            {if(myDebugPart2){msg("%d program_heading:1---%s",block,st_get_id_str($2));}}
  ;

optional_par_id_list:
    /* empty */
  | '(' id_list ')'
  ;

id_list:
    new_identifier                {if(myDebugPart1){msg("Found in id_list:1---");} $$ = addToList($1, NULL);}
  | id_list ',' new_identifier    {if(myDebugPart1){msg("Found in id_list:2---");} $$ = addToList($3, $1);}
  ;

typename:
    LEX_ID          {if(myDebugPart1 | myDebugPart2){msg("%d Found in typename:LEX_ID---%s",block, $1);}$$ = st_enter_id($1);}
  ;

identifier:  /*ST_ID*/
    LEX_ID          {if(myDebugPart1 | myDebugPart2){msg("\n %d identifier:LEX_ID---%s", block, $1);} $$ = st_enter_id($1);}
  ;

new_identifier:
    new_identifier_1    {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier:new_identifier_1---%s",block, st_get_id_str($1));}  $$ = $1;}
  ;

new_identifier_1:
    LEX_ID              {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:LEX_ID---%s",block,$1);} $$ = st_enter_id($1);}
/* Standard Pascal constants */
  | p_MAXINT  {}
  | p_FALSE  {}
  | p_TRUE  {}
/* Standard Pascal I/O */
  | p_INPUT  {}
  | p_OUTPUT  {}
  | p_REWRITE  {}
  | p_RESET  {}
  | p_PUT  {}
  | p_GET  {}
  | p_WRITE  {}
  | p_READ  {}
  | p_WRITELN  {}
  | p_READLN  {}
  | p_PAGE  {}
  | p_EOF  {}
  | p_EOLN  {}
/* Standard Pascal heap handling */
  | p_NEW  {}
  | p_DISPOSE  {}
/* Standard Pascal arithmetic */
  | p_ABS  {}
  | p_SQR  {}
  | p_SIN  {}
  | p_COS  {}
  | p_EXP  {}
  | p_LN  {}
  | p_SQRT  {}
  | p_ARCTAN  {}
  | p_TRUNC  {}
  | p_ROUND  {}
/* Standard Pascal transfer functions */
  | p_PACK  {}
  | p_UNPACK  {}
/* Standard Pascal ordinal functions */
  | p_ORD   {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:p_ORD---line %d",block, sc_line());};}
  | p_CHR   {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:p_CHR---line %d",block, sc_line());};}
  | p_SUCC  {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:p_SUCC---line %d",block, sc_line());};}
  | p_PRED  {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:p_PRED---line %d",block, sc_line());};}
  | p_ODD   {if(myDebugPart1 | myDebugPart2){msg("%d new_identifier_1:p_ODD---line %d",block, sc_line());};}
/* Other extensions */
  | BREAK  {}
  | CONTINUE  {}
  | RETURN_  {}
  | RESULT  {}
  | EXIT  {}
  | SIZEOF  {}
  | FAIL  {}  {}
  | BITSIZEOF  {}
  ;

any_global_declaration_part:
    /* empty */                               {if(myDebugPart2){msg("%d any_global_declaration_part:0---EMPTY",block);}}
  | any_global_declaration_part any_decl      {if(myDebugPart2){msg("%d any_global_declaration_part:1---line %d",block, sc_line());}
  }
  ;


any_declaration_part:   /* var decls for local vars*/
    /* empty */                     {if(myDebugPart2){msg("%d any_declaration_part:0---EMPTY",block);}}
  | any_declaration_part any_decl   {if(myDebugPart2){msg("%d any_declaration_part:1---line %d",block, sc_line());}

                                    }
  ;

any_decl:
    simple_decl                        {if(myDebugPart2){msg("%d any_decl:simple_decl---line %d",block, sc_line());}
                                          //b_func_prologue("main");  //was our test
                                          /*this is called at the end of var section (main)*/
                                       }
  | function_declaration               {if(myDebugPart2){msg("%d any_decl:function_declaration---line %d",block, sc_line());}}
  ;

simple_decl:
    constant_definition_part           {if(myDebugPart1 | myDebugPart2){msg("%d simple_decl:constant_definition_part---line %d",block, sc_line());}}
  | type_definition_part               {if(myDebugPart1 | myDebugPart2){msg("%d simple_decl:type_definition_part---line %d",block, sc_line());}}
  | variable_declaration_part          {if(myDebugPart1 | myDebugPart2){msg("%d simple_decl:variable_declaration_part---line %d",block, sc_line());}}
  ;

/* constant definition part */

constant_definition_part:
    LEX_CONST constant_definition_list            {if(myDebugPart2){msg("%d constant_definition_part:LEX_CONST---line %d",block, sc_line());}}
  ;

constant_definition_list:
    constant_definition                           {if(myDebugPart2){msg("%d constant_definition_list:constant_definition---line %d",block, sc_line());}}
  | constant_definition_list constant_definition  {if(myDebugPart2){msg("%d constant_definition_list:constant_definition_list---line %d",block, sc_line());}}
  ;

constant_definition:
    new_identifier '=' static_expression semi     {if(myDebugPart2){msg("%d constant_definition:new_identifier = ---line %d",block, sc_line());}}
  ;

constant:
    identifier                    {}
  | sign identifier               {}
  | number                        {if(myDebugPart1){msg("constant:number---");} $$=$1;}
  | constant_literal              {}
  ;

number:     /*stripped to all ints, could be a problem. currently only effects subranges*/
    sign unsigned_number            {if(myDebugPart1){msg("number:sign unsigned_number---");}
                                        long tempInt;
                                        if($2->tag == REALCONSTANT){
                                          tempInt = (long)$2->u.realconstant;
                                        }
                                        else{
                                          tempInt = $2->u.intconstant;
                                        }
                                        if($1 == 1)$$=-tempInt; else $$=tempInt;
                                    }
  | unsigned_number                 {if(myDebugPart1){msg("Found in number:2---");}
                                        long tempInt;
                                        if($1->tag == REALCONSTANT){
                                          tempInt = (long)$1->u.realconstant;
                                        }
                                        else{
                                          tempInt = $1->u.intconstant;
                                        }
                                        $$= tempInt;
                                    }
  ;

unsigned_number:  /*TREE NODE*/
    LEX_INTCONST                    {if(myDebugPart1 | myDebugPart2){msg("%d Found in unsigned_number:INT CONST:%ld---line %d",block, $1, sc_line());}
                                      $$ = makeIntConstNode($1);
                                    }
  | LEX_REALCONST                   {if(myDebugPart1 | myDebugPart2){msg("%d Found in unsigned_number:REAL CONST:%f---line %d",block, $1, sc_line());}
                                      $$ = makeRealConstNode($1);
                                    }
  ;

sign:
    '+'                            {if(myDebugPart1 | myDebugPart2){msg("%d Found in sign:1---POSITIVE",block);} $$ = 0;}
  | '-'                            {if(myDebugPart1 | myDebugPart2){msg("%d Found in sign:2---NEGATIVE",block);} $$ = 1;}
  ;

constant_literal:        /*TREE NODE*/
    string                         {/*might be needed later*/}
  | predefined_literal             {$$ = $1;}
  ;

predefined_literal:     /*TREE NODE*/
    LEX_NIL                        {/*idk if used*/}
  | p_FALSE                        {$$ = makeBoolNode(0);}
  | p_TRUE                         {$$ = makeBoolNode(1);}
  ;

string:                  /*TREE NODE*/
    LEX_STRCONST                    {if(myDebugPart1 | myDebugPart2){msg("%d Found in string:1---line %d",block, sc_line());}
                                      $$ = makeCharConstNode($1[0]);
                                    }
  | string LEX_STRCONST             {if(myDebugPart1 | myDebugPart2){msg("%d Found in string:2---line %d",block, sc_line());}}
  ;

type_definition_part:
    LEX_TYPE type_definition_list semi        {if(myDebugPart1){msg("Found type_definition_part:1 resolving pointers---");}
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
  ;

type_definition_list:
    type_definition
  | type_definition_list semi type_definition
  ;

type_definition:
    new_identifier '=' type_denoter           {if(myDebugPart1){msgn("type_definition:1---"); ty_print_typetag(ty_query($3)); msg("");}


                                                ST_ID IDtoInstall = st_lookup($1, &block);
                                                if(IDtoInstall == NULL){
                                                  ST_DR DRtoInstall = stdr_alloc();
                                                  DRtoInstall->tag = TYPENAME;
                                                  DRtoInstall->u.typename.type = $3;
                                                  if(!(st_install($1,DRtoInstall))){
                                                    bug("st_install failed in type_definition");
                                                  }else{
                                                    //if(myDump)stdr_dump(DRtoInstall);
                                                  }
                                                }else error("Duplicate variable declaration: \"%s\"", st_get_id_str(IDtoInstall));
                                              }
  ;

type_denoter:
    typename                            {if(myDebugPart1){msg("Found in type_denoter:1---");}
                                          if($1 != NULL){
                                            ST_DR testTemp = st_lookup($1,&block);
                                            if(testTemp != NULL){
                                              $$ = testTemp->u.typename.type;
                                            }else{
                                               error("Undeclared type name: \"%s\"", st_get_id_str($1));
                                               $$ = ty_build_basic(TYERROR);
                                             }

                                          }else{
                                             //this shouldnt ever happen *hopefully*
                                             bug("ST_ID from typename in type_denoter is NULL!");
                                           }
                                        }
  | new_ordinal_type                    {if(myDebugPart1){msg("Found in type_denoter:2---");} $$ = $1;}
  | new_pointer_type                    {if(myDebugPart1){msg("Found in type_denoter:3---");} $$ = $1;}
  | new_procedural_type                 {if(myDebugPart1){msg("Found in type_denoter:4---");} $$ = $1;}
  | new_structured_type                 {if(myDebugPart1){msg("Found in type_denoter:5---");} $$ = $1;}
  ;

new_ordinal_type:
    enumerated_type                     {if(myDebugPart1){msg("Found in new_ordinal_type:1---");}}
  | subrange_type                       {if(myDebugPart1){msg("Found in new_ordinal_type:2---");} $$ = $1;}
  ;

enumerated_type:
    '(' enum_list ')'           {}
  ;

enum_list:
    enumerator
  | enum_list ',' enumerator
  ;

enumerator:
    new_identifier                    {}
  ;

subrange_type:
    constant LEX_RANGE constant        {if(myDebugPart1){msg("Found in subrange_type:1---");}
                                          if($1 <= $3){
                                            $$ = ty_build_subrange(ty_build_basic(TYSIGNEDLONGINT),$1,$3);
                                          }else{
                                            error("Subrange values are invalid!");
                                            $$ = ty_build_basic(TYERROR);
                                          }
                                        }
  ;

new_pointer_type:
    pointer_char pointer_domain_type    {if(myDebugPart1){msg("Found in new_pointer_type:1---");} $$ = $2;}
  ;

pointer_char:
    '^'
  | '@'
  ;

pointer_domain_type:
    new_identifier                    {if(myDebugPart1){msg("Found in pointer_domain_type:1---");}
                                        ST_DR tempDR = st_lookup($1,&block);
                                        TYPE tempType;
                                          if(tempDR == NULL){
                                            tempType = ty_build_unresolved_ptr($1);
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
                                          $$ = tempType;

                                      }
  | new_procedural_type               {if(myDebugPart1){msg("Found in pointer_domain_type:2---");} $$ = ty_build_ptr($1);/*To our knowledge this is not tested in PROJECT 1 */}
  ;

new_procedural_type:
    LEX_PROCEDURE optional_procedural_type_formal_parameter_list              {if(myDebugPart1){msg("Found in new_procedural_type:1---");} $$ = ty_build_func(ty_build_basic(TYVOID), NULL, TRUE);}
  | LEX_FUNCTION optional_procedural_type_formal_parameter_list functiontype  {if(myDebugPart1){msg("Found in new_procedural_type:2---");}
                                                                                TYPE tempTYPE = $3;
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
                                                                                  $$ = ty_build_func(tempTYPE, NULL, TRUE);

                                                                                }else{
                                                                                  error("Function type invalid");
                                                                                  $$ = ty_build_basic(TYERROR);
                                                                                }
                                                                              }
  ;

optional_procedural_type_formal_parameter_list:
    /* empty */                                           {if(myDebugPart1){msg("Found in optional_procedural_type_formal_parameter_list:0---");}}
  | '(' procedural_type_formal_parameter_list ')'         {if(myDebugPart1){msg("Found in optional_procedural_type_formal_parameter_list:1---");}}
  ;

procedural_type_formal_parameter_list:
    procedural_type_formal_parameter                                              {if(myDebugPart1){msg("Found in procedural_type_formal_parameter_list:1---");}}
  | procedural_type_formal_parameter_list semi procedural_type_formal_parameter   {if(myDebugPart1){msg("Found in procedural_type_formal_parameter_list:2---");}}
  ;

procedural_type_formal_parameter:
    id_list                         {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:1---");}}
  | id_list ':' typename            {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:2---");}}
  | LEX_VAR id_list ':' typename    {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:3---");}}
  | LEX_VAR id_list                 {if(myDebugPart1){msg("Found in procedural_type_formal_parameter:4---");}}
  ;

new_structured_type:
    array_type              {if(myDebugPart1){msg("Found in new_structured_type:1---");} $$ = $1;}
  | set_type                {if(myDebugPart1){msg("Found in new_structured_type:2---");}}
  | record_type             {if(myDebugPart1){msg("Found in new_structured_type:3---");}}
  ;

/* Array */

array_type:
    LEX_ARRAY '[' array_index_list ']' LEX_OF type_denoter        {if(myDebugPart1){msg("array_type:1---"); ty_print_typetag(ty_query($6)); msg("");}
                                                                    if(ty_query($6) != TYERROR && ty_query($3->type) != TYERROR){
                                                                      if(ty_query($6) != TYFUNC){
                                                                        $$ = ty_build_array($6,$3);
                                                                      }else{
                                                                        error("Data type expected for array elements");
                                                                        $$ = ty_build_basic(TYERROR);
                                                                      }
                                                                    }else{ // keep passing the error type up
                                                                      $$ = $6;
                                                                    }
                                                                  }
  ;

array_index_list:
    ordinal_index_type                           {if(myDebugPart1){msg("Found in array_index_list:1---");} $$ = addToArraySubList($1, NULL);}
  | array_index_list ',' ordinal_index_type      {if(myDebugPart1){msg("Found in array_index_list:2---");} $$ = addToArraySubList($3, $1);}
  ;


ordinal_index_type:
    new_ordinal_type            {if(myDebugPart1){msg("Found in ordinal_index_type:1---");} $$ = $1; /*this is a subrange return (for now)*/}
  | typename                    {if(myDebugPart1){msg("Found in ordinal_index_type:2---");} $$ = $1; /*ST_Id*/}
  ;


/* sets */
set_type:
    LEX_SET LEX_OF type_denoter
  ;

record_type:
    LEX_RECORD record_field_list LEX_END
  ;

record_field_list:
    /* empty */
  | fixed_part optional_semicolon
  | fixed_part semi variant_part
  | variant_part
  ;

fixed_part:
    record_section
  | fixed_part semi record_section
  ;

record_section:
    id_list ':' type_denoter
  ;

variant_part:
    LEX_CASE variant_selector LEX_OF variant_list rest_of_variant
  ;

rest_of_variant:
    optional_semicolon
  | case_default '(' record_field_list ')' optional_semicolon
  ;

variant_selector:
    new_identifier ':' variant_type
  | variant_type
  ;

variant_type:
    typename
  | new_ordinal_type
  ;

variant_list:
    variant
  | variant_list semi variant
  ;

variant:
    case_constant_list ':' '(' record_field_list ')'
  ;

case_constant_list:
    one_case_constant                                  {if(myDebugPart3){msg("%d case_constant_list:one_case_constant---line %d", block, sc_line());}}
  | case_constant_list ',' one_case_constant           {if(myDebugPart3){msg("%d case_constant_list:case_constant_list---line %d", block, sc_line());}}
  ;

one_case_constant:
    static_expression
  | static_expression LEX_RANGE static_expression
  ;

/* variable declaration part */
/* We keep track of total size needed in case of local variables by
   using a simple inherited attribute of type int */

variable_declaration_part:
    LEX_VAR variable_declaration_list           {if(myDebugPart2){msg("%d variable_declaration_part---line %d",block, sc_line());}}

  ;

variable_declaration_list:
    variable_declaration                            {if(myDebugPart2){msg("%d variable_declaration_list:1---line %d",block, sc_line());}}
  | variable_declaration_list variable_declaration  {if(myDebugPart2){msg("%d variable_declaration_list:2---line %d",block, sc_line());}}
  ;

variable_declaration:
    id_list ':' type_denoter semi           {if(myDebugPart1){msg("variable_declaration:1---"); ty_print_typetag(ty_query($3)); msg("");}
                                            LD tempLD = $1;
                                            if(tempLD != NULL){
                                              do{
                                                ST_ID IDtoInstall = st_lookup(tempLD->data, &block);
                                                char *idName = st_get_id_str(tempLD->data);
                                                TYPE typeToInstall = $3;

                                                if(ty_query($3) != TYFUNC){
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
  ;

function_declaration:

                /*
                typedef enum {
                    STATIC_SC, EXTERN_SC, AUTO_SC, TYPEDEF_SC, REGISTER_SC, NO_SC
                } STORAGE_CLASS;



                { install function name FDECL
                    two possibilities:
                        if function name is not already in symbol table: then install it as a fresh FDECL
                        if already in the symbolTAB (st_lookup returns a record ST_DR)
                            only allowed situation is previous installment was a GDECL of a function of the same type that is not external
                                this would be a forward decl (look at the storage class)
                            anything else is a symantic error
                                if FDECL then duplicate declaration
                                not a function
                                func but wrong args or return type (dont match)

                st_enter_block()
                    enters a new namespace or new "scope"
                    any decls from now on are local

                    b_init_formal_param_offset()
                    install parameters into the symbol table as PDECL (left to right)
                            with offsets (ints)(from the currrent frame pointer at runtime)

                    offset value is obtained by calling b_get_formal_param_offset(type tag)  offset is installed in table?!
                }
                */

    function_heading semi directive_list semi                         {if(myDebugPart2){msg("%d function_declaration:directive_list---line %d",block, sc_line());}
                                                                        //EXTERNAL DECLARED FUNCTIONS/PARAMETERS
                                                                        //cant have params (inputs)
                                                                        int directive = $3;
                                                                        TN tempFuncNode = $1;
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
                                                                      }//END function_heading semi directive_list semi
  | function_heading semi {
                            funcST_ID = $1->u.func_node.funcName;
                          }
    any_declaration_part {if(myDebugPart2){msg("%d function_declaration:any_declaration_part---line %d",block,sc_line());}
                            b_func_prologue(st_get_id_str(funcST_ID));
                            insideFunc = 1;
                         }
    statement_part semi  {if(myDebugPart2){msg("%d function_declaration:statement_part---line %d",block,sc_line());}
                                                                          /* statement_part semi*/
                                                                          TN tempFuncNode = $1;
                                                                          ST_ID funcName = tempFuncNode->u.func_node.funcName;
                                                                          TYPETAG funcTYPETAG = tempFuncNode->u.func_node.typeTag;
                                                                          TYPE funcTYPE = tempFuncNode->u.func_node.type;
                                                                          //need to handle assignments to func names first (aka returns)
                                                                          //b_prepare_return(funcTYPETAG);  //TYVOID for procedures
                                                                          b_func_epilogue(st_get_id_str(funcName));
                                                                      }
  ;

function_heading:
    LEX_PROCEDURE new_identifier optional_par_formal_parameter_list                {if(myDebugPart2){msg("%d function_heading:LEX_PROCEDURE---line %d",block, sc_line());}
                                                                                      TYPETAG tempTYPETAG = TYVOID;
                                                                                      ST_ID tempSTID = $2;
                                                                                      $$ = makeFuncNode(tempSTID, tempTYPETAG, ty_build_basic(tempTYPETAG));
                                                                                   }
  | LEX_FUNCTION new_identifier optional_par_formal_parameter_list functiontype    {if(myDebugPart2){msg("%d function_heading:LEX_FUNCTION---line %d",block, sc_line());}
                                                                                      TYPETAG tempTYPETAG;
                                                                                      if(ty_query($4) == TYERROR){
                                                                                        error("No return type for function");
                                                                                      }else{
                                                                                        tempTYPETAG = ty_query($4);
                                                                                      }
                                                                                      ST_ID tempSTID = $2;
                                                                                      $$ = makeFuncNode(tempSTID, tempTYPETAG, $4);
                                                                                      /*MAKE FUNCTION NODE - fill it
                                                                                        new identifier for name
                                                                                        optional_par_formal_parameter_list for parameters
                                                                                        functiontype for type
                                                                                      */
                                                                                   }
  ;

directive_list:
    directive                       {if(myDebugPart2){msg("%d directive_list:directive---line %d",block, sc_line());} $$ = $1;}
  | directive_list semi directive   {if(myDebugPart2){msg("%d directive_list:directive_list---line %d",block, sc_line());}/*assume not used for now*/}
  ;

directive:
    LEX_FORWARD                     {if(myDebugPart2){msg("%d directive:LEX_FORWARD---line %d",block, sc_line());} $$ = 1;}
  | LEX_EXTERNAL                    {if(myDebugPart2){msg("%d directive:LEX_EXTERNAL---line %d",block, sc_line());} $$ = 0;}
  ;

functiontype:
    /* empty */                     {if(myDebugPart1){msg("functiontype:0---EMPTY");} $$ = ty_build_basic(TYERROR);}  //procedure
    | ':' typename                  {if(myDebugPart1){msg("functiontype:1--- %s", st_get_id_str($2));}
                                    ST_ID tempID = $2;
                                    ST_DR tempDR = st_lookup(tempID, &block);
                                    if(tempDR != NULL){
                                      $$ = tempDR->u.typename.type;
                                    }else{
                                      error("Function returnType invalid: \"%s\"", st_get_id_str($2));
                                    }
                                    }
  ;

/* parameter specification section */

optional_par_formal_parameter_list:
    /* empty */
  | '(' formal_parameter_list ')'
  ;

formal_parameter_list:
    formal_parameter
  | formal_parameter_list semi formal_parameter
  ;

formal_parameter:
    id_list ':' typename
  | LEX_VAR id_list ':' typename
  ;


/* Pascal statements */

statement_part:
    compound_statement                                 {if(myDebugPart3){msg("%d statement_part:compound_statement---line %d", block, sc_line());}}
  ;

compound_statement:
    LEX_BEGIN {if(!insideFunc)b_func_prologue("main");}
    statement_sequence
    LEX_END              {/*everything withing begin and end, could be func/procedure def, or main*/
                                                        if(myDebugPart2){msg("%d compound_statement:BEGIN and END---line %d", block, sc_line());}
                                                        if(!insideFunc)b_func_epilogue("main");
                                                        insideFunc = 0;
                                                      }
  ;

statement_sequence:
    statement                                         {if(myDebugPart3){msg("%d statement_sequence:statement---line %d", block, sc_line());}}
  | statement_sequence semi statement                 {if(myDebugPart3){msg("%d statement_sequence:statement_sequence---line %d", block, sc_line());}}
  ;

statement:
    structured_statement                                {if(myDebugPart3){msg("%d statement:structured_statement---line %d", block, sc_line());}}
  | simple_statement                                    {if(myDebugPart3){msg("%d statement:simple_statement---line %d", block, sc_line());}}
  ;

structured_statement:
    compound_statement                                  {if(myDebugPart3){msg("%d structured_statement:compound_statement---line %d", block, sc_line());}}
  | with_statement                                      {if(myDebugPart3){msg("%d structured_statement:with_statement---line %d", block, sc_line());}}
  | conditional_statement                               {if(myDebugPart3){msg("%d structured_statement:conditional_statement---line %d", block, sc_line());}}
  | repetitive_statement                                {if(myDebugPart3){msg("%d structured_statement:repetitive_statement---line %d", block, sc_line());}}
  ;

with_statement:
    LEX_WITH structured_variable_list LEX_DO statement  {if(myDebugPart3){msg("%d structured_statement:compound_statement---line %d", block, sc_line());}}
  ;

structured_variable_list:
    structured_variable
  | structured_variable_list ',' structured_variable
  ;

structured_variable:
    variable_or_function_access                           {if(myDebugPart3){msg("%d structured_variable:variable_or_function_access---line %d", block, sc_line());}}
  ;

conditional_statement:
    if_statement                                          {if(myDebugPart3){msg("%d conditional_statement:if_statement---line %d", block, sc_line());}}
  | case_statement                                        {if(myDebugPart3){msg("%d conditional_statement:case_statement---line %d", block, sc_line());}}
  ;

simple_if:
    LEX_IF boolean_expression LEX_THEN statement           {if(myDebugPart3){msg("%d simple_if:LEX_IF and LEX_THEN---line %d", block, sc_line());}
                                                            /*possibly build IF_NODE here*/
                                                           }
  ;

if_statement:
    simple_if LEX_ELSE statement                           {if(myDebugPart3){msg("%d if_statement:LEX_ELSE---line %d", block, sc_line());}
                                                              /*possibly function to link a IF_NODE to a ELSE_NODE (and create the ELSE_NODE)*/
                                                           }
  | simple_if %prec prec_if                                {if(myDebugPart3){msg("%d if_statement:2---line %d", block, sc_line());}}
  ;

case_statement:
    LEX_CASE expression LEX_OF case_element_list optional_semicolon_or_else_branch LEX_END
  ;

optional_semicolon_or_else_branch:
    optional_semicolon                                     {if(myDebugPart3){msg("%d optional_semicolon_or_else_branch:optional_semicolon---line %d", block, sc_line());}}
  | case_default statement_sequence                        {if(myDebugPart3){msg("%d optional_semicolon_or_else_branch:case_default---line %d", block, sc_line());}}
  ;

case_element_list:
    case_element                                           {if(myDebugPart3){msg("%d case_element_list:case_element---line %d", block, sc_line());}}
  | case_element_list semi case_element                    {if(myDebugPart3){msg("%d case_element_list:case_element_list---line %d", block, sc_line());}}
  ;

case_element:
    case_constant_list ':' statement
  ;

case_default:
    LEX_ELSE                                                {if(myDebugPart3){msg("%d case_default:LEX_ELSE---line %d", block, sc_line());}}
  | semi LEX_ELSE                                           {if(myDebugPart3){msg("%d case_default:semi LEX_ELSE---line %d", block, sc_line());}}
  ;

repetitive_statement:
    repeat_statement                                        {if(myDebugPart3){msg("%d repetitive_statement:repeat_statement---line %d", block, sc_line());}}
  | while_statement                                         {if(myDebugPart3){msg("%d repetitive_statement:while_statement---line %d", block, sc_line());}}
  | for_statement                                           {if(myDebugPart3){msg("%d repetitive_statement:for_statement---line %d", block, sc_line());}}
  ;

repeat_statement:
    LEX_REPEAT statement_sequence LEX_UNTIL boolean_expression  {if(myDebugPart3){msg("%d repeat_statement:LEX_REPEAT---line %d", block, sc_line());}}
  ;

while_statement:
    LEX_WHILE boolean_expression LEX_DO statement               {if(myDebugPart3){msg("%d while_statement:LEX_WHILE---line %d", block, sc_line());}}
  ;

for_statement:
    LEX_FOR variable_or_function_access LEX_ASSIGN expression for_direction expression LEX_DO statement
  ;

for_direction:
    LEX_TO
  | LEX_DOWNTO
  ;

simple_statement:
    empty_statement                     {if(myDebugPart2){msg("%d simple_statement:1---EMPTY STATEMENT", block);}
                                          /*no return, if last stement has a semi, this is the filler to allow it*/}
  | assignment_or_call_statement        {if(myDebugPart2){msg("%d simple_statement:2---line %d", block, sc_line());}
                                          if(myDebugPart2){msg("Calling genBackendAssignment() on");treeNodeToString($1, 1);}
                                          //always call an assigment with (node, 0, 0) from gramar
                                          if($1->tag != ERROR_NODE) genBackendAssignment($1, 0, 0);

                                        }
  | standard_procedure_statement        {if(myDebugPart2){msg("%d simple_statement:3---line %d", block, sc_line());}

                                        }
  | statement_extensions                {/*not used, not part of standard pascal*/}
  ;

empty_statement:
    /* empty */ %prec lower_than_error
  ;

/* function calls */

optional_par_actual_parameter_list:
    /* empty */
  | '(' actual_parameter_list ')'
  ;

actual_parameter_list:
    actual_parameter
  | actual_parameter_list ',' actual_parameter
  ;

actual_parameter:
    expression  {$$ = $1;}
  ;

/* ASSIGNMENT and procedure calls */

assignment_or_call_statement:     /*tree node*/
    variable_or_function_access_maybe_assignment rest_of_statement   {if(myDebugPart2){msg("%d assignment_or_call_statement:1---line %d", block, sc_line());}
                                                                        /*rest_of_statement can be empty, or :=*/
                                                                        TN tempTreeNode;
                                                                        if($1->tag == VAR_NODE){
                                                                          if($2->tag == FUNC_NODE && $2->u.func_node.typeTag == TYVOID){
                                                                            error("Cannot convert between nondata types");
                                                                            $$ = makeErrorNode();
                                                                          }else if($2->tag != ERROR_NODE){
                                                                          tempTreeNode = makeAssignNode($1, $2);
                                                                          $$ = tempTreeNode;
                                                                        }else{
                                                                            error("Expected procedure name, saw data");
                                                                            $$ = $2;
                                                                        }
                                                                      }else if($1->tag == FUNC_NODE){
                                                                        if($2->tag == ERROR_NODE){
                                                                          //rest of statement is empty for function calls
                                                                          $$ = $1;
                                                                        }else{ //assigning to a function name
                                                                          //error("not a return inside a function definition");
                                                                          error("Assignment requires l-value on the left");
                                                                          $$ = makeErrorNode();
                                                                        }

                                                                      }else if($1->tag == ERROR_NODE){
                                                                        //undeclared id
                                                                        $$ = $1;

                                                                      }else if($1->tag != VAR_NODE && $2->tag != ERROR_NODE){
                                                                        error("Assignment requires l-value on the left");
                                                                        $$ = makeErrorNode();
                                                                      }else{
                                                                        error("Procedure call expected");
                                                                        $$ = makeErrorNode();
                                                                      }

                                                                    }//END of assignment_or_call_statement
  ;

variable_or_function_access_maybe_assignment:    /*tree node*/
    identifier                                            {if(myDebugPart2){msg("%d variable_or_function_access_maybe_assignment:1--- %s",block, st_get_id_str($1));}
                                                            ST_DR tempDR = st_lookup($1,&block);
                                                            STDR_TAG tempSTDR_TAG;
                                                            TYPE tempTYPE;
                                                            if(tempDR == NULL){
                                                              error("Undeclared identifier \"%s\" in expression",st_get_id_str($1));
                                                              $$ = makeErrorNode();
                                                            }else{
                                                              //ECONST, GDECL, LDECL, PDECL, FDECL, TYPENAME
                                                              tempSTDR_TAG = tempDR->tag;
                                                              tempTYPE = tempDR->u.decl.type;

                                                              if(tempSTDR_TAG == GDECL | tempSTDR_TAG == LDECL){
                                                                if(tempDR->u.decl.sc == EXTERN_SC){
                                                                  $$ = makeFuncNode($1, ty_query(tempTYPE), tempTYPE);
                                                                }else if(tempDR->u.decl.sc == NO_SC){
                                                                  $$ = makeVarNode($1);
                                                                }else{
                                                                  bug("unhandled storage class in variable_or_function_access_maybe_assignment:identifier");
                                                                }

                                                              }else if(tempSTDR_TAG == FDECL){
                                                                $$ = makeFuncNode($1, ty_query(tempTYPE), tempTYPE);
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

  | address_operator variable_or_function_access          {/*not used*/if(myDebugPart2){msg("variable_or_function_access_maybe_assignment:2---OUT OF SCOPE?!?! ");}}

  | variable_or_function_access_no_id                     {if(myDebugPart2){msg("%d variable_or_function_access_maybe_assignment:3---line %d", block, sc_line());}
                                                            /*example:    foo(x)^ := 6  */
                                                              $$ = $1;
                                                          }
  ;

rest_of_statement:  /*tree node*/
    /* Empty */                                           {if(myDebugPart2){msg("%d rest_of_statement:0---EMPTY", block);}
                                                            //Procedure or function call
                                                            $$ = makeErrorNode();
                                                          }
  | LEX_ASSIGN expression                                 {if(myDebugPart2){msg("%d rest_of_statement:1---line %d", block, sc_line());}
                                                             $$ = $2;
                                                          }
  ;

standard_procedure_statement:
    rts_proc_onepar '(' actual_parameter ')'
  | rts_proc_parlist '(' actual_parameter_list ')'
  | p_WRITE optional_par_write_parameter_list
  | p_WRITELN optional_par_write_parameter_list
  | p_READ optional_par_actual_parameter_list
  | p_READLN optional_par_actual_parameter_list
  | p_PAGE optional_par_actual_parameter_list
  | p_DISPOSE '(' actual_parameter ')'
  | p_DISPOSE '(' actual_parameter ',' actual_parameter_list ')'
  ;

optional_par_write_parameter_list:
    /* empty */
  | '(' write_actual_parameter_list ')'
  ;

write_actual_parameter_list:
    write_actual_parameter
  | write_actual_parameter_list ',' write_actual_parameter
  ;

write_actual_parameter:
    actual_parameter
  | actual_parameter ':' expression
  | actual_parameter ':' expression ':' expression
  ;

/* run time system calls with one parameter */
rts_proc_onepar:
    p_PUT
  | p_GET
  | p_MARK
  | p_RELEASE
  | p_CLOSE
  | p_UPDATE
  | p_GETTIMESTAMP
  | p_UNBIND
  ;

rts_proc_parlist:
    p_REWRITE     /* Up to three args */
  | p_RESET       /* Up to three args */
  | p_EXTEND      /* Up to three args */
  | bp_APPEND     /* Up to three args */
  | p_PACK        /* Three args */
  | p_UNPACK      /* Three args */
  | p_BIND        /* Two args */
  | p_SEEKREAD
  | p_SEEKWRITE
  | p_SEEKUPDATE
  | p_DEFINESIZE  /* Two args */
  | LEX_AND           /* Two args */
  | LEX_OR            /* Two args */
  | LEX_NOT           /* One arg */
  | LEX_XOR        /* Two args */
  | LEX_SHL           /* Two args */
  | LEX_SHR           /* Two args */
  ;

statement_extensions:
    return_statement
  | continue_statement
  | break_statement
  ;

return_statement:
    RETURN_
  | RETURN_ expression
  | EXIT
  | FAIL
  ;

break_statement:
    BREAK
  ;

continue_statement:
    CONTINUE
  ;

variable_access_or_typename:
    variable_or_function_access_no_id             {if(myDebugPart3){msg("%d variable_access_or_typename:variable_or_function_access_no_id---line %d", block, sc_line());}}
  | LEX_ID                                        {if(myDebugPart3){msg("%d variable_access_or_typename:LEX_ID---line %d", block, sc_line());}}
  ;

index_expression_list:
      index_expression_item
    | index_expression_list ',' index_expression_item
    ;

index_expression_item:
      expression
    | expression LEX_RANGE expression
  ;

/* expressions */

static_expression:
    expression
  ;

boolean_expression:
    expression                                            {if(myDebugPart3){msg("%d boolean_expression:expression---line %d", block, sc_line());}}
  ;

expression:     /*tree node*/      /*net result of evaluating an expression, one return value push on the stack*/
    expression relational_operator simple_expression     {if(myDebugPart2){msg("%d expression:1---line %d", block, sc_line());}
                                                            relationalType relType = $2;
                                                            $$ = makeRelopNode($1, relType, $3);
                                                         }
  | expression LEX_IN simple_expression                  {if(myDebugPart2){msg("%d expression:2---line %d", block, sc_line());}
                                                          /* probably unused for part 2*/
                                                         }
  | simple_expression                                    {if(myDebugPart2){msg("%d expression:3---line %d", block, sc_line());}
                                                          $$ = $1;
                                                         }
  ;

simple_expression:   /*tree node*/ /*simple statements leave the stack unchanged*/
    term                                                {if(myDebugPart2){msg("%d simple_expression:1---line %d", block, sc_line());}
                                                          $$ = $1;
                                                        }
  | simple_expression adding_operator term              {if(myDebugPart2){msg("%d simple_expression:2---line %d", block, sc_line());}
                                                          binopType tempBinopType;

                                                          if($2 == 1) tempBinopType = ADD;
                                                          else tempBinopType = SUB;

                                                          $$ = makeBinopNode($1, $3, tempBinopType);
                                                        }
  | simple_expression LEX_SYMDIFF term                  {if(myDebugPart2){msg("%d simple_expression:3---line %d", block, sc_line());}} //NO CLUE WHAT THIS IS >.<
  | simple_expression LEX_OR term                       {if(myDebugPart2){msg("%d simple_expression:4---line %d", block, sc_line());}}
  | simple_expression LEX_XOR term                      {if(myDebugPart2){msg("%d simple_expression:5---line %d", block, sc_line());}}
  ;

term:              /*TREE NODE*/
    signed_primary                                      {if(myDebugPart2){msg("%d term:1---line %d", block, sc_line());}
                                                          $$ = $1;
                                                        }
  | term multiplying_operator signed_primary            {if(myDebugPart2){msg("%d term:2---line %d", block, sc_line());}
                                                          binopType tempBinopType;
                                                          if($2 == 0){//integer division
                                                            tempBinopType = INT_DIV;
                                                          }else if($2 == 1){//modulus
                                                            tempBinopType = MOD;
                                                          }else if($2 == 2){//real division
                                                            tempBinopType = REAL_DIV;
                                                          }else if($2 == 3){//multiplication
                                                            tempBinopType = MULT;
                                                          }

                                                          $$ = makeBinopNode($1, $3, tempBinopType);

                                                        }
  | term LEX_AND signed_primary                         {if(myDebugPart2){msg("%d term:3---line %d", block, sc_line());}}
  ;

signed_primary:   /*TREE NODE*/
    primary                                             {if(myDebugPart2){msg("%d signed_primary:1---line %d", block, sc_line());}
                                                          $$ = $1;
                                                        }
  | sign signed_primary                                 {if(myDebugPart2){msgn("%d signed_primary:", block);}
                                                          if($1 == 1){
                                                            if(myDebugPart2){msg(" NEGATIVE---");}
                                                            $$ = makeNegNumNode($2);
                                                          }else{
                                                            if(myDebugPart2){msg(" POSITIVE---");}
                                                            $$ = $2;
                                                          }
                                                        }
  ;

primary:     /*TREE NODE*/
    factor                                              {if(myDebugPart2){msg("%d primary:1---line %d", block, sc_line());}
                                                          $$ = $1;
                                                        }
  | primary LEX_POW factor                              {if(myDebugPart2){msg("%d primary:2---line %d", block, sc_line());}
                                                          /*idk what a LEX_POW is*/
                                                        }
  | primary LEX_POWER factor                            {if(myDebugPart2){msg("%d primary:3---line %d", block, sc_line());}
                                                          /*LEX_POWER  **   */
                                                        }
  | primary LEX_IS typename                             {if(myDebugPart2){msg("%d primary:4---line %d", block, sc_line());}
                                                          /*NOT SURE IF leX_IS NEEDS TO BE HANDLED*/
                                                        }
  ;

signed_factor:  /*TREE NODE*/
    factor                                              {if(myDebugPart2){msg("%d signed_factor:1---line %d", block, sc_line());}
                                                          $$ = $1;
                                                        }
  | sign signed_factor                                  {if(myDebugPart2){msg("%d signed_factor:2---line %d", block, sc_line());}
                                                          if($1 == '-'){
                                                            $$ = makeNegNumNode($2);
                                                          }else{
                                                            $$ = $2;
                                                          }
                                                        }
  ;

factor:     /*TREE NODE*/
    variable_or_function_access                         {if(myDebugPart2){msg("%d factor:1---line %d", block, sc_line());}
                                                          $$ = $1;
                                                        }
  | constant_literal                                    {if(myDebugPart2){msg("%d factor:2---line %d", block, sc_line());}
                                                          $$ = $1;
                                                        }
  | unsigned_number                                     {if(myDebugPart2){msg("%d factor:3---line %d", block, sc_line());}
                                                          $$ = $1;  //int or real node
                                                        }
  | set_constructor                                     {if(myDebugPart2){msg("%d factor:4---line %d", block, sc_line());}}
  | LEX_NOT signed_factor                               {if(myDebugPart2){msg("%d factor:5---line %d", block, sc_line());}}
  | address_operator factor                             {if(myDebugPart2){msg("%d factor:6---line %d", block, sc_line());}}
  ;

address_operator:
    '@'
  ;

variable_or_function_access:
    variable_or_function_access_no_standard_function    {if(myDebugPart2){msg("%d variable_or_function_access:1---line %d", block, sc_line());}
                                                          $$ = $1;
                                                        }
  | standard_functions                                  {if(myDebugPart2){msg("%d variable_or_function_access:2---line %d", block, sc_line());}
                                                          $$ = $1;
                                                        }
  ;

variable_or_function_access_no_standard_function:
    identifier                                          {if(myDebugPart2){msg("%d variable_or_function_access_no_standard_function:1---line %d", block, sc_line());}


                                                          ST_DR tempDR = st_lookup($1,&block);
                                                          STDR_TAG tempSTDR_TAG;
                                                          TYPE tempTYPE;
                                                          if(tempDR == NULL){
                                                            error("Undeclared identifier \"%s\" in expression",st_get_id_str($1));
                                                            $$ = makeErrorNode();
                                                          }else{
                                                            //ECONST, GDECL, LDECL, PDECL, FDECL, TYPENAME
                                                            tempSTDR_TAG = tempDR->tag;
                                                            tempTYPE = tempDR->u.decl.type;

                                                            if(tempSTDR_TAG == GDECL | tempSTDR_TAG == LDECL){
                                                              if(tempDR->u.decl.sc == EXTERN_SC){
                                                                $$ = makeFuncNode($1, ty_query(tempTYPE), tempTYPE);
                                                              }else if(tempDR->u.decl.sc == NO_SC){
                                                                $$ = makeVarNode($1);
                                                              }else{
                                                                bug("unhandled storage class in variable_or_function_access_maybe_assignment:identifier");
                                                              }

                                                            }else if(tempSTDR_TAG == FDECL){
                                                              $$ = makeFuncNode($1, ty_query(tempTYPE), tempTYPE);
                                                            }else{
                                                              bug("variable_or_function_access_maybe_assignment:identifier unhandled STDR_TAG");
                                                            }
                                                            // check if function name of current function definition (for setting return value)
                                                            //   create function return node (or something)
                                                            //
                                                            // check if a procedure call name (that has no parameters)
                                                            //   go get this procedures top node, or create it i guess

                                                        }//was found in the DR

                                                      }//END identifier

  | variable_or_function_access_no_id                   {if(myDebugPart2){msg("%d variable_or_function_access_no_standard_function:2---line %d", block, sc_line());}}
  ;

variable_or_function_access_no_id:
    p_OUTPUT                                                                          {/*not used*/}
  | p_INPUT                                                                           {/*not used*/}
  | variable_or_function_access '.' new_identifier                                    {/*not used*/}
  | '(' expression ')'                                                                {if(myDebugPart2){msg("%d variable_or_function_access_no_id:4---line %d", block, sc_line());}
                                                                                        $$ = $2;
                                                                                      }
  | variable_or_function_access pointer_char                                          {if(myDebugPart2){msg("%d variable_or_function_access_no_id:5---line %d", block, sc_line());}
                                                                                        /*something ex:  p^ := 6*/
                                                                                      }
  | variable_or_function_access '[' index_expression_list ']'                         {/*for project 3, not used in part 2. for array accesses*/}
  | variable_or_function_access_no_standard_function '(' actual_parameter_list ')'    {if(myDebugPart2){msg("%d variable_or_function_access_no_id:7---line %d", block, sc_line());}
                                                                                        /*function call, expr*/
                                                                                      }
  | p_NEW '(' variable_access_or_typename ')'                                         {if(myDebugPart2){msg("%d variable_or_function_access_no_id:8---line %d", block, sc_line());}
                                                                                        /*like a malloc but in pascal, continue on April 13th, monday*/
                                                                                      }
  ;

set_constructor:
    '[' ']'
  | '[' set_constructor_element_list ']'
  ;

set_constructor_element_list:
    member_designator
  | set_constructor_element_list ',' member_designator
  ;

member_designator:
    expression                                    {if(myDebugPart3){msg("%d member_designator:expression---line %d", block, sc_line());}}
  | expression LEX_RANGE expression               {if(myDebugPart3){msg("%d member_designator:LEX_RANGE---line %d", block, sc_line());}}
  ;

standard_functions:
    rts_fun_onepar '(' actual_parameter ')'     {if(myDebugPart2){msg("%d standard_functions:rts_fun_onepar(actual_parameter)---line %d",block, sc_line());}
                                                  unopType tempUnopType;
                                                  if($1 == pas_ORD){
                                                    tempUnopType = ORD;
                                                  }else if($1 == pas_CHR){
                                                    tempUnopType = CHR;
                                                  }else{
                                                    bug("Unexpected \"rts_fun_onepar\" value");
                                                  }
                                                  $$ = makeUnopNode($3,tempUnopType);
                                                }
  | rts_fun_optpar optional_par_actual_parameter  {}
  | rts_fun_parlist '(' actual_parameter_list ')' {if(myDebugPart2){msg("%d standard_functions:rts_fun_parlist(actual_parameter_list)---line %d",block, sc_line());}
                                                    unopType tempUnopType;
                                                    if($1 == pas_SUCC){
                                                      tempUnopType = SUCC;
                                                    }else if($1 == pas_PRED){
                                                      tempUnopType = PRED;
                                                    }else{
                                                      bug("Unexpected \"rts_fun_onepar\" value");
                                                    }
                                                    $$ = makeUnopNode($3,tempUnopType);
                                                  }
  ;


optional_par_actual_parameter:
    /* empty */
  | '(' actual_parameter ')'
  ;

rts_fun_optpar:
    p_EOF
  | p_EOLN
  ;

rts_fun_onepar:   /*type is enum rtsFunOnePar*/
    p_ABS           {if(myDebugPart2){msg("%d rts_fun_onepar:p_ABS---line %d",block, sc_line());};}
  | p_SQR           {if(myDebugPart2){msg("%d rts_fun_onepar:p_SQR---line %d",block, sc_line());};}
  | p_SIN           {if(myDebugPart2){msg("%d rts_fun_onepar:p_SIN---line %d",block, sc_line());};}
  | p_COS           {if(myDebugPart2){msg("%d rts_fun_onepar:p_COS---line %d",block, sc_line());};}
  | p_EXP           {if(myDebugPart2){msg("%d rts_fun_onepar:p_EXP---line %d",block, sc_line());};}
  | p_LN            {if(myDebugPart2){msg("%d rts_fun_onepar:p_LN---line %d",block, sc_line());};}
  | p_SQRT          {if(myDebugPart2){msg("%d rts_fun_onepar:p_SQRT---line %d",block, sc_line());};}
  | p_ARCTAN        {if(myDebugPart2){msg("%d rts_fun_onepar:p_ARCTAN---line %d",block, sc_line());};}
  | p_ARG           {if(myDebugPart2){msg("%d rts_fun_onepar:p_ARG---line %d",block, sc_line());};}
  | p_TRUNC         {if(myDebugPart2){msg("%d rts_fun_onepar:p_TRUNC---line %d",block, sc_line());};}
  | p_ROUND         {if(myDebugPart2){msg("%d rts_fun_onepar:p_ROUND---line %d",block, sc_line());};}
  | p_CARD          {if(myDebugPart2){msg("%d rts_fun_onepar:p_CARD---line %d",block, sc_line());};}
  | p_ORD           {if(myDebugPart2){msg("%d rts_fun_onepar:p_ORD---line %d",block, sc_line());}; $$ = pas_ORD;}
  | p_CHR           {if(myDebugPart2){msg("%d rts_fun_onepar:p_CHR---line %d",block, sc_line());}; $$ = pas_CHR;}
  | p_ODD           {if(myDebugPart2){msg("%d rts_fun_onepar:p_ODD---line %d",block, sc_line());};}
  | p_EMPTY         {if(myDebugPart2){msg("%d rts_fun_onepar:p_EMPTY---line %d",block, sc_line());};}
  | p_POSITION      {if(myDebugPart2){msg("%d rts_fun_onepar:p_POSITION---line %d",block, sc_line());};}
  | p_LASTPOSITION  {if(myDebugPart2){msg("%d rts_fun_onepar:p_LASTPOSITION---line %d",block, sc_line());};}
  | p_LENGTH        {if(myDebugPart2){msg("%d rts_fun_onepar:p_LENGTH---line %d",block, sc_line());};}
  | p_TRIM          {if(myDebugPart2){msg("%d rts_fun_onepar:p_TRIM---line %d",block, sc_line());};}
  | p_BINDING       {if(myDebugPart2){msg("%d rts_fun_onepar:p_BINDING---line %d",block, sc_line());};}
  | p_DATE          {if(myDebugPart2){msg("%d rts_fun_onepar:p_DATE---line %d",block, sc_line());};}
  | p_TIME          {if(myDebugPart2){msg("%d rts_fun_onepar:p_TIME---line %d",block, sc_line());};}
  ;

rts_fun_parlist:
    p_SUCC          {if(myDebugPart2){msg("%d rts_fun_parlist:p_SUCC---line %d",block, sc_line());}; $$ = pas_SUCC;}/* One or two args */
  | p_PRED          {if(myDebugPart2){msg("%d rts_fun_parlist:p_PRED---line %d",block, sc_line());}; $$ = pas_PRED;}/* One or two args */
  ;

relational_operator:   //typedef enum{NE,LE,GE,EQ,LT,GT}relationalType;
    LEX_NE   /* "<>" */     {$$ = NE;}
  | LEX_LE   /* "<=" */     {$$ = LE;}
  | LEX_GE   /* ">=" */     {$$ = GE;}
  | '='                     {$$ = EQ;}
  | '<'                     {$$ = LT;}
  | '>'                     {$$ = GT;}
  ;

multiplying_operator:    /*int type*/
    LEX_DIV                  {$$ = 0;}
  | LEX_MOD                  {$$ = 1;}
  | '/'                      {$$ = 2;}
  | '*'                      {$$ = 3;}
  ;

adding_operator:   /*int type*/
    '-'                     {$$ = 0;}
  | '+'                     {$$ = 1;}
  ;

semi:
    ';'
  ;

optional_semicolon:
    /* empty */
  | ';'
  ;

%%

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
