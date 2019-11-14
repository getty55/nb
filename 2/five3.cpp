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

Linked_list* recurse(Linked_list* one, Linked_list* two, Linked_list* ans, int carry){
    if (!one && !two) return ans;
    if (!two){
        ans = new Linked_list((one->val+carry)%10);
        carry = one->val+carry >= 10 ? 1 : 0;
        ans->next = recurse(one->next, nullptr, ans->next, carry);
    }
    else if (!one){
        ans = new Linked_list((two->val+carry)%10);
        carry = two->val+carry >= 10 ? 1 : 0;
        ans->next = recurse(nullptr, two->next, ans->next, carry);
    }
    else {
        ans = new Linked_list((one->val+two->val+carry)%10);
        carry = one->val+two->val+carry >= 10 ? 1 : 0;
        ans->next = recurse(one->next, two->next, ans->next, carry);
    }
}

Linked_list* sumLists(Linked_list* one, Linked_list* two){
    Linked_list* ans = new Linked_list((one->val+two->val)%10);

    int carry = one->val+two->val >= 10 ? 1 : 0;
    
    ans->next = recurse(one->next, two->next, ans->next, carry);

    return ans;
}

int main(){
    Linked_list* ll = new Linked_list(7);
    ll->next = new Linked_list(1);
    ll->next->next = new Linked_list(6);
    //ll->next->next->next = new Linked_list(4);
    print_list(ll);

    Linked_list* ll2 = new Linked_list(5);
    ll2->next = new Linked_list(9);
    ll2->next->next = new Linked_list(2);
    ll2->next->next->next = new Linked_list(4);
    ll2->next->next->next->next = new Linked_list(8);
    print_list(ll2);

    auto a = sumLists(ll, ll2);
    print_list(a);
}