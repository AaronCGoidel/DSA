/*
 * Dice.cpp
 * Author: Aaron Goidel
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

class Die{
	public:
  	int roll(){
    	return (rand()%6) + 1; // random number between 1 and 6
  	}
};

int main(){
	srand(time(NULL));
	Die d;

	// starting amounts of money
	int a, b;
	a = b = 100;

	while(a > 0 && b > 0){
		int turn = d.roll() + d.roll();
		cout << "Player #1 rolled: " << turn << "\n";

		if(turn == 7 || turn == 11){
			a += 3;
		}else{
			a--;
		}

		cout << "Player #1 now has: $" << a << "\n";

		turn = d.roll() + d.roll();
		cout << "Player #2 rolled: " << turn << "\n";

		if(turn == 7 || turn == 11){
			b += 3;
		}else{
			b--;
		}
		cout << "Player #2 now has: $" << b << "\n";
	}
	cout << "Player #" << (b <= 0 ? "1" : "2") << " wins." << "\n";
	return 0;
}