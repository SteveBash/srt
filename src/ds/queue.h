#ifndef _queue_h
#define _queue_h

struct Queue_el{
    int pid;          
    struct Queue_el *next;
};

typedef struct Queue_el Queue_el;

typedef struct{
    Queue_el *front; 
    Queue_el *end; 
} Queue;

Queue *create_queue();
int queue_empty(const Queue *q);
void enqueue(Queue *q, int pid);
Optional dequeue(Queue *q);

#endif
