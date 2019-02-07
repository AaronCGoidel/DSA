/* Huff Node.h
 * 2019
 */
#ifndef HUFFNODE_H
#define HUFFNODE_H

using namespace std;

class HuffNode{
  
private:
  char letter;
  int count;
  HuffNode* left;
  HuffNode* right;

 public:
  explicit HuffNode(char c, int i);
  explicit HuffNode(HuffNode* l, HuffNode* r);
  int getCount() const;
  char getChar();
  HuffNode* getLeft();
  HuffNode* getRight();
  void display();
}; 
#endif
  
