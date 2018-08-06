#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long int num){
    long long int n;
    if(num == 0 || num == 1 || num == 2)
        return false;
    for(n = 2; n * n <= num; n++){
        if(num % n == 0)
            return false;
    }
    return true;
}

int main(){
	long long int num;
	scanf("%lld", &num);
    while(!is_prime(num))
        num++;
	printf("%lld\n", num);
	return 0;
}
