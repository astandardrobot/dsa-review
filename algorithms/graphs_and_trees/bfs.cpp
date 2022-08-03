#include <iostream>
#include <vector>
#include <queue>

struct GraphNode {
    int val;
    GraphNode *left;
    GraphNode *right;
    GraphNode() : val(0), left(nullptr), right(nullptr) {}
    GraphNode(int x) : val(x), left(nullptr), right(nullptr) {}
    GraphNode(int x, GraphNode *left, GraphNode *right) : val(x), left(left), right(right) {}
};


class Graph {
private:
    int v;
    std::vector<std::vector<int>> adjList;
public:
    Graph(int v);
    void addEdge(int v, int w);
    void bfs(int node);
};

Graph::Graph(int v)
{
    this->v = v;
    adjList.resize(v);
}
 
void Graph::addEdge(int v, int w)
{
    adjList[v].push_back(w); // Add w to v’s list.
}

void Graph::bfs(int node) {
    
    std::vector<bool> visited(v,false);
    // Maintain a queue of unvisited adjacent nodes
    std::queue<int> neighborList;       
    neighborList.push(node);
    visited[node] = true;
    // as these values enter and are popped, mark them as visited
    while(!neighborList.empty()) {
        // inspect the top element
        int firstVal = neighborList.front();
        // pop it
        std::cout<<firstVal<<" ";
        neighborList.pop();
        // If an adjacent node to firstVal has not been visited, push it to the stack 
        for(auto adj : adjList[firstVal]) {
            if(!visited[adj]) {
                visited[adj] = true;
                neighborList.push(adj);
            }
        }
    }
}

int main() {
     // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    std::cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
 
    return 0;   
}
