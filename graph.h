#include <stdbool.h>


#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    int distance;
    int visited;
} node, *pnode;


void build_graph_cmd(pnode *head,  int numNodes) ;
void insert_node_cmd(pnode *head, int numNode);
void delete_node_cmd(pnode *head, int numndoe);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode *head);
int shortsPath_cmd(pnode *head, int fromID, int toID);
void TSP_cmd(pnode head);

pnode find_node(pnode *head, int id);
pedge get_last_edge(pnode item);
void fill_edge_in_node(pnode* head, int fromID, int toID, int weight);
pedge create_edge(int weight, pnode endpoint);
pnode init(pnode* head, int numNodes);
void delete_edge(pnode item, int endpoint);
// void delete_node(pnode head, int numndoe);
pnode min_unvisted(pnode *head);
// void build_node(pnode head, int numNode);
void free_edges(pnode item);
// int dijkstra(pnode head, int startID, int endID);
int graph_size(pnode *head);

#endif
