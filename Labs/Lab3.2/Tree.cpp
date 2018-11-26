#include <iostream>
#include "Tree.h"

template <typename T>
Tree<T>::Tree(){
  size = 0; // initialize a new tree with size 0
}

template <typename T>
void Tree<T>::insert(T data){
  if(contains(data)) return; // do nothing if the element is already in there
  nodes.push_back(data); // add to end of array
  size++; // increment size
}

template <typename T>
void Tree<T>::remove(T elem){
  for(int i = 0; i < size; i++){ // loop over array
    if(nodes[i] == elem){ // if this is the value we want
      nodes[i] = nodes.back(); // put last element in spot we just found target
      size--; // decrement size
      return;
    }
  }
}

template <typename T>
bool Tree<T>::contains(T elem){ 
  for(int i = 0; i < size; i++){ // simple linear search
    if(nodes[i] == elem) return true;
  }
  return false;
}

/*
  THE TRAVERSALS CALL THEIR RECURSIVE HELPERS AT POSITION 0
*/
template <typename T>
void Tree<T>::inOrder(){
  inOrderTraversal(0);
}

template <typename T>
void Tree<T>::preOrder(){
  preOrderTraversal(0);
}

template <typename T>
void Tree<T>::postOrder(){
  postOrderTraversal(0);
}


template <typename T>
void Tree<T>::breadthFirst(){
  for(int i = size - 1; i >= 0; i--){ // iterates backwards through array
    visit(i);
  }
}

int main(){
  Tree<int> tree;
  tree.insert(12);
  std::cout<<"Contains 12? (expecting 1): " << tree.contains(12) << "\n";

  tree.remove(12);
  std::cout<<"Contains 12? (expecting 0): " << tree.contains(12) << "\n";

  tree.insert(0);
  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);

  std::cout<<"---In-Order---"<<std::endl;
  tree.inOrder();
  std::cout<<"---Pre-Order---"<<std::endl;
  tree.preOrder();
  std::cout<<"---Post-Order---"<<std::endl;
  tree.postOrder();
  std::cout<<"---Breadth First---"<<std::endl;
  tree.breadthFirst();


}