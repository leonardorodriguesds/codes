#include <iostream>
using namespace std;

int main(){
	int n, cost, *earnings, i, j, z, bigger, profit;
	while(cin >> n){
		profit = 0;
		bigger = 0;
		cin >> cost;
		earnings = new int[n];
		for(i = 0; i < n; i++){
			cin >> earnings[i];
		}
		for(i = 0; i < n; i++){
			profit = 0;
			for(z = 0; z < (n - i); z++){
				profit = 0;
				for(j = i; j <= i + z; j++){
					profit += (earnings[j] - cost);
				}
				if(profit > bigger){
					bigger = profit;
				}
			}
		}
		cout << bigger << endl;
		delete [] earnings;
	}
	return 0;
}
