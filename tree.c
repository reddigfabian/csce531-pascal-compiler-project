#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "types.h"


/*
typedef enum{INTCONSTANT, REALCONSTANT, VAR_NODE, TYPE_NODE, NEGNUM, ASSIGN_NODE}tagtype;

typedef struct tn{
  tagtype tag;

  union{

    long intconstant;
    double realconstant;
    struct tn *negNode;
    ST_ID varName;

    struct{
        struct tn *varNode;
        struct tn *expression;
    }assign_node;

		// struct{
		// 	ST_ID id;
    //   TYPE type;
		// }type_node;

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

TN makeVarNode(ST_ID id){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = VAR_NODE;
  tempTN->u.varName = id;
  return tempTN;
}

TN makeAssignNode(TN var, TN expr){
  TN tempTN = (TN)malloc(sizeof(treeNode));
  tempTN->tag = ASSIGN_NODE;
  tempTN->u.assign_node.varNode = var;
  tempTN->u.assign_node.expression = expr;
  return tempTN;
}


void genBackend(TN startNode){
  /*
  b_negates(TYPETAG type)
  deal with unary negative


  */
}

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

      case NEGNUM:
          msgn("NEGNUM node --> ");
          treeNodeToString(node->u.negNode, 0);
          break;

      case VAR_NODE:
          msg("VAR_NODE node: %s",st_get_id_str(node->u.varName));
          break;

      case ASSIGN_NODE:
          msgn("ASSIGN_NODE var --> ");
          treeNodeToString(node->u.assign_node.varNode, 0);
          msgn("             Expression nodes --> ");
          treeNodeToString(node->u.assign_node.expression, 0);
          msg("");
          break;

      default:
          if(isTop) msg("NULL -- THIS IS AN ERROR");
          else msgn("NULL -- THIS IS AN ERROR");
    }
}


char *treeToString(TN node){
    //init
    //recurse
    //return
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
