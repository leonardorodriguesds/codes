#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long ans = 0;
    scanf("%d", &n);
    vector<long long> odd;
    for(int i = 0; i < n; i++){
        long long num;
        scanf("%lld", &num);
        if((num % 2))
            odd.push_back(num);
        else
            ans += num;
    }
    if(!(odd.size() % 2)){
        for(auto num: odd)
            ans += num;
    } else {
        sort(odd.begin(), odd.end(), greater<long long>());
        for(int i = 0; i < odd.size() - 1; i++)
            ans += odd[i];
    }
    printf("%lld\n", ans);
    return 0;
}