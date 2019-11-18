#include <iostream>
#include <stack>

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
    auto slow = head;
    auto fast = head;
    std::stack<char> s;

    while (fast && fast->next){
        s.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast) slow = slow->next;

    while (slow){
        if (slow->val != s.top()) return false;
        slow = slow->next;
        s.pop();
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