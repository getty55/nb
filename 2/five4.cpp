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

Linked_list* sumLists(Linked_list* one, Linked_list* two){
    int carry;
    if (!two->next || !one->next) carry = 0;
    else carry = one->next->val + two->next->val >= 10 ? 1 : 0;

    Linked_list* ans = new Linked_list(one->val+two->val+carry); //std::cout << "a " << ans->val << '\n';
    
    auto p = one->next;
    auto pp = two->next;
    auto a = ans;

    while (p || pp){
        if (!pp->next && p->next) a->next = new Linked_list(p->val);
        else if (!p->next && pp->next) a->next = new Linked_list(pp->val);
        else if (!p->next && !pp->next) a->next = new Linked_list((p->val+pp->val)%10);
        else {
            carry = p->next->val + pp->next->val >= 10 ? 1 : 0;
            a->next = new Linked_list((p->val+pp->val+carry)%10);
        }
        p = p->next;
        pp = pp->next;
        a = a->next;
    }
    return ans;
}

int main(){
    Linked_list* ll = new Linked_list(6);
    ll->next = new Linked_list(1);
    ll->next->next = new Linked_list(7);
    //ll->next->next->next = new Linked_list(4);
    print_list(ll);

    Linked_list* ll2 = new Linked_list(2);
    ll2->next = new Linked_list(9);
    ll2->next->next = new Linked_list(5);
    //ll2->next->next->next = new Linked_list(4);
    print_list(ll2);

    auto a = sumLists(ll, ll2);
    print_list(a);
}