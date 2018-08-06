#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
	ifstream cin("input.txt");
	int w, l, r1, r2, sum, bigger, hypotenuse;
	while(cin >> w >> l >> r1 >> r2){
		if(w == 0 && l == 0 && r1 == 0 && r2 == 0)
			break;
		sum = (r1 + r2) * 2;
		bigger = (r1 > r2? r1 : r2);
		if((w < sum && l < sum) || (w < bigger && l < bigger)){
			hypotenuse = sqrt(w * w + l * l) - (sqrt(r1 * r1 * 2) - r1) - (sqrt(r2 * r2 * 2) - r2);
			if(hypotenuse < sum || (w < bigger && l < bigger)){
				cout << "N" << endl;
				continue;
			}
		}
		cout << "S" << endl;
	}
	return 0;
}
