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
typedef pair<double, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef vector<pqi> vpqi;

int n, m;

double dkijstra(int x, int y, vector<vii>& graph) {
    int n = graph.size();
    double d[101];
    for (int u = 0; u < n; u++)
        d[u] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> aux;
    d[x] = 1.0;
    aux.emplace(d[x], x);
    double dt, w;
    int u, v;
    while (!aux.empty()) {
        tie(dt, u) = aux.top();
        aux.pop();
        if (u == y)
            return dt;
        for (auto edge : graph[u]) {
            tie(w, v) = edge;
            if (d[v] < d[u] * w) {
                d[v] = d[u] * w;
                aux.emplace(d[v], v);
            }
        }
    }
    return -1;
}

void init_problem() {
    vector<vii> graph(n);

    FOR(i,m) {
        int a, b, p;
        scanf3(a, b, p);
        graph[a - 1].emplace_back(((double)p/100), b - 1);
        graph[b - 1].emplace_back(((double)p/100), a - 1);
    }

    cout << fixed << setprecision(6);
    cout << dkijstra(0, n - 1, graph) * 100 << " percent" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    while (cin >> n && n != 0) {
        cin >> m;
        init_problem();
    }
    return 0;
}