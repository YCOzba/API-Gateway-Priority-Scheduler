#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

static void heapify_up(PriorityQueue *pq, int index);
static void heapify_down(PriorityQueue *pq, int index);
static void swap(Request *a, Request *b);

PriorityQueue* create_queue(int initial_capacity) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->capacity = initial_capacity;
    pq->size = 0;
    pq->array = (Request*)malloc(sizeof(Request) * initial_capacity);
    return pq;
}

void free_queue(PriorityQueue *pq) {
    if (pq) {
        if (pq->array) free(pq->array);
        free(pq);
    }
}

bool is_empty(PriorityQueue *pq) { return pq->size == 0; }

void insert_request(PriorityQueue *pq, Request req) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->array = (Request*)realloc(pq->array, sizeof(Request) * pq->capacity);
    }
    int current_index = pq->size;
    pq->array[current_index] = req;
    pq->size++;
    heapify_up(pq, current_index);
}

Request extract_min(PriorityQueue *pq) {
    if (is_empty(pq)) {
        Request empty_req = {-1, "", -1, false};
        return empty_req;
    }
    Request min_req = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    heapify_down(pq, 0);
    return min_req;
}

static void swap(Request *a, Request *b) {
    Request temp = *a; *a = *b; *b = temp;
}

static void heapify_up(PriorityQueue *pq, int index) {
    int parent_index = (index - 1) / 2;
    while (index > 0 && pq->array[parent_index].urgency > pq->array[index].urgency) {
        swap(&pq->array[parent_index], &pq->array[index]);
        index = parent_index;
        parent_index = (index - 1) / 2;
    }
}

static void heapify_down(PriorityQueue *pq, int index) {
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    
    if (left_child < pq->size && pq->array[left_child].urgency < pq->array[smallest].urgency)
        smallest = left_child;
    if (right_child < pq->size && pq->array[right_child].urgency < pq->array[smallest].urgency)
        smallest = right_child;
        
    if (smallest != index) {
        swap(&pq->array[index], &pq->array[smallest]);
        heapify_down(pq, smallest);
    }
}