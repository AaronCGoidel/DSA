#ifndef QUEUE_H
#define QUEUE_H

#include "lib/Node.h"

template <typename T> 
class Queue{
  // Data members
  Node<T>* head;
  Node<T>* tail;
  int size;

  private:
    bool isEmpty();

  public:
    explicit Queue();
    ~Queue();
    void enqueue(T data);
    T dequeue();
    T peek();
    int getSize();
};

#endif