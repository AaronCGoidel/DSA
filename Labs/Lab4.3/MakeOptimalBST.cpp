/* Make optimal BST from sorted list of BST single nodes using DP (tabulation) 
 * Spring 2019
 * DSA 
 */

#include <iostream>
#include "BST.h"
#include <vector>

vector<BST*> makeNodes(vector<int> keys, vector<int> probs){
  // takes list of keys and probabilities and makes nodes
}

vector<BST*> sort(vector<BST*> treeNodes){
  // sort tree nodes by key
}

BST* getTree(vector<vector<BST*> > optimals, int size, int start, int end){
  //iterate over all trees in optimal at appropraite row (size)
  // and return a copy of the one with
  //chosen start and end
}

BST* getOptimal(int size, vector<BST* > keys, vector<vector<BST*> > optimal){
  // keys is the first row of optimals (just the singleton keys)

  vector<BST* > trees; // where all trees will be stored
  //while figuring out which minimizes cost

  // iterate over keys size distance apart
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
  vector<int> keys = {3, 5, 20, 4, 1, 19, 6, 7};
  vector<double> probs = {.12, .4, .04, .3, .09, .1, .2, .29}
  int numKeys = keys.size();
  
  vector<vector<BST* > > optimals;
  
  // create an array of BST nodes 
  // sort them by key
  // put that in the first row of optimals
  // set current size var to 2
  // start calling get optimal for each size 2 - numKeys

  // I've suggested some methods that might help - feel free to use them
  // or not
 
}
