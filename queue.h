#ifndef QUEUE_H
#define QUEUE_H

#include "traffic_simulation.h"  // Include Vehicle struct

// Queue Node
typedef struct Node {
    Vehicle vehicle;
    struct Node* next;
} Node;

// Queue Structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Queue Functions
void initQueue(Queue* q);
void enqueue(Queue* q, Vehicle vehicle);
Vehicle dequeue(Queue* q);
int isQueueEmpty(Queue* q);

#endif
