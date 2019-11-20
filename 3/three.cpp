#include <iostream>

template<typename T>
class SetOfStacks{
    T data;
    SetOfStacks* top;
    SetOfStacks* next;
    const int limit = 3;
    int count;
  public:
    SetOfStacks() : top{nullptr}, next{nullptr}, count{0} {}
    SetOfStacks(T d) : data{d}, top{nullptr}, next{nullptr}, count{0} {}

    void push(T);
    void pop();
    T peek();
    bool isEmpty(){ return top == nullptr; }
};

template<typename T>
void SetOfStacks<T>::push(T item){
    if (count == limit) std::cout << "starting a new stack\n";

    SetOfStacks<T>* t = new SetOfStacks(item);
    t->next = top;
    top = t;
    ++count;
    if (count == limit) std::cout << "this stack is full\n";
}

template<typename T>
void SetOfStacks<T>::pop(){
    if (!top){
        std::cerr << "Stack is Empty\n";
        return;
    }
    top = top->next;
}

template<typename T>
T SetOfStacks<T>::peek(){
    if (!top) std::cerr << "Stack is Empty\n";
    return top->data;
}

int main(){
    SetOfStacks<int> sos;
    sos.push(4);
    sos.push(8);
    sos.push(5);
    sos.push(7);
}