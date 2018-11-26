#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>

template <typename T>
class Tree{
  private:
    std::vector<T> nodes; // new empty vector of type T
    int size;

    void visit(int pos){ // visit prints element at given position
      std::cout<<nodes[pos]<<"\n";
    }

    /*
      TRAVERSAL HELPER FUNCTIONS
    */
    void inOrderTraversal(int pos){
      if(2*pos + 1 < size) inOrderTraversal(2*pos + 1); // does this have a left child?
      visit(pos); // print "root" (i.e. current postion)
      if(2*pos + 2 < size) inOrderTraversal(2*pos + 2); // does this have a right child?
    }
    void preOrderTraversal(int pos){
      visit(pos);
      if(2*pos + 1 < size) inOrderTraversal(2*pos + 1);
      if(2*pos + 2 < size) inOrderTraversal(2*pos + 2);
    }
    void postOrderTraversal(int pos){
      if(2*pos + 1 < size) inOrderTraversal(2*pos + 1);
      if(2*pos + 2 < size) inOrderTraversal(2*pos + 2);
      visit(pos);
    }
  public:
    explicit Tree();
    void insert(T data);
    void remove(T elem);
    void preOrder();
    void inOrder();
    void postOrder();
    void breadthFirst();
    bool contains(T elem);
};

#endif