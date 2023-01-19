#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void build_graph_cmd(pnode* head,  int numNodes) {
    if(*head != NULL){
        deleteGraph_cmd(head);
    }
    init(head, numNodes);

    // fill_edge_in_node(head, 0, 2, 5);
    // fill_edge_in_node(head, 0, 3, 3);
    // fill_edge_in_node(head, 2, 0, 4);
    // fill_edge_in_node(head, 2, 1, 1);
    // fill_edge_in_node(head, 1, 3, 7);
    // fill_edge_in_node(head, 1, 0, 2);
    // delete_node(head, 0);
    // int res = dijkstra(head, 2, 3);
    // printf("end");
}

void deleteGraph_cmd(pnode *head) {
    pnode curr = *head;
    while (curr)
    {
        pnode delNode = curr;
        curr = curr->next;
        free_edges(delNode);
        free(delNode);
    }
    
}

void init(pnode* head, int numNodes) {
    pnode prev = NULL;
    for(int i = 0; i<numNodes; i++)
    {
        pnode item = (pnode)malloc(sizeof(node));
        item->node_num = i;
        item->edges = NULL;
        if(*head == NULL){
            *head  = item;            
        }
        if(prev != NULL){
            prev->next = item;
        }
        prev = item;
    }
}

void fill_edge_in_node(pnode* head, int fromID, int toID, int weight){
    pnode fromNode = find_node(head, fromID);
    pnode toNode = find_node(head, toID);
    pedge new_edge = create_edge(weight,toNode);
    pedge lastEdge = get_last_edge(fromNode);
    if(lastEdge == NULL){
        fromNode->edges = new_edge;
    } else {
        lastEdge->next = new_edge;
    }
}

int graph_size(pnode *head){
    // Initialize the current and counter variables
    pnode curr = *head;
    int i = 0;
    while (curr) {
        curr = curr->next;
        i++;
    }
    // Return the number of nodes in the graph
    return i;
}


