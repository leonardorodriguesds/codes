#include <bits/stdc++.h>
using namespace std;
#define upper_bound 1000000
vector<int> is_prime(upper_bound + 1, 1);

int divisors(long long n){	
	long long left, right, middle, tmp;
	left = 0;
	right = upper_bound;
	while(left <= right){
		middle = (left + right) / 2;
		tmp = middle * middle;
		if(tmp > n)
			right = middle - 1;
		else if(tmp < n)
			left = middle + 1;
		else
			return is_prime[middle];
	}
	return 0;
}

int main(){
	int i, z, q;
	is_prime[0] = 0;
	is_prime[1] = 0;
	for(i = 2; i * i < upper_bound; i++)
		if(is_prime[i] == 1){
			for(z = i * i; z < upper_bound; z += i)
				is_prime[z] = 0;
		}

    long long num;
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%lld", &num);
        printf("%d\n", (num == 1)? 0 : (divisors(num)));
    }
    return 0;
}