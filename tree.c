#include <stdlib.h>
#include "tree.h"



/*
typedef struct LoIDs{
  ST_ID data;
  struct listOfIds *next;
}listOfIds, *LID;
*/
LD addToList(ST_ID id, LD oldList){
  LD tempLid = (LD)malloc(sizeof(listOfIds));
  tempLid->data = id;
  tempLid->next = oldList;

  return tempLid;
}


/*
typedef struct arrayListofSubranges{
  TYPE data;
  struct arrayListofSubranges *next;
}aLoSR, *LSR;
*/
LSR addToArraySubList(TYPE object, LSR oldList){
  LSR tempEntry = (LSR)malloc(sizeof(aLoSR));
  tempEntry->data = object;
  tempEntry->next = oldList;

  return tempEntry;
}
