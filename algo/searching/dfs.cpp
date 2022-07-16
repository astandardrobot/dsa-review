#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <map>
using namespace std;
/*
 * A depth-first search starts at the root (usually), looks at all nodes on one path before backtracking to the next.
 *            0
 *        1       2
 *      3   4       5
 *
 * Consider the above tree. 
 *      - Start at the root. Push it to the stack and mark it as visited by declaring its index in the boolean
 *        vector to true
 *      - While the stack is NOT EMPTY, do the following:
 *              - pop the most recently pushed node (in this case, 0)
 *              - add the node (0) to be traversed.
 *              - push the adjacent nodes to the stack (in this case, 1 and 2) and mark them as visited.
 */

// DFS and BFS are used with graphs and trees, typically. This class is just used to showcase the properties of
// a DFS.
class Graph {

private:

    int nodes;
    std::list<int> *adjlist;
    std::vector<bool> visited;

public:

    Graph() {}

    Graph (int nodes) { // Allocate resources 
        adjlist = new list<int> [nodes];
        visited.resize(nodes, false);
        this->nodes = nodes;
    }

    ~Graph () { // Free allocated resources
        delete [] adjlist;
    }

    void AddEdge (int src, int dst) {
        adjlist[src].push_back(dst);
        adjlist[dst].push_back(src);
    }
};

void recursivedfs(int vertex) {
    // Creating three structures here...
    
    // A vector for visited nodes
    std::vector<bool> visited;
   
    // a list for the appended values in the graph
    std::list<int> *adjlist;
    
    // set all of the indicies to true initially
    visited[vertex] = true;

    // that way, if the current has not been visited we can just move onto the next path
    for(auto &node : adjlist[vertex]) {
        if(!visited[node]) {recursivedfs(node);}
    }
}

// In this iterative version, popping and pushing to the stack essentially replaces the recursive DFS calls in the
// previous algorithm
void iterativedfs(int vertex) {
    std::stack<int> stk;
    std::vector<bool> visited;
    std::list<int> *adjlist;
    visited[vertex] = true;

    while(!stk.empty()) {
        vertex = stk.top();
        stk.pop();
        for(auto &node : adjlist[vertex]) {
            if(!visited[node]) {
                visited[node] = true;
                stk.push(node);
            }
        }
    }
}


int main() {
}
