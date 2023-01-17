#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
    build_graph_cmd();

}


void build_graph_cmd() {
    int numNodes = 4;
    pnode head =  init(numNodes);

    fill_edge_in_node(head, 0, 2, 5);
    fill_edge_in_node(head, 0, 3, 3);
    fill_edge_in_node(head, 2, 0, 4);
    fill_edge_in_node(head, 2, 1, 1);
    fill_edge_in_node(head, 1, 3, 7);
    fill_edge_in_node(head, 1, 0, 2);
    // delete_node(head, 2);
    int res = dijkstra(head, 1, 3);
    printf("end");
}

pnode init(int numNodes) {
    pnode head = NULL;
    pnode prev = NULL;
    for(int i = 0; i<numNodes; i++)
    {
        pnode item = (pnode)malloc(sizeof(node));
        item->node_num = i;
        item->edges = NULL;
        if(head == NULL){
            head  = item;            
        }
        if(prev != NULL){
            prev->next = item;
        }
        prev = item;
    }
    return head;
}

void free_edges(pnode item) {
    pedge currEdge = item->edges;
    while (currEdge) {
        pedge nextEdge = currEdge->next;
        free(currEdge);
        currEdge = nextEdge;
    }
    item->edges = NULL;
}


void build_node(pnode head, int numNode){
    pnode currNode = find_node(head, numNode);
    if(currNode == NULL){
        // Create a new node and initialize its fields
        pnode item = (pnode)malloc(sizeof(node));
        item->node_num = numNode;
        item->edges = NULL;
        item->next = NULL;
        
        // Traverse the list to find the last node
        currNode = head;
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


pedge create_edge(int weight, pnode endpoint){
    pedge new_edge = (pedge) malloc(sizeof(edge));
    new_edge->weight = weight;
    new_edge->endpoint = endpoint;
    new_edge->next = NULL;
    return new_edge;
}

void fill_edge_in_node(pnode head, int fromID, int toID, int weight){
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

pnode find_node(pnode head, int id){
    pnode item = head;
    while (item != NULL)
    {
        if(item->node_num == id){
            return item;
        }
        item = item->next;
    }
    return NULL;
}

void delete_node(pnode head, int numndoe){
    pnode currNode = head;
    pnode prevNode = NULL;
    while (currNode)
    {
        delete_edge(currNode, numndoe);
        currNode = currNode->next;
    }
    currNode = head;
    while (currNode){
        if(currNode->node_num == numndoe){
            if(prevNode == NULL){
                head = currNode->next;
            } else{
                prevNode->next = currNode->next;
            }
            free(currNode);
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    
}

void delete_edge(pnode item, int endpoint){
    pedge currEdge = item->edges;
    pedge prevEdge = NULL;
    while (currEdge)
    {
        if(currEdge->endpoint->node_num == endpoint){
            if(prevEdge == NULL) {
                item->edges = currEdge->next;
            } else {
                prevEdge->next = currEdge->next;
            }
            free(currEdge);
            break;
        }
        prevEdge = currEdge;
        currEdge = currEdge->next;
    }
}










// pnode findMinNotVisited(pnode head)
// {
//     int min = __INT_MAX__;
//     pnode result = NULL;
//     while (head)
//     {
//         if (!head->visited && head->distance < min)
//         {
//             min = head->distance;
//             result = head;
//         }
//         head = head->next;
//     }
//     return result;
// }

pnode min_unvisted(pnode head){
    pnode current = head, minNode = NULL;
    int minDist = __INT_MAX__;
    while (current) {
        if (!current->visited && current->distance < minDist) {
            minNode = current;
        }
        current = current->next;
    }
    return minNode;
}




int dijkstra(pnode head, int fromID, int toID) {
    pnode current = head;
    int shortest_paths[4]={0};

    int i = 0;
    while (current) {
        if(current->node_num != fromID){
            current->distance = __INT_MAX__;
            shortest_paths[i] = __INT_MAX__;
        }
        i++;
        current = current->next;
    }

    // running dijkstra's algorithm
    current = find_node(head, fromID);
    while (current) {
        current->visited = 1;
        pedge currEdge = current->edges;
        while (currEdge) {
            int alt = current->distance + currEdge->weight;
            if (alt < currEdge->endpoint->distance) {
                currEdge->endpoint->distance = alt;
                shortest_paths[currEdge->endpoint->node_num] = alt;
            }
            currEdge = currEdge->next;
        }
        current = min_unvisted(head);
    }

    // return shortest path distanceance from source to destination
    return shortest_paths[toID];
}
