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

int solveIt(int start, int end, int n, vvii& graph){
    int before = -1;
    int dist[n + 1];
    for(int i = 0; i < n; i++)
        dist[i] = INF;
    priority_queue<ii, vector<ii>, greater<ii>> aux;
    dist[start] = 0;
    aux.emplace(dist[start], start);
    int u, v, dt, w;
    while(!(aux.empty())){
        tie(dt, u) = aux.top();
        aux.pop();
        if(u == end){
            if(!~before)
                before = dt;
            else if(dt > before)
                return dt;
        }
        for(auto e: graph[u]){
            tie(v, w) = e;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                aux.emplace(dist[v], v);
            }
        }
    }
    return -1;
}

int main(){
    int n, m, s, d;
    while(scanf("%d %d", &n, &m) == 2){
        if(n == 0 and m == 0)
            break;
        scanf("%d %d", &s, &d);
        vvii graph(n, vii());
        for (int i = 0; i < m; i++){
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            graph[u].emplace_back(v, p);
        }
        printf("%d\n", solveIt(s, d, n, graph));
    }
    return 0;
}