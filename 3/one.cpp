#include <iostream>

class FixedMultiStack{
    int numberOfStacks;
    int stackCapacity;
    int* values;
    int* sizes;
  public:
    FixedMultiStack(int sc) : numberOfStacks{3}, stackCapacity{sc}, values{new int[sc*numberOfStacks]}, sizes{new int[numberOfStacks]} {}

    bool isFull(int stackNum) { return sizes[stackNum] == stackCapacity; }
    bool isEmpty(int stackNum) { return sizes[stackNum] == 0; }
    int indexOfTop(int);
    void push(int, int);
    int pop(int);
    int peek(int);
};

int FixedMultiStack::indexOfTop(int stackNum){
    int offset = stackNum*stackCapacity;
    int size = sizes[stackNum];
    return offset+size-1;
}

void FixedMultiStack::push(int stackNum, int value){
    /* check that we have space for the next element */
    if (isFull(stackNum)) std::cerr << "Stack is full\n";

    /* increment stack pointer and then update top value */
    sizes[stackNum]++;
    values[indexOfTop(stackNum)] = value;
}

int FixedMultiStack::pop(int stackNum){
    if (isEmpty(stackNum)){
        std::cerr << "Stack is Empty\n";
        return 0;
    }
    int topIndex = indexOfTop(stackNum);
    int value = values[topIndex];   // get top
    values[topIndex] = 0;   // clear
    sizes[stackNum]--;
    return value;
}

int FixedMultiStack::peek(int stackNum){
    if (isEmpty(stackNum)){
        std::cerr << "Stack is Empty\n";
        return 0;
    }
    return values[indexOfTop(stackNum)];
}

int main(){
    FixedMultiStack fs(3);
    fs.push(1, 8);
    fs.push(1, 9);
    fs.push(1, 7);
    std::cout << fs.peek(1) << '\n';

    /*if (fs.isFull(1)) std::cout << "full\n";
    else std::cout << "not full\n";*/
}