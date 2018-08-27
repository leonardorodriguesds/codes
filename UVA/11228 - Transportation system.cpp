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
typedef vector<pair<double, ii>> vpii;
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

double kruskal(int n, vpii& edges, UnionFind& uf){
    double ans = 0;
    sort(all(edges));
    for(auto edge: edges){
        if(uf.find(edge.second.first) == uf.find(edge.second.second)) continue;
        uf.c_union(edge.second.first, edge.second.second);
        ans += edge.first;
    }
    return ans;
}


int main(){
    int t, n, r, aux = 0;
    scanf("%d", &t);
    while(t-- and scanf2(n, r) == 2){
        vpii edges, states;
        array<int, 3> ans;
        ii pos[n];
        for(int i = 0; i < n; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            pos[i] = make_pair(x, y);
        }
        for(int i = 0; i < n; i++){
            ii& cur = pos[i];
            for(int k = (i + 1); k < n; k++){
                ii& z = pos[k]; //(Xa - Xb)² + (Ya - Yb)² <= r²
                double dist = ((cur.first - z.first) * (cur.first - z.first)) + ((cur.second - z.second) * (cur.second - z.second));
                if(dist <= (double)(r * r)) edges.emplace_back(sqrt(dist), ii(i, k));
                else states.emplace_back(sqrt(dist), ii(i, k));
            }
        }
        UnionFind uf(n);
        ans[1] = (int)round(kruskal(n, edges, uf)), ans[0] = uf.total, ans[2] = (int)round(kruskal(n, states, uf));
        printf("Case #%d: %d %d %d\n", ++aux, ans[0], ans[1], ans[2]);
    }
    return 0;
}