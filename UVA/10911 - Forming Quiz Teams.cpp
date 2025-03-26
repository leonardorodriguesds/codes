#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
    #define DEBUG false
#else
    #define DEBUG true
#endif
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA            256
#define MOD             1000000007
#define INF             0x3f3f3f3f
#define INFLL           0x3f3f3f3f3f3f3f3f
#define EPS             (1e-9)
#define PI              3.141592653589793238462643383279502884
#define all(a)          a.begin(), a.end()
// #define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b)    (scanf("%d %d", &a, &b))
#define scanf3(a, b, c) (scanf("%d %d %d", &a, &b, &c))
#define FOR(x,n) for(int x = 0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x = 1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x = int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x = int(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define mset(x, y) memset(&x, (y), sizeof(x))
#define bl "\n"
#define debugarr(arr)   if (DEBUG) { for(auto a: arr) { cout << a << " "; } cout << bl; }
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef vector<pqi> vpqi;

const int MAX_N = 16;
double dp[1 << MAX_N];
ii coords[MAX_N];
int n;

double dist(int i, int j) {
    int dx = coords[i].first - coords[j].first;
    int dy = coords[i].second - coords[j].second;
    return sqrt(dx*dx + dy*dy);
}

double solve(int mask) {
    if (dp[mask] >= 0) return dp[mask];
    if (__builtin_popcount(mask) == 2 * n) return 0;

    double ans = 1e9;
    FOR(i, 2 * n) {
        if (mask & (1 << i)) continue;
        for(int j = i + 1; j < 2 * n; j++) {
            if (mask & (1 << j)) continue;
            int new_mask = mask | (1 << i) | (1 << j);
            ans = min(ans, dist(i, j) + solve(new_mask));
        }
        break;
    }

    return dp[mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    cin >> n;
    FOR(i, 2*n) 
        cin >> coords[i].first >> coords[i].second;

    fill(dp, dp + (1 << (2 * n)), -1.0);
    cout << fixed << setprecision(2) << solve(0) << endl;
    
    return 0;
}