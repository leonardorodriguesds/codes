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
int table[1001][101];

int solveIt(int i, int n, int c, vii& list){
    if(c < 0)
        return -INF;
    if(i >= n or c == 0)
        return 0;
    int& ans = table[i][c];
    if(ans == -1){
        if(c - list[i].first >= 0)
            ans = max(ans, list[i].second + solveIt(i + 1, n, c - list[i].first, list));
        ans = max(ans, solveIt(i + 1, n, c, list));
    }
    return ans;
}

int main(){
    int z = 0;
    while(true){
        int n, c;
        z++;
        scanf("%d %d", &n, &c);
        if(n == 0 and c == 0)
            break;
        fill(table, -1);
        vii list;
        for (int i = 0; i < n; i++){
            int w, v;
            scanf("%d %d", &w, &v);
            list.emplace_back(w, v);
        }
        printf("Caso %d: %d\n", z, solveIt(0, n, c, list));
    }
    return 0;
}