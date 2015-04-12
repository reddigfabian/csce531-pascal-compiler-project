#include "symtab.h"

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



typedef struct LoIDs{
  ST_ID data;
  struct LoIDs *next;
}listOfIds, *LD;


TN makeIntConstNode(long intconstant);
TN makeRealConstNode(double realconstant);
TN makeNegNumNode(TN numNode);
TN makeVarNode(ST_ID id);
TN makeAssignNode(TN var, TN exp);


void treeNodeToString(TN node, int isTop);
char *treeToString(TN node);


//TN makeTypeNode(ST_ID id, TYPE type);

void genBackend(TN startNode);

LD addToList(ST_ID id, LD oldList);
INDEX_LIST addToArraySubList(TYPE object, INDEX_LIST oldList);
INDEX_LIST addToUnresolvedPtrs(TYPE object, INDEX_LIST root);


/*
typedef enum {
    TYVOID, TYFLOAT, TYDOUBLE, TYLONGDOUBLE, TYSIGNEDLONGINT,
    TYSIGNEDSHORTINT, TYSIGNEDINT, TYUNSIGNEDLONGINT,
    TYUNSIGNEDSHORTINT, TYUNSIGNEDINT, TYUNSIGNEDCHAR,
    TYSIGNEDCHAR, TYSTRUCT, TYUNION, TYENUM, TYARRAY, TYSET,
    TYFUNC, TYPTR, TYBITFIELD, TYSUBRANGE, TYERROR
} TYPETAG;
*/
