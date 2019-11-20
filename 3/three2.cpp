#include <iostream>

template<typename T>
class SetOfStacks{
    int numOfStacks;
    int currCount;

    class Stack{
        T data;
        Stack* top;
        Stack* next;
      public:
        Stack() : top{nullptr}, next{nullptr} {}
        Stack(T d) : data{d}, top{nullptr}, next{nullptr} {}
    };

  public:
    SetOfStacks() : numOfStacks{1}, currCount{0} {}
};

int main(){
    SetOfStacks<int> sos;
}