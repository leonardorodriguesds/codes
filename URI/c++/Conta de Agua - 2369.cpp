#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream cin("input_2.txt");
	//ofstream cout("output.txt");
	int n, price;
	while(cin >> n){
		price = 7;
		n -= 10;
		price += (n > 0? (n > 20? 20 : n) : 0);
		n -= (n > 20? 20 : n);
		price += (n > 0? (n > 70? 140 : n * 2) : 0);
		n -= (n > 70? 70 : n);
		price += (n > 0? n * 5 : 0);
		cout << price << endl;
	}
	return 0;
}
