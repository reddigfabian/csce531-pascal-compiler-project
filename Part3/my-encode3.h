#include "types.h"
#include "symtab.h"
#include "tree.h"

#if 0
/* Records the base offset (from %fp) for all local variables in a function */
extern int base_offset_stack[BS_DEPTH];
extern int bo_top;
#endif

void encode_global_var_decl(char *id, int align, unsigned int size);
int get_local_var_offset();
void enter_func_body(char * global_func_name, TYPE type, int loc_var_size);
void exit_func_body(char * global_func_name, TYPE type);
void enter_main_body();
void exit_main_body();



/* Project III */

/* NOTE: In my solution code, many back-end routines are called directly
   from actions within the grammar.  Also, array access encoding is handled
   in helper functions to encode_expr()  This means that the following
   functions do not include all the encoding that is done.
*/

/* gram: simple_if (intermediate action after LEX_THEN), case_statement (intermediate action after LEX_OF), while_statement (intermediate action after LEX_DO), for_statement (reduce action -- to push the address of the loop control variable for incrementing/decrementing), simple_statement (3rd and 4th productions)
   This function is also modified from Project II to encode ARRAY_ACCESS
   expressions.
*/
void encode_expr(EXPR expr);


/* gram: structured_statement (4th production, intermediate action before repetitive_statement)
   Generates a new label (calling new_symbol()) and pushes it onto a private
   global stack of exit labels.  (The stack is initially empty when parsing
   starts.)
*/
void new_exit_label();


/* gram: structured_statement (4th production's reduce action)
   Pops an exit label off of the private global stack of exit labels and
   returns it.  (BUG message if the stack is empty.)
*/
char * old_exit_label();


/* gram: while_statement (intermediate action after LEX_DO), statement_extensions (3rd production)
   Returns the label at the top of the private global stack of exit labels
   without popping it.  (BUG message if the stack is empty)
*/
char * current_exit_label();


/* gram: statement_extensions (3rd production)
   Returns true iff the private global stack of exit labels is nonempty.
*/
BOOLEAN is_exit_label();


/* gram: case_element (intermediate action after ':')
   At run time, it is assumed that the value of the case expression is on
   top of the control stack.  Each case constant in vals is compared with
   the case expression using b_dispatch().  The label parameter is the
   destination to jump to if there are no matches among the current constants.
   (This destination will be the start of the next case element if there is
   one, otherwise the start of the else-clause if there is one, otherwise the
   end of the entire case statement itself.)

   Before looping through the constants, a new "match" label is generated,
   to be used as the destination to jump to if a match is found.  This will
   be the beginning of the subsequent statement inside the current case
   element.

   In each loop iteration:
   -- For a single case constant value (low==high), B_EQ is used for
      the comparison, and only one call to b_dispatch() is made (with the
      match label).
   -- For a nontrivial subrange (low < high):
      1. A new label l is generated.
      2. The low value is compared with B_LT and label l.
      3. The high value is compared with B_LE and the match label.
      4. The label l is emitted with b_label().
   The point of the label l is that if the case expresion is less than the
   low value, we want to avoid the subsequent comparison with the high value,
   so we are branching around it.

   After the loop:
   1. Unconditional jump to the "no match" label given by the parameter.
   2. Emit the match label using b_label()

   In all instances of b_dispatch(), the comparison uses TYSIGNEDLONGINT,
   which is assumed to be how the values are stored internally.

   The last parameter to b_dispatch() should be TRUE (thus popping the
   case expression) if and only if there is a match (branch to the match
   label -- see the comments for b_dispatch() in backend.h).
*/
void encode_dispatch(VAL_LIST vals, char * label);


/* gram: for_statement (part of intermediate action after LEX_DO)
   Encodes the preamble to a for-loop:
   1. Encodes the limit expression, implicitly converting it to
      TYSIGNEDLONGINT if it isn't already (b_convert()).  (This pushes the
      value onto the control stack at runtime.)
   2. Emits code to duplicate this value (b_duplicate()).
   3. Encodes what amounts to an assignment of the initial value to the
      loop control variable, except tha the value assigned is not popped
      off the control stack afterwards.
   4. Emits a new "return" label (with b_label()).
   5. Emits code to convert the initial value (on top of the control stack) to
      TYSIGNEDLONGING (b_convert()) if it isn't already.
   6. Emits code to compare the duplicate limit value with the top stack
      value (b_arith_rel_op()) with either B_LT or B_GT,
      depending on the direction (dir).  (There are two possible directions,
      corresponding to the two token types LEX_TO and LEX_DOWNTO.)
   7. Emits a conditional jump on true (B_NONZERO) to the current exit label
      (current_exit_label()).

   Note: For this to work, at the end of each iteration, when the loop
   control variable is incremented (or decremented, according to the direction),
   the condition of the control stack must be similar to the above upon
   jumping back to the "return" label.  That is, the new value of the
   loop control variable must be on top, with a duplicate of the limit
   value immediately beneath it.  This latter conditioning should be done
   in the reduce action to the for_statement production.  The easiest way
   to increment or decrement the variable so that the the new value is left
   on the stack is to use b_inc_dec() with either B_PRE_INC or B_PRE_DEC,
   depending on the direction.
*/
char * encode_for_preamble(EXPR var, EXPR init, int dir, EXPR limit);
