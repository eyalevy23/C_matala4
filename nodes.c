#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


void insert_node_cmd(pnode *head, int numNode){
    pnode currNode = find_node(head, numNode);
    if(currNode == NULL){ // in case of new node 
        // Create a new node and initialize its fields
        pnode item = (pnode)malloc(sizeof(node));
        item->node_num = numNode;
        item->edges = NULL;
        item->next = NULL;
        
        // Traverse the list to find the last node
        currNode = *head;
        while (currNode->next != NULL)
        {
            currNode = currNode->next;
        }
        // Add the new node to the end of the list
        currNode->next = item;
    } else {
        free_edges(currNode);
    }
}

pnode find_node(pnode* head, int id){
    pnode item = *head;
    while (item != NULL)
    {
        if(item->node_num == id){
            return item;
        }
        item = item->next;
    }
    return NULL;
}

void delete_node_cmd(pnode *head, int numndoe){
    pnode currNode = *head;
    pnode prevNode = NULL;
    while (currNode) {
        // Delete all edges that have the specified node as an endpoint
        delete_edge(currNode, numndoe);
        currNode = currNode->next;
    }
    // Reset the currNode variable
    currNode = *head;
    while (currNode) {
        if(currNode->node_num == numndoe){
            // Check if the current node is the head of the linked list
            if(prevNode == NULL){
                // Update the head of the linked list
                *head = currNode->next;
            } else{
                // Remove the current node from the linked list
                prevNode->next = currNode->next;
            }
            // Free the memory allocated for the current node
            free(currNode);
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}