#include <list>
#include <iostream>
#include <vector>
#include <queue>

class Graph
{
    int numVertices;
    std::list<int> *adjLists;
    bool *visited;
public:
    Graph(int V);
    void addEdge(int src, int dest);
    void BFS(int vertex);
};


Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
    visited = new bool[vertices];
}
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_front(dest);
}

/*
 * A Breadth-First Search (BFS) is useful when it comes to finding the shortest path.
 * Similar to a DFS, we start from the root. However, We go top-down and left to right.
 *
 * The complexity of a properly implemented BFS should be O(V+E), where V indicates the vertices and E indicates the edges
 *
 */

void Graph::BFS(int src) {
    std::queue<int> q;
    visited[src] = true;
    q.push(src);
    while(!q.empty()) {
        int newnode = q.front();
        q.pop();

        for(auto &adj : adjLists[newnode]) {
            if (!visited[adj]) {
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
}
