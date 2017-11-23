// code produced by Martin Siddons.

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iomanip>

using namespace std;

void rollDice(vector<int> &r)
{
	int a;
	for (int i = 1; i <= 360000; i++) // generate 360000 throws of 2 dice.
	{
		a = (rand() % 6 + 1) + (rand() % 6 + 1); // generate a random number between 1-6 and add it to another random number from the same range, then assign that to 'a'.
		for (int c = 2; c <= 12; c++) // loop which checks a (c)ounter and adds that result to the correct spot. We won't bother writing to cells 0 or 1 to make it easier to reference.
			if (a == c)
				r[c]++;
	}
}

int main()
{
	vector<int> rolls(13); // initialise the vector with 13 elements since that's all we'll need.
	srand(time(0));
	rollDice(rolls);
	for (int i = 2; i <= 12; i++) // loop which iterates through numbers 2-12 to print the row numbers.
	{
		cout << setw(2) << setfill(' ') << i << ":  "; // print the line up until the stars.
		cout << setw(lrint(rolls[i] / 10000.0) + 1) << setfill('*') << " " << endl; // cleverly fill each row of stars using setw rather than another for loop.
	}

	return 0;
}