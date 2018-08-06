#include <iostream>
using namespace std;

int main(){
	int N, i, Pa, Pb, years;
	double Ca, Cb;
	cin >> N;
	for(i = 0; i < N; i++){
		years = 0;
		cin >> Pa >> Pb >> Ca >> Cb;
		Ca /= 100.0;
		Cb /= 100.0;
		while(Pa <= Pb && years < 101){
			Pa += Pa * Ca;
			Pb += Pb * Cb;
			years++;
		}
		if(years < 101)
			cout << years << " anos." << endl;
		else
			cout << "Mais de 1 seculo." << endl;
	}
}
