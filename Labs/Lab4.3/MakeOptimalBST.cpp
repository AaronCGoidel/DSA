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
  //iterate over all trees in optimal at appropraite row (size)
  for(int i = 0; i < optimals[size - 1].size(); i++){
    BST* current = optimals[size - 1][i];
    if(current->getFirst() == start && current->getLast() == end){
      // and return a copy of the one with
      //chosen start and end
      BST* best = new BST(* current);
      return best;
    }
  }
  return NULL;
}

void getOptimal(int size, std::vector<BST* > &keys, std::vector<std::vector<BST*> > &optimal){
  // keys is the first row of optimals (just the singleton keys)
  std::vector<BST* > trees(keys.size() - size + 1); // where all trees will be stored
  //while figuring out which minimizes cost

  // iterate over keys size distance apart
  for(int i = 0; i <= keys.size() - size; i++){
    int leftmost = i;
    int rightmost = i + size - 1;

    int minCost = INT_MAX;
    for(int j = i; j < i + size; j++){
      BST* root = new BST(*keys[j]);

      if(j > leftmost){
        BST* left = getTree(optimal, j - leftmost, keys[i]->getKey(), keys[j - 1]->getKey());
        root->addLeft(left);
      }
      if(j < rightmost){
        BST* right = getTree(optimal, rightmost - j, keys[j + 1]->getKey(), keys[i + size - 1]->getKey());
        root->addRight(right);
      }

      if(root->getCost() < minCost){
        trees[i] = root;
      }
    }
  }
  optimal.push_back(trees);
}

int main(){
  // no duplicate keys are allowed
  static const int key[] = {1, 3, 4};
  std::vector<int> keys(key, key + sizeof(key) / sizeof(key[0]) );
  static const double prob[] = {.11, .4, .24};
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

  for(int size = 2; size <= numKeys; size++){
    getOptimal(size, singletons, optimals);
  }

  for(int i = 0; i < numKeys; i++){
    singletons[i]->inOrder();
    std::cout << "---" << std::endl;
  }
  optimals.back().back()->inOrder();
}
