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
int depth[2 * 100000 + 1], parent[2 * 100000 + 1];
vvi graph(2 * 100000 + 1);

void dfs(int i, int p, int aux){
    static int count = 0;
    depth[i] = aux;
    parent[i] = p;
    for(int u: graph[i]) 
        if(u != p) dfs(u, i, aux + 1);
}

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    dfs(0, -1, 0);
    vii aux;
    for(int i = 0; i < n; i++) if(depth[i] > 2) aux.emplace_back(-depth[i], i);
    sort(all(aux));
    for(auto e: aux){
        int i = e.second;
        depth[i] = min(depth[parent[i]] + 1, depth[i]);
        if(depth[i] <= 2) continue;
        ans++, depth[parent[i]] = 1, depth[i] = 2;
    }
    printf("%d\n", ans);
    return 0;
}