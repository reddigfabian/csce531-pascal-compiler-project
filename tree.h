#include "symtab.h"

typedef enum{INTCONSTANT, REALCONSTANT, VAR_NODE, NEGNUM, ASSIGN_NODE, BOOL_NODE, BINOP_NODE}tagtype;

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
      ST_DR *DR;
      STDR_TAG DRtag;
      TYPE type;
      TYPETAG typetag;
    }var_node;

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



typedef struct LoIDs{
  ST_ID data;
  struct LoIDs *next;
}listOfIds, *LD;


TN makeIntConstNode(long intconstant);
TN makeRealConstNode(double realconstant);
TN makeNegNumNode(TN numNode);
TN makeVarNode(ST_ID id);
TN makeAssignNode(TN var, TN exp);
TN makeBoolNode(int tempBool);
TN makeBinopNode(TN leftSide, TN rightSide, binopType binTagType);


void treeNodeToString(TN node, int isTop);
char *treeToString(TN node);


void genBackend(TN startNode);

LD addToList(ST_ID id, LD oldList);
INDEX_LIST addToArraySubList(TYPE object, INDEX_LIST oldList);
INDEX_LIST addToUnresolvedPtrs(TYPE object, INDEX_LIST root);
