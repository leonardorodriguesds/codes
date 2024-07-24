#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
    #define DEBUG false
#else
    #define DEBUG true
#endif
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
#define bl "\n"
#define debugarr(arr)   if (DEBUG) { for(auto a: arr) { cout << a << " "; } cout << bl; }
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

bool bfs(int i, int j, int n, vvi& graph, vi& parent) {
    int visited[n];
    fill(visited, -1);
    parent[i] = -1;
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: graph[u]) {
            if (!~visited[v]) {
                parent[v] = u;
                visited[v] = 1;

                if (v == j)
                    return true;

                q.push(v);

            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    int n, m; cin >> n >> m;
    vvi graph(n, vi());
    int a, b;
    FOR(i, m) {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vi parent(n, -1);
    if (bfs(0, n - 1, n, graph, parent)) {
        vi ans;

        int u = n - 1;
        ans.push_back(u);
        while (parent[u] != -1) {
            ans.push_back(parent[u]);
            u = parent[u];
        }

        cout << ans.size() << bl;
        for(auto it = ans.rbegin(); it < ans.rend(); it++)
            cout << (*it) + 1 << " ";
        cout << bl;
    } else cout << "IMPOSSIBLE" << bl;
    return 0;
}