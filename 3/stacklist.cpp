#include <iostream>

template<typename T>
class Sstack{
    T data;
    Sstack<T>* next;
    Sstack<T>* top;
  public:
    Sstack() : next{nullptr}, top{nullptr} {}
    Sstack(T d) : data{d}, next{nullptr}, top{nullptr} {}

    T pop();
    void push(T);
    T peek();
    bool is_empty();
};

template<typename T>
T Sstack<T>::pop(){
    if (!top) std::cerr << "Empty Sstack\n";
    T item = top->data;
    top = top->next;
    return item;
}

template<typename T>
void Sstack<T>::push(T item){
    Sstack<T>* t = new Sstack<T>(item);
    t->next = top;
    top = t;
}

template<typename T>
T Sstack<T>::peek(){
    if (!top) std::cerr << "Empty Sstack\n";
    return top->data;
}

template<typename T>
bool Sstack<T>::is_empty(){
    return top == nullptr;
}

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
    Sstack<char> s;
     
    auto slow = head;
    auto fast = head;
    while (fast && fast->next){
        s.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast) slow = slow->next;

    while (slow){
        if (slow->val != s.peek()) return false;
        slow = slow->next;
        s.pop();
    }
}

int main(){
    Linked_list* ll = new Linked_list('h');
    ll->next = new Linked_list('a');
    ll->next->next = new Linked_list('n');
    ll->next->next->next = new Linked_list('p');
    ll->next->next->next->next = new Linked_list('a');
    ll->next->next->next->next->next = new Linked_list('h');

    print_list(ll);
    if (is_palindrome(ll)) std::cout << "palindrome\n";
    else std::cout << "not palindrome\n";
}