#include <iostream>

template<typename T>
class Sstack{
    T data;
    T minimum;
    Sstack<T>* next;
    Sstack<T>* top;
  public:
    Sstack() : next{nullptr}, top{nullptr} {}
    Sstack(T d) : data{d}, next{nullptr}, top{nullptr} {}

    void push(T);
    void pop();
    T peek();
    T min() const{ return top->minimum; }
    bool is_empty() { return top == nullptr; }
};

template<typename T>
void Sstack<T>::push(T item){
    Sstack<T>* t = new Sstack<T>(item);
    
    if (!top) t->minimum = item;
    else t->minimum = item < top->minimum ? item : top->minimum;

    t->next = top;
    top = t;
}

template<typename T>
void Sstack<T>::pop(){
    if (!top) std::cerr << "Stack is Empty\n";
    top = top->next;
}

template<typename T>
T Sstack<T>::peek(){
    if (!top) std::cerr << "Stack is Empty\n";
    return top->data;
}

int main(){
    Sstack<int> ss;
    ss.push(5);
    ss.push(9);
    std::cout << ss.min() << '\n';
    ss.push(4);
    std::cout << ss.min() << '\n';
    ss.pop();
    std::cout << ss.min() << '\n';
} 