#include <iostream>
#include <cmath>

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

struct Result{
    Linked_list* tail;
    int size;
    Result(Linked_list* t, int s) : tail{t}, size{s} {}
};

Result getTailAndSize(Linked_list* list){
    if (!list) return Result(nullptr, 0);
    int size = 1;
    Linked_list* current = list;
    while (current){
        ++size;
        current = current->next;
    }
    return Result(current, size);
}

Linked_list* getKthNode(Linked_list* head, int k){
    //Linked_list* current = head;
    while (k > 0 && head){
        head = head->next;
        --k;
    }
    return head;
}

Linked_list* findIntersection(Linked_list* list1, Linked_list* list2){
    if (!list1 || !list2) return nullptr;

    /* get tail and size */
    Result result1 = getTailAndSize(list1);
    Result result2 = getTailAndSize(list2);

    /* if different tail nodes, then there's no intersection */
    if (result1.tail != result2.tail) return nullptr;

    /* set pointers to the start of each linked list */
    Linked_list* shorter = result1.size < result2.size ? list1 : list2;
    Linked_list* longer = result1.size < result2.size ? list2 : list1;

    /* advance the pointer for the longer linked list by difference in length */
    longer = getKthNode(longer, std::abs(result1.size-result2.size));

    /* move both pointers until you have a collision */
    while (shorter != longer){
        shorter = shorter->next;
        longer = longer->next;
    }

    /* return either one */
    return longer;
}

int main(){
    Linked_list* common = new Linked_list(7);
    common->next = new Linked_list(2);
    common->next->next = new Linked_list(1);

    Linked_list* ll = new Linked_list(3);
    ll->next = new Linked_list(1);
    ll->next->next = new Linked_list(5);
    ll->next->next->next = new Linked_list(9);
    ll->next->next->next->next = common;
    print_list(ll);

    Linked_list* ll2 = new Linked_list(4);
    ll2->next = new Linked_list(6);
    ll2->next->next = common;
    print_list(ll2);
    
    auto a = findIntersection(ll, ll2);
    if (!a) std::cout << "no intersection\n";
    else std::cout << "the intersection is " << a->val << '\n';
}