#include <stdio.h>
#include "graph.h"

int main() 
{

    char letter = ' ';
    pnode head = NULL;
        while (!feof(stdin))
    {
        switch (letter)
        {
        case 'A':   
            build_graph_cmd(head);
            break;
        case 'B':
          

            break;
        case 'D':
           

            break;
        case 'S':
 

            break;
        case 'P':
      

            break;
        case 'T':
           

            break;
        
        case 'n':

            
        break;

        default:
            break;
        }

    }

    return 0;
}
