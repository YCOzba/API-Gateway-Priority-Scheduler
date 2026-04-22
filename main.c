#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rfc9213_parser.h"
#include "priority_queue.h"

int main() {
    printf("Sistem baslatiliyor efendim. API Gateway devrede.\n\n");

    PriorityQueue *pq = create_queue(4);

    const char *headers[] = {"u=5", "u=0, i", "u=7", "u=2", "u=0", "i"};
    const char *endpoints[] = {"/api/v1/metrics", "/api/v1/defense", "/api/v1/sync", "/api/v1/auth", "/api/v1/override", "/api/v1/stream"};

    printf("--- Gelen Istekler Ayristiriliyor ---\n");
    for (int i = 0; i < 6; i++) {
        int urgency; bool incremental;
        parse_priority_header(headers[i], &urgency, &incremental);
        
        Request req;
        req.request_id = 1000 + i;
        strcpy(req.endpoint, endpoints[i]);
        req.urgency = urgency;
        req.incremental = incremental;

        printf("ID: %d | Oncelik: u=%d | Endpoint: %s\n", req.request_id, req.urgency, req.endpoint);
        insert_request(pq, req);
    }
    
    printf("\n--- Istekler Isleniyor (Oncelik Sirasina Gore) ---\n");
    while (!is_empty(pq)) {
        Request processed = extract_min(pq);
        printf("Islenen ID: %d | Oncelik: %d | Endpoint: %s\n", processed.request_id, processed.urgency, processed.endpoint);
    }

    free_queue(pq);
    printf("\nSistem bellegi temizlendi efendim. Sifinti yok.\n");
    return 0;
}