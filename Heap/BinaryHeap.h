/* DSA Fall 2018
 * Binary Heap
 */
#ifndef BINARYHEAP_H
#define BINARYHEAP_H


#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

template <typename Comparable>
class BinaryHeap{
 private:
  vector<Comparable> array;
  int size;

  bool removeHelper(int n){
    bool left = size > 2 * n + 1 && array[n] < array[2 * n + 1];
    bool right = size > 2 * n + 1 && array[n] < array[2 * n + 1];
    return left || right;
  }

 public:
  
  //constructor
  explicit BinaryHeap<Comparable> (){ vector<Comparable> array; size = 0; }
  
  //insert
  void printHeap(){
    for(int i = 0; i < size; i++)
      cout << array[i] << " ";
    cout << endl;
  }
  void insert(Comparable elt){
    array.push_back(elt);
    size++;
    
    int n = size - 1;
    //check its parents
    while(n > 0 && array[(n-1)/2] < array[n]){
      //swap
      Comparable temp = array[(n-1)/2];
      array[(n-1)/2] = array[n];
      array[n] = temp;
      n = (n-1)/2;
    }
  }

  Comparable remove(){
    Comparable elt = array[0];
    array[0] = array[size - 1];

    int n = 0;
    while(removeHelper(n)){
      if(array[2*n+2] > array[2*n+1]){
	Comparable temp = array[n];
	array[n] = array[2*n+2];
	array[2*n+2] = temp;
	n = 2*n+2;
      }
      else{
        Comparable temp = array[n];
        array[n] = array[2*n+1];
        array[2*n+1] = temp;
	n = 2*n+1;
      }
    }
      
    size--;
    array.pop_back();
    return elt;
 }
 
};

#endif


		
