#ifndef _queue_h
#define _queue_h

typedef struct Queue_el{
    char pid;          
    struct Queue_el *next;
}Queue_el;

typedef struct Queue{
    Queue_el *front; 
    Queue_el *end; 
}Queue;

Queue *create_queue();
int queue_empty(const Queue *q);
void enqueue(Queue *q, char pid);
char dequeue(Queue *q);
Queue *copy(Queue *q);

#endif
