#ifndef BST_H
#define BST_H

/* Binary Search Tree - recursive
 * Fall 2018
 * DSA
 * For the sake of demonstration and clarity we are going to use 
 * only a numerical value in the nodes of the tree. An element 
 * that is comparable could be used instead, but the syntax is 
 * more complicated than we need to deal with to understand 
 * Binary Search trees. Since this class is not templated the 
 * .h file is only a header file.
 */

#include <queue>

class BST{
 private:
  BST* left;
  BST* right;
 
  /* some private helper functions */
  void visit() const;
  bool isLeaf() const;

  void calculateCost(BST* justAdded);
  double getSumProb();
  

 public:
  int key;
  double cost; //cost of whole tree
  double prob; //individual probability
  int first; //farthest left number
  int last; //farthest right number
  explicit BST(int k, double p);
  //need a copy constructor
  explicit BST(BST &b2);
  

  /* Accessors */
  int getKey();
  double getCost();
  double getProb();
  int getFirst();
  int getLast();
  void inOrder();
  BST* getLeft();
  BST* getRight();

  
  /* Mutators */
  bool addLeft(BST* l);
  bool addRight(BST* r);
  
};

#endif
