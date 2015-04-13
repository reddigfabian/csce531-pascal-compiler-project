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

int myDebugPart1 = 1;
int myDebugPart2 = 1;
int myDump = 0;
int block;
INDEX_LIST rootOfUnRP;

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
%type <y_int> constant number LEX_INTCONST sign adding_operator multiplying_operator
%type <y_real> LEX_REALCONST
//%type <y_single>
%type <y_char> '+' '-'
//s%type <y_bool>

%type <y_TN> variable_or_function_access_maybe_assignment expression variable_or_function_access_no_id
    simple_expression rest_of_statement unsigned_number factor signed_factor primary
    signed_primary term assignment_or_call_statement constant_literal predefined_literal
    variable_or_function_access variable_or_function_access_no_standard_function



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
    program_heading semi any_global_declaration_part statement_part  {if(myDebugPart2){msg("%d main_program_declaration:1---",block);}}
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
  | p_ORD  {}
  | p_CHR  {}
  | p_SUCC  {}
  | p_PRED  {}
  | p_ODD  {}
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
    /* empty */
  | any_global_declaration_part any_decl
  ;


any_declaration_part:   /* var decls for local vars*/
    /* empty */                     {if(myDebugPart2){msg("%d any_declaration_part:0---EMPTY",block);}}
  | any_declaration_part any_decl {if(myDebugPart2){msg("%d any_declaration_part:1---",block);}
                                    /*
                                    b_func_prologue()
                                    for each formal parameter (in left-right order)
                                      call b_store_formal_param()  //returns an offset, check with offset in sysm table to check for bugs in our compiler
                                    if function (not a precedure, aka, has a return)
                                      b_alloc_return_value()
                                      *He Draws a picture of the stack @ about 11mins*
                                      b_alloc_local_vars( size )*/
                                  }
  ;

any_decl:
    simple_decl                        {if(myDebugPart2){msg("%d any_decl:simple_decl---",block);}}
  | function_declaration               {if(myDebugPart2){msg("%d any_decl:function_declaration---",block);}}
  ;

simple_decl:
    constant_definition_part           {if(myDebugPart1 | myDebugPart2){msg("%d Found in simple_decl:constant_definition_part---",block);}}
  | type_definition_part               {if(myDebugPart1 | myDebugPart2){msg("%d Found in simple_decl:type_definition_part---",block);}}
  | variable_declaration_part          {if(myDebugPart1 | myDebugPart2){msg("%d Found in simple_decl:variable_declaration_part---",block);}}
  ;

/* constant definition part */

constant_definition_part:
    LEX_CONST constant_definition_list
  ;

constant_definition_list:
    constant_definition
  | constant_definition_list constant_definition
  ;

constant_definition:
    new_identifier '=' static_expression semi
  ;

constant:
    identifier                    {}
  | sign identifier               {}
  | number                        {if(myDebugPart1){msg("Found in constant:3---");} $$=$1;}
  | constant_literal              {}
  ;

number:     /*stripped to all ints, could be a problem. currently only effects subranges*/
    sign unsigned_number            {if(myDebugPart1){msg("Found in number:1---");}
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
    LEX_INTCONST                    {if(myDebugPart1 | myDebugPart2){msg("%d Found in unsigned_number:INT CONST:%ld---",block, $1);}
                                      $$ = makeIntConstNode($1);
                                    }
  | LEX_REALCONST                   {if(myDebugPart1 | myDebugPart2){msg("%d Found in unsigned_number:REAL CONST:%f---",block, $1);}
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
    LEX_STRCONST                    {/*might be needed later*/}
  | string LEX_STRCONST             {/*might be needed later*/}
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
    one_case_constant
  | case_constant_list ',' one_case_constant
  ;

one_case_constant:
    static_expression
  | static_expression LEX_RANGE static_expression
  ;

/* variable declaration part */
/* We keep track of total size needed in case of local variables by
   using a simple inherited attribute of type int */

variable_declaration_part:
    LEX_VAR variable_declaration_list           {if(myDebugPart2){msg("%d variable_declaration_part---",block);}}

  ;

variable_declaration_list:
    variable_declaration                            {if(myDebugPart2){msg("%d variable_declaration_list:1---",block);}}
  | variable_declaration_list variable_declaration  {if(myDebugPart2){msg("%d variable_declaration_list:2---",block);}}
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
  ;

function_declaration:

                /*
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

    function_heading semi directive_list semi                         {if(myDebugPart2){msg("%d function_declaration:directive_list---",block);}}
  | function_heading semi any_declaration_part statement_part semi    {if(myDebugPart2){msg("%d function_declaration:any_declaration_part---",block);}
                                                                              /* statement_part semi
                                                                            b_prepare_return( return type )  //TYVOID for procedures
                                                                            b_func_epilogue(func name)*/
                                                                      }
  ;

function_heading:
    LEX_PROCEDURE new_identifier optional_par_formal_parameter_list
  | LEX_FUNCTION new_identifier optional_par_formal_parameter_list functiontype
  ;

directive_list:
    directive                       {if(myDebugPart2){msg("%d directive_list:directive---",block);}}
  | directive_list semi directive   {if(myDebugPart2){msg("%d directive_list:directive_list---",block);}}
  ;

directive:
    LEX_FORWARD                     {if(myDebugPart2){msg("%d directive:LEX_FORWARD---",block);}}
  | LEX_EXTERNAL                    {if(myDebugPart2){msg("%d directive:LEX_EXTERNAL---",block);}}
  ;

functiontype:
    /* empty */                     {if(myDebugPart1){msg("functiontype:0---");}}  //procedure
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
    compound_statement
  ;

compound_statement:
    LEX_BEGIN statement_sequence LEX_END              {/*everything withing begin and end, could be func/procedure def*/
                                                        if(myDebugPart2){msg("%d compound_statement:BEGIN and END---", block);}
                                                      }
  ;

statement_sequence:
    statement                                         {/*last stement in Pascal doesnt need a semi (optional, works either way)*/

                                                      }
  | statement_sequence semi statement
  ;

statement:
    structured_statement
  | simple_statement
  ;

structured_statement:
    compound_statement
  | with_statement
  | conditional_statement
  | repetitive_statement
  ;

with_statement:
    LEX_WITH structured_variable_list LEX_DO statement
  ;

structured_variable_list:
    structured_variable
  | structured_variable_list ',' structured_variable
  ;

structured_variable:
    variable_or_function_access
  ;

conditional_statement:
    if_statement
  | case_statement
  ;

simple_if:
    LEX_IF boolean_expression LEX_THEN statement
  ;

if_statement:
    simple_if LEX_ELSE statement
  | simple_if %prec prec_if
  ;

case_statement:
    LEX_CASE expression LEX_OF case_element_list optional_semicolon_or_else_branch LEX_END
  ;

optional_semicolon_or_else_branch:
    optional_semicolon
  | case_default statement_sequence
  ;

case_element_list:
    case_element
  | case_element_list semi case_element
  ;

case_element:
    case_constant_list ':' statement
  ;

case_default:
    LEX_ELSE
  | semi LEX_ELSE
  ;

repetitive_statement:
    repeat_statement
  | while_statement
  | for_statement
  ;

repeat_statement:
    LEX_REPEAT statement_sequence LEX_UNTIL boolean_expression
  ;

while_statement:
    LEX_WHILE boolean_expression LEX_DO statement
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
  | assignment_or_call_statement        {if(myDebugPart2){msg("%d simple_statement:2---", block);}
                                          /* needs to be implimented:
                                          variable_or_function_access_maybe_assignment rest_of_statement*/
                                        }
  | standard_procedure_statement        {if(myDebugPart2){msg("%d simple_statement:3---", block);}
                                          /*needs to be implimented i think, not covered in NOTES yet
                                            rts_proc_onepar '(' actual_parameter ')'
                                          | rts_proc_parlist '(' actual_parameter_list ')'
                                          | p_WRITE optional_par_write_parameter_list
                                          | p_WRITELN optional_par_write_parameter_list
                                          | p_READ optional_par_actual_parameter_list
                                          | p_READLN optional_par_actual_parameter_list
                                          | p_PAGE optional_par_actual_parameter_list
                                          | p_DISPOSE '(' actual_parameter ')'
                                          | p_DISPOSE '(' actual_parameter ',' actual_parameter_list ')'*/
                                        }
  | statement_extensions                {/*not used, not part of standar pascal*/}
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
    expression
  ;

/* ASSIGNMENT and procedure calls */

assignment_or_call_statement:     /*tree node*/
    variable_or_function_access_maybe_assignment rest_of_statement   {if(myDebugPart2){msg("%d assignment_or_call_statement:1---", block);}
                                                                        /*rest_of_statement can be empty, or :=*/
                                                                        TN tempTreeNode;
                                                                        if($1->tag == VAR_NODE){
                                                                          tempTreeNode = makeAssignNode($1, $2);
                                                                          if(myDebugPart2){treeNodeToString(tempTreeNode, 1);}
                                                                          $$ = tempTreeNode;
                                                                        }
                                                                     }
  ;

variable_or_function_access_maybe_assignment:    /*tree node*/
    identifier                                            {if(myDebugPart2){msg("%d variable_or_function_access_maybe_assignment:1--- %s",block, st_get_id_str($1));}
                                                            //if(variable name){
                                                            $$ = makeVarNode($1);
                                                            //}
                                                            /*check if function name of current function definition (for setting return value)
                                                              create function return node (or something)
                                                            */
                                                            /*check if a procedure call name (that has no parameters)
                                                              go get this procedures top node, or create it i guess
                                                            */
                                                          }
  | address_operator variable_or_function_access          {/*not used*/if(myDebugPart2){msg("variable_or_function_access_maybe_assignment:2---OUT OF SCOPE?!?! ");}}
  | variable_or_function_access_no_id                     {if(myDebugPart2){msg("%d variable_or_function_access_maybe_assignment:3---", block);}/*example:    foo(x)^ := 6  */}
  ;

rest_of_statement:  /*tree node*/
    /* Empty */                                           {if(myDebugPart2){msg("%d rest_of_statement:0---EMPTY", block);}}
  | LEX_ASSIGN expression                                 {if(myDebugPart2){msg("%d rest_of_statement:1---", block);}
                                                             /*curently only handles simple expression, 1 term*/
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
    variable_or_function_access_no_id
  | LEX_ID
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
    expression
  ;

expression:     /*tree node*/      /*net result of evaluating an expression, one return value push on the stack*/
    expression relational_operator simple_expression     {if(myDebugPart2){msg("%d expression:1---", block);}
                                                            /* confirmed used in Part2 */
                                                         }
  | expression LEX_IN simple_expression                  {if(myDebugPart2){msg("%d expression:2---", block);}
                                                          /* probably unused for part 2*/
                                                         }
  | simple_expression                                    {if(myDebugPart2){msg("%d expression:3---", block);}
                                                          $$ = $1;
                                                         }
  ;

simple_expression:   /*tree node*/ /*simple statements leave the stack unchanged*/
    term                                                {if(myDebugPart2){msg("%d simple_expression:1---", block);}
                                                          $$ = $1;
                                                        }
  | simple_expression adding_operator term              {if(myDebugPart2){msg("%d simple_expression:2---", block);}
                                                          binopType tempBinopType;

                                                          if($2 == 1) tempBinopType = ADD;
                                                          else tempBinopType = SUB;

                                                          $$ = makeBinopNode($1, $3, tempBinopType);
                                                        }
  | simple_expression LEX_SYMDIFF term                  {if(myDebugPart2){msg("%d simple_expression:3---", block);}} //NO CLUE WHAT THIS IS >.<
  | simple_expression LEX_OR term                       {if(myDebugPart2){msg("%d simple_expression:4---", block);}}
  | simple_expression LEX_XOR term                      {if(myDebugPart2){msg("%d simple_expression:5---", block);}}
  ;

term:              /*TREE NODE*/
    signed_primary                                      {if(myDebugPart2){msg("%d term:1---", block);}
                                                          $$ = $1;
                                                        }
  | term multiplying_operator signed_primary            {if(myDebugPart2){msg("%d term:2---", block);}
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
  | term LEX_AND signed_primary                         {if(myDebugPart2){msg("%d term:3---", block);}}
  ;

signed_primary:   /*TREE NODE*/
    primary                                             {if(myDebugPart2){msg("%d signed_primary:1---", block);}
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
    factor                                              {if(myDebugPart2){msg("%d primary:1---", block);}
                                                          $$ = $1;
                                                        }
  | primary LEX_POW factor                              {if(myDebugPart2){msg("%d primary:2---", block);}
                                                          /*idk what a LEX_POW is*/
                                                        }
  | primary LEX_POWER factor                            {if(myDebugPart2){msg("%d primary:3---", block);}
                                                          /*LEX_POWER  **   */
                                                        }
  | primary LEX_IS typename                             {if(myDebugPart2){msg("%d primary:4---", block);}
                                                          /*NOT SURE IF leX_IS NEEDS TO BE HANDLED*/
                                                        }
  ;

signed_factor:  /*TREE NODE*/
    factor                                              {if(myDebugPart2){msg("%d signed_factor:1---", block);}
                                                          $$ = $1;
                                                        }
  | sign signed_factor                                  {if(myDebugPart2){msg("%d signed_factor:2---", block);}
                                                          if($1 == '-'){
                                                            $$ = makeNegNumNode($2);
                                                          }else{
                                                            $$ = $2;
                                                          }
                                                        }
  ;

factor:     /*TREE NODE*/
    variable_or_function_access                         {if(myDebugPart2){msg("%d factor:1---", block);}
                                                          $$ = $1;
                                                        }
  | constant_literal                                    {if(myDebugPart2){msg("%d factor:2---", block);}
                                                          $$ = $1;
                                                        }
  | unsigned_number                                     {if(myDebugPart2){msg("%d factor:3---", block);}
                                                          $$ = $1;  //int or real node
                                                        }
  | set_constructor                                     {if(myDebugPart2){msg("%d factor:4---", block);}}
  | LEX_NOT signed_factor                               {if(myDebugPart2){msg("%d factor:5---", block);}}
  | address_operator factor                             {if(myDebugPart2){msg("%d factor:6---", block);}}
  ;

address_operator:
    '@'
  ;

variable_or_function_access:
    variable_or_function_access_no_standard_function    {if(myDebugPart2){msg("%d variable_or_function_access:1---", block);}
                                                          $$ = $1;
                                                        }
  | standard_functions                                  {if(myDebugPart2){msg("%d variable_or_function_access:2---", block);}}
  ;

variable_or_function_access_no_standard_function:
    identifier                                          {if(myDebugPart2){msg("%d variable_or_function_access_no_standard_function:1---", block);}
                                                          $$ = makeVarNode($1);
                                                        }
  | variable_or_function_access_no_id                   {if(myDebugPart2){msg("%d variable_or_function_access_no_standard_function:2---", block);}}
  ;

variable_or_function_access_no_id:
    p_OUTPUT                                                                          {/*not used*/}
  | p_INPUT                                                                           {/*not used*/}
  | variable_or_function_access '.' new_identifier                                    {/*not used*/}
  | '(' expression ')'                                                                {if(myDebugPart2){msg("%d variable_or_function_access_no_id:4---", block);}
                                                                                        $$ = $2;
                                                                                      }
  | variable_or_function_access pointer_char                                          {if(myDebugPart2){msg("%d variable_or_function_access_no_id:5---", block);}
                                                                                        /*something ex:  p^ := 6*/
                                                                                      }
  | variable_or_function_access '[' index_expression_list ']'                         {/*for project 3, not used in part 2. for array accesses*/}
  | variable_or_function_access_no_standard_function '(' actual_parameter_list ')'    {if(myDebugPart2){msg("%d variable_or_function_access_no_id:7---", block);}
                                                                                        /*function call, expr*/
                                                                                      }
  | p_NEW '(' variable_access_or_typename ')'                                         {if(myDebugPart2){msg("%d variable_or_function_access_no_id:8---", block);}
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
    expression
  | expression LEX_RANGE expression
  ;

standard_functions:
    rts_fun_onepar '(' actual_parameter ')'
  | rts_fun_optpar optional_par_actual_parameter
  | rts_fun_parlist '(' actual_parameter_list ')'
  ;

optional_par_actual_parameter:
    /* empty */
  | '(' actual_parameter ')'
  ;

rts_fun_optpar:
    p_EOF
  | p_EOLN
  ;

rts_fun_onepar:
    p_ABS
  | p_SQR
  | p_SIN
  | p_COS
  | p_EXP
  | p_LN
  | p_SQRT
  | p_ARCTAN
  | p_ARG
  | p_TRUNC
  | p_ROUND
  | p_CARD
  | p_ORD
  | p_CHR
  | p_ODD
  | p_EMPTY
  | p_POSITION
  | p_LASTPOSITION
  | p_LENGTH
  | p_TRIM
  | p_BINDING
  | p_DATE
  | p_TIME
  ;

rts_fun_parlist:
    p_SUCC    /* One or two args */
  | p_PRED    /* One or two args */
  ;

relational_operator:
    LEX_NE   /* "<>" */
  | LEX_LE   /* "<=" */
  | LEX_GE   /* ">=" */
  | '='
  | '<'
  | '>'
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
