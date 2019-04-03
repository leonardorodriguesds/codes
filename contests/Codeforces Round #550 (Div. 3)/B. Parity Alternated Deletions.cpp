#include <bits/stdc++.h>
using namespace std;
#define ALFA            256
#define MOD             1000000007
#define INF             0x3f3f3f3f
#define INFLL           0x3f3f3f3f3f3f3f3f
#define EPS             (1e-9)
#define PI              3.141592653589793238462643383279502884
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b)    (scanf("%d %d", &a, &b))
#define scanf3(a, b, c) (scanf("%d %d %d", &a, &b, &c))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    vi even, odd;
    for(int i = 0; (i < n); i++){
        int aux;
        scanf("%d", &aux);
        ans += aux;
        if ((aux % 2) == 0) even.push_back(aux);
        else odd.push_back(aux);
    }

    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());
    int k = min(even.size(), odd.size());
    ans -= accumulate(even.begin(), even.begin() + k, 0);
    ans -= accumulate(odd.begin(), odd.begin() + k, 0);
    if ((int)odd.size() > k) ans -= odd[k];
    if ((int)even.size() > k) ans -= even[k];

    printf("%d\n", ans);
    return 0;
}