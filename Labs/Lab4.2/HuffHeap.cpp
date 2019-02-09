/* HuffHeap
 * 2019
 */

#include <iostream>
#include "HuffHeap.h"
#include "HuffNode.h"
#include <vector>

using namespace std;


HuffHeap::HuffHeap(){
  vector<HuffNode* > heap;
}

int HuffHeap::getSize(){
  return heap.size();
}

void HuffHeap::insert(HuffNode* node){
  heap.push_back(node);

  int index = heap.size() - 1;
  int parent = (index - 1) / 2;
  while(index > 0 && *(heap[index]) < *(heap[parent])){
    HuffNode* temp = heap[index];
    heap[index] = heap[parent];
    heap[parent] = temp;
    parent = (index - 1) / 2;
    index = parent;
  }
}

bool removeHelper(vector<HuffNode* > heap, int n){
  bool left = heap.size() > 2 * n + 1 && *(heap[n]) > *(heap[2 * n + 1]);
  bool right = heap.size() > 2 * n + 2 && *(heap[n]) > *(heap[2 * n + 2]);
  return left || right;
}

HuffNode* HuffHeap::remove(){
  HuffNode* root = heap[0];
  heap[0] = heap[heap.size() - 1];

  int index = 0;
  while(removeHelper(heap, index)){
    if(*(heap[2*index + 2]) < *(heap[2*index + 1])){
      HuffNode* temp = heap[index];
      heap[index] = heap[2*index + 2];
      heap[2*index + 2] = temp;
      index = 2*index + 2;
    }else{
      HuffNode* temp = heap[index];
      heap[index] = heap[2*index + 1];
      heap[2*index + 1] = temp;
      index = 2*index + 1;
    }
  }
  heap.pop_back();
  return root;
}

char HuffHeap::peakMin(){
  return heap[0]->getChar();
}

HuffNode* HuffHeap::get(){
  return heap[0];
}

void HuffHeap::display(){
  for (int i = 0; i < heap.size(); i++){
    cout << heap[i]->toString(1) << endl;
  }
  // cout << heap[0]->toString(4) << endl;
}

