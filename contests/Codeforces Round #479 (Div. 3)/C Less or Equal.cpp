#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, k, i;
    scanf("%lld %lld", &n, &k);
    vector<long long int> numbers(n, 0);
    for(i = 0; i < n; i++)
        scanf("%lld", &numbers[i]);
    sort(numbers.begin(), numbers.end());
    vector<long long int>::iterator down;
    down = lower_bound(numbers.begin(), numbers.end(), numbers[k]);
    printf("%lld\n", (down - numbers.begin() == k)? numbers[k] - 1 : -1);
    return 0;
}