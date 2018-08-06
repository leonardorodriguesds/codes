#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream cin("input.txt");
	unsigned int num, last = 0;
	while(cin >> num){
		if(num <= last)
			break;
		else
			last = num;
	}
	cout << last + 1 << endl;
	return 0;
}
