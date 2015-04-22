#ifndef TREE_H
#define TREE_H

#include "defs.h"
#include "types.h"
#include "symtab.h"


/* Some struct types for the semantic stack */

/* Used for nonterminals: optinal_par_id_list, id_list */
typedef struct id_node {
    ST_ID           id;
    struct id_node *next;
} ID_NODE, *ID_LIST;

/* Used for nonterminal: variable_or_function_access_maybe_assignment

   This could be any number of things: a simple variable (identifier) on
   the left-hand side of an assignment; a stand-alone procedure call (with
   no assignment); an expression involving an array index or indirection
   operator (^) indicating an l-value on the left-hand side of an assignment;
   a function name on the left-hand side of an assignment (indicating a
   return value assignment).  All uses should produce an expression, but
   the last one also requires the ST_ID.  We don't know at this production
   what will be used until we see the rest of the statement, so we use this
   structure to pass back all available relevant information.  (If the
   production is to variable_or_function_access_no_id, then the id field
   should be set to NULL).
*/
typedef struct {
    struct exprnode * expr;
    ST_ID id;
} EXPR_ID;

/* Dual purpose:
     PTR_OBJ used for nonterminal: pointer_domain_type (to deal with
       possibly unresolved pointers)
     FUNC_HEAD used for nonterminal: function_heading

   For FUNC_HEAD, we can't st_install a function at the function_heading
   production, because we don't know what kind of function declaration
   it will be used for (a forward declaration, external declaration, or
   actual function definition), so we pass back the relevant information
   so that it can be installed later.
*/
typedef struct {
    ST_ID	id;
    TYPE	type;
} PTR_OBJ, FUNC_HEAD;

/* Stores the type and the low and high values used in a case constant
   (assumed to be a subrange).  If the constant is a single value, then the
   high and low values are both set to this value. */
typedef struct val_node {
    long lo, hi;
    TYPETAG type;
    struct val_node * next;
} VAL_LIST_REC, *VAL_LIST;

/* Record for holding attributes of a case statement on the semantic stack.
   One such record is used per case statement.
   Fields:
       type: the type of the case expression
       label: the exit label for the case statement (a fresh label)
       values: the linked list of case constants (initially empty)
   This record is initialized and placed on the semantic stack in an
   intermediate action in the case_statement production, after LEX_OF but
   before any case_element's.  The list of case constants is built up
   inside each case_element.  Alternatively, one could use a global
   stack of CASE_RECORDs instead of using the semantic stack.  (A stack is
   required because case statements can be nested, and information for an
   inner case statement and its surrounding case statement should be kept
   separate.
*/
typedef struct {
    TYPETAG	type;
    char * 	label;
    VAL_LIST	values;
} CASE_RECORD;


/* Structures for syntax tree nodes (EXPR and EXPR_LIST) */

/* Possible expression types (tags) */
/* New type ARRAY_ACCESS added to handle array accesses in Project III */
typedef enum {
    INTCONST, REALCONST, STRCONST, GID, LVAR, LFUN, NULLOP, UNOP, BINOP,
    FCALL, ARRAY_ACCESS, ERROR
} EXPR_TAG;

/* Possible nullary operators (tags) */
typedef enum {
    NULL_EOF_OP, NULL_EOLN_OP, NIL_OP
} EXPR_NULLOP;

/* Possible unary operators (tags) */
typedef enum {
    CONVERT_OP, DEREF_OP, NEG_OP, ORD_OP, CHR_OP, UN_SUCC_OP, UN_PRED_OP,
    NOT_OP, ABS_OP, SQR_OP, SIN_OP, COS_OP, EXP_OP, LN_OP, SQRT_OP, ARCTAN_OP,
    ARG_OP, TRUNC_OP, ROUND_OP, CARD_OP, ODD_OP, EMPTY_OP, POSITION_OP,
    LASTPOSITION_OP, LENGTH_OP, TRIM_OP, BINDING_OP, DATE_OP, TIME_OP,
    UN_EOF_OP, UN_EOLN_OP, INDIR_OP, UPLUS_OP, NEW_OP, DISPOSE_OP, ADDRESS_OP,
    SET_RETURN_OP
} EXPR_UNOP;

/* Possible binary operators (tags) */
typedef enum {
    ADD_OP, SUB_OP, MUL_OP, DIV_OP, MOD_OP, REALDIV_OP, EQ_OP, LESS_OP, LE_OP,
    NE_OP, GE_OP, GREATER_OP, SYMDIFF_OP, OR_OP, XOR_OP, AND_OP, BIN_SUCC_OP,
    BIN_PRED_OP, ASSIGN_OP
} EXPR_BINOP;

/* Used for lists of actual arguments to functions/procedures */
typedef struct exprlistnode {
    struct exprnode * expr;
    struct exprlistnode * next;
} EXPR_LIST_NODE, * EXPR_LIST;

/* The syntax tree node for an expression
   (includes the type of the expression)
*/
typedef struct exprnode {
    EXPR_TAG tag;
    TYPE type;
    union {
	long intval;
	double realval;
	char * strval;
	ST_ID gid;          /* For global variables and global functions */
	struct {            /* For local variables and formal parameters */
	    BOOLEAN is_ref; /* TRUE if expr is a VAR (reference) parameter */
	    int offset;     /* storage location relative to frame pointer */
	    int link_count; /* Number of ref links to follow to find the var */
	} lvar;
	struct {            /* For local functions */
	    char * global_name; /* The assembler entry point label */
	    int link_count; /* Number of ref links to follow to find the fcn */
	} lfun;
	struct {            /* For nullary operators */
	    EXPR_NULLOP op;
	} nullop;
	struct {            /* For unary operators */
	    EXPR_UNOP op;
	    struct exprnode * operand;
	} unop;
	struct {            /* For binary operators */
	    EXPR_BINOP op;
	    struct exprnode * left, * right;
	} binop;
	struct {            /* For proc/func calls and array accesses */
		            /* Style issue: these fields do double duty and
			       really should be renamed, e.g., to
			       function_or_array and args_or_indices, and
			       the name of the struct itself to
			       fcall_or_array_access */
	    struct exprnode * function;
	    EXPR_LIST args;
	} fcall;
    } u;
} EXPR_NODE, * EXPR;


/* Procedure and function prototype directives */
typedef enum { DIR_EXTERNAL, DIR_FORWARD } DIRECTIVE;


/* Records the current function identifier to detect return value assigns */
extern ST_ID func_id_stack[BS_DEPTH];
extern int fi_top;


/**** Prototypes ****/

/* Project 1 */

ID_LIST id_prepend(ST_ID id, ID_LIST list);
ID_LIST id_reverse(ID_LIST list);
INDEX_LIST index_append(INDEX_LIST indices, TYPE type);
TYPE check_typename(ST_ID id);
void resolve_ptr_types();
void make_type(ST_ID id, TYPE type);
TYPE make_array(TYPE object, INDEX_LIST indices);
PARAM_LIST check_params(PARAM_LIST params);
PARAM_LIST make_params(ID_LIST ids, TYPE type, BOOLEAN is_ref);
PARAM_LIST param_concat(PARAM_LIST first, PARAM_LIST second);
BOOLEAN is_simple_type(TYPETAG tag);
BOOLEAN is_ordinal_type(TYPETAG tag);
BOOLEAN is_index_type(TYPE type);
BOOLEAN is_data_type(TYPETAG tag);
unsigned int size_of(TYPE type);

/* Project 2 */

EXPR_LIST expr_list_reverse(EXPR_LIST list);
EXPR_LIST expr_prepend(EXPR expr, EXPR_LIST list);
int process_var_decl(ID_LIST ids, TYPE type, int cur_offset);
TYPE check_subrange(EXPR lo, EXPR hi);
void build_func_decl(ST_ID id, TYPE type, DIRECTIVE dir);
int enter_function(ST_ID id, TYPE type, char * global_func_name);
EXPR make_intconst_expr(long val, TYPE type);
EXPR make_realconst_expr(double val);
EXPR make_strconst_expr(char * str);
EXPR make_id_expr(ST_ID id);
EXPR make_null_expr(EXPR_NULLOP op);
EXPR make_un_expr(EXPR_UNOP op, EXPR sub);
EXPR make_bin_expr(EXPR_BINOP op, EXPR left, EXPR right);
EXPR make_fcall_expr(EXPR func, EXPR_LIST args);
EXPR make_error_expr();
EXPR check_assign_or_proc_call(EXPR lhs, ST_ID id, EXPR rhs);
BOOLEAN is_lval(EXPR expr);
void expr_free(EXPR expr);
void expr_list_free(EXPR_LIST list);
EXPR rvalue(EXPR expr);
EXPR un_convert(EXPR expr);
char * get_global_func_name(ST_ID id);

/* Project 3 */

/* Returns the number of possible values of the given type, assumed to be
   an integral (ordinal) type smaller than long (usually a subrange).
   Also sets the output parameter low to the lowest possible value of the
   given type.
   Used to compute offsets and element sizes in array accesses.  Return
   value can also be used in size_of() to help find the size of an array.
*/
unsigned long get_value_range(TYPE type, long * low);


/* gram: variable_or_function_access_no_id (6th production)
   Returns a new ARRAY_ACCESS expr with the given array (in u.fcall.function)
   and given list of indices (in u.fcall.args).  These fields are "borrowed"
   from the function call expression.  Checks that the array is of array type
   (tag TYARRAY), else error.  Gets the r-value of each index expression, then
   unary converts it.  Also checks that the type of each index expression
   (after unary conversion) matches the corresponding "formal" index type
   (after base types are substituted for subranges), else error.  Also checks
   that the number of index expressions matches that of the array type.

   Note: things of array type are always l-values in Pascal, although they
   are always r-values in C.  Array accesses are always l-values (in both
   languages).
*/
EXPR make_array_access_expr(EXPR array, EXPR_LIST indices);


/* gram: one_case_constant (both productions), case_statement (intermediate action after LEX_OF, just to make an inital dummy record)
   Returns a new VAL_LIST node with the given information for a single case
   constant (obtained from an earlier call or calls to get_case_value()).
*/
VAL_LIST new_case_value(TYPETAG type, long lo, long hi);


/* gram: case_element (intermediate action after ':')
   Parameters:
       type: the type of the case expression
       vals: the list of current case constants
       prev_vals: the list of all previous case constants (for previous
           case elements)
   For each case constant on the vals list: Checks that its type (of both low
   and high values if subrange) matches that of the case expression, and if a
   subrange, checks that the low value is <= the high value (else ignored with
   warning), then checks for any overlap between the current value and any of
   the previous case constants (if so, error).  If all is ok, appends the case
   constant onto the list of previous values.

   Returns true iff no errors.

   Note: the case expression should be internally converted to a long,
   regardless of its type.  All comparisons of the case expression with
   case constants should be as TYSIGNEDLONGINT.  This internal conversion
   does not affect the TYPE being passed to check_case_values().
*/
BOOLEAN check_case_values(TYPETAG type, VAL_LIST vals, VAL_LIST prev_vals);


/* gram: case_constant_list (2nd production -- if error occurred), optional_semicolon_or_else_branch (both productions)
   De-allocates a list of case constants.
*/
void case_value_list_free(VAL_LIST vals);


/* gram: one_case_constant (once in 1st production; twice in 2nd production)
   Here, expr is a static (constant) expression, either alone or part of
   a subrange.  Sets the output parameters to the value and type of the
   expression.  The expr (after converting a STRCONST if possible or necessary)
   must be an INTCONST (else error).  Returns true iff no errors.
*/
BOOLEAN get_case_value(EXPR expr, long * val, TYPETAG * type);


/* gram: for_statement (in intermediate action after LEX_DO)
   Expressions passed are for the loop control variable, the initial value
   and the limit value, respectively.  Checks that the var is an l-value of
   ordinal type, and that its type matches those of the init and limit
   (after base types are substituted for subranges, as usual).
   Returns true iff all checks are ok.
*/
BOOLEAN check_for_preamble(EXPR var, EXPR init, EXPR limit);

#endif
