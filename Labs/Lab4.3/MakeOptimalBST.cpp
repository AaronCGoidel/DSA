/* Make optimal BST from sorted list of BST single nodes using DP (tabulation) 
 * Spring 2019
 * DSA 
 */

#include <iostream>
#include "BST.h"
#include <vector>

std::vector<BST*> makeNodes(std::vector<int> keys, std::vector<double> probs){
  std::vector<BST*> nodes;
  for(int i = 0; i < keys.size(); i++){
    nodes.push_back(new BST(keys[i], probs[i]));
  }

  return nodes;
}

void sort(std::vector<BST*> &treeNodes){
  for(int i = 0; i < treeNodes.size(); i++){
    for(int j = i; j > 0; j--){
      if(treeNodes[j - 1]->getKey() > treeNodes[j]->getKey()){
        BST* temp = treeNodes[j];
        treeNodes[j] = treeNodes[j - 1];
        treeNodes[j - 1] = temp;
      }
    }
  }
}

BST* getTree(std::vector<std::vector<BST*> > optimals, int size, int start, int end){
  BST* optimal;
  //iterate over all trees in optimal at appropraite row (size)
  for(int i = 0; i < optimals[size].size(); i++){
    BST* current = optimals[size][i];
    if(current->getFirst() == start && current->getLast() == end){
      // and return a copy of the one with
      //chosen start and end
      optimal = new BST(*current);
      return optimal;
    }
  }
}

void getOptimal(int size, std::vector<BST* > keys, std::vector<std::vector<BST*> > optimal){
  // keys is the first row of optimals (just the singleton keys)

  std::vector<BST* > trees(100); // where all trees will be stored
  //while figuring out which minimizes cost

  // iterate over keys size distance apart
  for(int i = 0; i < keys.size() - size; i++){
    int minCost = INT_MAX;
    for(int j = i; j < size; j++){
      BST* root = keys[j];
      if(i < j){
        BST* left = getTree(optimal, j - i, keys[i]->getKey(), keys[j - i]->getKey());
        root->addLeft(left);
      }
      if(i > j){
        BST* right = getTree(optimal, i - j, keys[j]->getKey(), keys[i + size]->getKey());
        root->addLeft(right);
      }
      if(root->getCost() < minCost) trees[i] = root;
    }
  }
  optimal.push_back(trees);
  // get appropriate root node and construct the tree with that root node
  // and optimal subtree of appropriate size
  // once the tree is constructed put it in trees

  // iterate over all things in trees and find one of minimimum cost
  // store BST*
  // delete stuff
  // return BST
}

int main(){
  // no duplicate keys are allowed
  static const int key[] = {3, 5, 20, 4, 1, 19, 6, 7};
  std::vector<int> keys(key, key + sizeof(key) / sizeof(key[0]) );
  static const double prob[] = {.12, .4, .04, .3, .09, .1, .2, .29};
  std::vector<double> probs(prob, prob + sizeof(prob) / sizeof(prob[0]) );
  int numKeys = keys.size();
  
  std::vector<std::vector<BST* > > optimals;
  
  // create an array of BST nodes 
  std::vector<BST*> singletons = makeNodes(keys, probs);
  // sort them by key
  sort(singletons);
  // put that in the first row of optimals
  optimals.push_back(singletons);

  // set current size var to 2
  // start calling get optimal for each size 2 - numKeys
  for(int size = 2; size < numKeys; size++){
    getOptimal(size, singletons, optimals);
  }

  // I've suggested some methods that might help - feel free to use them
  // or not
 
}
