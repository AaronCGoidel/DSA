/*
 * 1.cpp
 * Author: Aaron Goidel
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num){
	if(num <= 1) return false;

	for(int divisor = 2; divisor < round(sqrt(num))+1; divisor++){
		if(num % divisor == 0) return false;
	}
	return true;
}

int modPow(int base, int power, int p){
	int solution = 1;
	while(power > 0){
		if(power%2 != 0){
			solution = (solution * base)%p;
		}
		power /= 2;
		base = (base * base)%p;
	}
	return solution;
}

bool isGenerator(int m, vector<int>& arr, int p){
	for(int i = 0; i < arr.size()-1; i++){
		if(modPow(m, arr[i], p) == 1){
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
	
	for(int i = 1; i < prime; i++){
		intsModP.push_back(i);
	}

	for(int i = 0; i < intsModP.size(); i++){
		int current = intsModP[i];
		if(isGenerator(current, intsModP, prime)){
			generators.push_back(current);
		}
	}
	
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
