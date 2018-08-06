#include <bits/stdc++.h>
using namespace std;
#define upper_bound 1000001
vector<int> is_prime(upper_bound, 1);
int main(){
	int i, z, q, l, r;
	is_prime[0] = 0;
	is_prime[1] = 0;
	for(i = 2; i * i < upper_bound; i++)
		if(is_prime[i] == 1){
			for(z = i * i; z < upper_bound; z += i)
				is_prime[z] = 0;
		}

    for(i = 1; i < upper_bound; i++)
        is_prime[i] += is_prime[i - 1];

	scanf("%d", &q);
	for(i = 0; i < q; i++){
		scanf("%d %d", &l, &r);
		printf("%d\n", (is_prime[r] - is_prime[l - 1]));
	}
	return 0;
}