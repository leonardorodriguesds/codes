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
int n, m, k;
int dist[1001];

int solveIt(vvii& graph){
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    priority_queue<pair<ll, ii>, vector<pair<ll, ii>>, greater<pair<ll, ii>>> aux;
    dist[0] = 0;
    aux.emplace(0, make_pair(0, 1));
    int v, u, c;
    ii z;
    ll dt, w;
    while(!(aux.empty())){
        tie(dt, z) = aux.top();
        tie(u, c) = z;
        aux.pop();
        if(u == (n - 1) and (c <= k))
            return dt;
        if((c + 1 > k))
            continue;
        for(ii e: graph[u]){
            tie(v, w) = e;
            if((dist[v] > dist[u] + w)){
                dist[v] = dist[u] + w;
                aux.emplace(dist[v], make_pair(v, c + 1));
            }
        }
    }
    return -1;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &k);
        vvii graph(n, vii());
        for (int i = 0; i < m; i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            graph[a].emplace_back(b, c);
        }
        printf("%d\n", solveIt(graph));
    }
    return 0;
}