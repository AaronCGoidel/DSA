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
  // for(int i = 0; i < pQueue->getSize(); i++){
  //   cout << pQueue->get(i)->getChar() << ", " << pQueue->get(i)->getCount() << endl;
  // }
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

  // heap->display();
  return root;
}

bool lookup(HuffNode* root, char c, string &code, string direction){
  code += direction;
  if(!root->isLeaf()){
    if(lookup(root->getLeft(), c, code, "0")){
      return true;
    }else{
      code.pop_back();
    }
    if(lookup(root->getRight(), c, code, "1")){
      return true;
    }else{
      code.pop_back();
    }
  }else{
    if(root->getChar() == c){
      return true;
    }else{
      return false;
    }
  }
  return false;
}

string encodeChar(HuffNode* trie, char c){
  string code;
  lookup(trie, c, code, "");
  return code;
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

void tester(){
  cout << "------TEST ONE------" << endl;
  string file = "HuffTest1.txt";
  HuffNode* trie = makeTrie(makeHeap(file));
  cout << encode(trie, file) << endl;

  cout << "------TEST TWO------" << endl;
  file = "HuffTest2.txt";
  trie = makeTrie(makeHeap(file));
  cout << encode(trie, file) << endl;

  cout << "------TEST THREE------" << endl;
  file = "HuffTest3.txt";
  trie = makeTrie(makeHeap(file));
  cout << encode(trie, file) << endl;
}

void testfiles(){
  string filename;
  HuffNode* trie;
  ofstream out;

  filename = "HuffTest1.txt";
  trie = makeTrie(makeHeap(filename));
  out.open("Output1.txt");
  out << encode(trie, filename);
  out.close();
 
  filename = "HuffTest2.txt";
  trie = makeTrie(makeHeap(filename));
  out.open("Output2.txt");
  out << encode(trie, filename);
  out.close();

  filename = "HuffTest3.txt";
  trie = makeTrie(makeHeap(filename));
  out.open("Output3.txt");
  out << encode(trie, filename);
  out.close();
}

int main(int argc, char const* argv[]){
  if(argc != 3){
    std::cerr << "Usage: " << argv[0] 
      << " input.txt output.txt" << std::endl;
    return 1;
  }
  HuffNode* trie = makeTrie(makeHeap(argv[1]));
  ofstream output(argv[2]);
  output << encode(trie, argv[1]);
  output.close();

  string treefile = "Tree";
  output.open(treefile + argv[2]);
  output << trie->toString(1);
  output.close();
}