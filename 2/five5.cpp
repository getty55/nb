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

int list_length(Linked_list* l){
    int length = 0;
    while (l){
        l = l->next;
        ++length;
    }
    return length;
}

Linked_list* sumLists(Linked_list* one, Linked_list* two){
    auto p = one;
    auto pp = two;
    int carry = 0;
    Linked_list* ans = nullptr;
    Linked_list* a = nullptr;

    if (list_length(one) != list_length(two)){
        int diff = list_length(one) > list_length(two) ? list_length(one)-list_length(two) : list_length(two)-list_length(one);
        if (list_length(one) > list_length(two)){
            while (diff > 1){
                if (!ans){
                    ans = new Linked_list(p->val);
                    a = ans;
                }
                else{
                    a = ans;
                    a->next = new Linked_list(p->val); 
                    a = a->next; 
                }
                p = p->next;
                --diff;
            }


            carry = (p->next->val + pp->val) >= 10 ? 1 : 0;
            a->next = new Linked_list(p->val+carry); 
            a = a->next;
            p = p->next;


            while (p || pp){
                if (p->next && pp->next) carry = (p->next->val + pp->next->val) >= 10 ? 1 : 0;
                else carry = 0;
                a->next = new Linked_list((p->val+pp->val+carry)%10);
                a = a->next; 
                p = p->next;
                pp = pp->next;
            }
        }
    }
    return ans;
}

int main(){
    Linked_list* ll = new Linked_list(6);
    ll->next = new Linked_list(1);
    ll->next->next = new Linked_list(7);
    ll->next->next->next = new Linked_list(5);
    ll->next->next->next->next = new Linked_list(3);
    ll->next->next->next->next->next = new Linked_list(8);
    print_list(ll);

    Linked_list* ll2 = new Linked_list(7);
    ll2->next = new Linked_list(9);
    ll2->next->next = new Linked_list(1);
    ll2->next->next->next = new Linked_list(4);
    print_list(ll2);

    auto a = sumLists(ll, ll2);
    print_list(a);
}