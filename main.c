#include <stdio.h>
#include<ctype.h>
#include "graph.h"
#include <stdlib.h>


int main() 
{
    int num = 0;
    int pairs1 = -1 , pairs2 = -1;
    char letter = ' ';
    pnode *head = (pnode*)malloc(sizeof(pnode));
    while (!feof(stdin))
    {
        
        if(letter == 'A'){   
            scanf("%d", &num);
            build_graph_cmd(head, num);
        }
        else if(letter == 'B'){
            scanf("%d", &num);
            scanf(" %c", &letter);
            while (scanf(" %c", &letter) && !isalpha(letter))
            {
                pairs1 = letter - '0';
                scanf("%d", &pairs2);  
                fill_edge_in_node(head, num, pairs1, pairs2);
            }
            continue;
        }
        else if(letter == 'D'){
            scanf("%d", &num);
            delete_node_cmd(head, num);
        }
        else if(letter == 'S'){
            scanf("%d %d", &pairs1, &pairs2);        
            int s = shortsPath_cmd(head, pairs1, pairs2);
            printf("Dijsktra shortest path: %d\n", s);
        }
        else if(letter == 'T'){
            scanf("%d", &num);
            for(int i = 0; i<num; i++){
                scanf("%d", &pairs1);
            }
        }
        else if(letter == 'n'){
            scanf("%d", &num);

            while (scanf(" %c", &letter) && !isalpha(letter))
            {
                pairs1 = letter - '0';
                scanf("%d", &pairs2);  
                fill_edge_in_node(head, num, pairs1, pairs2);
            }
            continue;
        }
        scanf(" %c", &letter);

    }
    return 0;
}