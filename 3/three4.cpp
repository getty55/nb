#include <iostream>
#include <vector>

template<typename T>
class Stack{
    T data;
    int capacity;
    Stack<T>* top;
    Stack<T>* bottom;
    int size = 0;
  public:
    //Stack(int c) : capacity{c} {}
    Stack(T d) : data{d}, top{nullptr}, bottom{nullptr} {}

    bool isFull(){ return capacity == size; }
    void join(Stack<T>*, Stack<T>*);
    bool push(T);
    void pop();
    T peek();
    bool isEmpty(){ return size == 0; }
    void removeBottom();
};

template<typename T>
void Stack<T>::join(Stack<T>* above, Stack<T>* below){
    if (below) below->top = above;
    if (above) above->bottom = below;
}

template<typename T>
bool Stack<T>::push(T v){
    if (size >= capacity) return false;
    ++size;
    Stack<T>* n = new Stack<T>(v);
    if (size == 1) bottom = n;
    join(n, top);
    top = n;
    return true;
}

template<typename T>
void Stack<T>::pop(){
    Stack<T>* t = top;
    top = top->below;
    --size;
}

template<typename T>
T Stack<T>::peek(){
    return top->data;
}

template<typename T>
void Stack<T>::removeBottom(){
    Stack<T>* b = bottom;
    bottom = bottom->above;
    if (bottom) bottom->below = nullptr;
    --size;
}


template<typename T>
class SetOfStacks{
    std::vector<Stack<T>*> stacks;
    int capacity;
  public:
    SetOfStacks(int c) : capacity{c} {}
    Stack<T>* getLastStack() const{ if (!stacks.size()) return nullptr; return stacks[stacks.size()-1]; }
    void push(T);
    void pop();
    T peek();
    bool isEmpty();
    void popAt(int);
    void leftShift(int, bool);
};

template<typename T>
void SetOfStacks<T>::push(T v){
    Stack<T>* last = getLastStack();
    if (last && !last->isFull()) last->push(v);
    else {
        Stack<T>* stack = new Stack<T>(capacity);
        stack->push(v);
        stacks.push_back(stack);
    }
}

template<typename T>
void SetOfStacks<T>::pop(){
    Stack<T>* last = getLastStack();
    if (!last) std::cerr << "Stack is Empty\n";
    if (last->size == 0) stacks.pop_back();
}

template<typename T>
T SetOfStacks<T>::peek(){
    Stack<T>* last = getLastStack();
    if (!last) std::cerr << "Stack is Empty\n";
    return last->peek();
}

template<typename T>
bool SetOfStacks<T>::isEmpty(){
    Stack<T>* last = getLastStack();
    return last == nullptr ||last->isEmpty();
}

template<typename T>
void SetOfStacks<T>::popAt(int index){
    leftShift(index, true);
}

template<typename T>
void SetOfStacks<T>::leftShift(int index, bool removeTop){
    Stack<T>* stack = stacks[index];
    int removed_item;
    if (removeTop) removed_item = stack->pop();
    else removed_item = stack->removeBottom();
    if (stack->isEmpty()){
        stacks.erase(index);
    }
    else if (stacks.size() > index+1) {
        int v = leftShift(index+1, false);
        stack.push(v);
    }
}

int main(){
    SetOfStacks<int> sos(3);
    sos.push(5);
    std::cout << sos.peek() << '\n';
}