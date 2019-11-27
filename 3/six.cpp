#include <iostream>

template<typename T>
struct Linked_list{
    T data;
    Linked_list* next;
    Linked_list(T d) : data{d}, next{nullptr} {}
};

template<typename T>
void print_list(Linked_list<T>* head){
    auto p = head;
    while (p){
        std::cout << p->data;
        p = p->next;
        if (p) std::cout << " -> ";
    }
    std::cout << '\n';
}



template<typename T>
class Shelter{
    Linked_list<T>* dogs;
    Linked_list<T>* cats;
  public:
    Shelter() : dogs{nullptr}, cats{nullptr} {}

    void enqueue(Linked_list<T>*, std::string);
    Linked_list<T>* dequeueCat();
    Linked_list<T>* dequeueDog();
};

template<typename T>
void Shelter<T>::enqueue(Linked_list<T>* in, std::string type){
    if (type != "dogs" && type != "cats") return;

    if (type == "dogs"){
        if (!dogs) dogs = in;
        else {
            auto p = dogs; 
            while (p->next) p = p->next;
            p->next = in;
        }
        print_list(dogs);
    }

    if (type == "cats"){
        if (!cats) cats = in;
        else {
            auto p = cats;
            while (p->next) p = p->next;
            p->next = in;
        }
        print_list(cats);
    }
}

template<typename T>
Linked_list<T>* Shelter<T>::dequeueCat(){
    Linked_list<T>* p = cats;
    cats = cats->next;
    return p;
}

template<typename T>
Linked_list<T>* Shelter<T>::dequeueDog(){
    Linked_list<T>* p = dogs;
    dogs = dogs->next;
    return p;
}

int main(){
    Shelter<int> s;
    s.enqueue(new Linked_list<int>(5), "cats");
    s.enqueue(new Linked_list<int>(7), "cats");
    s.enqueue(new Linked_list<int>(9), "cats");
    auto a = s.dequeueCat();
    std::cout << "a " << a->data << '\n';
}