#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *create_queue(){
    Queue *q = malloc(sizeof(Queue));
    q->front= NULL; 
    q->end= NULL; 
    return q;
}

int queue_empty(const Queue *q){
   return q->end==NULL; 
}

void enqueue(Queue *q, char pid){
    Queue_el *qel = malloc(sizeof(Queue_el)); 
    qel->pid = pid;
    qel->next = NULL;
    if(queue_empty(q)){
        q->front = qel;
        q->end = q->front;
    }else{
        q->front->next = qel; 
        q->front = q->front->next;
     }
}

char dequeue(Queue *q){
    if(!queue_empty(q)){ 
        char res = q->end->pid;
        q->end = q->end->next;
        return res;
    }else
        return '*'; //Elemento nulo
}

