#include <iostream>

template<typename T>
class Sstack{
    T data;
    Sstack<T>* next;
    Sstack<T>* top;
    T minimum;
  public:
    Sstack() : next{nullptr}, top{nullptr} {}
    Sstack(T d) : data{d}, next{nullptr}, top{nullptr} {}

    void push(T);
    void pop();
    T min() const{ return minimum; }
    T peek();
    bool is_empty();

    void track_min(T);
};

template<typename T>
void Sstack<T>::track_min(T item){
    if (!top) minimum = item;
    else if (item < minimum) minimum = item;
}

template<typename T>
void Sstack<T>::push(T item){
    Sstack<T>* t = new Sstack<T>(item);
    track_min(item);
    
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

template<typename T>
bool Sstack<T>::is_empty(){
    return top == nullptr;
}

int main(){
    Sstack<int> ss;
    ss.push(4);
    std::cout << ss.min() << '\n';
    ss.push(8);
    std::cout << ss.min() << '\n';
    ss.push(2);
    std::cout << ss.min() << '\n';
} 