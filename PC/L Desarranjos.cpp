#include <bits/stdc++.h>
using namespace std;
int n;
long long table[1000001];

long long calc(int n){
    if(n < 2)
        return (n == 1)? 0 : 1;
    if(table[n] == -1)
        table[n] = ((n - 1) * ((calc(n - 1) ) + calc(n - 2)) % 1000000007);
    return table[n];
}

int main(){
    memset(table, -1, sizeof(table));
    scanf("%d", &n);
    printf("%lld\n", calc(n));
    return 0;
}