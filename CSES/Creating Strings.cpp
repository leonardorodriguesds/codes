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
#define bl "\n"
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
 
string str;
int n;
int chosen = 0;
vi permutation;
set<string> permutations;
 
void solve() {
    int m = permutation.size();
    if (m == n) {
        ostringstream oss;
        FOR(i, n)
            oss << str[permutation[i]];
        permutations.insert(oss.str());
    } else {
        FOR(i, n) {
            if (!(chosen & (1 << i))) {
                chosen |= (1 << i);
                permutation.push_back(i);
                solve();
                chosen &= (~(1 << i));
                permutation.pop_back();
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cin >> str;
    n = str.size();
    solve();
    cout << permutations.size() << bl;
    for(string s: permutations)
        cout << s << bl;
    return 0;
}