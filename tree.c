#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "types.h"

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
**********BACKEND STUFF*******
*/

TYPETAG genBackendAssigment(TN startNode, int fromExpr){
  /*
  b_negates(TYPETAG type)
  deal with unary negative

  typedef enum{ADD, SUB, REAL_DIV, INT_DIV, MOD, MULT}binopType;
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
      if(fromExpr){
        if(startNode->u.var_node.isInstalled){
          char *tempIdString = st_get_id_str(startNode->u.var_node.varName);
          b_push_ext_addr(tempIdString);
          TYPETAG tempTypeTag = startNode->u.var_node.typeTag;
          b_deref(tempTypeTag);
          return tempTypeTag;
        }else{ //var_node not installed in symbol table
          error("variable in expression has not been initilized");
          break;
        }
      }else{ //var is on the left hand side of an assignment, dont deref
        char *tempIdString = st_get_id_str(startNode->u.var_node.varName);
        b_push_ext_addr(tempIdString);
        TYPETAG tempTypeTag = startNode->u.var_node.typeTag;
        return tempTypeTag;
      }

    }case BINOP_NODE:{
      //HANDLE BINOP NODE BACKEND
      break;

    }case ASSIGN_NODE:{
      TYPETAG varTypeTag = genBackendAssigment(startNode->u.assign_node.varNode, 0);
      TYPETAG expTypeTag = genBackendAssigment(startNode->u.assign_node.expression, 1);

      b_assign(varTypeTag);
      b_pop();
      return expTypeTag;

    }default:{
      bug("BACKEND ASSIGNEMTN -- THIS IS AN ERROR");
      break;
    }}
  }//END genBackendAssigment()



  TYPETAG getTYPETAG(TN node){
    if(node->tag == VAR_NODE){
      TYPETAG tempTypeTag = node->u.var_node.typeTag;
      return tempTypeTag;
    }
    return TYERROR;
  }


  /*
  **********DEBUGGING STUFF**************
  */
  void treeNodeToString(TN node, int isTop){
    //INTCONSTANT, REALCONSTANT, NEGNUM
    if(isTop) msgn("TREE NODE    ");
    switch(node->tag){

      case INTCONSTANT:
      if(isTop) msg("INTCONSTANT node: %ld", node->u.intconstant);
      else msgn("INTCONSTANT node: %ld", node->u.intconstant);
      break;

      case REALCONSTANT:
      if(isTop) msg("REALCONSTANT node: %f",node->u.realconstant);
      else msgn("REALCONSTANT node: %f",node->u.realconstant);
      break;

      case BOOL_NODE:
      if(isTop) msg("BOOL_NODE node: %d",node->u.boolean);
      else msgn("BOOL_NODE node: %d",node->u.boolean);
      break;

      case NEGNUM:
      msgn("NEGNUM node --> ");
      treeNodeToString(node->u.negNode, 0);
      break;

      case VAR_NODE:
      msgn("VAR_NODE node: %s of type: ",st_get_id_str(node->u.var_node.varName));
      ty_print_typetag(node->u.var_node.typeTag);
      msg("");
      break;

      case BINOP_NODE:
      msgn(" LEFT: ");
      treeNodeToString(node->u.binop.left, 0);
      msgn("BINOP_NODE %d ", node->u.binop.binTag);
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
  OTHER STUFF
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
