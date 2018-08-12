/** Meet in the middle
 * Given a set of n integers where n <= 40. Each of them is at most 1012, 
 * determine the maximum sum subset having sum less than or equal S where S <= 1018.
 * 
 * Input  : set[] = {45, 34, 4, 12, 5, 2} and S = 42
 * Output : 41
 * Maximum possible subset sum is 41 which can be 
 * obtained by summing 34, 5 and 2.
 * 
 * Final complexy is O((2^(n / 2)) * n).
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void meetinthemiddleHelper(int, int, int[], ll[]);
ll meetinthemiddle(int, int[], ll);

void meetinthemiddleHelper(int c, int n, int arr[], ll x[]){
    for(int z = 0; z < (1 << n); z++){
        ll sum = 0;
        for(int i = 0; i < n; i++) if(z & (1 << i)) sum += arr[c + i];
        x[z] = sum;
    }
}

ll meetinthemiddle(int n, int arr[], ll s){
    int a_size = (1 << (n / 2)), b_size = (1 << (n - (n / 2)));
    ll a[a_size], b[b_size], ans = 0;
    meetinthemiddleHelper(0, (n / 2), arr, a);
    meetinthemiddleHelper((n / 2), (n - (n / 2)), arr, b);
    sort(b, b + b_size);
    for(int i = 0; i < a_size; i++){
        if(a[i] > s) continue;
        int p = lower_bound(b, b + b_size, (s - a[i])) - b;
        if(p == b_size or b[p] != (s - a[i])) p--;
        ans = max(ans, a[i] + b[p]);
    }
    return ans;
}

int main(){
    int n;
    ll s;
    scanf("%d %lld", &n, &s);
    int num[n];
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    printf("%lld\n", meetinthemiddle(n, num, s));
    return 0;
}