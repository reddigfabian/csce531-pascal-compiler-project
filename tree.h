#include "symtab.h"
#include "backend-x86.h"

typedef enum{CHARCONSTANT, INTCONSTANT, REALCONSTANT, VAR_NODE, NEGNUM, ASSIGN_NODE, BOOL_NODE, UNOP_NODE, BINOP_NODE,
                  FUNC_NODE, RELOP_NODE, ERROR_NODE, IF_NODE, ELSE_NODE, WHILE_NODE, STATEMENT_NODE}tagtype;

typedef enum{CHR, ORD, SUCC, PRED, NEG}unopType;

typedef enum{ADD, SUB, REAL_DIV, INT_DIV, MOD, MULT}binopType;

typedef enum{NE,LE,GE,EQ,LT,GT}relationalType;

typedef enum{
  pas_ABS,pas_SQR,pas_SIN,pas_COS,
  pas_EXP,pas_LN,pas_SQRT,pas_ARCTAN,
  pas_ARG,pas_TRUNC,pas_ROUND,pas_CARD,
  pas_ORD,pas_CHR,pas_ODD,pas_EMPTY,
  pas_POSITION,pas_LASTPOSITION,
  pas_LENGTH,pas_TRIM,pas_BINDING,
  pas_DATE,pas_TIME, pas_SUCC, pas_PRED
}rtsFunOnePar;

typedef struct tn{
  tagtype tag;

  union{

    long intconstant;
    double realconstant;
    struct tn *negNode;
    int boolean;
    char character;

    /*PART 3*/
    struct{
      struct tn *relop;
      struct tn *expression;
      struct tn *elseNode;
    }if_node;

    struct{
      struct tn *expression;
    }else_node;

    struct{
      struct tn *relop;
      struct tn *expression;
    }while_node;

    struct{
      struct tn *nextStatement;
      struct tn *expression;
    }statement_node;


    /*PART 2*/
    struct{
      ST_ID varName;
      int isInstalled;
      ST_DR DR;
      STDR_TAG DRtag;
      TYPE type;
      TYPETAG typeTag;
    }var_node;

    struct{
      ST_ID funcName;
      STORAGE_CLASS SC;
      int isInstalled;
      ST_DR DR;
      STDR_TAG DRtag;
      TYPE type;
      TYPETAG typeTag;
    }func_node; //PLAY THAT FUNC-Y MUSIC...WHIIIIIIIITE NODE

    struct{
      struct tn *varNode;
      struct tn *expression;
    }assign_node;

    struct{
      unopType unTag;
      struct tn *operand;
    }unop;

    struct{
      binopType binTag;
      struct tn *left;
      struct tn *right;
    }binop;

    struct{
      binopType relTag;
      struct tn *left;
      struct tn *right;
    }relop;
    /*END PART 2*/


  }u;

}treeNode, *TN;



typedef struct LoIDs{
  ST_ID data;
  struct LoIDs *next;
}listOfIds, *LD;

//PART 3
TN makeIfNode(TN relop,TN expr);
TN makeElseNode(TN ifNode, TN expr);
TN makeWhileNode(TN relop,TN expr);
TN makeStatementNode(TN root, TN expr);


//PART 2
TN makeErrorNode();
TN makeIntConstNode(long intconstant);
TN makeRealConstNode(double realconstant);
TN makeCharConstNode(char charconstant);
TN makeNegNumNode(TN numNode);
TN makeVarNode(ST_ID id);
TN makeAssignNode(TN var, TN exp);
TN makeBoolNode(int tempBool);
TN makeBinopNode(TN leftSide, TN rightSide, binopType binTagType);
TN makeRelopNode(TN leftSide, relationalType relTagType, TN rightSide);
TN makeUnopNode(TN operand, unopType op);
TN makeFuncNode(ST_ID id, TYPETAG typeTag, TYPE type);

void treeNodeToString(TN node, int isTop);

TYPETAG genBackendAssignment(TN startNode, int fromExpr, int genBackend);
TYPETAG handleUNOP_NODE(TN node, int genBackend);
TYPETAG handleBINOP_NODE(TN node, int genBackend);
TN handleConstantFolding(binopType op, TN Lnode, TN Rnode, TYPETAG Ltag, TYPETAG Rtag);
TN handleConstantFoldingUNOP(unopType op, TN node);
TYPETAG handleRELOP_NODE(TN startNode, int genBackend);
TYPETAG getTYPETAG(TN node);
//void getBinopInfo(TN node, TYPETAG *tag, tagtype *nodeType);

LD addToList(ST_ID id, LD oldList);
INDEX_LIST addToArraySubList(TYPE object, INDEX_LIST oldList);
INDEX_LIST addToUnresolvedPtrs(TYPE object, INDEX_LIST root);
