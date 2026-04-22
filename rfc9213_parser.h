#ifndef RFC9213_PARSER_H
#define RFC9213_PARSER_H
#include <stdbool.h>
#include "request.h"

void parse_priority_header(const char *header_value, int *urgency, bool *incremental);

#endif