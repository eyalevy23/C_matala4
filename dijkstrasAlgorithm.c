#include "graph.h"
#include <stdlib.h>
#include <stdbool.h>


void rest(pnode *head){
    pnode curr = *head;
    while (curr)
    {
        curr->distance = 0;
        curr->visited = 0;
        curr = curr->next;
    }
    
}

pnode min_unvisted(pnode *head){
    pnode current = *head, minNode = NULL;
    int minDist = __INT_MAX__;
    while (current) {
        // Check if the current node has not been visited and its distance is less than the current minimum distance
        if (!current->visited && current->distance < minDist) {
            // Update the minNode and minDist variables
            minNode = current;
            minDist = current->distance;
        }
        current = current->next;
    }
    // Return the node with the minimum distance
    return minNode;
}

int max2(int a, int b, int c){
    int m = 0;
    if(a < b){
        m = b;
    } else {
        m = a;
    }
    if(c < m) return m;
    return c;
}

//dijkstra algorithm using dynamic programming
int shortsPath_cmd(pnode *head, int fromID, int toID) {
    int maxI = max2(graph_size(head), fromID, toID);
    maxI++;
    pnode current = *head;
    // Allocate memory for the shortest_paths array
    int *shortest_paths = malloc(sizeof(int) * maxI);
    rest(head);
    for(int i = 0; i<maxI; i++){
        shortest_paths[i] = INF;
    }
    while (current) {
        if(current->node_num != fromID){
            // Set the distance of all nodes except the starting node to infinity
            current->distance = INF;
        }
        current = current->next;
    }
    // Set the current node to the starting node
    current = find_node(head, fromID);
    while (current) {
        // Mark the current node as visited
        current->visited = 1;
        pedge currEdge = current->edges;
        while (currEdge) {
            // Calculate the alternate distance from the starting node to the endpoint of the current edge
            int alt = current->distance + currEdge->weight;
            // Check if the alternate distance is less than the current distance of the endpoint
            if (alt < currEdge->endpoint->distance) {
                // Update the distance of the endpoint
                currEdge->endpoint->distance = alt;
                shortest_paths[currEdge->endpoint->node_num] = alt;
            }
            currEdge = currEdge->next;
        }
        // Get the next unvisited node with the minimum distance
        current = min_unvisted(head);
    }
    // Return the shortest path distance from the source to the destination
    if(shortest_paths[toID] == __INT_MAX__){
        shortest_paths[toID] = -1;
    }
    return shortest_paths[toID];

}