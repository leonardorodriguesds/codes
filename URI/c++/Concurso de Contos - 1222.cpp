#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream cin("input.txt");
	//ofstream cout("output.txt");
	unsigned int n, l, c, i, characters = 0, line = 0, page = 0, result = 0;
	string word;
	while(cin >> n >> l >> c){
		for(i = 0; i < n; i++){
			cin >> word;
			characters = word.size();
			if(line + characters + 1 >= c - 1 && line + characters + 1 <= c){
				page++;
				line = 0;
			} else {
				if(line + characters + 1 < c)
					line += characters + 1;
				else{
					page++;
					line = 0;
				}
			}
			if(page >= l){
				result++;
				page = 0;
			}
		}
		result += (result == 0? 1: 0);
		cout << result << endl;
	}
	return 0;
}
