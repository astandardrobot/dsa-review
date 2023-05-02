#include <iostream>
#include <stack>
#include <vector>


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
    void dfs(int x);
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

/*
 * A depth-first search (DFS) is a way to find a node that meets determined criteria. Unlike a BFS,
 * it travels down the height of one branch before backtracking to the parent node and moving to the next branch.
 * It we visualize what this looks like, it makes sense to use a stack (the nodes are stacked upon one another).
 * THe LIFO access policy embraces the logic behind backtracking.
 *
 * The complexity of a DFS is O(|V| + |E|) where V = vertices and E = edges
 * The space complexity of a DFS is O(|V|) where V = edges
 */
void Graph::dfs(int node) {
    
    std::vector<bool> visited(v,false);
    // Maintain a stack of unvisited adjacent nodes
    std::stack<int> neighborList;
    neighborList.push(node);
    // as these values enter and are popped, mark them as visited
    while(!neighborList.empty()) {
        // inspect the top element
        int firstVal = neighborList.top();
        // pop it
        neighborList.pop();
        // The stack may contain already visited nodes. if this isn't a visited node
        if(!visited[firstVal]) {
            std::cout<<firstVal<<" ";
            // mark it as visited and print it
            visited[firstVal] = true;
        }
        // If an adjacent node to firstVal has not been visited, push it to the stack 
        for(auto i= adjList[firstVal].begin(); i != adjList[firstVal].end(); i++) {
            if(!visited[*i]) {
               neighborList.push(*i);
            }
        }
    }
}

int main() {
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
 
    std::cout << "Following is Depth First Traversal\n";
    g.dfs(0);     
}

