#ifndef REQUEST_H
#define REQUEST_H
#include <stdbool.h>

typedef struct {
    int request_id;
    char endpoint[128];
    int urgency;
    bool incremental;
} Request;

#endif