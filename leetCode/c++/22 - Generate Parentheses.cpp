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

void backtracking(string str, int left, int right, int n, vs& ans) {
    if (left > n || right > n)
        return;

    if (left == n && right == n) {
        ans.pb(str);
    }

    if (left < n) {
        str.pb('(');
        backtracking(str, left + 1, right, n, ans);
        str.pop_back();
    }
    if (right < n && right < left) {
        str.pb(')');
        backtracking(str, left, right + 1, n, ans);
        str.pop_back();
    }
}

vs solve_problem(int n) {
    vs ans = vs();
    backtracking("", 0, 0, n, ans);
    return ans;
}

class Solution {
public:
    vs generateParenthesis(int n) {
        return solve_problem(n);
    }
};

int main() {
    auto ans = Solution();
    auto res = ans.generateParenthesis(3);
    cout << "[";
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << (i < res.size() - 1 ? ", " : "");
    cout << "]" << endl;
    
    res = ans.generateParenthesis(1);
    cout << "[";
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << (i < res.size() - 1 ? ", " : "");
    cout << "]" << endl;
    return 0;
}