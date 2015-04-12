#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "types.h"


/*
typedef enum{INTCONSTANT, REALCONSTANT, ID_NODE, TYPE_NODE, NEGNUM}tagtype;

typedef struct tn{
  tagtype tag;

  union{

    long intconstant;
    double realconstant;
    struct tn *negNode;

    // ST_ID id;
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


void genBackend(TN startNode){
  /*
  b_negates(TYPETAG type)
  deal with unary negative


  */
}

void treeNodeToString(TN node){
    //INTCONSTANT, REALCONSTANT, NEGNUM
    switch(node->tag){
      case INTCONSTANT:
          msg("INTCONSTANT node: %ld", node->u.intconstant);
          break;
      case REALCONSTANT:
          msg("REALCONSTANT node: %f",node->u.realconstant);
          break;
      case NEGNUM:
          msgn("NEGNUM node --> ");
          treeNodeToString(node->u.negNode);
          break;
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
