#include <bits/stdc++.h>
using namespace std;

int n, m, s, q;
vector<pair<long long, int>> graph[2 * 10005];
long long dist[2 * 10005];

void bfs(int root){
    for(int u = 0; u < 2 * 10002; u++)
		dist[u] = (1e9 + 7);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > aux;
    dist[root] = 0;
    aux.emplace(dist[root], root);
    long long dt, w;
    int u, v;
    while(!(aux.empty())){
        tie(dt, u) = aux.top();
        aux.pop();
        for(auto edge: graph[u]){
            tie(v, w) = edge;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                aux.emplace(dist[v], v);
            }
        }
    }
}

int main(){    
    scanf("%d %d %d %d", &n, &m, &s, &q);
    for(int i = 0; i < m; i++){
        int a, b;
        long long w;
        scanf("%d %d %lld", &a, &b, &w);
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }
    bfs(s);
    for(int i = 0; i < q; i++){
        int x;
        long long dt;
        scanf("%d", &x);
        dt = dist[x];
        if(dt == (1e9 + 7))
            printf("-1\n");
        else
            printf("%lld\n", dt);
    }
    return 0;
}