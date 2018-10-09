#include <assert.h>
#include <vector>
#include <cmath>
using namespace std;

bool one(int num){
  for(int i = 2; i < round(sqrt(num)); i++){
    if(num % i == 0) return false;
  }
  return true;
}

bool two(int num){
  if(num == 2 || num == 3) return false;
  if(num % 2 == 0 || num % 3 == 0) return false;

  int i = 5;
  int j = 2;

  while(i <= sqrt(num)){
    if(num % i == 0) return false;
    i += j;
    j = 6 - j;
  }
  return true;
}

