#include <bits/stdc++.h>
using namespace std;
#define DEBUG           true
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
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef vector<pqi> vpqi;

void init_problem(int, int, int, int);
void solveIt(vpii&, int, vi&, int);
int dkijstra(int, int, vector<vii>&, vi&, vi&) ;

int dkijstra(int x, int y, vector<vii>& graph, vi& route) {
    const int SINF = INT_MAX;
    int n = graph.size();
    long long d[501];
    for (int u = 0; u < n; u++)
        d[u] = SINF;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> aux;
    d[x] = 0;
    aux.emplace(d[x], x);
    ll dt, w;
    int u, v;
    while (!aux.empty()) {
        tie(dt, u) = aux.top();
        aux.pop();
        if (u == y)
            return dt;
        for (auto edge : graph[u]) {
            tie(w, v) = edge;
            w = ((u < v && v <= y) ? route[max(u,v)] - route[min(u,v)] : (u < y && v > y) ? INF : w);
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                aux.emplace(d[v], v);
            }
        }
    }
    return -1;
}

void init_problem(int n, int m, int c, int k) {
    vector<vii> graph(n);
    vi route(c + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v, p;
        scanf3(u, v, p);

        graph[u].emplace_back(p, v);
        graph[v].emplace_back(p, u);
    }
    
    int i = 1;
    while(i <= c) {
        int w = -1;

        for(auto it: graph[i]) {
            if (it.second == i - 1) {
                w = it.first;
                break;
            }
        }
        route[i] = w + route[i - 1];
        i++;
    }
    cout << dkijstra(k, c, graph, route) << endl;
}

int main() {    
    int N, M, C, K;
    while (true) {  
        cin >> N >> M >> C >> K;      
        if (N == 0 && M == 0 && C == 0 && K == 0) {
            break;
        }
        init_problem(N, M, C - 1, K);
    }
    return 0;
}