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
  return pQueue;
}

HuffNode* makeTrie(HuffHeap* heap){
  // takes the heap and makes it into the tree
  HuffNode* root;
  while(heap->size != 1){
    HuffNode* left = heap->remove();
    HuffNode* right = heap->remove();
    root = new HuffNode(left, right);
    heap->insert(root);
  }
  // cout << "-----" << endl;
  // heap->display();
  return root;
}

void encodeChar(HuffNode* trie, char c){
  // takes in one char and finds its encoding with the trie
} 
string encode(HuffNode* trie, string fileName){
  // takes in the trie and filename and uses encodeChar to encode each char
  // creating a string of 0s and 1s as output
}

int main(){
  makeTrie(makeHeap("tester.txt"));
  // read in the file with input
  // count the characters and make the heap
  // make the trie out of the heap
  // encode the file
  // output the encoded to a file called filename_Encoded.txt
  // output the preorder traversal of the trie to filename_Trie.txt
}
