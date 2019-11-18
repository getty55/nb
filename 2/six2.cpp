#include <iostream>

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

Linked_list* reverse(Linked_list* head){
    Linked_list* p = nullptr;
    while (head){
        Linked_list* n = new Linked_list(head->val);
        n->next = p;
        p = n;
        head = head->next;
    }
    return p;
}

bool is_palindrome(Linked_list* head){
    auto flipped = reverse(head);
    while (head && flipped){
        if (head->val != flipped->val) return false;
        head = head->next;
        flipped = flipped->next;
    }
    if (!head && flipped || head && !flipped) return false;
    return true;
}

int main(){
    Linked_list* ll2 = new Linked_list('h');
    ll2->next = new Linked_list('a');
    ll2->next->next = new Linked_list('n');
    ll2->next->next->next = new Linked_list('o');
    ll2->next->next->next->next = new Linked_list('n');
    ll2->next->next->next->next->next = new Linked_list('a');
    ll2->next->next->next->next->next->next = new Linked_list('h');
    print_list(ll2);
    
    if (is_palindrome(ll2)) std::cout << "palindrome\n";
    else std::cout << "not palindrome\n";
}