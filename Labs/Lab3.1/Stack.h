#ifndef STACK_H
#define STACK_H

#include "lib/Node.h"
#include <vector>

template <typename T> 
class Stack{
  private:
    int size;
    std::vector<T> elements;
    bool isEmpty(){
      return size == 0;
    }

  public:
    explicit Stack();
    void push(T data);
    T pop();
    T peek();
    int getSize(){
      return size;
    }
};

#endif