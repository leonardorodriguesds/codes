#include <bits/stdc++.h>
#define DEBUG false
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
#define fill(t,v)       memset(t, v, sizeof(t))
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

int n, t;
int mem[1000 + 1][2000 + 1];

int dp(int i, int j, vii& orders) {
    if (i >= n || j <= 0) {
        return 0;
    }

    if (!~mem[i][j]) {
        int c, v;
        tie(c, v) = orders[i];

        if (c <= j) mem[i][j] = max(max(v + dp(i, j - c, orders), v + dp(i + 1, j - c, orders)), dp(i + 1, j, orders));
        else mem[i][j] = dp(i + 1, j, orders);
    } 
    
    return mem[i][j];
}

void init_problem() {
    memset(mem, -1, sizeof(mem));

    vii orders;
    orders.reserve(n);
    FOR(i, n) {
        int c, v;
        cin >> c >> v;

        orders.emplace_back(c, v);
    }

    cout << dp(0, t, orders) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> n >> t;
    init_problem();
    return 0;
}