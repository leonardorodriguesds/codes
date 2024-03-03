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

const int MAX = 1e6 + 10;
ll fat[MAX];

ll fexp(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) return fexp(a*a % MOD, b/2);
    return a * fexp(a, b-1) % MOD;
}

ll inv(ll a) {
    return fexp(a, MOD-2);
}

ll comb(int n, int i) {
    return fat[n] * inv(fat[i]) % MOD * inv(fat[n-i]) % MOD;
} 

int main() {
    ios_base::sync_with_stdio(false); 
    int a, b, n; cin >> a >> b >> n;

    fat[0] = 1;
    FOR1(i, MAX)
        fat[i] = fat[i-1] * i % MOD;

    ll res = 0;
    FOR(i, n + 1) {
        int a_qtd = i, b_qtd = n-i;
        
        bool excellent = true;

        ll sum = a_qtd * a + b_qtd * b;

        while (sum > 0) {
            if (sum % 10 != a && sum % 10 != b) excellent = false;
            sum /= 10;
        }

        if (excellent) res = (res + comb(n, i)) % MOD;

    }
    cout << res << endl;
    return 0;
}