#include <iostream>
#include <vector>
#include <queue>

class Graph{
    public:
    int vertices;
    std::vector<int>* adj;
  
    Graph(int);
    void addEdge(int, int);
    bool isRoute(int, int);
};

Graph::Graph(int v) : vertices{v}, adj{new std::vector<int>[vertices]} {}

void Graph::addEdge(int x, int y){ adj[x].push_back(y); }

bool Graph::isRoute(int x, int y){
    std::vector<bool> visited(vertices, false);
    std::queue<int> q;
    q.push(x);

    while (!q.empty()){
        int curr = q.front();
        if (curr == y) return true;

        q.pop();
        visited[curr] = true;
        int n_size = adj[curr].size();
        for (int i = 0; i < n_size; ++i){
            if (!visited[adj[curr][i]]) q.push(adj[curr][i]);
        }
    }
    return false;
}

int main(){
    Graph g(6);
    std::cout << g.adj->size() << '\n';
    /*g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    std::cout << g.isRoute(5, 4) << '\n';
    std::cout << g.isRoute(5, 1) << '\n';*/
}