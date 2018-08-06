#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	vector<string> inputs;
	string read;
	while (1){
		getline(cin, read);
		if(!read.compare("0 0"))
			break;
		inputs.push_back(read);
	}
	int n, m, x, y, z, i;
	while(inputs.size()){
		sscanf(inputs[0].c_str(), "%d %d", &n, &m);
		string boxes;
		sscanf(inputs[1].c_str(), "%d %d %d", &x, &y, &z);
		for(i = 2; i < m + 2; i++){
			char buffer[20];
			size_t length = inputs[i].copy(buffer, inputs[i].size(), 0);
			buffer[length] = '\0';
		}
	}
	return 0;
}
