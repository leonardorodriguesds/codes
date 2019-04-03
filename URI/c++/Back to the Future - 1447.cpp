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
int graph[5001][5001];

int dijkstra(int s, int t){
    int aux[t + 1], parent[t + 1];
    for(int i = 0; i < t + 1; i++)
        aux[i] = INF, parent[i] = -1;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, s);
    int u, c;
    parent[s] = -1;
    while(!pq.empty()){
        tie(c, u) = pq.top(), pq.pop();
        if(u == t){
            int x = t;
            while(parent[x] != -1 and x != s)
                graph[parent[x]][x] = 0, x = parent[x];
            return c;
        }
        for(int i = 0; i < t + 1; i++)
            if(graph[u][i] > 0)
                if(aux[i] > c + graph[u][i])
                    aux[i] = c + graph[u][i], parent[i] = u, pq.emplace(aux[i], i);
    }
    return -1;  
}

int fluxo(int s, int t){

}

int main(){
    int n, m, d, k, z = 0;
    while(scanf2(n, m)){
        z++;
        fill(graph, 0);
        while(m--){
            int a, b, c;
            scanf3(a, b, c);
            graph[a - 1][b - 1] = c;
        }
        scanf2(d, k);
        int ans = 0;
        while(d > 0){
            int x = dijkstra(0, n - 1);
            cout << x << " ";
            if(x == -1) break;
            ans += min(k, d) * x, d -= k;
        }
        cout << endl;
        if(d > 0) printf("Instancia %d\nimpossivel\n\n", z);
        else printf("Instancia %d\n%d\n\n", z, ans);
    }
    return 0;
}