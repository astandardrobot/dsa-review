#include <iostream>
#include <vector>

/*
 * Kruskal's minimum spanning tree is useful for, well, finding the minimum spanning tree in a graph.
 * A spanning tree is an acyclic subset of a graph in which all edges are connected.
 *
 * The MST is the spanning tree with the lowest combined "weight" of its edges.
 *
 * Kruskal's uses a Union-Find algorithm to determine if a set of vertices/edges produces a cycle.
 *
 * Sort the edges in increasing order
 * Check the smallest edge for a cycle. If there's none, include this edge.
 * Recursively invoke this until vertices-1 exist in the ST.
 */

#define vertices 5

int parentArray[vertices];

int findAlgo(int n) {
    while(parentArray[n] != n) {
        n = parentArray[n];
    }
    return n;
}

void unionAlgo(int x, int y) {
    int a = findAlgo(x);
    int b = findAlgo(y);

    parentArray[a] = b;
}

void kruskal(int weight[][vertices]) {
    int minimum = 0;

    for(int i=0; i<vertices; i++) {
        parentArray[i] = i;
    }
    int edges = 0;
    while(edges < vertices-1) {
        int fence = INT_MAX;
        int x = -1, y = -1;
        for(int j=0; j<vertices; j++) {
            for(int k=0; k<vertices; k++) {
                if(findAlgo(j) != findAlgo(k) && weight[j][k] < fence) {
                    fence = weight[j][k];
                    x = j;
                    y = k;
                }
            }
        }
        unionAlgo(x,y);
        printf("Edge %d:(%d, %d) cost:%d \n",edges++, x,y, fence);
        minimum += fence;
    }
    printf("\n Minimum cost= %d \n", minimum);
}

int main() {
    int cost[][vertices] = {
        { INT_MAX, 2, INT_MAX, 6, INT_MAX },
        { 2, INT_MAX, 3, 8, 5 },
        { INT_MAX, 3, INT_MAX, INT_MAX, 7 },
        { 6, 8, INT_MAX, INT_MAX, 9 },
        { INT_MAX, 5, 7, 9, INT_MAX },
    };
 
    // Print the solution
    kruskal(cost);
 
    return 0;
}
