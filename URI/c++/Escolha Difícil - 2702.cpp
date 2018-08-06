#include <iostream>
using namespace std;

int main(){
	int Ca, Ba, Pa, Cr, Br, Pr;
	cin >> Ca >> Ba >> Pa >> Cr >> Br >> Pr;
	Cr = (Cr - Ca <= 0? 0 : Cr - Ca);
	Br = (Br - Ba <= 0? 0 : Br - Ba);
	Pr = (Pr - Pa <= 0? 0 : Pr - Pa);
	cout << Cr + Br + Pr << endl;
	return 0;
}
