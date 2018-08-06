#include <iostream>
using namespace std;

int main() {
    float numbers[3];
    int i, j, temp;
    for(i = 0; i < 3; i++){
    	cin >> numbers[i];
    }
    for(i = 0; i < 3; i++)
	{		
		for(j = i + 1; j < 3; j++)
		{
			if(numbers[i] < numbers[j])
			{
				temp  = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
	if(numbers[0] >= numbers[1] + numbers[2]){
		cout << "NAO FORMA TRIANGULO" << endl;
	} else {
		if(numbers[0] * numbers[0] == numbers[1] * numbers[1] + numbers[2] * numbers[2]){
			cout << "TRIANGULO RETANGULO" << endl;
		}
		if(numbers[0] * numbers[0] > numbers[1] * numbers[1] + numbers[2] * numbers[2]){
			cout << "TRIANGULO OBTUSANGULO" << endl;
		}
		if(numbers[0] * numbers[0] < numbers[1] * numbers[1] + numbers[2] * numbers[2]){
			cout << "TRIANGULO ACUTANGULO" << endl;
		}
		if(numbers[0] == numbers[1] && numbers[0] == numbers[2]){
			cout << "TRIANGULO EQUILATERO" << endl;
		}
		else if(numbers[0] == numbers[1] || numbers[1] == numbers[2] || numbers[0] == numbers[2]){
			cout << "TRIANGULO ISOSCELES" << endl;
		}
	}
    return 0;
}
