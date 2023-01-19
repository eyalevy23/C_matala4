#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include "graph.h"
#include <stdbool.h>

int min(int a, int b){
    if(a < b) return a;
    return b;
}

int max(int a, int b){
    if(a<b) return b;
    return a;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *begin, int *end) {
    end--;
    while (begin < end) {
        swap(begin, end);
        begin++;
        end--;
    }
}


bool next_permutation(int *begin, int *end) {
    if (begin == end) return false;
    int *i = end;
    if (i == begin) return false;
    i--;
    while (true) {
        int *j = i;
        i--;
        if (*i < *j) {
            int *k = end;
            while (*i >= *--k);
            swap(i, k);
            reverse(j, end);
            return true;
        }
        if (i == begin) {
            reverse(begin, end);
            return false;
        }
    }
}


int TSP_cmd(pnode *head) {
    int numTotalCities = graph_size(head);
    int numCitiesToVisit = 0;
    scanf("%d", &numCitiesToVisit);
    int *citiesToVisit = (int*)(malloc(sizeof(int)* numCitiesToVisit)); 
    int maxI = 0;    
    for (int i = 0; i < numCitiesToVisit; i++)
    {
        scanf("%d", &citiesToVisit[i]);
        if(maxI < citiesToVisit[i]){
            maxI = citiesToVisit[i];
        }
    }
    numTotalCities = max(maxI, numTotalCities);

    int dist[numTotalCities+1][numTotalCities+1];
    for(int i = 0; i<= numTotalCities; i++ ){
        for(int j = 0; j <= numTotalCities; j++){
            dist[i][j] = INF;
        }
    }

    // Initialize the dist array with the distances between all pairs of cities
    for (int i = 0; i < numCitiesToVisit; i++) {
        for (int j = i+1; j < numCitiesToVisit; j++) {
            int from = citiesToVisit[i];
            int to = citiesToVisit[j];
            int path1 = shortsPath_cmd(head, from, to);
            int path2 =  shortsPath_cmd(head, to, from);
            int path = 0;
            if(path1 == -1 && path2 == -1){
                path = __INT_MAX__;
            }else if(path1 != -1 && path2 != -1){
                path = min(path1, path2);
            } else{
                path = max(path1, path2);
            }
            dist[from][to] = path;
            dist[to][from] = dist[from][to];
        }
    }

    // initialize the permutation array
    int S[numCitiesToVisit];
    for (int i = 0; i < numCitiesToVisit; i++) {
        S[i] = citiesToVisit[i];
    }
    int min_cost = __INT_MAX__;

    // find the minimum cost of visiting all the cities
    do {
        int current_cost = 0;
        int current_city = S[0];
        for (int i = 0; i < numCitiesToVisit-1; i++) {
            int next_city = S[i+1];
            current_cost += dist[current_city][next_city];
            current_city = next_city;
        }
        if (current_cost < min_cost) {
            min_cost = current_cost;
        }
    } while (next_permutation(S, S+numCitiesToVisit));

    // free the memory allocated for the citiesToVisit array
    free(citiesToVisit);
    if(min_cost == INF || 0 > min_cost){
        min_cost = -1;
    }
    return min_cost;
}