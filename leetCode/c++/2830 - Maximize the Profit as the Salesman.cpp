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
    ll mem[100001];
    ll dp(int i, int n, map<int, vvi>& cache) {
        if (i >= n)
            return 0;

        ll& ans = mem[i];

        if (!~ans) {
            ans = dp(i + 1, n, cache);
            vvi offers = cache[i];
            int m = offers.size();
            FOR(j, m)
                ans = max(offers[j][2] + dp(offers[j][1] + 1, n, cache), ans);
        }

        return ans;
    }
public:
    ll maximizeTheProfit(int n, vvi& offers) {
        fill(mem, -1);
        map<int, vvi> cache = map<int, vvi>();
        int m = offers.size();
        FOR(i, m) {
            vi offer = offers[i];
            vvi house_offers = vvi();
            if (cache.find(offer[0]) != cache.end())
                house_offers = cache[offer[0]];

            house_offers.push_back(offer);
            cache[offer[0]] = house_offers;
        }
        return dp(0, n, cache);
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    auto sol = Solution();
    vvi offers = {{0,0,1},{0,2,2},{1,3,2}};
    cout << sol.maximizeTheProfit(5, offers) << endl;

    offers = {{0,0,1},{0,2,10},{1,3,2}};
    cout << sol.maximizeTheProfit(5, offers) << endl;
    return 0;
}