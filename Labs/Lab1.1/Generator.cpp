/*
 * Generator.cpp
 * Author: Aaron Goidel
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// fun brute force prime number sieve
bool isPrime(int num){
	if(num <= 1) return false;

	// the only possible factors are [2, sqrt(n)]
	for(int divisor = 2; divisor <= round(sqrt(num)); divisor++){
		if(num % divisor == 0) return false;
	}
	return true;
}

// calculates a power mod a number
// (x^y) mod p
// this allows us to work with much bigger exponents than usual since we take
// only a couple digits at most
int modPow(int base, int power, int p){
	int solution = 1;
	while(power > 0){ // we keep going until we reach a power of 0
		if(power%2 != 0){ // make sure our exponent is even
			solution = (solution * base)%p; // go through an iteration and mod
		}
		power /= 2; // half our exponent
		base = (base * base)%p;
	}
	return solution;
}

// checks if a number is a generator mod p given a set of numbers
bool isGenerator(int m, vector<int>& arr, int p){
	for(int i = 0; i < arr.size() - 1; i++){ // iterate over array
		if(modPow(m, arr[i], p) == 1){ // (m^x) mod p != 1
			return false;
		}
	}
	return true;
}

int main(){
	int prime;
	
	// take input
	cout << "Enter a prime number" << "\n" << "> ";
	cin >> prime;

	while(!isPrime(prime)){ // validate input and re-prompt as needed
		cout << "Your number is composite, try again." << "\n";
		cout << "Enter a prime number" << "\n" << "> ";
		cin >> prime;
	}

	vector<int> generators;
	vector<int> intsModP;
	
	for(int i = 1; i < prime; i++){ // array of the ints mod p
		intsModP.push_back(i);
	}

	for(int i = 0; i < intsModP.size(); i++){
		int current = intsModP[i];
		if(isGenerator(current, intsModP, prime)){ // check if number is generator
			generators.push_back(current); // put it in solutions vector
		}
	}
	
	// start printing results
	int found = generators.size();
	cout << found << " generators found." << "\n";

	if(found > 0){
		for (int i = 0; i < found - 1; i++) {
			cout << generators[i] << ", ";
		}
		cout << generators[found - 1] << "\n";
	}
	return 0;
}
