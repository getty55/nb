#include <iostream>

template<typename T>
class Stack{
    T data;
    Stack<T>* top;
    Stack<T>* next;
  public:
    Stack() : top{nullptr}, next{nullptr} {}
    Stack(T d) : data{d}, top{nullptr}, next{nullptr} {}

    void push(T);
    T pop();
    T peek();
    bool is_empty(){ return top == nullptr; }
};

template<typename T>
void Stack<T>::push(T item){
    Stack<T>* t = new Stack<T>(item);
    t->next = top;
    top = t;
}

template<typename T>
T Stack<T>::pop(){
    T val = top->data;
    top = top->next;
    return val;
}

template<typename T>
T Stack<T>::peek(){
    return top->data;
}

void sort_back(Stack<int>& s, Stack<int>& sorter){
    bool first_pass = false;
    int t;
    if (sorter.is_empty()) first_pass = true;
    else t = sorter.peek();
    
    int tmp = s.pop();
    while (!s.is_empty()){
        if (s.peek() < tmp){
            sorter.push(tmp);
            tmp = s.pop();
        }
        else sorter.push(s.pop());
    }
    if (first_pass) while (!sorter.is_empty()) s.push(sorter.pop());
    else while (sorter.peek() != t) s.push(sorter.pop());

    sorter.push(tmp);
}

void sort_stack(Stack<int>& s){
    Stack<int> sorter;
    while (!s.is_empty()) sort_back(s, sorter);
    while (!sorter.is_empty()) s.push(sorter.pop());
}

int main(){
    Stack<int> s;
    s.push(8);
    s.push(4);
    s.push(9);
    s.push(7);
    s.push(1);
    s.push(5);
    sort_stack(s);
    while (!s.is_empty()) std::cout << s.pop() << '\n';
}