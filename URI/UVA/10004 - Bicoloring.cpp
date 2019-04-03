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
int visited[201];

bool dfsAux(int u, vvi& graph, bool c){
    visited[u] = (c? 1 : 0);
    for(int v: graph[u]){
        if(!~visited[v])
            dfsAux(v, graph, !c);
        else if(visited[u] == visited[v])
            return false;
    }
    return true;
} 

int main(){
    int n, l;
    while(scanf("%d", &n) and n != 0){
        scanf("%d", &l);
        vvi graph(n);
        while(l--){
            int x, y;
            scanf2(x, y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        fill(visited, -1);
        bool ans = true;
        for(int i = 0; i < n and ans; i++)
            if(!~visited[i]) ans &= dfsAux(i, graph, true);
        printf("%s\n", ans? "BICOLORABLE." : "NOT BICOLORABLE.");
    }
    return 0;
}