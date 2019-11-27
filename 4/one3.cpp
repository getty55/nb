#include <iostream>
#include <vector>
#include <queue>

enum State { UNVISITED, VISITING, VISITED };

class Node{
    std::vector<Node*> adjacent;
    int adjacentCount;
    std::string vertex;
    State state;
  public:
    Node(std::string v, int al) : vertex{v}, adjacentCount{0} {
        //for (int i = 0; i < al; ++i) adjacent.push_back(new Node);
        adjacent.resize(al);
    }

    void addAdjacent(Node*);
    std::vector<Node*> getAdjacent() const{ return adjacent; }
    std::string getVertex() const{ return vertex; }
    void setState(State s){ this->state = s; }
    State getState() const{ return state; }
};

void Node::addAdjacent(Node* x){
    if (adjacentCount < adjacent.size()){
        adjacent[adjacentCount] = x;
        ++adjacentCount;
    }
    else std::cerr << "no more adjacent can be added\n";
}



class Graph{
    const int MAX_VERTICES = 6;
    std::vector<Node*> vertices;
    int count;
  public:
    Graph() : count{0}{
        vertices.resize(MAX_VERTICES);
    }

    void addNode(Node*);
    std::vector<Node*> getNodes() const{ return vertices; }
};

void Graph::addNode(Node* x){
    if (count < vertices.size()){
        vertices[count] = x;
        ++count;
    }
    else std::cerr << "graph full\n";
}

Graph createNewGraph(){
    Graph g;
    std::vector<Node*> temp(6);

    temp[0] = new Node("a", 3);
    temp[1] = new Node("b", 0);
    temp[2] = new Node("c", 0);
    temp[3] = new Node("d", 1);
    temp[4] = new Node("e", 1);
    temp[5] = new Node("f", 0);

    temp[0]->addAdjacent(temp[1]);
    temp[0]->addAdjacent(temp[2]);
    temp[0]->addAdjacent(temp[3]);
    temp[3]->addAdjacent(temp[4]);
    temp[4]->addAdjacent(temp[5]);

    for (int i = 0; i < 6; ++i) g.addNode(temp[i]);

    return g;
}

bool search(Graph g, Node* start, Node* end){
    std::queue<Node*> q;
    for (Node* u : g.getNodes()) u->setState(State::UNVISITED);

    start->setState(State::VISITING);
    q.push(start);
    Node* u;
    while (!q.empty()){
        u = q.front();
        q.pop();
        if (u){
            for (Node* v : u->getAdjacent()){
                if (v->getState() == State::UNVISITED){
                    if (v == end) return true;
                    else {
                        v->setState(State::VISITING);
                        q.push(v);
                    }
                }
            }
            u->setState(State::VISITED);
        }
    }
    return false;
}

int main(){
    Graph g = createNewGraph();
    std::vector<Node*> n = g.getNodes();
    Node* start = n[0];
    Node* end = n[5];
    std::cout << search(g, start, end) << '\n';
}