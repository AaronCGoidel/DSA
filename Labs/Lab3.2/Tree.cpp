#include <iostream>
#include "Tree.h"

template <typename T>
Tree<T>::Tree(){
  size = 0;
}

template <typename T>
void Tree<T>::insert(T data){
  if(contains(data)) return;
  nodes.push_back(data);
  size++;
}

template <typename T>
void Tree<T>::remove(T elem){
  for(int i = 0; i < size; i++){
    if(nodes[i] == elem){
      nodes[i] = nodes.back();
      size--;
      return;
    }
  }
}

template <typename T>
bool Tree<T>::contains(T elem){
  for(int i = 0; i < size; i++){
    if(nodes[i] == elem) return true;
  }
  return false;
}

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
  for(int i = size - 1; i >= 0; i--){
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