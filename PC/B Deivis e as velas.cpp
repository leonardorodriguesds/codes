#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k, total = 0;
	scanf("%d %d", &n, &k);
	total += n;
	while(n >= k){
		total += 1;
		n -= k - 1;
	}
	printf("%d\n", total);
	return 0;
}
