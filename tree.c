#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "types.h"

int myDebug = 1;
int errorCalled = 0;
char* tagtypeStrings[] = {"STRINGCONSTANT", "INTCONSTANT", "REALCONSTANT", "VAR_NODE", "NEGNUM", "ASSIGN_NODE", "BOOL_NODE", "BINOP_NODE", "FUNC_NODE", "RELOP_NODE"};
char* unopTypeStrings[] = {"CHR", "ORD", "SUCC", "PRED", "NEG"};
char* binopTypeStrings[] = {"ADD", "SUB", "REAL_DIV", "INT_DIV", "MOD", "MULT"};
char* relationalTypeStrings[] = {"NE","LE","GE","EQ","LT","GT"};
char* rtsFunOneParStrings[] = {
    "pas_ABS","pas_SQR","pas_SIN","pas_COS","pas_EXP",
    "pas_LN","pas_SQRT","pas_ARCTAN",
    "pas_ARG","pas_TRUNC","pas_ROUND","pas_CARD",
    "pas_ORD","pas_CHR","pas_ODD","pas_EMPTY",
    "pas_POSITION","pas_LASTPOSITION",
    "pas_LENGTH","pas_TRIM","pas_BINDING",
    "pas_DATE","pas_TIME","pas_SUCC","pas_PRED"};


/*
typedef enum {
TYVOID, TYFLOAT, TYDOUBLE, TYLONGDOUBLE, TYSIGNEDLONGINT,
TYSIGNEDSHORTINT, TYSIGNEDINT, TYUNSIGNEDLONGINT,
TYUNSIGNEDSHORTINT, TYUNSIGNEDINT, TYUNSIGNEDCHAR,
TYSIGNEDCHAR, TYSTRUCT, TYUNION, TYENUM, TYARRAY, TYSET,
TYFUNC, TYPTR, TYBITFIELD, TYSUBRANGE, TYERROR
} TYPETAG;
*/


/*
typedef enum{INTCONSTANT, REALCONSTANT, VAR_NODE, NEGNUM, ASSIGN_NODE, BOOL_NODE, BINOP_NODE, FUNC_NODE}tagtype;

typedef enum{ADD, SUB, REAL_DIV, INT_DIV, MOD, MULT}binopType;

typedef struct tn{
  tagtype tag;

  union{

    long intconstant;
    double realconstant;
    struct tn *negNode;
    int boolean;

    struct{
      ST_ID varName;
      int isInstalled;
      ST_DR DR;
      STDR_TAG DRtag;
      TYPE type;
      TYPETAG typetag;
    }var_node;

    struct{
      ST_ID funcName;
      int isInstalled;
      ST_DR DR;
      STDR_TAG DRtag;
      TYPE type;
      TYPETAG typeTag

      //PARAMETERLIST PARAMS - add this

    }func_node; //PLAY THAT FUNC-Y MUSIC...WHIIIIIIIITE BOI

    struct{
      struct tn *varNode;
      struct tn *expression;
    }assign_node;

    struct{
      binopType binTag;
      struct tn *left;
      struct tn *right;
    }binop;


  }u;

}treeNode, *TN;

*/

/*
********************MAKE FUNCTIONS*********************
*/

TN makeErrorNode(){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = ERROR_NODE;
  return tempTN;
}

TN makeIntConstNode(long intconstant){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = INTCONSTANT;
  tempTN->u.intconstant = intconstant;
  return tempTN;
}

TN makeRealConstNode(double realconstant){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = REALCONSTANT;
  tempTN->u.realconstant = realconstant;
  return tempTN;
}

TN makeStringConstNode(char *stringconstant){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = STRINGCONSTANT;
  tempTN->u.string = stringconstant;
  return tempTN;
}

TN makeNegNumNode(TN numNode){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = NEGNUM;
  tempTN->u.negNode = numNode;
  return tempTN;
}

TN makeVarNode(ST_ID id){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = VAR_NODE;
  tempTN->u.var_node.varName = id;

  int block;
  ST_DR tempDR = st_lookup(id, &block);
  if(tempDR != NULL){
    tempTN->u.var_node.isInstalled = 1;
    tempTN->u.var_node.DR = tempDR;
    tempTN->u.var_node.DRtag = tempDR->tag;
    if(tempDR->tag == GDECL | tempDR->tag == LDECL | tempDR->tag == PDECL | tempDR->tag == FDECL){
      tempTN->u.var_node.type = tempDR->u.decl.type;
      tempTN->u.var_node.typeTag = ty_query(tempDR->u.decl.type);
    }else if(tempDR->tag == ECONST){
      tempTN->u.var_node.type = tempDR->u.econst.type;
      tempTN->u.var_node.typeTag = ty_query(tempDR->u.econst.type);
    }else if(tempDR->tag == TYPENAME){
      tempTN->u.var_node.type = tempDR->u.typename.type;
      tempTN->u.var_node.typeTag = ty_query(tempDR->u.typename.type);
    }else{
      bug("Bad DR tag in makeVarNode()");
    }
  }else{ //tempDR == NULL
    tempTN->u.var_node.isInstalled = 0;
    //tempTN->u.var_node.DR = NULL;
    //tempTN->u.var_node.DRtag = NULL;
    //tempTN->u.var_node.type = NULL;
    //tempTN->u.var_node.typeTag = NULL;
  }

  return tempTN;
}

TN makeAssignNode(TN var, TN expr){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = ASSIGN_NODE;
  tempTN->u.assign_node.varNode = var;
  tempTN->u.assign_node.expression = expr;
  return tempTN;
}

TN makeBoolNode(int tempBool){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = BOOL_NODE;
  tempTN->u.boolean = tempBool;
  return tempTN;
}

TN makeUnopNode(TN operand, unopType op){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = UNOP_NODE;
  tempTN->u.unop.unTag = op;
  tempTN->u.unop.operand = operand;
  return tempTN;
}

TN makeBinopNode(TN leftSide, TN rightSide, binopType binTagType){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = BINOP_NODE;
  tempTN->u.binop.binTag = binTagType;
  tempTN->u.binop.left = leftSide;
  tempTN->u.binop.right = rightSide;
  return tempTN;
}

TN makeRelopNode(TN leftSide, relationalType relTagType, TN rightSide){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = RELOP_NODE;
  tempTN->u.relop.relTag = relTagType;
  tempTN->u.relop.left = leftSide;
  tempTN->u.relop.right = rightSide;
  return tempTN;
}

TN makeFuncNode(ST_ID id, TYPETAG typeTag, TYPE type){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = FUNC_NODE;
  tempTN->u.func_node.funcName = id;
  tempTN->u.func_node.typeTag = typeTag;
  tempTN->u.func_node.type = type;
  return tempTN;
}

/*
********************************BACKEND STUFF****************************
*/

TYPETAG genBackendAssignment(TN startNode, int fromExpr, int genBackend){
  /*
  b_negates(TYPETAG type)
  deal with unary negative
  */
  switch(startNode->tag){

    case FUNC_NODE:{
      errorCalled = 0;
      TYPETAG tempTYPETAG = startNode->u.func_node.typeTag;
      char *tempName = st_get_id_str(startNode->u.func_node.funcName);
      b_alloc_arglist(0);  //for exterens and forwards (no args)
      b_funcall_by_name(tempName, tempTYPETAG);
      return tempTYPETAG;

    }case STRINGCONSTANT:{
      char *tempStr;
      tempStr = startNode->u.string;
      int tempInt = (int)tempStr[0];
      if(genBackend) b_push_const_int(tempInt);
      if(genBackend) b_convert(TYSIGNEDLONGINT, TYUNSIGNEDCHAR);
      return TYUNSIGNEDCHAR;

    }case INTCONSTANT:{
      long tempInt;
      tempInt = startNode->u.intconstant;
      if(genBackend) b_push_const_int(tempInt);
      return TYSIGNEDLONGINT;   //not 100% yet

    }case REALCONSTANT:{
      double tempReal = startNode->u.realconstant;
      if(genBackend) b_push_const_double(tempReal);
      return TYDOUBLE;  //not 100% yet

    }case BOOL_NODE:{
      int tempBool = startNode->u.boolean;
      if(genBackend) b_push_const_int(tempBool);
      if(genBackend) b_convert(TYSIGNEDLONGINT, TYSIGNEDCHAR);
      return TYSIGNEDCHAR;

    }case NEGNUM:{
      TN tempNode = startNode->u.negNode;
      tagtype tempTagType = tempNode->tag;
      if(tempTagType == INTCONSTANT){
        long tempInt = -1 * tempNode->u.intconstant;
        if(genBackend) b_push_const_int(tempInt);
        return TYSIGNEDLONGINT;   //not 100% yet

      }else if(tempTagType == REALCONSTANT){
        double tempReal = -1 * tempNode->u.realconstant;
        if(genBackend) b_push_const_double(tempReal);
        return TYDOUBLE;  //not 100% yet

      }else if(tempTagType == VAR_NODE){
        TYPETAG varTypeTag = genBackendAssignment(startNode->u.assign_node.varNode, 0, genBackend);
        if(genBackend) b_negate(varTypeTag);
        return varTypeTag;

      }else{
        bug("unchecked tag in NEGNUM genBackendAssignment()");
        break;
      }

    }case VAR_NODE:{
      errorCalled = 0;
      if(fromExpr){
        if(startNode->u.var_node.isInstalled){
          char *tempIdString = st_get_id_str(startNode->u.var_node.varName);
          if(genBackend) b_push_ext_addr(tempIdString);
          TYPETAG tempTypeTag = getTYPETAG(startNode);
          if(genBackend) b_deref(tempTypeTag);
          return tempTypeTag;
        }else{ //var_node not installed in symbol table
          error("variable in expression has not been initilized");
          break;
        }
      }else{ //var is on the left hand side of an assignment, dont deref
        char *tempIdString = st_get_id_str(startNode->u.var_node.varName);
        if(genBackend) b_push_ext_addr(tempIdString);
        TYPETAG tempTypeTag = getTYPETAG(startNode);
        return tempTypeTag;
      }

    }case UNOP_NODE:{
      return handleUNOP_NODE(startNode,genBackend);

    }case BINOP_NODE:{
      return handleBINOP_NODE(startNode, genBackend);

    }case RELOP_NODE:{
      return handleRELOP_NODE(startNode, genBackend);

    }case ASSIGN_NODE:{
      //just get what the return TYPETAGS would be, before generating any backend
      TYPETAG varTypeTag = genBackendAssignment(startNode->u.assign_node.varNode, 0, 0);
      TYPETAG expTypeTag = genBackendAssignment(startNode->u.assign_node.expression, 1, 0);


      if(myDebug){
        msgn("ASSIGNMENT: ");
        ty_print_typetag(varTypeTag);
        msgn(" := ");
        ty_print_typetag(expTypeTag);
        msg(";");
      }

      //check TYPETAG values for the assignment, then error check or gen the backend
      int INVALID = 1;
      if(varTypeTag == expTypeTag) INVALID = 0;
      if(varTypeTag == TYDOUBLE && expTypeTag == TYSIGNEDLONGINT) INVALID = 0;  //needs to do the conversion
      if(varTypeTag == TYFLOAT && expTypeTag == TYSIGNEDLONGINT) INVALID = 0;
      if(varTypeTag == TYFLOAT && expTypeTag == TYDOUBLE) INVALID = 0;
      if(varTypeTag == TYUNSIGNEDCHAR && expTypeTag == TYSIGNEDCHAR) INVALID = 0;
      if(varTypeTag == TYSIGNEDCHAR && expTypeTag == TYUNSIGNEDCHAR) INVALID = 0;


      if(INVALID){ if(expTypeTag != TYERROR){ error("Illegal conversion");} //if TYERROR, the an error was printed already
      }else{
        genBackendAssignment(startNode->u.assign_node.varNode, 0, 1);

        genBackendAssignment(startNode->u.assign_node.expression, 1, 1);


        if(varTypeTag == TYDOUBLE && expTypeTag == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT,TYDOUBLE);
        if(varTypeTag == TYFLOAT && expTypeTag == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT,TYFLOAT);
        if(varTypeTag == TYFLOAT && expTypeTag == TYDOUBLE) b_convert(TYDOUBLE,TYFLOAT);
        if(varTypeTag == TYUNSIGNEDCHAR && expTypeTag == TYSIGNEDCHAR) b_convert(TYSIGNEDCHAR,TYUNSIGNEDCHAR);
        if(varTypeTag == TYSIGNEDCHAR && expTypeTag == TYUNSIGNEDCHAR) b_convert(TYUNSIGNEDCHAR,TYSIGNEDCHAR);

        b_assign(varTypeTag);
        b_pop();
      }
      return expTypeTag;

    }default:{
      bug("BACKEND ASSIGNMENT -- THIS IS AN error");
      break;
    }}
  }//END genBackendAssignment()



TYPETAG handleConstantFolding(binopType op, TN node, TYPETAG Ltag, TYPETAG Rtag, int genBackend){
  double leftD;
  double rightD;

  if(Ltag == Rtag){ //they are the same type
    if(Ltag == TYSIGNEDLONGINT){ //both ints
      long left = node->u.binop.left->u.intconstant;
      long right = node->u.binop.right->u.intconstant;
      long tempInt;
      if(op == ADD) tempInt = left + right;
      if(op == SUB) tempInt = left - right;
      if(op == REAL_DIV) tempInt = left / right;
      if(op == INT_DIV) tempInt = left / right;
      if(op == MULT) tempInt = left * right;
      if(op == MOD) tempInt = left % right;
      if(genBackend) b_push_const_int(tempInt);
      return TYSIGNEDLONGINT;
    }else{ //both doubles
      double leftD = node->u.binop.left->u.realconstant;
      double rightD = node->u.binop.right->u.realconstant;
    }
  }else{ //one of them is a double, other is an INT
      if(Ltag == TYDOUBLE){
        double leftD = node->u.binop.left->u.realconstant;
        double rightD = (double)node->u.binop.right->u.intconstant;
      }else{ //Ltag == TYSIGNEDLONGINT
        double leftD = (double)node->u.binop.left->u.intconstant;
        double rightD = node->u.binop.right->u.realconstant;
      }
  }

  double tempReal;

  if(op == ADD) tempReal = leftD + rightD;
  if(op == SUB) tempReal = leftD - rightD;
  if(op == REAL_DIV) tempReal = leftD / rightD;
  if(op == INT_DIV) tempReal = leftD / rightD;
  if(op == MULT) tempReal = leftD * rightD;
  if(op == MOD){
    error("wrong type for mod function");
    return TYERROR;
  }

  if(genBackend) b_push_const_double(tempReal);
  return TYDOUBLE;

}//END handleConstantFolding



TYPETAG handleBINOP_NODE(TN node, int genBackend){
  if(node->tag == BINOP_NODE){

    TYPETAG Ltag = genBackendAssignment(node->u.binop.left, 1, 0); //just get return type
    TYPETAG Rtag;
    if(Ltag != TYERROR){
      Rtag = genBackendAssignment(node->u.binop.right, 1, 0);
    }else{
       if(myDebug){msg("Ltag was tyerror in handleBINOP_NODE");}
       Rtag = TYERROR;
     }
    tagtype LnodeType = node->u.binop.left->tag;
    tagtype RnodeType = node->u.binop.right->tag;
    int inValid = 1;

    //DOESNT HANDLE NEGNUMS YET
    TN tempNode = node;

    //CONSTANT FOLDING of const ints/doubles
    if((LnodeType == INTCONSTANT | LnodeType == REALCONSTANT) &&
       (RnodeType == INTCONSTANT | RnodeType == REALCONSTANT)){
         if(myDebug && genBackend == 0){msg("CONSTANT FOLDING");}
         return handleConstantFolding(node->u.binop.binTag, tempNode, Ltag, Rtag, genBackend);
    }//END CONSTANT FOLDING of const ints/doubles
    else{ //NOT CONSTANT FOLDING

        if(Ltag == Rtag) inValid = 0;
        //if(Ltag == TYSIGNEDCHAR | Rtag == TYSIGNEDCHAR) inValid = 0;
        //if(Ltag == TYUNSIGNEDCHAR | Rtag == TYUNSIGNEDCHAR) inValid = 0;

        //Left cast up to Right
        if(Ltag == TYSIGNEDLONGINT && Rtag == TYFLOAT)  inValid = 0;
        if(Ltag == TYSIGNEDLONGINT && Rtag == TYDOUBLE)  inValid = 0;
        if(Ltag == TYFLOAT && Rtag == TYDOUBLE)  inValid = 0;

        //Right cast up to Left
        if(Rtag == TYSIGNEDLONGINT && Ltag == TYFLOAT)  inValid = 0;
        if(Rtag == TYSIGNEDLONGINT && Ltag == TYDOUBLE)  inValid = 0;
        if(Rtag == TYFLOAT && Ltag == TYDOUBLE)  inValid = 0;

        //WRONG TYPES for MOD
        if(node->u.binop.binTag == MOD){
          if(Ltag == TYDOUBLE | Ltag == TYFLOAT) inValid = 1;
          if(Rtag == TYDOUBLE | Rtag == TYFLOAT) inValid = 1;
        }

        if(inValid == 0){

          genBackendAssignment(node->u.relop.left, 0, genBackend);
          //Left cast up to Right
          if(Ltag == TYSIGNEDLONGINT && Rtag == TYFLOAT){  b_convert(TYSIGNEDLONGINT, TYFLOAT); Ltag = TYFLOAT;}
          if(Ltag == TYSIGNEDLONGINT && Rtag == TYDOUBLE){ b_convert(TYSIGNEDLONGINT, TYDOUBLE); Ltag = TYDOUBLE;}
          if(Ltag == TYFLOAT && Rtag == TYDOUBLE){         b_convert(TYFLOAT, TYDOUBLE); Ltag = TYDOUBLE;}
          //if(Ltag == TYSIGNEDCHAR){                              b_convert(TYSIGNEDCHAR, TYSIGNEDLONGINT); Ltag = TYSIGNEDLONGINT;}
          //if(Ltag == TYUNSIGNEDCHAR){                            b_convert(TYUNSIGNEDCHAR, TYSIGNEDLONGINT); Ltag = TYSIGNEDLONGINT;}

          genBackendAssignment(node->u.relop.right, 0, genBackend);
          //Right cast up to Left
          if(Rtag == TYSIGNEDLONGINT && Ltag == TYFLOAT)   b_convert(TYSIGNEDLONGINT, TYFLOAT);
          if(Rtag == TYSIGNEDLONGINT && Ltag == TYDOUBLE)  b_convert(TYSIGNEDLONGINT, TYDOUBLE);
          if(Rtag == TYFLOAT && Ltag == TYDOUBLE)          b_convert(TYFLOAT, TYDOUBLE);
          //if(Rtag == TYSIGNEDCHAR){                              b_convert(TYSIGNEDCHAR, TYSIGNEDLONGINT);}
          //if(Rtag == TYUNSIGNEDCHAR){                            b_convert(TYUNSIGNEDCHAR, TYSIGNEDLONGINT);}



        switch(node->u.binop.binTag){
          case ADD:{
              if(genBackend) b_arith_rel_op(B_ADD, Ltag);
              return Ltag;
          }case SUB:{
            if(genBackend) b_arith_rel_op(B_SUB, Ltag);
            return Ltag;
          }case INT_DIV:{
              if(genBackend) b_arith_rel_op(B_DIV, Ltag);
              return Ltag;
          }case REAL_DIV:{
              if(genBackend) b_arith_rel_op(B_DIV, Ltag);
              return Ltag;
          }case MOD:{
              if(genBackend) b_arith_rel_op(B_MOD, Ltag);
              return Ltag;
          }case MULT:{
              if(genBackend) b_arith_rel_op(B_MULT, Ltag);
              return Ltag;
          }default:{
            bug("handleBINOP_NODE() bad binopType-- THIS IS AN error");
            break;
          }
        }//end switch on binTag
      }//END for inValid check
      else{
        if(errorCalled == 0) error("Nonnumerical type argument(s) to arithmetic operation");
        errorCalled = 1;
        return TYERROR;
      }
    }//END NOT CONST fOLDING
  }//end if BINOP_NODE

  else{ //not a BINOP_NODE, left or right side of a BINOP_NODE
    bug("handleBINOP_NODE() was passed NON-BINOP_NODE");
  }

}//end handleBINOP_NODE



TYPETAG handleUNOP_NODE(TN node, int genBackend){

    switch(node->u.unop.unTag){

      case CHR:{
        TYPETAG tempTYPETAG = genBackendAssignment(node->u.unop.operand, 0, genBackend);
        if(tempTYPETAG != TYSIGNEDLONGINT){
           error("Wrong type for chr(int)");
           return TYERROR;
         }else{
          if(genBackend) b_convert(TYSIGNEDLONGINT, TYUNSIGNEDCHAR);
          return TYUNSIGNEDCHAR;
        }

      }case ORD:{  //no decimals
        TYPETAG tempTYPETAG = genBackendAssignment(node->u.unop.operand, 0, genBackend);
        if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDLONGINT | tempTYPETAG == TYSIGNEDCHAR){
          if(genBackend) b_convert(tempTYPETAG, TYSIGNEDLONGINT);
          return TYSIGNEDLONGINT;
         }else{
           error("Nonordinal type argument to Ord");
           return TYERROR;
          }

      }case SUCC:{ //no decimals
        TYPETAG tempTYPETAG = genBackendAssignment(node->u.unop.operand, 0, genBackend);
        if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDLONGINT | tempTYPETAG == TYSIGNEDCHAR){
          if(genBackend){
            if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDCHAR) b_convert(tempTYPETAG, TYSIGNEDLONGINT);
            b_push_const_int(1);
            b_arith_rel_op( B_ADD , TYSIGNEDLONGINT);
            if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDCHAR) b_convert (TYSIGNEDLONGINT, tempTYPETAG);
          }
          return tempTYPETAG;
        }else{
          error("Nonordinal type argument to Succ");
          return TYERROR;
        }

      }case PRED:{ //no decimals
        TYPETAG tempTYPETAG = genBackendAssignment(node->u.unop.operand, 0, genBackend);
        if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDLONGINT  | tempTYPETAG == TYSIGNEDCHAR){
          if(genBackend){
            if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDCHAR) b_convert(tempTYPETAG, TYSIGNEDLONGINT);
            b_push_const_int(-1);
            b_arith_rel_op(B_ADD , TYSIGNEDLONGINT);
            if(tempTYPETAG == TYUNSIGNEDCHAR | tempTYPETAG == TYSIGNEDCHAR) b_convert(TYSIGNEDLONGINT, tempTYPETAG);
          }
          return tempTYPETAG;
        }else{
          error("Nonordinal type argument to Pred");
          return TYERROR;
        }

      }case NEG:{
        if(myDebug){msg("SHOULD NEVER BE CALLED");}
        TYPETAG tempTYPETAG = genBackendAssignment(node->u.unop.operand, 0, genBackend);
        if(tempTYPETAG == TYVOID) error("Wrong type for -()"); //maybe more type not allowed
        if(genBackend) b_negate(tempTYPETAG);
        return tempTYPETAG;

      }default:{
        bug("unhandled case in handleUNOP_NODE");
      }

    }//END SWITC
}//end handleUNOP_NODE


TYPETAG handleRELOP_NODE(TN startNode, int genBackend){

  TYPETAG lhsTYPETAG = genBackendAssignment(startNode->u.relop.left, 0, 0);
  TYPETAG rhsTYPETAG = genBackendAssignment(startNode->u.relop.right, 0, 0);

  int inValid = 1;
  if(lhsTYPETAG == rhsTYPETAG) inValid = 0;
  if(lhsTYPETAG == TYSIGNEDCHAR | rhsTYPETAG == TYSIGNEDCHAR) inValid = 0;
  if(lhsTYPETAG == TYUNSIGNEDCHAR | rhsTYPETAG == TYUNSIGNEDCHAR) inValid = 0;

  //Left cast up to Right
  if(lhsTYPETAG == TYSIGNEDLONGINT && rhsTYPETAG == TYFLOAT)  inValid = 0;
  if(lhsTYPETAG == TYSIGNEDLONGINT && rhsTYPETAG == TYDOUBLE)  inValid = 0;
  if(lhsTYPETAG == TYFLOAT && rhsTYPETAG == TYDOUBLE)  inValid = 0;

  //Right cast up to Left
  if(rhsTYPETAG == TYSIGNEDLONGINT && lhsTYPETAG == TYFLOAT)  inValid = 0;
  if(rhsTYPETAG == TYSIGNEDLONGINT && lhsTYPETAG == TYDOUBLE)  inValid = 0;
  if(rhsTYPETAG == TYFLOAT && lhsTYPETAG == TYDOUBLE)  inValid = 0;

  if(inValid == 0){

    genBackendAssignment(startNode->u.relop.left, 0, genBackend);
    //Left cast up to Right
    if(lhsTYPETAG == TYSIGNEDLONGINT && rhsTYPETAG == TYFLOAT){  b_convert(TYSIGNEDLONGINT, TYFLOAT); lhsTYPETAG = TYFLOAT;}
    if(lhsTYPETAG == TYSIGNEDLONGINT && rhsTYPETAG == TYDOUBLE){ b_convert(TYSIGNEDLONGINT, TYDOUBLE); lhsTYPETAG = TYDOUBLE;}
    if(lhsTYPETAG == TYFLOAT && rhsTYPETAG == TYDOUBLE){         b_convert(TYFLOAT, TYDOUBLE); lhsTYPETAG = TYDOUBLE;}
    if(lhsTYPETAG == TYSIGNEDCHAR){                              b_convert(TYSIGNEDCHAR, TYSIGNEDLONGINT); lhsTYPETAG = TYSIGNEDLONGINT;}
    if(lhsTYPETAG == TYUNSIGNEDCHAR){                            b_convert(TYUNSIGNEDCHAR, TYSIGNEDLONGINT); lhsTYPETAG = TYSIGNEDLONGINT;}

    genBackendAssignment(startNode->u.relop.right, 0, genBackend);
    //Right cast up to Left
    if(rhsTYPETAG == TYSIGNEDLONGINT && lhsTYPETAG == TYFLOAT)   b_convert(TYSIGNEDLONGINT, TYFLOAT);
    if(rhsTYPETAG == TYSIGNEDLONGINT && lhsTYPETAG == TYDOUBLE)  b_convert(TYSIGNEDLONGINT, TYDOUBLE);
    if(rhsTYPETAG == TYFLOAT && lhsTYPETAG == TYDOUBLE)          b_convert(TYFLOAT, TYDOUBLE);
    if(rhsTYPETAG == TYSIGNEDCHAR){                              b_convert(TYSIGNEDCHAR, TYSIGNEDLONGINT);}
    if(rhsTYPETAG == TYUNSIGNEDCHAR){                            b_convert(TYUNSIGNEDCHAR, TYSIGNEDLONGINT);}

    switch(startNode->u.relop.relTag){
      case NE:{
        if(genBackend) b_arith_rel_op(B_NE,lhsTYPETAG);
        return TYSIGNEDCHAR;
      }case LE:{
        if(genBackend) b_arith_rel_op(B_LE,lhsTYPETAG);
        return TYSIGNEDCHAR;
      }case GE:{
        if(genBackend) b_arith_rel_op(B_GE,lhsTYPETAG);
        return TYSIGNEDCHAR;
      }case EQ:{
        if(genBackend) b_arith_rel_op(B_EQ,lhsTYPETAG);
        return TYSIGNEDCHAR;
      }case LT:{
        if(genBackend) b_arith_rel_op(B_LT,lhsTYPETAG);
        return TYSIGNEDCHAR;
      }case GT:{
        if(genBackend) b_arith_rel_op(B_GT,lhsTYPETAG);
        return TYSIGNEDCHAR;
      }default:{
        bug("Unhandled case in handleRELOP_NODE() with relTag: %d a.k.a. %s", startNode->u.relop.relTag, startNode->u.relop.relTag[relationalTypeStrings]);
      }
    }//END switch
  }//END INVALID
  else{
    error("Incompatible type arguments to comparison operator");
    return TYERROR;
  }
}//END handleRELOP_NODE



  TYPETAG getTYPETAG(TN node){
    if(node->tag == VAR_NODE){
      TYPETAG tempTypeTag = node->u.var_node.typeTag;
      if(tempTypeTag != NULL){
         return tempTypeTag;
      }else{
        if(myDebug) msg("\n ----- getTYPETAG, returned tyerror:");
         return TYERROR;
       }
    } //end if VAR_NODE
    if(myDebug) msg("\n ----- VAR_NODE, getTYPETAG, returned tyerror:");
    return TYERROR;
  }//END getTYPETAG()


  /*
  **********DEBUGGING STUFF**************
  */
  void treeNodeToString(TN node, int isTop){
    //INTCONSTANT, REALCONSTANT, NEGNUM
    if(isTop) msgn("TREE NODE    ");
    switch(node->tag){

      case STRINGCONSTANT:
      if(isTop) msg("STRINGCONSTANT node: %s ", node->u.string);
      else msgn("STRINGCONSTANT node: %s ", node->u.string);
      break;

      case INTCONSTANT:
      if(isTop) msg("INTCONSTANT node: %ld ", node->u.intconstant);
      else msgn("INTCONSTANT node: %ld ", node->u.intconstant);
      break;

      case REALCONSTANT:
      if(isTop) msg("REALCONSTANT node: %f ",node->u.realconstant);
      else msgn("REALCONSTANT node: %f ",node->u.realconstant);
      break;

      case BOOL_NODE:
      if(isTop) msg("BOOL_NODE node: %d ",node->u.boolean);
      else msgn("BOOL_NODE node: %d ",node->u.boolean);
      break;

      case NEGNUM:
      msgn("NEGNUM node --> ");
      treeNodeToString(node->u.negNode, 0);
      break;

      case VAR_NODE:
      msgn("VAR_NODE node: %s of type: ",st_get_id_str(node->u.var_node.varName));
      ty_print_typetag(getTYPETAG(node));
      msg("");
      break;

      case UNOP_NODE:
      msgn("UNOP_NODE %s ", unopTypeStrings[node->u.unop.unTag]);
      msgn("operand: ");
      treeNodeToString(node->u.unop.operand, 0);
      break;

      case BINOP_NODE:
      msgn(" LEFT: ");
      treeNodeToString(node->u.binop.left, 0);
      msgn("BINOP_NODE %s ", binopTypeStrings[node->u.binop.binTag]);
      msgn("RIGHT: ");
      treeNodeToString(node->u.binop.right, 0);
      break;

      case RELOP_NODE:
      msgn(" LEFT: ");
      treeNodeToString(node->u.relop.left, 0);
      msgn("RELOP_NODE %s ", relationalTypeStrings[node->u.relop.relTag]);
      msgn("RIGHT: ");
      treeNodeToString(node->u.relop.right, 0);
      break;

      case ASSIGN_NODE:
      msgn("ASSIGN_NODE var --> ");
      treeNodeToString(node->u.assign_node.varNode, 0);
      msgn("             Expression nodes --> ");
      treeNodeToString(node->u.assign_node.expression, 0);
      msg("");
      break;

      case FUNC_NODE:{
        msgn("FUNC_NODE node: %s of type: ",st_get_id_str(node->u.func_node.funcName));
        ty_print_typetag(node->u.func_node.typeTag);
        break;
      }

      default:
      if(isTop) msg("NULL -- THIS IS AN error");
      else msgn("NULL -- THIS IS AN error");
    }
  }



  /*
  ********************OTHER STUFF*************
  */




  LD addToList(ST_ID id, LD oldList){
    LD tempLid = (LD)malloc(sizeof(listOfIds));
    tempLid->data = id;
    tempLid->next = oldList;

    return tempLid;
  }



  INDEX_LIST addToArraySubList(TYPE object, INDEX_LIST root){
    INDEX_LIST tempEntry = (INDEX_LIST)malloc(sizeof(INDEX));
    tempEntry->type = object;
    tempEntry->next = NULL;
    tempEntry->prev = NULL;
    INDEX_LIST lastEntry = root;

    if(lastEntry != NULL){
      while(lastEntry->next != NULL){
        lastEntry = lastEntry->next;
      }
      lastEntry->next = tempEntry;
      tempEntry->prev = lastEntry;
    }


    if(root == NULL){
      return tempEntry;
    }else{
      return root;
    }
  }


  INDEX_LIST addToUnresolvedPtrs(TYPE object, INDEX_LIST root){
    INDEX_LIST tempEntry = (INDEX_LIST)malloc(sizeof(INDEX));
    tempEntry->type = object;
    tempEntry->next = NULL;
    INDEX_LIST lastEntry = root;
    while(lastEntry->next != NULL){
      lastEntry = lastEntry->next;
    }

    lastEntry->next = tempEntry;
    tempEntry->prev = lastEntry;

    return tempEntry;
  }
