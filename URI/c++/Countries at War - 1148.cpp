#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define SINF            (1e18)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;
int n, e, k;
int connect[501][501];
int solveIt(int x, int y, vector<vii>& graph){
    long long d[501];
    for(int u = 0; u < n; u++)
		d[u] = SINF;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> aux;
    d[x] = 0;
    aux.emplace(d[x], x);
    ll dt, w;
	int u, v;
    while(!(aux.empty())){
        tie(dt, u) = aux.top(); 
        aux.pop();
        if(u == y)
            return dt;
        for(auto edge : graph[u]){
			tie(w, v) = edge;
            w = (connect[u][v] == 1 and connect[v][u] == 1)? 0: w;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				aux.emplace(d[v], v);
			}
		}
    }
    return -1;
}

int main(){
    while(true){
        scanf("%d %d", &n, &e);
        if(e == 0 and n == 0)
            break;
        fill(connect, -1);
        vector<vii> graph(n, vii());
        for (int i = 0; i < e; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            graph[x - 1].emplace_back(z, y - 1);
            connect[x - 1][y - 1] = 1;
        }
        scanf("%d", &k);
        for (int i = 0; i < k; i++){
            int o, d;
            scanf("%d %d", &o, &d);
            long long dt = solveIt(o - 1, d - 1, graph);
            if(dt >= 0)
                printf("%lld\n", dt);
            else
                printf("Nao e possivel entregar a carta\n");
        }
        printf("\n");
    }
    return 0;
}