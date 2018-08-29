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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;

ll prims_mst(int n, vvii& graph){
    ll ans = 0LL;
    int inMST[n], parent[n];
    ll cost[n];
    for (int i = 0; i < n; i++) cost[i] = INFLL, inMST[i] = -1, parent[i] = -1;
    priority_queue<ii, vector<ii>, greater<ii>> aux;
    aux.emplace(0, 0);
    cost[0] = 0LL;
    int u, dt;
    while(!aux.empty()){
        tie(dt, u) = aux.top(), aux.pop();
        inMST[u] = 1;
        for(auto e: graph[u]){
            if(!~inMST[e.second] and e.first < cost[e.second])
                parent[e.second] = u, aux.push(e), cost[e.second] = e.first;
        }
    }
    for(int i = 1; i < n; i++) ans += cost[i];
    return ans;
}

int main(){
    int m, n;
    while(scanf2(m, n) == 2 and m != 0 and n != 0){
        ll from = 0;
        vvii graph(m);
        for(int i = 0; i < n; i++){
            int a, b;
            ll w;
            scanf("%d %d %lld", &a, &b, &w);
            graph[a].emplace_back(w, b);
            graph[b].emplace_back(w, a);
            from += w;
        }
        printf("%lld\n", from - prims_mst(m, graph));
    }
    return 0;
}