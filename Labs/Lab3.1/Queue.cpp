/*
  Queue implmentation using a linked list 
 */

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

  while(current != NULL){ // loop over elements in linked list
    next = current->getNext();
    delete current;
    current = next;
  }
}

template <typename T>
int Queue<T>::getSize(){
  return size; // this one doesn't need explaining
}

template <typename T>
bool Queue<T>::isEmpty(){
  return head == NULL; // this one also doesn't need explaining
}

template <typename T>
void Queue<T>::enqueue(T data){
  Node<T>* element = new Node<T>(data); // create new node with value of data

  if(isEmpty()){ // special case: this is the first node
    head = element; // set both front and back pointers to this element
    tail = element;
    size = 1;
    return;
  }
  // general case
  tail->setNext(element); // set last element's next to new node
  tail = element; // set back pointer to new node
  size++;
}

template <typename T>
T Queue<T>::dequeue(){
  // if there is nothing to return throw
  if(isEmpty()) throw std::out_of_range("No element");

  Node<T>* retrieved = head; // set node to output to the first node
  head = head->getNext(); // reset front pointer to second element
  T data = retrieved->getElement(); // set return value to data from old head
  
  size--;
  delete retrieved; // free memory from returned node
  
  return data;
}

template <typename T>
T Queue<T>::peek(){
  // throw if empty
  if(isEmpty()) throw std::out_of_range("No element");
  return head->getElement(); // return value of front element
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