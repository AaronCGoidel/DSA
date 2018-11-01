/* 
  Stack implementation using std::vector
 */

#include <iostream>
#include "Stack.h"

template <typename T>
Stack<T>::Stack(){
  size = 0;
}

template <typename T>
void Stack<T>::push(T data){
  elements.push_back(data); // push new thing to front of vector
  size++;
}

template <typename T>
T Stack<T>::pop(){
  if(isEmpty()) throw std::out_of_range("No element"); // throw if empty

  T data = elements.back(); // set output node to last thing
  elements.pop_back(); // remove last thing from vector

  size--;
  return data;
}

template <typename T>
T Stack<T>::peek(){
  if(isEmpty()) throw std::out_of_range("No element"); // throw if empty

  T data = elements.back(); // return last thing
  return data;
}

int main(){
  Stack<int> S;
  S.push(1);
  S.push(2);
  printf("Expecting 2... Recieved: %d\n", S.pop());
  printf("Expecting 1... Recieved: %d\n", S.peek());
  printf("Expecting 1... Recieved: %d\n", S.pop());
  printf("Size is (expecting 0): %d\n", S.getSize());
  S.push(1);
  S.push(2);
  S.push(3);
  printf("Size is (expecting 3): %d\n", S.getSize());
  return 0;
}