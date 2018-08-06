#include <bits/stdc++.h>
using namespace std;
vector<long long> factorials(1000001, -1);

long long factorial(long long num){
    if(num == 0 or num == 1)
        return 1;
    if(factorials[num] == -1)
        factorials[num] = ((num * factorial(num - 1)) % 1000000007);
    return factorials[num];
}

int main(){
    int q;
    long long x;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%lld", &x);
        printf("%lld\n", factorial(x));
    }
    return 0;
}