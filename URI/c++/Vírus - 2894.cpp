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
int low[1001], disc[1000], visited[1001], parent[1001];
int solveitUtil(int, int, int&, vvi&);
int solveit(int, int, vvi&);

int solveitUtil(int u, int c, int& time, vvi& graph){
    visited[u] = 1, low[u] = disc[u] = time++;
    for(int v: graph[u]){
        if(!~visited[v]){
            parent[v] = u;
            solveitUtil(v, c, time, graph);
            low[u] = min(low[u], low[v]);
        } else if(v != parent[u])
        low[u] = min(low[u], disc[v]);
    }
    return 0;
}

int solveit(int n, int c, vvi& graph){
    fill(low, 0), fill(disc, 0), fill(visited, -1), fill(parent, -1);
    int time = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(!~visited[i]) ans = max(ans, solveitUtil(i, c, time, graph));
        cout << i + 1 << ": " << "low[" << low[i] << "], disc[" << disc[i] << "];" << endl;
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, c;
        scanf3(n, m, c);
        vvi graph(n);
        while(m--){
            int u, v;
            scanf2(u, v);
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        printf("%d\n", solveit(n, c, graph));
    }
    return 0;
}