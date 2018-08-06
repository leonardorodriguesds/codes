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
int graph[101][101];
int tab[101][101][101];

int solveIt(int i, int j, int k){
    if(k == 0)
        return (graph[i][j] == -1? INF : graph[i][j]);
    int& ans = tab[i][j][k];
    if(ans == -1)
        ans = min(solveIt(i, j, k - 1), solveIt(i, k, k - 1) + solveIt(k, j, k - 1));
    return ans;
}

int main(){
    int n, m, q;
    while(scanf("%d %d", &n, &m) == 2){
        fill(graph, -1);
        fill(tab, -1);
        for (int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u][v] = w;
            graph[v][u] = w;
        }
        for(int i = 0; i <= n; i++)
            graph[i][i] = 0;
        scanf("%d", &q);
        while(q--){
            int u, v, k;
            scanf("%d %d %d", &u, &v, &k);
            int ans = solveIt(u, v, k);
            printf("%d\n", ans == INF? (int)-1 : ans);
        }
    }
    return 0;
}