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

HuffNode* HuffHeap::remove(){
  HuffNode* root = heap[0];
  heap[0] = heap[heap.size()-1];

  int n = 0;
  int leftPos = 2 * n + 1;
  int rightPos = 2 * n + 2;

  while((heap.size() > leftPos && *(heap[n]) > *(heap[leftPos])) ||
        (heap.size() > rightPos && *(heap[n]) > *(heap[rightPos]))){
    if(*(heap[rightPos]) < *(heap[leftPos])){
      HuffNode* temp = heap[rightPos];
      heap[rightPos] = heap[n];
      heap[n] = temp;
      n = rightPos;
    }else{
      HuffNode* temp = heap[leftPos];
      heap[leftPos] = heap[n];
      heap[n] = temp;
      n = leftPos;
    }
    leftPos = 2 * n + 1;
    rightPos = 2 * n + 2;
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

