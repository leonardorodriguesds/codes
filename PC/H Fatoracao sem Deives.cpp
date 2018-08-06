#include <bits/stdc++.h>
using namespace std;

void factor(int n){
  	for(int p = 2; p*p <= n; p++){
	    if(n % p == 0){
	    	printf("%d ", p);
	      	while(n % p == 0)
	      		n /= p;
	    }
  	}
  	if(n > 1) 
  		printf("%d ", n);
}

int main(){
	int i, j, q, num;
	scanf("%d", &q);
	vector<int> query;
	for(i = 0; i < q; i++){
		scanf("%d", &num);
		factor(num);
		printf("\n");
	}
	return 0;
}