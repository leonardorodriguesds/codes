#include <bits/stdc++.h>
using namespace std;

int main(){
	int num, i, total = 0, bigger = 0, *money;
	scanf("%d", &num);
	money = new int[num];
	for(i = 0; i < num; i++){
		scanf("%d", &money[i]);
		if(money[i] > bigger)
			bigger = money[i];
	}
	for(i = 0; i < num; i++){
		total += (bigger - money[i]);
	}
	printf("%d\n", total);
	delete [] money;
	return 0;
}
