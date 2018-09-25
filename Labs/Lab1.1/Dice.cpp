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

	while(a > 0 && b > 0){ // keep going until someone loses
		int turn = d.roll() + d.roll();
		cout << "Player #1 rolled: " << turn << "\n";

		if(turn == 7 || turn == 11){ // did they roll a 7 or 11
			a += 3; // reward
		}else{
			a--;
		}

		cout << "Player #1 now has: $" << a << "\n"; // print player 1 balance

    // time for player 2's turn
		turn = d.roll() + d.roll();
		cout << "Player #2 rolled: " << turn << "\n";

		if(turn == 7 || turn == 11){
			b += 3;
		}else{
			b--;
		}
		cout << "Player #2 now has: $" << b << "\n";
	}
  // a fun little ternary to print which player wins
	cout << "Player #" << (b <= 0 ? "1" : "2") << " wins." << "\n";
	return 0;
}