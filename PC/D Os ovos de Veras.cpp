#include <bits/stdc++.h>
using namespace std;

vector<int> dividers(int n, int limit){
	int i;
	vector<int> ans;
	for(i = 1; i * i <= n; i++){
		if(!(n % i)){
			if(i < limit)
				ans.push_back(i);
			if(i != n / i && n / i < limit) ans.push_back(n / i);
		}
	}
	return ans;
}

int main(){
	int m, n, i, y, x, size, z, ans;
	scanf("%d %d", &m, &n);
	vector<int> friends(n + 1, -1);
	for(i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		ans = 0;
		vector<int> div = dividers(x, n + 1);
		size = div.size();
		for(z = 0; z < size; z++)
			if(i - friends[div[z] - 1] > y){
				ans++;
				friends[div[z] - 1] = i;
			}
		printf("%d\n", ans);
	}
	return 0;
}
