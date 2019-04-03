#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
int visited[100001];

void dfs(int u, vvi& graph){
    visited[u] = 1;
    for(int v: graph[u])
        if(!~visited[v]) dfs(v, graph);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf2(n, m);
        vvi graph(n);
        while(m--){
            int x, y;
            scanf2(x, y);
            graph[x - 1].push_back(y - 1);
            graph[y - 1].push_back(x - 1);
        }
        int ans = 0;
        fill(visited, -1);
        for(int i = 0; i < n; i++)
            if(!~visited[i]) dfs(i, graph), ans++;
        printf("%d\n", ans);
    }
    return 0;
}