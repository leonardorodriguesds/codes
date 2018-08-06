#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream cin("input_2.txt");
	ofstream cout("output.txt");
	int n, num, i, z, j;
	string options = ("**ABCDE");
	while(cin >> n){
		if(n == 0)
			break;
		for(i = 0; i < n; i++){
			j = 0;
			for(z = 0; z < 5; z++){
				cin >> num;
				if(num >= 0 && num <= 127){
					if(j == 0)
						j = z + 2;
					else{
						j = 1;
					}
				}
			}
			cout << options[j] << endl;
		}
	}
	return 0;
}
