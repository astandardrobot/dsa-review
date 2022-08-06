#include <iostream>
/*
 * Prim's algorithm is like a modified Dijkstra's. Given a source, it's trying to find all neighboring nodes and create a MST out of them.
 * We're essentially keeping track of two sets of vertices: one for nodes in the MST, and one for nodes that aren't included.
 *
 * Each time this step is invoked, it will consider all of the edges connecting the two sets before the minimum weight is calculated.
 */
#define vertices 5

void printMST(int parent[], int graph[vertices][vertices]) {
    std::cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < vertices; i++) 
        std::cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
}

int minAlgo(int newArray[], bool spanningSet[]) {
    int minimum = INT_MAX;
    int min_index;

    for(int i=0; i<vertices; i++) {
        if(spanningSet[i] == false && newArray[i] < minimum) {
            minimum = newArray[i];
            min_index = i;
        }
    }
    return min_index;
}

void prim(int graph[vertices][vertices]) {
    int parent[vertices];
    int newArray[vertices];

    bool spanningSet[vertices];
    for(int i=0; i<vertices; i++) {
        newArray[i] = INT_MAX;
        spanningSet[i] = false;
    }
    spanningSet[0] = 0;
    parent[0] = -1;
    for(int j=0; j<vertices-1; j++) {
        int unprocess = minAlgo(newArray, spanningSet);
        spanningSet[unprocess] = true;
    
        for(int k=0; k<vertices; k++) {
            if (graph[unprocess][k] && spanningSet[k] == false && graph[unprocess][k] < newArray[k]) {
                    parent[k] = unprocess, newArray[k] = graph[unprocess][k];
            }
        }
    }
    printMST(parent, graph);
}

int main() {
    return 0;
}
