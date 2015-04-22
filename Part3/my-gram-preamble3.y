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
 *
 * SHIFT/REDUCE CONFLICTS
 *
 * The dangling else will not cause a shift/reduce conflict - it's
 * solved by precedence rules.
 */

%{

#include "defs.h"
#include "types.h"
#include "symtab.h"
#include "backend.h"
#include "tree.h"
#include "encode.h"

/* Cause the `yydebug' variable to be defined.  */
#define YYDEBUG 1

void set_yydebug(int);
void yyerror(const char *);

/* Like YYERROR but do call yyerror */
#define YYERROR1 { yyerror ("syntax error"); YYERROR; }
%}

/* Start symbol for the grammar */

%start pascal_program

/* The union representing a semantic stack entry */
%union {
    char *     	y_string;
    int		y_cint;
    long       	y_int;
    double     	y_real;
    TYPE       	y_type;
    ID_LIST    	y_idlist;
    ST_ID      	y_stid;
    PTR_OBJ	y_ptrobj;
    PARAM_LIST 	y_params;
    MEMBER_LIST	y_members;
    INDEX_LIST 	y_indices;
    EXPR	y_expr;
    EXPR_LIST	y_exprlist;
    EXPR_NULLOP	y_nullop;
    EXPR_UNOP	y_unop;
    EXPR_BINOP	y_binop;
    EXPR_ID	y_exprid;
    FUNC_HEAD	y_funchead;
    DIRECTIVE	y_dir;
    VAL_LIST	y_valuelist;
    CASE_RECORD	y_caserec;
}

%token <y_string> LEX_ID

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
%token <y_string> p_INPUT p_OUTPUT p_REWRITE p_RESET p_PUT p_GET p_WRITE p_READ
%token <y_string> p_WRITELN p_READLN p_PAGE p_NEW p_DISPOSE
%token <y_string> p_ABS p_SQR p_SIN p_COS p_EXP p_LN p_SQRT p_ARCTAN
%token <y_string> p_TRUNC p_ROUND p_PACK p_UNPACK p_ORD p_CHR p_SUCC p_PRED
%token <y_string> p_ODD p_EOF p_EOLN p_MAXINT p_TRUE p_FALSE

/* Additional redefinable identifiers for Borland Pascal */
%token bp_RANDOM bp_RANDOMIZE BREAK CONTINUE

/* redefinable keyword extensions */
%token RETURN_ RESULT EXIT FAIL p_CLOSE CONJUGATE p_DEFINESIZE SIZEOF
%token BITSIZEOF ALIGNOF TYPEOF gpc_RETURNADDRESS gpc_FRAMEADDRESS
%token LEX_LABEL_ADDR

/* GPC internal tokens */
%token <y_int> LEX_INTCONST
%token <y_string> LEX_STRCONST
%token <y_real> LEX_REALCONST
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
%token LEX_EXTERNAL ucsd_STR p_MARK p_RELEASE p_UPDATE p_GETTIMESTAMP p_UNBIND
%token p_EXTEND bp_APPEND p_BIND p_SEEKREAD p_SEEKWRITE p_SEEKUPDATE LEX_SYMDIFF
%token p_ARG p_CARD p_EMPTY p_POSITION p_LASTPOSITION p_LENGTH p_TRIM p_BINDING
%token p_DATE p_TIME LEX_RENAME LEX_IMPORT LEX_USES LEX_QUALIFIED LEX_ONLY

/* Types for nonterminals */

%type <y_expr> unsigned_number number constant constant_literal
%type <y_expr> expression actual_parameter static_expression boolean_expression
%type <y_expr> simple_expression term signed_primary primary factor
%type <y_expr> signed_factor variable_or_function_access predefined_literal
%type <y_expr> variable_or_function_access_no_as standard_functions
%type <y_expr> variable_or_function_access_no_standard_function
%type <y_expr> variable_or_function_access_no_id rest_of_statement
%type <y_expr> assignment_or_call_statement standard_procedure_statement
%type <y_expr> variable_access_or_typename optional_par_actual_parameter
%type <y_expr> index_expression_item
%type <y_exprlist> actual_parameter_list optional_par_actual_parameter_list
%type <y_exprlist> index_expression_list
%type <y_nullop> rts_fun_optpar
%type <y_unop> sign rts_fun_onepar rts_fun_parlist
%type <y_binop> relational_operator multiplying_operator adding_operator
%type <y_exprid> variable_or_function_access_maybe_assignment
%type <y_idlist> optional_par_id_list id_list
%type <y_stid> identifier new_identifier
%type <y_string> new_identifier_1 string combined_string
%type <y_type> typename type_denoter type_denoter_1 new_ordinal_type 
%type <y_type> new_pointer_type new_procedural_type new_structured_type
%type <y_type> unpacked_structured_type enumerated_type array_type
%type <y_type> subrange_type ordinal_index_type functiontype parameter_form
%type <y_indices> array_index_list
%type <y_ptrobj> pointer_domain_type
%type <y_params> optional_procedural_type_formal_parameter_list
%type <y_params> procedural_type_formal_parameter_list
%type <y_params> procedural_type_formal_parameter
%type <y_params> optional_par_formal_parameter_list formal_parameter_list
%type <y_params> formal_parameter
%type <y_funchead> function_heading
%type <y_dir> directive_list directive
%type <y_cint> variable_declaration_part variable_declaration_list
%type <y_cint> variable_declaration simple_decl any_decl any_declaration_part
%type <y_string> simple_if if_statement case_statement conditional_statement
%type <y_valuelist> case_constant_list one_case_constant
%type <y_caserec> case_element_list case_element
%type <y_cint> repetitive_statement for_direction

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
