#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

using namespace std;
bool one(int num){
  if(num <= 1) return false;
  if(num == 2 || num == 3) return true;
  
  for(int i = 2; i < num; i++){
    if(num % i == 0) return false;
  }
  return true;
}

bool two(int num){
  if(num <= 1) return false;
  if(num <= 3) return true;
  if(num % 2 == 0 || num % 3 == 0) return false;

  for(int i = 5; i <= floor(sqrt(num)); i += 6){
    if(num % i == 0 || num % (i + 2) == 0) return false;
  }
  return true;
}

int modPow(int base, int power, int p){
	int solution = 1;
	while(power > 0){ 
		if(power%2 != 0){
			solution = ((long)solution * (long)base)%p;
		}
		power /= 2;
		base = ((long)base * (long)base)%p;
	}
	return solution;
}

bool three(int num){
  srand(time(NULL));

  if(num == 1) return false;
  
  int iters = 5;
  for(int i = 0; i < iters; i++){
    int a = rand()%(num - 1) + 1;
    
    if(modPow(a, num - 1, num) != 1) return false;
  }
  return true;
}