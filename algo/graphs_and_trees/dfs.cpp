#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>

class Graph 
{
    int numVertices;
    std::list<int> *adjLists;
    bool *visited;
public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
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
 * A depth-first search (DFS) is a very fundamental tree/graph algorithm.
 * Think about it like a game of chess. What your opponent does will deterine how you move your next piece
 * and this will occur over and over. There really isn't an option to look for the shortest path to victory...
 * (or rather, there obviously is, but it's extremely inefficient, if not flawed in this case).
 *
 * A DFS starts at the root, and looks at all nodes along a given branch before backtracking to the next.
 * We're using a stack to keep track of these nodes on a given path, and a visited vector to store the already visited nodes.
 * while the stack isn't empty, the vertex (or source) is the last added node.
 * We pop that from the stack to look at nodes adjacent to this source node.
 * If it hasn't been visited, mark its index in the visited vector as true and push it to the stack.
 */

void Graph::DFS(int vertex) {
    visited[vertex] = true;
    std::stack<int> stk;
    stk.push(vertex);
    while(!stk.empty()) {
        vertex = stk.top();
        stk.pop();
        for(auto &adj : adjLists[vertex]) {
            if(!visited[vertex]) {
                visited[adj] = true;
                stk.push(adj);
            }
        }
    }
}
