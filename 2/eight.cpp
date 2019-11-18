#include <iostream>
#include <unordered_set>

struct Linked_list{
    char val;
    Linked_list* next;
    Linked_list(char v) : val{v}, next{nullptr} {}
};

void print_list(Linked_list* head){
    auto p = head;
    while (p){
        std::cout << p->val;
        p = p->next;
        if (p) std::cout << " -> ";
    }
    std::cout << '\n';
}

Linked_list* loop_detection(Linked_list* head){
    if (!head) return nullptr;

    std::unordered_set<Linked_list*> m;
    auto p = head;
    while (p){
        if (m.find(p) != m.end()) return p;
        m.insert(p);
        p = p->next;
    }
    
    return nullptr;
}

int main(){
    Linked_list* boom = new Linked_list('C');

    Linked_list* ll = new Linked_list('A');
    ll->next = new Linked_list('B');
    ll->next->next = boom;
    ll->next->next->next = new Linked_list('D');
    ll->next->next->next->next = new Linked_list('E');
    ll->next->next->next->next->next = boom;
    //print_list(ll);

    auto a = loop_detection(ll);
    if (!a) std::cout << "no loop detected\n";
    else std::cout << "loop detected at node: " << a->val << '\n';
}