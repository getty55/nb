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

bool is_palindrome(Linked_list* head){
    auto p = head;
    int size = 1;
    while (p->next){
        p = p->next;
        ++size;
    }
    
    int looper = size-3;

    int i = 0;
    while (i < size/2){ //std::cout << head->val << " " << p->val << '\n';
        if (head->val != p->val) return false;
        head = head->next;
        p = head;
        int j = 0;
        while (j < looper){
            p = p->next;
            ++j;
        }
        ++i;
        looper -= 2;
    }

    return true;
}

int main(){
    Linked_list* ll2 = new Linked_list('h');
    ll2->next = new Linked_list('a');
    ll2->next->next = new Linked_list('n');
    ll2->next->next->next = new Linked_list('o');
    ll2->next->next->next->next = new Linked_list('p');
    ll2->next->next->next->next->next = new Linked_list('a');
    ll2->next->next->next->next->next->next = new Linked_list('h');
    print_list(ll2);

    if (is_palindrome(ll2)) std::cout << "palindrome\n";
    else std::cout << "not palindrome\n";
}