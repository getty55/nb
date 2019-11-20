#include <iostream>

class StackInfo{
    int start, size, capacity;
  public:
    StackInfo(int s, int c) : start{s}, capacity{c} {}

    bool isWithinStackCapacity(int);
};

bool StackInfo::isWithinStackCapacity(int index){
    /* if outside of bounds of array, return false */
    if (index < 0 || index >= values.size()) return false;
}