#include <iostream>
#include "Queue.h"

template <typename T>
Queue<T>::Queue(){
  head = NULL;
  tail = NULL;
  size = 0;
}

template <typename T>
Queue<T>::~Queue(){
  Node<T>* current = head;
  Node<T>* next = NULL;

  while(current != NULL){
    next = current->getNext();
    delete current;
    current = next;
  }
}

template <typename T>
int Queue<T>::getSize(){
  return size;
}

template <typename T>
bool Queue<T>::isEmpty(){
  return head == NULL;
}

template <typename T>
void Queue<T>::enqueue(T data){
  Node<T>* element = new Node<T>(data);

  if(isEmpty()){
    head = element;
    tail = element;
    size = 1;
    return;
  }

  tail->setNext(element);
  tail = element;
  size++;
}

template <typename T>
T Queue<T>::dequeue(){
  if(isEmpty()) throw std::out_of_range("No element");

  Node<T>* retrieved = head;
  head = head->getNext();
  T data = retrieved->getElement();
  
  size--;
  delete retrieved;
  
  return data;
}

template <typename T>
T Queue<T>::peek(){
  if(isEmpty()) throw std::out_of_range("No element");
  return head->getElement();
}

int main(){
  Queue<int> Q = Queue<int>();
  Q.enqueue(4);
  Q.enqueue(3);
  Q.enqueue(2);
  printf("Expecting 4... Recieved: %d\n", Q.dequeue());
  printf("Size (Expecting 2)... Recieved: %d\n", Q.getSize());
  printf("Expecting 3... Recieved: %d\n", Q.peek());
  printf("Expecting 3... Recieved: %d\n", Q.dequeue());
  Q.dequeue();
  printf("Size (Expecting 0)... Recieved: %d\n", Q.getSize());
}