/* Huffman Encoding
 * 2019
 * Starter Code
 */

#include "HuffNode.h"
#include "HuffHeap.h"

#include <iostream>
#include <fstream>
#include <map> 
using namespace std;

map<char, uint32_t> counts;


HuffHeap* makeHeap(string fileName){
  //takes in a file name, counts the characters and creates the heap
  //consider making a helper file to count all characters
  //and then puts them all into a heap

  // count number of times each character appears
  ifstream is(fileName);
  char c;
  while(is.get(c)){
    counts[c]++;
  }
  is.close();

  // make heap
  HuffHeap* pQueue = new HuffHeap();
  
  map<char, uint32_t>::iterator iter;
  for(iter = counts.begin(); iter != counts.end(); iter++){
    HuffNode* node = new HuffNode(iter->first, iter->second);
    pQueue->insert(node);
  }
  // pQueue->display();
  for(int i = 0; i < 8; i++){
    cout << pQueue->remove()->getChar() << endl;
  }
  return pQueue;
}

HuffNode* makeTrie(HuffHeap* heap){
  // takes the heap and makes it into the tree
  HuffNode* root = NULL;
  while(heap->getSize() != 1){
    HuffNode* left = heap->remove();
    HuffNode* right = heap->remove();
    root = new HuffNode(left, right);
    heap->insert(root);
  }

  heap->display();
  return root;
}

string lookup(HuffNode* root, char c, string prevCode, string direction){
  string currentCode = prevCode + direction;
  if(!root->isLeaf()){
    currentCode = lookup(root->getLeft(), c, currentCode, "0");
    currentCode = lookup(root->getRight(), c, currentCode, "1");
  }else{
    if(root->getChar() == c){
      return currentCode;
    }else{
      return prevCode;
    }
  }

  return currentCode;
}

string encodeChar(HuffNode* trie, char c){
  // takes in one char and finds its encoding with the trie
  return lookup(trie, c, "", "");
} 
string encode(HuffNode* trie, string fileName){
  // takes in the trie and filename and uses encodeChar to encode each char
  // creating a string of 0s and 1s as output
  string out = "";
  ifstream is(fileName);
  char c;
  while(is.get(c)){
    out += encodeChar(trie, c);
  }
  is.close();
  return out;
}

int main(){
  string file = "HuffTest2.txt";
  makeHeap(file);
  // HuffNode* trie = makeTrie(makeHeap(file));
  // cout << encode(trie, file) << endl;
}
