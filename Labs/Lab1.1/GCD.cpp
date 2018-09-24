/*
 * GCD.cpp
 * Author: Aaron Goidel
 */

#include <iostream>
using namespace std;

int euclid(int a, int b){
	return (b == 0) ? a : euclid(b, a%b);
	// ok I know the thing above is hard to read
	// if(b == 0){
	// 	return a;
	// }else{
	// 	return euclid(b, a%b);
	// }
}

int main(){
	int a, b;
	cout << "Enter your first integer" << "\n" << "> ";
	cin >> a;

	while(a < 1){ // validate input and re-prompt as needed
		cout << "The number must be greater than 1" << "\n";
		cout << "Enter a number" << "\n" << "> ";
		cin >> a;
	}

	cout << "Enter your second integer" << "\n" << "> ";
	cin >> b;

	while(b < 1){
		cout << "The number must be greater than 1" << "\n";
		cout << "Enter a number" << "\n" << "> ";
		cin >> b;
	}

	cout << "The greatest common divisor of " << a << " and " << b << " is: "
	 << euclid(a, b) << "\n";
}