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
    Linked_list* ans = nullptr;

    int carry = 0;

    auto p = one;
    auto pp = two;
    Linked_list* a = ans;

    while (p || pp){
        if (!pp){
            if (!ans){
                ans = new Linked_list((p->val+carry)%10);
                a = ans;
            }
            else a->next = new Linked_list((p->val+carry)%10);
            a = a->next;
            if ((p->val+carry)>10) carry = 1;
            else carry = 0;
            p = p->next;
        }
        else if (!p){
            a->next = new Linked_list((pp->val+carry)%10);
            a = a->next;
            if ((pp->val+carry)>10) carry = 1;
            else carry = 0;
            pp = pp->next;
        }
        else {
            if (!ans){
                ans = new Linked_list((p->val+pp->val+carry)%10);
                a = ans;
            }
            else a->next = new Linked_list((p->val+pp->val+carry)%10);
            std::cout << "a " << a->val << '\n';
            a = a->next;
            if ((p->val+pp->val+carry)>10) carry = 1;
            else carry = 0;
            p = p->next;
            pp = pp->next;
        }
    }
    return ans;
}

int main(){
    /*Linked_list* u;// = nullptr;
    u = new Linked_list(11);
    print_list(u);*/
    Linked_list* ll = new Linked_list(7);
    ll->next = new Linked_list(1);
    ll->next->next = new Linked_list(6);
    ll->next->next->next = new Linked_list(4);
    print_list(ll);

    Linked_list* ll2 = new Linked_list(5);
    ll2->next = new Linked_list(9);
    ll2->next->next = new Linked_list(2);
    //ll2->next->next->next = new Linked_list(4);
    print_list(ll2);

    auto a = sumLists(ll, ll2);
    print_list(a);
}