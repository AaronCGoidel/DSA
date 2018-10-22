#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

using namespace std;
// O(n)
bool one(int num){
  if(num <= 1) return false;
  if(num == 2 || num == 3) return true;
  
  for(int i = 2; i < num; i++){
    if(num % i == 0) return false;
  }
  return true;
}

// O(sqrt(n))
bool two(int num){
  if(num <= 1) return false;
  if(num == 2) return true;
  if(num % 2 == 0) return false;

  for(int i = 3; (i * i) <= num; i += 2){
    if(num % i == 0) return false;
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

bool miller(int d, int n) { 
  int a = 2 + rand() % (n - 4); 
  int x = modPow(a, d, n); 
  
  if(x == 1 || x == n - 1) return true; 

  while(d != n - 1){ 
    x = (x * x) % n; 
    d = d * 2; 
  
    if(x == 1) return false; 
    if(x == n - 1) return true; 
  } 
  return false; 
} 

// O(k log^3 n)
// for simplicity k = 5 in this assignment
bool three(int n){ 
  srand(time(NULL));

  if (n <= 1 || n == 4) return false; 
  if (n <= 3) return true; 
  
  int d = n - 1; 
  while(d % 2 == 0){
    d /= 2; 
  }

  for (int i = 0; i < 5; i++){
    if(!miller(d, n)) return false; 
  }
  return true; 
} 