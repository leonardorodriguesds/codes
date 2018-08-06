#include <bits/stdc++.h>
using namespace std;

int check(long long, long long);
long long calc(long long);

int check(long long num, long long result){
    long long s = ((num * (num + 1)) / 2);
    if(s >= result) 
        return 1;
    else if(s < result)
        return -1;
}

long long calc(long long num){
    long long middle, left, right, ans;
    int result;
    left = 1;
    right = 2e9;
    while(left <= right){
        middle = (left + right) / 2;
        result = check(middle, num);
        if(result > 0){
            ans = middle;
            right = middle - 1;
        } else if(result < 0)
            left = middle + 1;
    }
    return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	long long x, y;
	while(t--){
		scanf("%lld %lld", &y, &x);
        if(x < y){
		    y -= x;
		    printf("%lld\n", (x + calc(y)));
        } else 
            printf("%lld\n", y);
	}
  	return 0;
}
