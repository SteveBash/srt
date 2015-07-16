
#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode{
    int i;
    struct IntNode *next;
} IntNode;

typedef struct IntList{
   IntNode *first;
} IntList;

IntList *create_int_list(){
    IntList  *il = malloc(sizeof(IntList));
    il->first = NULL;
    return il;
}

int int_list_empty(IntList *il){
    return il->first==NULL;
}

void int_list_add(IntList *il, int i){
    IntNode *in = malloc(sizeof(IntNode)); 
    in->i = i;
    in->next = NULL;
    if(int_list_empty(il)){
        il->first = in;
    }
    else{
        IntNode *itemp = il->first;
        while(itemp->next!=NULL)
            itemp = itemp->next;
        itemp->next = in;
    }
}

