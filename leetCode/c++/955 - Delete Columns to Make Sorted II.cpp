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
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;

        int n = strs[0].size(), m = strs.size();
        FOR(i, n) {
            int res = 0;
            FOR(j, m - 1) {
                if (strs[j][i] > strs[j + 1][i]) {
                    res++;
                    break;
                }
            }

            if (res == 0)
                break;
            else ans += res;
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    auto sol = Solution();
    vs in = {"ca","bb","ac"};
    cout << sol.minDeletionSize(in) << endl;

    in = {"xc","yb","za"};
    cout << sol.minDeletionSize(in) << endl;

    in = {"zyx","wvu","tsr"};
    cout << sol.minDeletionSize(in) << endl;

    in = {"xga","xfb","yfa"};
    cout << sol.minDeletionSize(in) << endl;
    return 0;
}