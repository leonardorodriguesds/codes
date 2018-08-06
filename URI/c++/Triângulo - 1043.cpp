#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	float A, B, C;
	cin >> A >> B >> C;
	float P = A + B + C;
	cout << setprecision(1) << fixed;
	if(abs(B - C) <= A && A <= (B + C) && abs(A - C) <= B && B <= (A + C) && abs(A - B) <= C && C <= (A + B)){
		P /= 2;
		float area = sqrt(P * (P - A) * (P - B) * (P - C));
		cout << "Area = " << area << endl;
	} else {
		cout << "Perimetro = " << P << endl;
	}
	return 0;
}
