#include <bits/stdc++.h>
using namespace std;

int main(){
	long int o, q, i, ans;
	long long n, left, right, middle, pi, amount;
	scanf("%lld %ld %d", &n, &o, &q);
	vector<long long int> production(o + 1, 0);
	production[0] = 0;
	for(i = 1; i <= o; i++){
		scanf("%lld", &production[i]);
		production[i] += production[i - 1];
	}
	for(i = 0; i < q; i++){
		cin >> pi; 
		ans = -1;
		left = 0;
		right = o;
		while(left <= right){
			middle = (left + right) / 2;
			amount = n + production[middle] - pi;
			if(amount < 0)
				left = middle + 1;
			else{
				ans = middle;
				right = middle - 1;
			}
		}
		printf("%ld\n", ans);
	}
}