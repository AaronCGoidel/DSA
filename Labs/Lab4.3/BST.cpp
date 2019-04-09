/* Binary Search Tree - recursive
 * Fall 2018
 * DSA
 * AMMENDED FOR USE IN OPTIMIZING BST
 */
#include <iostream>
#include "BST.h"
#include <assert.h> 

using namespace std;

// Constructor, destructor, copy 
BST::BST(){
}
BST::BST(int k, double p){
  key = k; 
  prob = p; cost = p; // cost and prob are same for singleton
  left = nullptr; right = nullptr;
  first = k; last = k; //start and end are root for singleton
}
BST::BST(BST &b2){
  BST* clone = copyHelper(&b2);

  key = clone->getKey();
  prob = clone->getProb();
  cost = clone->getCost();
  left = clone->getLeft();
  right = clone->getRight();
  first = clone->getFirst();
  last = clone->getLast();
}

BST* BST::copyHelper(BST* toCopy){
  if(toCopy == NULL) return NULL;
  
  BST* copyNode = new BST();
  copyNode->key = toCopy->getKey();
  copyNode->prob = toCopy->getProb();
  copyNode->cost = toCopy->getCost();
  copyNode->first = toCopy->getFirst();
  copyNode->last = toCopy->getLast();

  copyNode->left = copyHelper(toCopy->getLeft());
  copyNode->right = copyHelper(toCopy->getRight());

  return copyNode;
}
  

  
// private methods
void BST::visit() const{
  cout << key << ": " << cost << endl;
}
bool BST::isLeaf() const{
  return left == nullptr && right == nullptr;
}

double BST::sumNodes(BST* root){
  if(root == NULL) return 0;
  
  // return sumNodes(root->getLeft()) + sumNodes(root->getRight()) + root->getProb();
  return 1;
}

void BST::calculateCost(BST* justAdded){
  // happens when a node is added to left or right of current
  // current prob + total cost of node added + sum of all nodes in tree added
  // to do

  cost = sumNodes(justAdded) + getProb() + justAdded->getCost();
}

/* Accessors */
int BST::getKey(){ return key; }
double BST::getCost(){ return cost; }
double BST::getProb(){ return prob; }
int BST::getFirst(){ return first; }
int BST::getLast(){ return last; }
BST* BST::getLeft() { return left; }
BST* BST::getRight() { return right;}

/* Mutators */
bool BST::addLeft(BST* l){
  if(l == NULL) return false;
  assert(l->getKey() < key);
  left = l;
  first = l->getFirst();
  calculateCost(l);
  return true;
}

bool BST::addRight(BST* r){
  if(r == NULL) return false;
  assert(r->getKey() > key);
  right = r;
  last = r->getLast();
  calculateCost(r);
  return true;
}

void BST::inOrder(){
  if (left != nullptr)
    left->inOrder();
  visit();
  if (right != nullptr)
    right->inOrder();
}

