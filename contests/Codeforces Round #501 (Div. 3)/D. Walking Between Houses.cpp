#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define SINF            (1e18)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)     (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)     (lower_bound(all(v), x) - v.begin())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int main(){
    ll n, k, s;
    scanf("%lld %lld %lld", &n, &k, &s);
    if((n - 1) * k < s or k > s){
        printf("NO\n");
        return 0;
    }
    vi ans;
    ll xs = s / k, dxs = s % k, x = 1;
    while(k--){
        x += (x + xs + (dxs? 1 : 0)) <= n? (xs + (dxs? 1 : 0)) : -(xs + (dxs? 1 : 0));
        dxs -= dxs > 0? 1 : 0;
        ans.push_back(x);
    }
    printf("YES\n");
    for(int u: ans)
        printf("%d ", u);
    printf("\n");
    return 0;
}