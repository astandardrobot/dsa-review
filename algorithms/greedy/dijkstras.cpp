#include <limits.h>
#include <vector>
#include <stdio.h>
/*
 * Given a graph and a source vertex, Dijkstra's is supposed to find the shortest path between the source
 * and all of the other vertices.
 *
 * This implementation will be made for an adjacency matrix, but there are a few ways to represent a graph.
 * For the sake of understanding the logic, though, this should be fine.
 */

#define vertices 9

int printq(int dist[], int n) {
    printf("vertex  distance from source\n");
    for(int i=0; i<vertices; i++) {
         printf("%d \t\t %d\n", i, dist[i]);
    }
    return 0;
}

/*
 * This minDist function is the meat of the algorithm. This finds the shortest path from the vertices that are not yet included in the
 * shortest path tree.
 */
int minDist(int dist[], bool visitedSet[]) {
    int min = INT_MAX;
    int index;

    for(int i=0; i<vertices; i++) {
        if(visitedSet[i] == false && dist[i] <= min) {
            min = dist[i], index = i;
        }
    }
    return index;
}
/*
 * Dijkstra's single source shortest path algorithm.
 */
void dijkstra(int structure[vertices][vertices], int src) {
    // dist is the output array for the shortest distance between src and i
    // shortestPathSet will check if shortestPathSet[i] is in the shortest path tree or if the distance between
    // src and shortestPathSet[i] is set.
    int dist[vertices];
    bool shortestPathSet[vertices];
    // init all distances between vertices to infinite and unvisited
    for(int i=0; i<vertices; i++) {
        dist[i] = INT_MAX;
        shortestPathSet[i] = false;
    }
    // init the distance between src and itself as 0...obviously
    dist[src] = 0;
    // Discover the shortest distance between src and all vertices
    for(int count=0; count<vertices-1; count++) {
        int unprocess = minDist(dist, shortestPathSet);
        shortestPathSet[unprocess] = true;
        for(int picked=0; picked<vertices; picked++) {
            // Update dist[picked] only if is not in shortestPathSet, there is an edge from
            // unprocess to picked, and total weight of path from src to picked through unprocess is
            // smaller than current value of dist[picked]
            if(!shortestPathSet[picked] && structure[unprocess][picked] && dist[unprocess] != INT_MAX && dist[unprocess] + structure[unprocess][picked] < dist[picked]) {
                dist[picked] = dist[unprocess] + structure[unprocess][picked]; 
            }
        }
    }
    printq(dist, vertices);
}
int main() {
    int graph[vertices][vertices] = { 
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
    };
    dijkstra(graph, 0);
}
