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

class Solution {
    int mem[100002];
    int dp(int s, int low, int high, int zero, int one) {
        if (s > high)
            return 0;
        
        int& ans = mem[s];
        if (!~ans) {
            ans = 0;
            if (low <= s && s <= high)
                ans += 1;

            ans += dp(s + zero, low, high, zero, one) + dp(s + one, low, high, zero, one) % MOD;
        }
        return ans % MOD;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        fill(mem, -1);
        return dp(0, low, high, zero, one);
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    auto sol = Solution();

    cout << sol.countGoodStrings(3, 3, 1, 1) << endl;

    cout << sol.countGoodStrings(2, 3, 1, 2) << endl;

    cout << sol.countGoodStrings(20, 20, 1, 6) << endl;

    cout << sol.countGoodStrings(200, 200, 10, 1) << endl;
    return 0;
}