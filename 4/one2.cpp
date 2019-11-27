#include <iostream>
#include <vector>
#include <queue>

enum State{ UNVISITED, VISITED, VISITING };

class Node{
    std::vector<Node> adjacent;
    int adjacentCount;
    std::string vertex;
    State state;
  public:
    Node(){}
    Node(std::string v, int al) : vertex{v}, adjacentCount{0} {
        adjacent.resize(al);
    }
    void addAdjacent(Node);
    std::vector<Node> getAdjacent() const{ return adjacent; }
    std::string getVertex() const{ return vertex; }

    State getState() const{ return state; }
    void setState(State s){ state = s; }
};

void Node::addAdjacent(Node x){
    if (adjacentCount < adjacent.size()){
        this->adjacent[adjacentCount] = x;
        ++adjacentCount;
    }
    else std::cerr << "no more adjacent can be added\n";
}


class Graph{
    const int MAX_VERTICES = 6;
    std::vector<Node> vertices;
    int count;
  public:
    Graph() : count{0}, vertices{std::vector<Node>(6)} {}

    void addNode(Node);
    std::vector<Node> getNodes() const{ return vertices; }
};

void Graph::addNode(Node x){
    if (count < vertices.size()){
        vertices[count] = x;
        ++count;
    }
    else std::cerr << "graph full\n";
}

Graph createNewGraph(){
    Graph g;
    std::vector<Node> temp;

    temp.push_back(Node("a", 3));
    temp.push_back(Node("b", 0));
    temp.push_back(Node("c", 0));
    temp.push_back(Node("d", 1));
    temp.push_back(Node("e", 1));
    temp.push_back(Node("f", 0));

    temp[0].addAdjacent(temp[1]);
    temp[0].addAdjacent(temp[2]);
    temp[0].addAdjacent(temp[3]);
    temp[3].addAdjacent(temp[4]);
    temp[4].addAdjacent(temp[5]);

    for (int i = 0; i < 6; ++i) g.addNode(temp[i]);

    return g;
}

bool search(Graph g, Node start, Node end){
    std::queue<Node> q;
    for (Node u : g.getNodes()) u.setState(State::UNVISITED);

    start.setState(State::VISITING);
    q.push(start);
    Node u;
    while (!q.empty()){
        u = q.front();
        q.pop();
        for (Node v : u.getAdjacent()){
            if (v.getState() == State::UNVISITED){
                if (&v == &end) return true;
                else {
                    v.setState(State::VISITING);
                    q.push(v);
                }
            }
        }
        u.setState(State::VISITED);
    }
    return false;
}

int main(){
    Graph g = createNewGraph();
    std::vector<Node> n = g.getNodes();
    Node start = n[2];
    Node end = n[1];
    std::cout << search(g, start, end) << '\n';
}