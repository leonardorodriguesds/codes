#include <bits/stdc++.h>
using namespace std;

int lastDigit(long long int A, long long int B){ 
    if (A == B)
	    return 1;
    else if ((B - A) >= 5) 
        return 0; 
    else {
		long long int i;
		int variable = 1;
        for (i = A + 1; i <= B; i++)
            variable = (variable * (i % 10)) % 10; 
        return variable % 10;
    }
}

int main(){
	long long i, a, b;
	int result = 1;
	scanf("%lld %lld", &a, &b);
	printf("%d\n", lastDigit(a, b));
	return 0;
}