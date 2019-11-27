#include <iostream>

template<typename T>
struct Linked_list{
    T data;
    Linked_list<T>* next;
    Linked_list() : next{nullptr} {}
    Linked_list(T d) : data{d}, next{nullptr} {}
};

class Animal{
    int order;
    std::string name;
  public:
    Animal(std::string n) : name{n} {}
    void setOrder(int o){ order = o; }
    int getOrder() const{ return order; }
    bool isOlderThan(Animal a){ return this->order < a.order; }
};

class Dog : public Animal{
  public:
    Dog(std::string n) : Animal{n} {}
};

class Cat : public Animal{
  public:
    Cat(std::string n) : Animal{n} {}
};

class AnimalQueue{
    Linked_list<Dog>* dogs = new Linked_list<Dog>();
    Linked_list<Cat>* cats = new Linked_list<Cat>();
    int order = 0;
  public:
    void enqueue(Animal*);
};

void AnimalQueue::enqueue(Animal* a){
    a->setOrder(order);
    ++order;
    if (dynamic_cast<Dog*>(a)) dogs->next = a;
    else if (dynamic_cast<Cat*>(a)) cats->next = a;
}

int main(){

}