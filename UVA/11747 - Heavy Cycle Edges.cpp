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
typedef vector<pair<ll, ii>> vpii;
typedef vector<string> vs;

class UnionFind{
    vi id, size;
    
    int _find(int i){
        if(id[i] == i) return i;
        return id[i] = _find(id[i]);
    }
    void _union(int i, int j){
        int p = _find(i);
        int q = _find(j);
        if(p == q) return;
        if(size[p] > size[q]) swap(p, q);
        id[p] = q;
        size[q] += size[p];
        total--;
    }
    
    public:
        int total;
        UnionFind(int n): total(n), id(n, 0), size(n, 1){
            for (int i = 0; i < n; i++) id[i] = i;
        };
        int find(int i){ return _find(i); };
        void c_union(int i, int j){ return _union(i, j); };
};

int kruskal(int n, vpii& edges){
    int ans = 0;
    UnionFind uf(n);
    sort(all(edges));
    for(auto edge: edges){
        if(uf.find(edge.second.first) == uf.find(edge.second.second)){
            printf("%s%lld", ans? " " : "", edge.first);
            ans++;
            continue;
        }
        uf.c_union(edge.second.first, edge.second.second);
    }
    if(ans) printf("\n");
    return ans;
}

int main(){
    int n, m;
    while(scanf2(n, m) == 2 and n != 0){
        vpii edges(m);
        for(int i = 0; i < m; i++){
            int a, b;
            ll w;
            scanf("%d %d %lld", &a, &b, &w);
            edges[i] = make_pair(w, ii(a, b));
        }
        int ans = kruskal(n, edges);
        if(ans == 0) printf("forest\n");
    }
    return 0;
}