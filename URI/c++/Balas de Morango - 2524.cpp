#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)     (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)     (lower_bound(all(v), x) - v.begin())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;
#define MAX_n 1010
ll n, m, v[MAX_n], table[MAX_n][MAX_n], q;

ll solveIt(int i, int j){
    ll& ans = table[i][j];
    if(ans != -1) return ans;
    if(i == 0) return table[i][j] = 0;
    if(((v[i] + j) % n) == 0) return (table[i][j] = 1 + solveIt(i - 1, 0));
    ans = max(q = solveIt(i - 1, (v[i] + j) % n), solveIt(i - 1, j)); 
    if(q) return ans = max(ans, q + 1);
    return ans;
}

int main(){
    while(scanf("%lld %lld", &n, &m) == 2){
        fill(table, -1);
        for (int i = 1; i <= m; i++)
            scanf("%lld", &v[i]);
        printf("%lld\n", solveIt(m, 0));
    }
    return 0;
}