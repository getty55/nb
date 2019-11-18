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

struct Partial_sum{
    Linked_list* sum;
    int carry;
    Partial_sum() : sum{nullptr}, carry{0} {}
};

Linked_list* insertBefore(Linked_list* list, int data){
    Linked_list* node = new Linked_list(data);
    if (list) node->next = list;

    return node;
}

Partial_sum addListsHelper(Linked_list* l1, Linked_list* l2){
    if (!l1 && !l2){
        Partial_sum sum;
        return sum;
    }
    /* add smaller digits recursively */
    Partial_sum sum = addListsHelper(l1->next, l2->next);

    /* add carry to current data */
    int val = sum.carry + l1->val + l2->val;

    /* insert sum of current digits */
    Linked_list* full_result = insertBefore(sum.sum, val%10);

    /* return sum so far, and the carry value */
    sum.sum = full_result;
    sum.carry = val/10;
    return sum;
}

Linked_list* padList(Linked_list* l, int padding){
    auto head = l;
    for (int i = 0; i < padding; ++i) head = insertBefore(head, 0);

    return head;
}

int list_length(Linked_list* l){
    int length = 0;
    while (l){
        l = l->next;
        ++length;
    }
    return length;
}

Linked_list* addLists(Linked_list* l1, Linked_list* l2){
    int len1 = list_length(l1);
    int len2 = list_length(l2);

    /* pad the shorter list with zeros */
    if (len1 < len2) l1 = padList(l1, len2-len1);
    else l2 = padList(l2, len1-len2);

    /* add lists */
    Partial_sum sum = addListsHelper(l1, l2);

    if (sum.carry == 0) return sum.sum;
    else {
        Linked_list* result = insertBefore(sum.sum, sum.carry);
        return result;
    }
}

int main(){
    Linked_list* ll = new Linked_list(8);
    ll->next = new Linked_list(1);
    ll->next->next = new Linked_list(7);
    ll->next->next->next = new Linked_list(5);
    /*ll->next->next->next->next = new Linked_list(3);
    ll->next->next->next->next->next = new Linked_list(8);*/
    print_list(ll);

    Linked_list* ll2 = new Linked_list(7);
    ll2->next = new Linked_list(9);
    ll2->next->next = new Linked_list(1);
    ll2->next->next->next = new Linked_list(4);
    print_list(ll2);

    auto a = addLists(ll, ll2);
    print_list(a);
}