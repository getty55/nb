#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

class Project{
  public:
    Project(std::string n) : name{n}, state{State::BLANK} {}
    enum State {COMPLETE, PARTIAL, BLANK};

    std::string getName() const{ return name; }
    State getState() const{ return state; }
    std::vector<Project*> getChildren() const{ return children; }
    void setState(State st){ state = st; }
    void addNeighbor(Project*);

  private:
    std::vector<Project*> children;
    std::unordered_map<std::string, Project*> m;
    std::string name;
    State state;
};

void Project::addNeighbor(Project* node){
    if (m.find(node->getName()) == m.end()){
        children.push_back(node);
        m.insert({node->getName(), node});
    }
}

class Graph{
    std::vector<Project*> nodes;
    std::unordered_map<std::string, Project*> m;
  public:
    std::vector<Project*> getNodes() const{ return nodes; }
    Project* getOrCreateNode(std::string);
    void addEdge(std::string, std::string);
};

Project* Graph::getOrCreateNode(std::string name){
    if (m.find(name) == m.end()){
        Project* node = new Project(name);
        nodes.push_back(node);
        m.insert({name, node});
    }
    return m[name];
}

void Graph::addEdge(std::string startName, std::string endName){
    Project* start = getOrCreateNode(startName);
    Project* end = getOrCreateNode(endName);
    start->addNeighbor(end);
}

Graph buildGraph(std::vector<std::vector<std::string>>& dependencies){
    Graph graph;
    for (auto dependency : dependencies){
        std::string first = dependency[0];
        std::string second = dependency[1];
        graph.addEdge(first, second);
    }
    return graph;
}

bool doDFS(Project* project, std::stack<Project*> s){
    if (project->getState() == project->State::PARTIAL) return false;

    if (project->getState() == project->State::BLANK){
        project->setState(project->State::PARTIAL);
        std::vector<Project*> children = project->getChildren();
        for (Project* child : children){
            if (!doDFS(child, s)) return false;
        }
        project->setState(project->State::COMPLETE);
        s.push(project);
    }
    return true;
}

std::stack<Project*> orderProjects(std::vector<Project*> projects){
    std::stack<Project*> s;
    for (Project* project : projects){
        if (project->getState() == project->State::BLANK){
            if (!doDFS(project, s)) return s;
        }
    }
    return s;
}

std::vector<std::string> convertToStringList(std::stack<Project*> projects){
    std::vector<std::string> buildOrder(projects.size());
    for (int i = 0; i < buildOrder.size(); ++i){
        buildOrder[i] = projects.top()->getName();
        projects.pop();
    }
    return buildOrder;
}

std::stack<Project*> findBuildOrder(std::vector<std::string> projects, std::vector<std::vector<std::string>>& dependencies){
    Graph graph = buildGraph(dependencies);
    return orderProjects(graph.getNodes());
}

std::vector<std::string> buildOrderWrapper(std::vector<std::string>& projects, std::vector<std::vector<std::string>>& dependencies){
    std::vector<std::string> buildOrderString;
    std::stack<Project*> buildOrder = findBuildOrder(projects, dependencies);
    if (buildOrder.empty()) return buildOrderString;
    buildOrderString = convertToStringList(buildOrder);
    return buildOrderString;
}

int main(){
    std::vector<std::string> projects = {"a","b","c","e","f"};
    std::vector<std::vector<std::string>> dependencies = {
        {"c", "f"},
        {"b", "f"},
        {"a", "f"},
        {"a", "c"},
        {"a", "b"},
        {"e", "a"},
        {"e", "b"}
    };

    std::vector<std::string> buildOrder = buildOrderWrapper(projects, dependencies);
    if (buildOrder.empty()) std::cout << "Circular Dependency\n";
    else {
        for (std::string s : buildOrder) std::cout << s << " ";
        std::cout << '\n';
    }
}