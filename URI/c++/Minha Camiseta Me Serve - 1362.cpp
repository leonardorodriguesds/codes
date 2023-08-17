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
#define V 39
int graph[V][V];
map<string, int> mapSizes = {
    {"XXL", 31},
    {"XL", 32},
    {"L", 33},
    {"M", 34},
    {"S", 35},
    {"XS", 36}
};
int t = 37, s = 0;
int parent[V], visited[V];

bool bfs(int s, int t) {
    memset(visited, -1, sizeof(visited));
    parent[s] = -1;
    visited[s] = 1;

    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        FOR(v, V) {
            if (!~visited[v] && graph[u][v] > 0) {
                parent[v] = u;
                if (v == t) {
                    return true;
                }

                q.push(v);
                visited[v] = 1;
            }
        }
    }

    return false;
}

void init_problem(int n, int m) {
    memset(graph, 0, sizeof(graph));
    memset(parent, -1, sizeof(parent));
    string s1, s2;
    FOR1(i, m) {
        cin >> s1 >> s2;
        graph[s][i] = graph[i][mapSizes[s1]] = graph[i][mapSizes[s2]] = 1;
    }

    for(int i = mapSizes["XXL"]; i < t; i++) {
        graph[i][t] = n / 6;
    }

    int max_flow = 0;

    while(bfs(s, t)) {
        int path_flow = INF, v, u;
        for(v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }

        for(int v = t; v != s; v = parent[v]) {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    if (max_flow >= m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        init_problem(n, m);
    }
    return 0;
}