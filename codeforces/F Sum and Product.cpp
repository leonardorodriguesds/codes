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

ll my_sqrt(ll a)
{
    ll l=0,r=5000000001;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false); 
    int t;
    cin >> t;
    map<ll, int> numbers;
    while (t--) {
        int n, q;
        cin >> n;
        numbers.clear();
        while(n--) {
            int x;
            cin >> x;
            numbers[x]++;
        }
        cin >> q;
        while (q--) {
            int x;
            ll y, x1, x2;
            cin >> x >> y;
            ll delta = 1ll*x*x - (4ll * y);
            if (delta < 0) cout << 0;
            else {
                auto sqrtDelta = my_sqrt(delta);
                x1 = (x - sqrtDelta) / 2;
                x2 = (x + sqrtDelta) / 2;

                // cout << x << " <> " << y << "; x1=" << x1 << ", x2=" << x2 << ", D=" << delta << endl;
                if (x1 + x2 != x || x1 * x2 != y) cout << 0;
                else if (x1 == x2) cout << 1ll * numbers[x1] * (numbers[x1] - 1) / 2ll;
                else cout << 1ll * numbers[x1] * numbers[x2];
            }

            cout << " ";
        }
        cout << endl;
    }
    return 0;
}