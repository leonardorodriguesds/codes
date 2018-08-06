#include <bits/stdc++.h>
using namespace std;
#define upper_bound 1000004
vector<int> is_prime(upper_bound, 1);
int main(){
	int i, z, q, l, r, num, left, right, ans, middle;
	is_prime[0] = 0;
	is_prime[1] = 1;
	for(i = 2; i * i < upper_bound; i++)
		if(is_prime[i] == 1){
			for(z = i * i; z < upper_bound; z += i)
				is_prime[z] = 0;
		}

    for(i = 1; i < upper_bound; i++)
        is_prime[i] += is_prime[i - 1];

	scanf("%d", &q);
	for(i = 0; i < q; i++){
		scanf("%d", &num);
		left = num;
		right = upper_bound - 1;
		ans = 0;
		while(left <= right){
			middle = (left + right) / 2;
			if(is_prime[middle] - is_prime[num - 1] > 0){
				ans = middle;
				right = middle - 1;
			} else
				left = middle + 1;
		}

		printf("%d\n", ans);
	}
	return 0;
}
