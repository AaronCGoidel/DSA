/* Huff Node.h
 * 2019
 */
#ifndef HUFFNODE_H
#define HUFFNODE_H
#include <string>

using namespace std;

class HuffNode{
  
private:
  char letter;
  int count;
  HuffNode* left;
  HuffNode* right;

 public:
  explicit HuffNode(char c, int i);
  explicit HuffNode();
  explicit HuffNode(HuffNode* l, HuffNode* r);
  int getCount() const;
  char getChar();
  bool isLeaf();
  HuffNode* getLeft();
  HuffNode* getRight();
  void display();
  string toString(int tab);
  bool operator<(HuffNode other);
  bool operator<=(HuffNode other);
  bool operator>(HuffNode other);

}; 
#endif
  
