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

vii prims_mst(int n, vvii& graph){
    vii mst;
    int inMST[n];
    int coust[n];
    int parent[n];
    for (int i = 0; i < n; i++)
        coust[i] = INF, inMST[i] = -1, parent[i] = -1;
    priority_queue<ii, vector<ii>, greater<ii>> aux;
    aux.emplace(0, 0);
    coust[0] = 0;
    int u, dt;
    for(int i = 0; i < n - 1; i++){
        tie(dt, u) = aux.top(), aux.pop();
        inMST[u] = 1;
        for(auto e: graph[u]){
            if(!~inMST[e.second] and e.first < coust[e.second])
                parent[e.second] = u, aux.push(e), coust[e.second] = e.first;
        }
    }
    for(int i = 1; i < n; i++)
        mst.emplace_back(i, parent[i]);
    return mst;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vvii graph(n, vii());
    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a - 1].emplace_back(c, b - 1);
        graph[b - 1].emplace_back(c, a - 1);
    }
    vii edges = prims_mst(n, graph);
    for(auto e: edges)
        printf("{%d, %d}\n", e.first, e.second);
    return 0;
}