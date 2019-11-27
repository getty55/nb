#include <iostream>
#include <vector>

template<typename T>
class Stack{
    T data;
    Stack<T>* top;
    Stack<T>* next;
  public:
    Stack() : top{nullptr}, next{nullptr} {}
    Stack(T d) : data{d}, top{nullptr}, next{nullptr} {}

    void push(T);
    T peek();
    void pop();
};

template<typename T>
void Stack<T>::push(T item){
    Stack<T>* t = new Stack<T>(item);
    t->next = top;
    top = t;
}

template<typename T>
T Stack<T>::peek(){
    return top->data;
}

template<typename T>
void Stack<T>::pop(){
    if (!top) {
        std::cerr << "Stack is Empty\n";
        return;
    }
    top = top->next;
}



template<typename T>
class SetOfStacks{
    std::vector<Stack<T>*> stacks;
    int numOfStacks;
    int currCount;
    const int STACK_LIMIT = 3;
  public:
    SetOfStacks() : numOfStacks{1}, currCount{0} {
        stacks.push_back(new Stack<T>);
    }

    void push(T);
    T peek();
    void pop();
};

template<typename T>
void SetOfStacks<T>::push(T item){
    if (currCount == STACK_LIMIT){
        stacks.push_back(new Stack<T>);
        currCount = 0;
        std::cout << "starting a new sub-stack. number of stacks: " << stacks.size() << '\n';
    }

    stacks[stacks.size()-1]->push(item);
    ++currCount;
    if (currCount == STACK_LIMIT) std::cout << "this stack is full\n";
}

template<typename T>
T SetOfStacks<T>::peek(){
    return stacks[stacks.size()-1]->peek();
}

template<typename T>
void SetOfStacks<T>::pop(){
    if (!stacks.size()){
        std::cerr << "there are no stacks\n";
        return;
    }
    stacks[stacks.size()-1]->pop();
    --currCount;
    if (currCount == 0) stacks.pop_back();
}

int main(){
    SetOfStacks<int> sos;
    sos.push(5);
    sos.push(9);
    sos.push(3);
    sos.push(1);
    std::cout << sos.peek() << '\n';
    sos.pop();
    std::cout << sos.peek() << '\n';
}