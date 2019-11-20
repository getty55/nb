#include <iostream>

template<typename T>
class Sstack{
    T data;
    Sstack<T> next;
    Sstack<T> top;
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

int main(){
    Sstack<int> ss;
    ss.push(5);
    ss.push(7);
    std::cout << ss.peek() << '\n';
    ss.pop();
    std::cout << ss.peek() << '\n';

    if (ss.is_empty()) std::cout << "empty\n";
    else std::cout << "not empty\n";
}