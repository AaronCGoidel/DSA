/* Huff Node
 * 2019
 * Huffman Encoding 
 */


#include <iostream>
#include "HuffNode.h"

using namespace std;

HuffNode::HuffNode(char c, int i) {
  letter = c;
  count = i;
}

HuffNode::HuffNode(HuffNode* l, HuffNode* r) {
  left = l;
  right = r;
  count = left->getCount() + right->getCount();
  letter = '*';
}

int HuffNode::getCount()const { return count; }

char HuffNode::getChar(){ return letter; }

HuffNode* HuffNode::getLeft(){ return left;}

HuffNode* HuffNode::getRight(){ return right; }

void HuffNode::display(){
  cout << letter << ": " << count << endl;
  if (letter != '*'){ return; }
  if (left != nullptr) {
    cout<< '\t'; left->display();
  }
  if (right != nullptr){
    cout << '\t'; right->display();
  }
}
