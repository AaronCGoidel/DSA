/* HuffHeap
 * 2019
 */

#include <iostream>
#include "HuffHeap.h"
#include "HuffNode.h"
#include <vector>

using namespace std;


HuffHeap::HuffHeap(){
  size = 0;
  vector<HuffNode* > heap;
}

void HuffHeap::insert(HuffNode* node){
  heap.push_back(node);
  size++;

  int index = size - 1;
  while(index > 0 && heap[(index-1)/2] < heap[index]){
    HuffNode* temp = heap[(index-1)/2];
    heap[(index-1)/2] = heap[index];
    heap[index] = temp;
    index = (index - 1)/2;
  }
}

HuffNode* HuffHeap::remove(){
  HuffNode* root = heap[0];
  heap[0] = heap[size-1];

  int n = 0;
  int leftPos = 2 * n + 1;
  int rightPos = 2 * n + 2;

  while((size > leftPos && heap[n] < heap[leftPos]) ||
        (size > rightPos && heap[n] < heap[rightPos])){
    if(heap[rightPos] > heap[leftPos]){
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
  }

  size--;
  heap.pop_back();
  return root;
}

char HuffHeap::peakMin(){
  return heap[0]->getChar();
}
void HuffHeap::display(){
  for (int i = 0; i < size; i++){
    heap[i] -> display();
  }
}

