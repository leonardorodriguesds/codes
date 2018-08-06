#include <iostream>
using namespace std;

void encrypt(string, char*, unsigned int);
int main(){
	string str;
	char result[13];
	int N, i;
	cin >> N;
	getline(cin, str);
	for(i = 0; i < N; i++){
		getline(cin, str);
		encrypt(str, result, 12);
		cout << result << endl;
	}
	return 0;
}

void encrypt(string pass, char* result, unsigned int num){
	string decrypted = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	string encrypted = "0123456789012345678901234568752309146875230914687623";
	unsigned int j, i = 0;
	size_t aux = 0;
	for(j = 0; j < pass.length(); j++){
		if(i == num)
			break;
		if(pass[j] == ' '){
			continue;
		}
		aux = decrypted.find(pass[j]);
		result[i] = encrypted[aux];
		i++;
	}
	result[i] = '\0';
}
