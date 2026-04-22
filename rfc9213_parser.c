#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rfc9213_parser.h"

void parse_priority_header(const char *header_value, int *urgency, bool *incremental) {
    *urgency = 3;
    *incremental = false;
    if (header_value == NULL) return;

    const char *u_ptr = strstr(header_value, "u=");
    if (u_ptr != NULL) {
        int u_val = *(u_ptr + 2) - '0';
        if (u_val >= 0 && u_val <= 7) *urgency = u_val;
    }

    const char *i_ptr = strstr(header_value, "i");
    if (i_ptr != NULL) *incremental = true;
}