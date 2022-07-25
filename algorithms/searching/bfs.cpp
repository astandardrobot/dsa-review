#include <iostream>
#include <vector>
#include <list>
#include <queue>

class Graph {
private:
    int vertices;
    std::list<int> *adjlist;
    std::vector<bool> visited;
public:
    Graph() {

    }

    Graph(int nodes) { 
        adjlist = new std::list<int> [nodes];
        visited.resize(nodes, false);  
        vertices = nodes;
    }

    ~Graph() { 
        delete [] adjlist;
    }

    void AddEdge(int src, int dst) {
        adjlist[src].push_back(dst);
    }

    
    void bfs(int vertex) {
        std::queue<int> newq; 
        visited[vertex] = false;
        newq.push(vertex);

        while(!newq.empty()) {
            int n = newq.front();
            newq.pop();
            std::cout<<n<<" ";

            for(auto& newnode : adjlist[n]) {
                if(!visited[newnode]) {
                    visited[newnode] = true;
                    newq.push(newnode);
                }
            }
        }
        std::fill(visited.begin(), visited.end(), false);
    }

};
          
int main() {
    Graph g(7); 

    g.AddEdge(0,1); 
    g.AddEdge(0,2); 
    g.AddEdge(1,3); 
    g.AddEdge(1,4); 
    g.AddEdge(2,3);
    g.AddEdge(3,5); 
    g.AddEdge(4,6); 
    g.AddEdge(5,6); 

    std::cout << "BFS Graph Traversal" << std::endl;
    std::cout << "Source Node(3): "; g.bfs(3); std::cout << std::endl;
    return 0;
}
