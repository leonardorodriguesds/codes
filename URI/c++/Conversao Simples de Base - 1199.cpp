#include <iostream>
#include <fstream>
using namespace std;

void convert(string*, string, int);
void convert(string *result, string num, int base){
	(*result).clear();
	string hexadecimal = "0123456789ABCDEF";
	long int number;
	if(base == 10)
		number = stoi (num, nullptr, 16);
	else
		number = stoi (num, nullptr, 10);
	while(number > 0){
		(*result) += hexadecimal[number % base];
		number /= base;
	}
	if(base == 16){
		(*result) += 'x';
		(*result) += '0';
	}
	*result = string((*result).rbegin(), (*result).rend());
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	string number;
	string num;
	while(cin >> num && num[0] != '-'){
		if(num[1] == 'x')
			convert(&number, num, 10);
		else
			convert(&number, num, 16);
		
		cout << number << endl;
	}
	return 0;
}
