#include <iostream>

template<typename T>
class Stack{
    T data;
    Stack<T>* top;
    Stack<T>* next;
    int size;
  public:
    Stack() : top{nullptr}, next{nullptr}, size{0} {}
    Stack(T d) : data{d}, top{nullptr}, next{nullptr}, size{0} {}

    void push(T);
    T peek();
    T pop();
    bool is_empty(){ return top == nullptr; }

    int get_size() const{ return size; }
};

template<typename T>
void Stack<T>::push(T item){
    Stack<T>* t = new Stack<T>(item);
    t->next = top;
    top = t;
    ++size;
}

template<typename T>
T Stack<T>::peek(){
    return top->data;
}

template<typename T>
T Stack<T>::pop(){
    T val = top->data;
    top = top->next;
    --size;
    return val;
}

template<typename T>
class MyQueue{
    Stack<T>* stackNewest;
    Stack<T>* stackOldest;
  public:
    MyQueue() : stackNewest{new Stack<T>}, stackOldest{new Stack<T>} {}

    int size(){ return stackNewest->get_size()+stackOldest->get_size(); }
    void add(T value){ stackNewest->push(value); }
    void shiftStacks();
    T peek();
    T remove();
};

template<typename T>
void MyQueue<T>::shiftStacks(){
    if (stackOldest->is_empty()){
        while (!stackNewest->is_empty()) stackOldest->push(stackNewest->pop());
    }
}

template<typename T>
T MyQueue<T>::peek(){
    shiftStacks();
    return stackOldest->peek();
}

template<typename T>
T MyQueue<T>::remove(){
    shiftStacks();
    return stackOldest->pop();
}

int main(){
    MyQueue<int> mq;
    std::cout << mq.size() << '\n';
    mq.add(8);
    mq.add(4);
    mq.add(2);
    std::cout << mq.size() << '\n';
    std::cout << mq.peek() << '\n';
    std::cout << mq.remove() << '\n';

    mq.add(6);

    std::cout << mq.size() << '\n';
    std::cout << mq.peek() << '\n';
}