#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream cin("input_2.txt");
	ofstream cout("output.txt");
	int n, d, i, j, count;
	string *alumni;
	while(cin >> n >> d){
		count = n;
		if(n == 0 && d == 0)
			break;
		alumni = new string[d + 1];
		getline(cin, alumni[0]);
		for(i = 0; i < d; i++){
			getline(cin, alumni[i]);
		}
		for(j = 0; j < n * 2; j++){
			if((j % 2))
				alumni[d] += ' ';
			else
				alumni[d] += '1';
		}
		for(i = 0; i < d; i++){
			for(j = 0; j < n * 2; j++){
				if(alumni[d][j] == '0' || alumni[d][j] == ' ')
					continue;
				if(alumni[i][j] == '0'){
					alumni[d][j] = '0';
					count--;
				}
			}
		}
		if(count)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		delete [] alumni;
	}
	return 0;
}
