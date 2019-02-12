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
  left = NULL;
  right = NULL;
}

HuffNode::HuffNode(){
  letter = 0;
  count = 0;
  left = NULL;
  right = NULL;
}

HuffNode::HuffNode(HuffNode* l, HuffNode* r) {
  left = l;
  right = r;
  count = left->getCount() + right->getCount();
  letter = '*';
}

bool HuffNode::operator<(HuffNode other){
  return count < other.count;
}

bool HuffNode::operator<=(HuffNode other){
  return count <= other.count;
}

bool HuffNode::operator>(HuffNode other){
  return count > other.count;
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

bool HuffNode::isLeaf(){
  return (getLeft() == NULL) && (getRight() == NULL);
}

string HuffNode::toString(int tab) {
    std::string out(tab * 2, ' ');
    if (isLeaf()) {
        if (getChar() == '\n') {
            out += "<newline>";
        } else if (getChar() == ' ') {
            out += "<space>";
        } else {
            out += getChar();
        }
        out += ": count=";
        out += to_string(getCount());
        out += "\n";
    } else {
        out += "+ ";
        out += to_string(getCount());
        out += "\n";
        out += left->toString(tab + 1);
        out += right->toString(tab + 1);
    }
    return out;
}
