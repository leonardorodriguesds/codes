#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define SINF            (1e18)
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
typedef vector<vii> vvii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;
int n;
vii park(40, ii());
int table[41][801][801];

int solveIt(int i, int g, int y){
    if((g == 0 and y == 0) or (i >= n))
        return 0;
    int& ans = table[i][g][y];
    if(ans == -1){
        if(g + park[i].first >= 0 and y + park[i].second >= 0)
            ans = 1 + solveIt(i + 1, g + park[i].first, y + park[i].second);
        ans = max(ans, solveIt(i + 1, g, y));
    }
    return ans;
}

int main(){
    while(scanf("%d", &n) == 1){
        fill(table, -1);
        int g, y;
        scanf("%d %d", &g, &y);
        for (int i = 0; i < n; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            park[i] = make_pair(x, y);
        }
        printf("%d\n", solveIt(0, g, y));
    }
    return 0;
}