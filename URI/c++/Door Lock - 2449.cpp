#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, i, add, ans = 0;
	scanf("%d %d", &n, &m);
	int pins[n];
	for(i = 0; i < n; i++)
		scanf("%d", &pins[i]);
	for(i = 1; i < n; i++){
		if(pins[i - 1] == m)
			continue;
		add = min(m - pins[i - 1], m - pins[i]);
		pins[i - 1] += add;
		pins[i] += add;
		ans += add >= 0? add : -add;
	}
	printf("%d\n", ans);
	return 0;
}
