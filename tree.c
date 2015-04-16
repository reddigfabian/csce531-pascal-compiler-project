#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "types.h"

int myDebug = 1;
char* tagtypeStrings[] = {"INTCONSTANT", "REALCONSTANT", "VAR_NODE", "NEGNUM", "ASSIGN_NODE", "BOOL_NODE", "BINOP_NODE", "FUNC_NODE"};
char* binopTypeStrings[] = {"ADD", "SUB", "REAL_DIV", "INT_DIV", "MOD", "MULT"};

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

TN makeNegNumNode(TN numNode){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = NEGNUM;
  tempTN->u.negNode = numNode;
  return tempTN;
}

TN makeVarNode(ST_ID id){ //here we pass block from gram.y through to makeVarNode in order to pass it as the output parameter of st_lookup. NOT SURE IF CORRECT
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

TN makeBinopNode(TN leftSide, TN rightSide, binopType binTagType){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = BINOP_NODE;
  tempTN->u.binop.binTag = binTagType;
  tempTN->u.binop.left = leftSide;
  tempTN->u.binop.right = rightSide;
  return tempTN;
}

TN makeFuncNode(ST_ID id, TYPETAG typeTag){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->u.func_node.funcName = id;
  tempTN->u.func_node.typeTag = typeTag;
  return tempTN;
}

/*
********************************BACKEND STUFF****************************
*/

TYPETAG genBackendAssigment(TN startNode, int fromExpr, TYPETAG assTYPE){
  /*
  b_negates(TYPETAG type)
  deal with unary negative
  */
  switch(startNode->tag){

    case INTCONSTANT:{
      long tempInt;
      tempInt = startNode->u.intconstant;
      b_push_const_int(tempInt);
      return TYSIGNEDLONGINT;   //not 100% yet

    }case REALCONSTANT:{
      double tempReal = startNode->u.realconstant;
      b_push_const_double(tempReal);
      return TYDOUBLE;  //not 100% yet

    }case BOOL_NODE:{
      int tempBool = startNode->u.boolean;
      b_push_const_int(tempBool);
      b_convert(TYSIGNEDLONGINT, TYSIGNEDCHAR);
      return TYSIGNEDCHAR;

    }case NEGNUM:{
      TN tempNode = startNode->u.negNode;
      tagtype tempTagType = tempNode->tag;
      if(tempTagType == INTCONSTANT){
        long tempInt = -1 * tempNode->u.intconstant;
        b_push_const_int(tempInt);
        return TYSIGNEDLONGINT;   //not 100% yet

      }else if(tempTagType == REALCONSTANT){
        double tempReal = -1 * tempNode->u.realconstant;
        b_push_const_double(tempReal);
        return TYDOUBLE;  //not 100% yet

      }else{
        bug("unchecked tag in NEGNUM genBackendAssigment()");
        break;
      }

    }case VAR_NODE:{
      if(fromExpr){
        if(startNode->u.var_node.isInstalled){
          char *tempIdString = st_get_id_str(startNode->u.var_node.varName);
          b_push_ext_addr(tempIdString);
          TYPETAG tempTypeTag = getTYPETAG(startNode);
          b_deref(tempTypeTag);
          return tempTypeTag;
        }else{ //var_node not installed in symbol table
          error("variable in expression has not been initilized");
          break;
        }
      }else{ //var is on the left hand side of an assignment, dont deref
        char *tempIdString = st_get_id_str(startNode->u.var_node.varName);
        b_push_ext_addr(tempIdString);
        TYPETAG tempTypeTag = getTYPETAG(startNode);
        return tempTypeTag;
      }


    }case BINOP_NODE:{
      int ConstValue; //potenital idea for cont folding, currently unused
      return handleBINOP_NODE(startNode, assTYPE, &ConstValue);

    }case ASSIGN_NODE:{
      TYPETAG varTypeTag = genBackendAssigment(startNode->u.assign_node.varNode, 0, TYVOID);
      TYPETAG expTypeTag = genBackendAssigment(startNode->u.assign_node.expression, 1, varTypeTag);

      if(myDebug){
        msgn("ASSIGNMENT: ");
        ty_print_typetag(varTypeTag);
        msgn(" := ");
        ty_print_typetag(expTypeTag);
        msg(";");
      }

      b_assign(varTypeTag);
      b_pop();
      return expTypeTag;

    }default:{
      bug("BACKEND ASSIGNMENT -- THIS IS AN ERROR");
      break;
    }}
  }//END genBackendAssigment()


  //typedef enum{ADD, SUB, REAL_DIV, INT_DIV, MOD, MULT}binopType;
  /*
  k := i+j;      {# b_push_ext_addr (K)
                    # b_push_ext_addr (I)
                    # b_deref (signed long int)
                    # b_push_ext_addr (J)
                    # b_deref (signed long int)
                    # b_arith_rel_op ( + , signed long int)
                    # b_assign (signed long int)
                    # b_pop ()}

 f := 6 - 2;     {# b_push_ext_addr (F)
                   # b_push_const_int (4)
                   # b_assign (signed long int)
                   # b_pop ()}

 b := True;       {# b_push_ext_addr (B)
                   # b_push_const_int (1)
                   # b_convert (signed long int -> signed char)
                   # b_assign (signed char)
                   # b_pop ()}

                   b_arith_rel_op() TYPES for first ARG:
                       B_ADD       add (+)
                       B_SUB       substract (-)
                       B_MULT      multiply (*)
                       B_DIV       divide (/)
                       B_MOD       mod (%)
                       B_LT        less than (<)
                       B_LE        less than or equal to (<=)
                       B_GT        greater than (>)
                       B_GE        greater than or equal to (>=)
                       B_EQ        equal (==)
                       B_NE        not equal (!=)
  */
TYPETAG handleBINOP_NODE(TN node, TYPETAG assTYPE, int *value){
 //returning the value might be harder than i anticipated for doing const folding.
 //maybe a data struct to pass up, so can contain diff types?
  if(node->tag == BINOP_NODE){
    switch(node->u.binop.binTag){
      //**************************************************************************************************
      case ADD:{
        int valueLeft;
        int valueRight;

        TYPETAG typeTagLeft = genBackendAssigment(node->u.binop.left, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagLeft == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagLeft == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        TYPETAG typeTagRight = genBackendAssigment(node->u.binop.right, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagRight == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagRight == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        b_arith_rel_op(B_ADD, assTYPE);
        return assTYPE;
        //**************************************************************************************************
      }case SUB:{
        int valueLeft;
        int valueRight;

        TYPETAG typeTagLeft = genBackendAssigment(node->u.binop.left, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagLeft == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagLeft == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        TYPETAG typeTagRight = genBackendAssigment(node->u.binop.right, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagRight == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagRight == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        b_arith_rel_op(B_SUB, assTYPE);
        return assTYPE;
        //**************************************************************************************************
      }case INT_DIV:{
        int valueLeft;
        int valueRight;

        TYPETAG typeTagLeft = genBackendAssigment(node->u.binop.left, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagLeft == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagLeft == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        TYPETAG typeTagRight = genBackendAssigment(node->u.binop.right, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagRight == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagRight == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        b_arith_rel_op(B_DIV, assTYPE);
        return assTYPE;
        //**************************************************************************************************
      }case REAL_DIV:{
        int valueLeft;
        int valueRight;

        TYPETAG typeTagLeft = genBackendAssigment(node->u.binop.left, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagLeft == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagLeft == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        TYPETAG typeTagRight = genBackendAssigment(node->u.binop.right, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagRight == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagRight == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        b_arith_rel_op(B_DIV, assTYPE);
        return assTYPE;
        //**************************************************************************************************
      }case MOD:{
        int valueLeft;
        int valueRight;

        TYPETAG typeTagLeft = genBackendAssigment(node->u.binop.left, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagLeft == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagLeft == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        TYPETAG typeTagRight = genBackendAssigment(node->u.binop.right, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagRight == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagRight == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        b_arith_rel_op(B_MOD, assTYPE);
        return assTYPE;
      //**************************************************************************************************
      }case MULT:{
        int valueLeft;
        int valueRight;

        TYPETAG typeTagLeft = genBackendAssigment(node->u.binop.left, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagLeft == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagLeft == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        TYPETAG typeTagRight = genBackendAssigment(node->u.binop.right, 1, assTYPE);
        if(assTYPE == TYDOUBLE && typeTagRight == TYSIGNEDLONGINT) b_convert(TYSIGNEDLONGINT, TYDOUBLE);
        if(assTYPE == TYSIGNEDLONGINT && typeTagRight == TYDOUBLE) b_convert(TYDOUBLE, TYSIGNEDLONGINT);

        b_arith_rel_op(B_MULT, assTYPE);
        return assTYPE;
        //**************************************************************************************************
      }default:{
        bug("handleBINOP_NODE() bad binopType-- THIS IS AN ERROR");
        break;
      }
    }//end switch on binTag
  }//end if BINOP_NODE

  else{ //not a BINOP_NODE, left or right side of a BINOP_NODE
    bug("handleBINOP_NODE() was passed NON-BINOP_NODE");
    /*
    switch(node->tag){

      case INTCONSTANT:{
        long tempInt = node->u.intconstant;
        b_push_const_int(tempInt);
        return TYSIGNEDLONGINT;   //not 100% yet

      }case REALCONSTANT:{
        double tempReal = startNode->u.realconstant;
        b_push_const_double(tempReal);
        return TYDOUBLE;  //not 100% yet

      }case BOOL_NODE:{
        //HANDLE BOOLEAN NODE BACKEND
        break;

      }case NEGNUM:{
        TN tempNode = startNode->u.negNode;
        tagtype tempTagType = tempNode->tag;
        if(tempTagType == INTCONSTANT){
          long tempInt = -1 * tempNode->u.intconstant;
          b_push_const_int(tempInt);
          return TYSIGNEDLONGINT;   //not 100% yet

        }else if(tempTagType == REALCONSTANT){
          double tempReal = -1 * tempNode->u.realconstant;
          b_push_const_double(tempReal);
          return TYDOUBLE;  //not 100% yet

        }else{
          bug("unchecked tag in NEGNUM genBackendAssigment()");
          break;
        }

      }case VAR_NODE:{


      }default:{
        ERRPR("Wrong type on right side of assignment -- THIS IS AN ERROR");
        break;
      }
    }//end switch for NOT a BINOP_NODE
    */

  }//end else (NOT a BINOP_NODE)

}//end handleBINOP_NODE




  TYPETAG getTYPETAG(TN node){
    if(node->tag == VAR_NODE){
      TYPETAG tempTypeTag = node->u.var_node.typeTag;
      if(tempTypeTag != NULL){
         return tempTypeTag;
      }else{
         msg("getTYPETAG, returned TYERROR:");
         return TYERROR;
       }
    } //end if VAR_NODE
    msg("VAR_NODE, getTYPETAG, returned TYERROR:");
    return TYERROR;
  }//END getTYPETAG()


  /*
  **********DEBUGGING STUFF**************
  */
  void treeNodeToString(TN node, int isTop){
    //INTCONSTANT, REALCONSTANT, NEGNUM
    if(isTop) msgn("TREE NODE    ");
    switch(node->tag){

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

      case BINOP_NODE:
      msgn(" LEFT: ");
      treeNodeToString(node->u.binop.left, 0);
      msgn("BINOP_NODE %s ", binopTypeStrings[node->u.binop.binTag]);
      msgn("RIGHT: ");
      treeNodeToString(node->u.binop.right, 0);
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
      }

      default:
      if(isTop) msg("NULL -- THIS IS AN ERROR");
      else msgn("NULL -- THIS IS AN ERROR");
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
