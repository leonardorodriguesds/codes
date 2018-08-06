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
int d[10001], low[10001], visited[10001];
vvi graph(10001, vi());

void dfs(int u, int f){
    static int count = 0;
    int nc = 0;
    d[u] = low[u] = count++;
    bool any = false, printed = false;
    visited[u] = 1;
    for(int v: graph[u]){
        if(!~visited[v]){
            dfs(v, u);
            nc++;
            if(low[v] >= d[u]) any = true;
            low[u] = min(low[v], low[u]);
            if(low[v] > d[u]){
                printed = true;
                printf("{%d, %d}", u + 1, v + 1);
            }
        } else if(v != f)
            low[u] = min(low[u], d[v]);
    }
    if((f == 0 and nc >= 2) or (f != 0 and any)){
        printf("%s[%d]", printed? " <=> " : "", u + 1);
        printed = true;
    }
    if(printed) printf("\n");
}

int main(){
    fill(visited, -1);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    dfs(0, 0);
    return 0;
}