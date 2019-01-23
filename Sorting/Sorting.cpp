#include <vector>
#include <iostream>
#include <stdlib.h>

void print(std::vector<int> &nums){
  if(nums.size() <= 0) return;
  int i;
  for(i = 0; i < nums.size() - 1; i++){
    std::cout << nums[i] << ", ";
  }
  std::cout << nums[i] << std::endl;
}

void random(std::vector<int> &nums){
  for(int i = 0; i < nums.size(); i++){
    int first = rand() % nums.size();
    int second = rand() % nums.size();
    int temp = nums[first];
    nums[first] = nums [second];
    nums[second] = temp;
  }
}

void bubble(std::vector<int> &nums){
  for(int i = 0; i < nums.size(); i++){
    for(int j = i; j < nums.size(); j++){
      if(nums[i] > nums[j]){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
  }
}

void insert(std::vector<int> &nums){
  for(int i = 0; i < nums.size(); i++){
    for(int j = i; j > 0; j--){
      if(nums[j-1] > nums[j]){
        int temp = nums[j-1];
        nums[j-1] = nums[j];
        nums[j] = temp;
      }
    }

  }
}

void select(std::vector<int> &nums){
  int min;
  for(int i = 0; i < nums.size(); i++){
    min = i;
    for(int j = i + 1; j < nums.size(); j++){
      if(nums[j] < nums[min]){
        min = j;
      }
    }
    int temp = nums[min];
    nums[min] = nums[i];
    nums[i] = temp;
  }
}

void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &origin){
  int i = 0, j = 0, k = 0;

  while(i < left.size() && j < right.size()){
    if(left[i] < right[j]){
      origin[k] = left[i];
      i++;
    }else{
      origin[k] = right[j];
      j++;
    }
    k++;
  }
  
  std::vector<int> leftover = i < left.size() ? left : right;

  for(int l = i < left.size() ? i : j; l < leftover.size(); l++){
    origin[k] = leftover[l];
  }
}
 
void mergesort(std::vector<int> &nums){
  if(nums.size() <= 1) return;

  int mid = nums.size()/2;
  std::vector<int> left;
  std::vector<int> right;

  for(int i = 0; i < mid; i++){
    left.push_back(nums[i]);
  }
  for(int j = 0; j < nums.size() - mid; j++){
    right.push_back(nums[mid + j]);
  }
  mergesort(left);
  mergesort(right);
  merge(left, right, nums);
}

void shell(std::vector<int> &nums){
  int gap = nums.size()/2;

  while(gap > 0){
    for(int i = gap; i < nums.size(); i++){
      int temp = nums[i];
      int j = i;
      while(j >= gap && nums[j - gap] > temp){
        nums[j] = nums[j - gap];
        j -= gap;
      }
      nums[j] = temp;
    }
    gap /= 2;
  }
}

void makeHeap(std::vector<int> &nums, int size, int root){
  int max = root;
  int left = 2*root + 1;
  int right = 2*root + 2;
  if(left < size && nums[left] > nums[max]){
    max = left;
  }
  if(right < size && nums[right] > nums[max]){
    max = right;
  }

  if(max != root){
    int temp = nums[root];
    nums[root] = nums[max];
    nums[max] = temp;
    makeHeap(nums, size, max);
  }
}

void heap(std::vector<int> &nums){
  for(int i = nums.size()/2; i > 0; i--){
    makeHeap(nums, nums.size(), i);
  }

  for(int i = nums.size(); i > 0; i--){
    int temp = nums[0];
    nums[0] = nums[i];
    nums[i] = temp; 

    makeHeap(nums, i, 0);
  }
}

void count(std::vector<int> &nums){
  int max = 0;
  for(int i = 0; i < nums.size(); i++){
    if(nums[i] < 0){
      std::cout << "Can\'t count sort negative numbers" << std::endl;
      return;
    }

    if(nums[i] > max) max = nums[i];
  }
  std::vector<int> counts(max + 1);

  for(int i = 0; i < nums.size(); i++){
    counts[nums[i]]++;
  }

  int j = 0;
  for(int i = 0; i <= max; i++){
    while(counts[i]-- > 0){
      nums[j++] = i;
    }
  }
}

void bucket(std::vector<int> &nums){
  std::vector<int> buckets[10];

  for(int i = 0; i < nums.size(); i++){
    int num = nums[i];
    int key = 0; 
    do{ 
      num /= 10; 
      key++;
    }while(num != 0);

    buckets[key].push_back(nums[i]);
  }

  for(int i = 0; i < 9; i++){
    insert(buckets[i]);
  }

  int originalIndex = 0;
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < buckets[i].size(); j++){
      nums[originalIndex] = buckets[i][j];
      originalIndex++;
    }
  }
}

int main(){
  srand(time(NULL));
  std::vector<int> v;
  v.push_back(24);
  v.push_back(20);
  v.push_back(2);
  v.push_back(39);
  v.push_back(14);
  v.push_back(6);
  v.push_back(22);
  v.push_back(48);
  v.push_back(20);
  v.push_back(38);
  v.push_back(34);
  v.push_back(9);
  v.push_back(8);
  v.push_back(91);
  v.push_back(7);

  std::cout << "-------BUBBLE SORT-------" << std::endl;
  print(v);
  bubble(v);
  print(v);
  random(v);

  std::cout << "-------INSERTION SORT-------" << std::endl;
  print(v);
  insert(v);
  print(v);
  random(v);

  std::cout << "-------SELECTION SORT-------" << std::endl;
  print(v);
  select(v);
  print(v);
  random(v);

  std::cout << "-------MERGE SORT-------" << std::endl;
  print(v);
  select(v);
  print(v);
  random(v);

  std::cout << "-------SHELL SORT-------" << std::endl;
  print(v);
  shell(v);
  print(v);
  random(v);
  
  std::cout << "-------HEAP SORT-------" << std::endl;
  print(v);
  heap(v);
  print(v);
  random(v);

  std::cout << "-------COUNTING SORT-------" << std::endl;
  print(v);
  count(v);
  print(v);
  random(v);

  std::cout << "-------BUCKET SORT-------" << std::endl;
  print(v);
  bucket(v);
  print(v);
}