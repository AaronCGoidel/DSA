#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <iostream>
#include <stdlib.h>


// HELPERS
void print(std::vector<int> &nums);
void random(std::vector<int> &nums);
void swap(std::vector<int> &vec);
bool isSorted(std::vector<int> &vec);

// SORTING ALGORITHMS
void bubble(std::vector<int> &nums);
void insert(std::vector<int> &nums);
void select(std::vector<int> &nums);
void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &origin);
void mergesort(std::vector<int> &nums);
void shell(std::vector<int> &nums);
void makeHeap(std::vector<int> &nums, int size, int root);
void heap(std::vector<int> &nums);
void count(std::vector<int> &nums);
void bucket(std::vector<int> &nums);


#endif