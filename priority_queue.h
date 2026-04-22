#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <stdbool.h>
#include "request.h"

typedef struct {
    Request *array;
    int capacity;
    int size;
} PriorityQueue;

PriorityQueue* create_queue(int initial_capacity);
void free_queue(PriorityQueue *pq);
void insert_request(PriorityQueue *pq, Request req);
Request extract_min(PriorityQueue *pq);
bool is_empty(PriorityQueue *pq);

#endif