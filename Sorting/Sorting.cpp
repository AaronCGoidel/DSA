#include <vector>
#include <iostream>

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

std::vector<int> slice(std::vector<int> &parent, int lo, int hi){
  auto start = parent.cbegin() + lo;
  auto end = parent.cbegin() + hi + 1;

  std::vector<int> subvec(start, end);
  return subvec;
}



std::vector<int> merge(std::vector<int> &left, std::vector<int> &right){
  int i = 0;
  int j = 0;
  std::vector<int> merged;

  while(i < left.size() && j < right.size()){
    if(left[i] < right[j]){
      merged.push_back(left[i]);
      i++;
    }else{
      merged.push_back(right[j]);
      j++;
    }
  }
  
  std::vector<int> leftover = i < left.size() ? left : right;

  for(int k = i < left.size() ? i : j; k < leftover.size(); k ++){
    merged.push_back(leftover[k]);
  }

  return merged;
}

std::vector<int> mergesort(std::vector<int> &nums){
  if(nums.size() <= 1){
    return nums;
  }
  std::vector<int> left = mergesort(slice(nums, 0, nums.size()/2));
  std::vector<int> right = mergesort(slice(nums, nums.size()/2, nums.size()));

  merge(left, right);
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

int main(){
  std::vector<int> v;
  v.push_back(1);
  v.push_back(9);
  v.push_back(6);
  v.push_back(0);

  for(int i = 0; i < v.size(); i++){
    std::cout << v[i];
  }
  std::cout << std::endl;

  shell(v);
  for(int i = 0; i < v.size(); i++){
    std::cout << v[i];
  }
  std::cout << std::endl;
}