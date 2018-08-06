#include <bits/stdc++.h>
using namespace std;

int main(){
	int num, n, i, count = 0, divisions;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &num);
		divisions = 0;
		while(!(num & 1) && !i || !(num & 1) && (i && divisions < count)){
			num = num >> 1;
			divisions++;
		}
		count = divisions;
		if(!count)
			break;
	}
	printf("%d\n", count);
	return 0;
}
