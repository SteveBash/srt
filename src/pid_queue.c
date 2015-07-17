
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue_el{
    char pid;          
    struct Queue_el *next;
}Queue_el;

typedef struct PidQueue{
    Queue_el *front; 
    Queue_el *end; 
}PidQueue;

PidQueue *create_queue(){
    PidQueue *q = malloc(sizeof(PidQueue));
    q->front = NULL; 
    q->end = NULL; 
    return q;
}

int queue_empty(const PidQueue *q){
   return q->end==NULL; 
}

void enqueue(PidQueue *q, char pid){
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

char dequeue(PidQueue *q){
    if(!queue_empty(q)){ 
        char res = q->end->pid;
        q->end = q->end->next;
        return res;
    }else
        return '-'; //Elemento nulo
}

/*char dequeue_pid(Queue *q, char pid){*/
    /*if(!queue_empty(q)){ */
        /*Queue_el *f = q->front; */
        /*while(f!=NULL){*/
            /*if(f->pid == pid){*/
               /*break;*/
            /*}*/
            /*f = f->next;  */
        /*}*/
        /*return res;*/
    /*}else*/
        /*return '*'; //Elemento nulo*/
/*}*/

PidQueue *copy(PidQueue *q){
    if(!queue_empty(q)){
        PidQueue *copy_q = malloc(sizeof(PidQueue));
        Queue_el *qel = malloc(sizeof(Queue_el)); 
        qel->pid = q->end->pid;
        qel->next = NULL;
        copy_q->end = qel;
        copy_q->front = qel;
        Queue_el *second_qel = q->end->next;
        while(second_qel!=NULL){
            Queue_el *next_qel = malloc(sizeof(Queue_el)); 
            next_qel->pid = second_qel->pid;
            next_qel->next= NULL;
            copy_q->front->next = next_qel;
            copy_q->front = copy_q->front->next;
            second_qel = second_qel->next;
        }
        return copy_q;
    }
    else return NULL;
}

/*int main(int argc, char **argv){*/
     /*Queue *q = create_queue();*/
     /*enqueue(q, '1');*/
     /*enqueue(q, '2');*/
     /*enqueue(q, '3');*/
     /*Queue *copy_q = copy(q);*/
     /*printf("%c\n", dequeue(copy_q));*/
     /*printf("%c\n", dequeue(copy_q));*/
     /*printf("%c\n", dequeue(copy_q));*/
     /*printf("%c\n", dequeue(copy_q));*/
     /*printf("%c\n", dequeue(q));*/
     /*printf("%c\n", dequeue(q));*/
     /*printf("%c\n", dequeue(q));*/
     /*printf("%c\n", dequeue(q));*/
     /*return 0;*/
/*}*/

