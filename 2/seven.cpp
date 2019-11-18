#include <iostream>

struct Linked_list{
    int val;
    Linked_list* next;
    Linked_list(int v) : val{v}, next{nullptr} {}
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

Linked_list* intersection(Linked_list* one, Linked_list* two){
    auto p = two;
    while (one){ 
        while (p){ std::cout << "one " << one->val << " two " << p->val << '\n';
            if (one == p) return one;
            p = p->next;
        }
        one = one->next;
        p = two;
    }

    return nullptr;
}

int main(){
    Linked_list* common = new Linked_list(9);

    Linked_list* ll = new Linked_list(2);
    ll->next = new Linked_list(6);
    ll->next->next = new Linked_list(4);
    ll->next->next->next = common;
    ll->next->next->next->next = new Linked_list(0);
    //ll2->next->next->next->next->next = new Linked_list('a');
    //ll2->next->next->next->next->next->next = new Linked_list('h');
    print_list(ll);

    Linked_list* ll2 = new Linked_list(7);
    ll2->next = new Linked_list(9);
    ll2->next->next = common; 
    ll2->next->next->next = new Linked_list(4);
    print_list(ll2);
    
    auto a = intersection(ll, ll2);
    if (!a) std::cout << "no intersection\n";
    else std::cout << "the intersection is " << a->val << '\n';
}