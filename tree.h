#include "symtab.h"

typedef enum{INTCONSTANT, REALCONSTANT, ID_NODE, TYPE_NODE}tagtype;

typedef struct tn{
  tagtype tag;

  union{

    long intconstant;
    double realconstant;
    ST_ID id;

		struct{
			ST_ID id;
      TYPE type;
		}type_node;

  }u;

}treeNode, *TN;



typedef struct LoIDs{
  ST_ID data;
  struct LoIDs *next;
}listOfIds, *LD;

/*
typedef struct arrayListofSubranges{
  TYPE data;
  struct arrayListofSubranges *next;
}aLoSR, *LSR;
*/


TN makeIntConstNode(long intconstant);
TN makeRealConstNode(double realconstant);
TN makeIDNode(ST_ID id);
TN makeTypeNode(ST_ID id, TYPE type);

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
