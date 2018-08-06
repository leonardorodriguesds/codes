#include <bits/stdc++.h>
using namespace std;

int main(){
    long long num, ans;
    scanf("%lld", &num);
    if((num % 2))
        ans = -((num / 2) + 1);
    else
        ans = (num / 2);
    printf("%lld\n", ans);
    return 0;
}