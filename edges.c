#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


void free_edges(pnode item) {
    pedge currEdge = item->edges;
    while (currEdge) {
        pedge nextEdge = currEdge->next;
        free(currEdge);
        currEdge = nextEdge;
    }
    item->edges = NULL;
}

pedge create_edge(int weight, pnode endpoint){
    pedge new_edge = (pedge) malloc(sizeof(edge));
    new_edge->weight = weight;
    new_edge->endpoint = endpoint;
    new_edge->next = NULL;
    return new_edge;
}

pedge get_last_edge(pnode item){
    pedge currEdge = item->edges;
    while (currEdge != NULL)
    {
        if(currEdge->next ==NULL){
            return currEdge;
        }
        currEdge = currEdge->next;
    }
    return NULL;
}

void delete_edge(pnode item, int endpoint){
    pedge currEdge = item->edges;
    pedge prevEdge = NULL;
    while (currEdge) {
        if(currEdge->endpoint->node_num == endpoint){
            // Check if the current edge is the head of the linked list
            if(prevEdge == NULL) {
                // Update the head of the linked list
                item->edges = currEdge->next;
            } else {
                // Remove the current edge from the linked list
                prevEdge->next = currEdge->next;
            }
            // Free the memory allocated for the current edge
            free(currEdge);
            break;
        }
        prevEdge = currEdge;
        currEdge = currEdge->next;
    }
}