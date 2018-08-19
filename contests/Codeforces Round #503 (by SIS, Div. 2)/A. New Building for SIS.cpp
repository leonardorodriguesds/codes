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
#define uIndex(x, v)    (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)    (lower_bound(all(v), x) - v.begin())
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int main(){
    int n, h, a, b, k;
    scanf("%d %d %d %d %d", &n, &h, &a, &b, &k);
    for(int i = 0; i < k; i++){
        int ta, fa, tb, fb;
        scanf("%d %d %d %d", &ta, &fa, &tb, &fb);
        int ans = (fa >= a and fa <= b)? 0 : (min(abs(fa - a), abs(fa - b)));
        fa = (fa >= a and fa <= b)? fa : abs(fa - a) < abs(fb - b)? a : b;
        ans = ans + abs(ta - tb) + abs(fa - fb);
        printf("%d\n", ans);
    }
    return 0;
}