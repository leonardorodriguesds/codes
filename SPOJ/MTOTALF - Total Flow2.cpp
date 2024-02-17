#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
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
#define FOR(x,n) for(int x = 0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x = 1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x = int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x = int(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define mset(x, y) memset(&x, (y), sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef vector<pqi> vpqi;

int bfsEdmondsKarp(int s, int t, int time, vi& seen, vvi& graph, vvi& capacity, vi& parent) {
    seen[s] = time;
    parent[s] = -1;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while(!q.empty()) {
        int u = q.front().first, w = q.front().second;
        q.pop();

        for(int e: graph[u]) {
            if (seen[e] < time && capacity[u][e] > 0) {
                seen[u] = time, parent[e] = u;
                int max_flow = min(w, capacity[u][e]);
                if (e == t) {
                    return max_flow;
                }

                q.push({e, max_flow});
            }
        }
    }

    return 0;
}

int EdmondsKarp(int s, int t, vvi& graph, vvi& capacity) {
    vi seen(graph.size(), -1);
    vi parent(graph.size(), -1);
    int time = 0, flow = 0;

    while(int w = bfsEdmondsKarp(s, t, time++, seen, graph, capacity, parent)) {
        flow += w;
        int u = t;

        while (u != s) {
            int p = parent[u];
            capacity[p][u] -= w;
            capacity[u][p] += w;
            u = p;
        }
    }

    return flow;
}

void init_problem(int n, int m) {
    vvi graph(n);
    vvi capacity(n, vi(n, 0));

    FOR(i, m) {
        char a, b;
        int w, u, v;

        cin >> a >> b >> w;
        u = a - 'A', v = b - 'A';
        graph[u].push_back(v);
        graph[v].push_back(u);

        capacity[u][v] = w;
    }

    cout << EdmondsKarp(0, 'Z' - 'A', graph, capacity) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    
    int n;
    while (cin >> n) {
        init_problem('z' - 'A' + 1, n);
    }
    return 0;
}