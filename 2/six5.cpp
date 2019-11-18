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

int list_length(Linked_list* l){
    int length = 0;
    while (l){
        l = l->next;
        ++length;
    }
    return length;
}

bool is_palindrome_recurse(Linked_list* head, int length, Linked_list** next){
    if (!head || length <= 0) return true;
    else if (length == 1) return true;

    bool res = is_palindrome_recurse(head->next, length-2, )

    return true;
}

bool is_palindrome(Linked_list* head){
    Linked_list** pp = &head->next;
    return is_palindrome_recurse(head, list_length(head), pp);
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