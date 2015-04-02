#include <stdlib.h>
#include "tree.h"
#include "types.h"



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
typedef struct tlist {
    TYPE type;
    struct tlist *next, *prev;
} TLIST_NODE, *TYPE_LIST;

typedef struct tlist INDEX, *INDEX_LIST;
*/
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
