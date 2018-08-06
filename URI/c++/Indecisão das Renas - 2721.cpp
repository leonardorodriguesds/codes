#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int count = 0, num, i;
	for (i = 0; i < 9; i++){
		cin >> num;
		count += num;
	}
	string reindeers[9] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};
	int winner = count % 9;
	winner = (winner - 1 >= 0? winner - 1 : 8);
	cout << reindeers[winner] << endl;
	return 0;
}
