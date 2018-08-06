#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream cin("input_2.txt");
	ofstream cout("output.txt");
	string line;
	string keyboard("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./");
	int i, j, c, size = keyboard.size();
	while(getline(cin, line)){
		c = line.size();
		for(i = 0; i < c; i++){
			if(line[i] != ' '){
				for(j = 0; j < size; j++){
					if(line[i] == keyboard[j]){
						line[i] = keyboard[j - 1];
						break;
					}
				}
			}
		}
		cout << line << endl;
		line.clear();
	}
	return 0;
}
