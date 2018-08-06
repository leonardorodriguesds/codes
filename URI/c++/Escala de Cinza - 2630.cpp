#include <iostream>
using namespace std;

int main(){
	int t, i, r, g, b, p = 0;
	string type;
	cin >> t;
	for(i = 0; i < t; i++){
		cin >> type >> r >> g >> b;
		if(!type.compare("eye")){
			p = 0.30*r + 0.59*g + 0.11*b;
		} else if(!type.compare("mean")){
			p = (r + b + g) / 3;
		} else if(!type.compare("max")){
			p = ((r >= g)? ((r >= b)? r : b) : (g >= b? g : b));
		} else if(!type.compare("min")){
			p = ((r <= g)? ((r <= b)? r : b) : (g <= b? g : b));
		}
		cout << "Caso #" << (i + 1) << ": " << p << endl;
	}
	return 0;
}
