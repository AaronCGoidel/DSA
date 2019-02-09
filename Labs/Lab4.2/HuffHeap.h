/* HuffHeap.h
 * 2019
 */

#ifndef HUFFHEAP_H
#define HUFFHEAP_H

#include <vector>
#include <string>
#include "HuffNode.h"

using namespace std;
// this class is used to build the trie

class HuffHeap{
 private:
 public:
  vector<HuffNode* > heap;
  int getSize();
  explicit HuffHeap();
  void insert(HuffNode* node);
  HuffNode* remove();
  char peakMin();
  HuffNode* get();
  void display();
};
#endif
