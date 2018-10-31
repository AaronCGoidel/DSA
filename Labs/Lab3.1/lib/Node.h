#ifndef NODE_H
#define NODE_H

/* Node header file
 * Fall 2018
 */

#include <iostream>

template <class T>

class Node{
 private:
  T element;
  Node<T>* next;
  
 public:
  explicit Node(T elt){
    element = elt;
    next = nullptr;
  }
  explicit Node(T elt, Node* n){
    element = elt;
    next = n;
  }

  Node(const Node<T>& other){
    element = other.getElement();
    next = new Node<T>(other.getElement(), other.getNext());
  }
  
  T getElement() const { return element;}
  Node<T>* getNext() const { return next; }
  void setElement(T elt) { element = elt; }
  void setNext(Node<T>* n) {next = n; }
};

#endif