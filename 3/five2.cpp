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

void sort_stack(Stack<int>& s){
    Stack<int> r;
    while (!s.is_empty()){
        /* insert each element in s in sorted order into r */
        int tmp = s.pop();
        while (!r.is_empty() && r.peek() > tmp) s.push(r.pop());
        r.push(tmp);
    }

    /* copy the elements from r back into s */
    while (!r.is_empty()) s.push(r.pop());
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