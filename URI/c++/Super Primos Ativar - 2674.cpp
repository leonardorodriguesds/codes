#include <iostream>
#include <cmath>
using namespace std;

int is_prime(int);
int super_prime(int);
int is_prime(int num){
	if(num == 0 || num == 1)
		return 0;
	if(num == 2 || num == 3)
		return 1;
	int half, i;
	half = sqrt(num);
	for(i = 2; i <= half; i++){
		if(!(num % i))
			return 0;
	}
	return 1;
}
int super_prime(int number){
	if(!is_prime(number))
		return 0;
	int digit;
	while(number){
		digit = number % 10;
		number /= 10;
		if(!is_prime(digit))
			return 1;
	}
	return 2;
}

int main(){
	int number, result;
	while(cin >> number){
		result = super_prime(number);
		switch(result){
			case 1:
				cout << "Primo" << endl;
				break;
			case 2:
				cout << "Super" << endl;
				break;
			default:
				cout << "Nada" << endl;
		}
	}
	return 0;
}
