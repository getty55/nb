#include <iostream>

template<typename T>
class Qqueue{
    T data;
    Qqueue<T>* next;
    Qqueue<T>* first;
    Qqueue<T>* last;
  public:
    Qqueue() : next{nullptr}, first{nullptr}, last{nullptr} {}
    Qqueue(T d) : data{d}, next{nullptr}, first{nullptr}, last{nullptr} {}

    void add(T);
    T remove();
    T peek();
    bool is_empty();
};

template<typename T>
void Qqueue<T>::add(T item){
    Qqueue<T>* t = new Qqueue<T>(item);
    if (last) last->next = t;
    last = t;
    if (!first) first = last;
}

template<typename T>
T Qqueue<T>::remove(){
    if (!first) std::cerr << "Qqueue is empty\n";
    T data = first->data;
    first = first->next;
    if (!first) last = nullptr;
    return data;
}

template<typename T>
T Qqueue<T>::peek(){
    if (!first) std::cerr << "Qqueue is empty\n";
    return first->data;
}

template<typename T>
bool Qqueue<T>::is_empty(){
    return first == nullptr;
}

int main(){
    Qqueue<int> qq;
    qq.add(3);
    qq.add(8);
    std::cout << qq.peek() << '\n';
    std::cout << qq.remove() << '\n';
    std::cout << qq.peek() << '\n';

    /*if (qq.is_empty()) std::cout << "empty\n";
    else std::cout << "not empty\n";*/
}