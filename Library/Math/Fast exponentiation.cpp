#include <bits/stdc++.h>
using namespace std;

long long fast_exp(long long base, long long exp){
    if(exp == 0)
        return 1;
    long long aux = fast_exp(base, (exp / 2));
    aux *= aux;
    return ((exp & 1))? base * aux : aux;
}

int main(){
    long long num, exp;
    cin >> num >> exp;
    printf("x: %lld\n", fast_exp(num, exp));
    return 0;
}