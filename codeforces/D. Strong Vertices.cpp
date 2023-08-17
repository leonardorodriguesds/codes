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

int arr[2 * 1000000 + 1], brr[2 * 1000000 + 1], total[2 * 1000000 + 1], visited[2 * 1000000 + 1];
int res = 0, n;
vi ascending;
vvi graph;

void dfs(int u) {
    visited[u] = 1;
    total[u] = 0;
    for(int v: graph[u]) {
        if (!~visited[v]) {
            dfs(v);
        }
        total[u]++;
    }

    if (total[u] == n - 1) {
        res++;
        ascending.push_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> n;
        res = 0;
        graph.clear();
        graph.reserve(n);
        ascending.clear();
        FOR(i, n) {
            cin >> x;
            arr[i] = x;
        }

        FOR(i, n) {
            cin >> x;
            brr[i] = x;
        }

        cout << n << " <--" << endl;

        for(int u = 0; u < n; u++) {
            for(int v = u + 1; v < n; v++) {
                int au = arr[u], av = arr[v], bu = brr[u], bv = brr[v];
                cout << u << " -- " << v << ", au=" << au << ", av=" << av << ", bu=" << bu << ", bv=" << bv << endl;
                if (au - av >= bu - bv) {
                    cout << "==> " << u << " <> " << v << endl;
                    graph[u].push_back(v);
                }

                if (av - au >= bv - bu) {
                    cout << "==> " << v << " <> " << u << endl;
                    graph[v].push_back(u);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int v: graph[i]) {
                cout << i << " <> " << v << endl;
            }
        }

        memset(total, 0, sizeof(total));
        memset(visited, -1, sizeof(visited));

        dfs(0);

        sort(all(ascending));

        FOR(i, n) {
            cout << total[i] << " ";
        }
        cout << endl;

        cout << res << endl;
        for (int x: ascending) {
            cout << x << " "; 
        }
        cout << endl;

    }
    return 0;
}