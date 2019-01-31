#include <iostream>
#include<vector>
#include "sosHelper.h"
#include "Sorting.h"

int main(int argc, char const* argv[]){
  if(argc != 3){
    std::cerr << "Usage: " << argv[0] 
      << " input.txt output.csv" << std::endl;
    return 1;
  }
  std::vector<double> times;
  std::vector<std::vector<int> > arrs = getArrays(argv[1]);

  for(int arrNum = 0; arrNum < arrs.size(); arrNum++){
    std::vector<int> a = arrs[arrNum];
    times.push_back(measureTime(bubble, a));
    a = arrs[arrNum];
    times.push_back(measureTime(insert, a));
    a = arrs[arrNum];
    times.push_back(measureTime(select, a));
    a = arrs[arrNum];
    times.push_back(measureTime(mergesort, a));
    a = arrs[arrNum];
    times.push_back(measureTime(heap, a));
    a = arrs[arrNum];
    times.push_back(measureTime(shell, a));
    a = arrs[arrNum];
    times.push_back(measureTime(count, a));
    a = arrs[arrNum];
    times.push_back(measureTime(bucket, a));
    output(times, argv[2]);
    times.clear();
  }
}

