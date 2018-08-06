#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define SINF            (1e18)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)     (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)     (lower_bound(all(v), x) - v.begin())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<pair<double, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

class UnionFind{
    int total;
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
    }
    
    public:
        UnionFind(int n): id(n, 0), size(n, 1){
            total = n;
            for (int i = 0; i < n; i++)
                id[i] = i;
        };
        int find(int i){ return _find(i); };
        void c_union(int i, int j){ return _union(i, j); };
};

int main(){
    int c;
    scanf("%d", &c);
    while(c--){
        int n;
        scanf("%d", &n);
        vii coords;
        for (int i = 0; i < n; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            coords.emplace_back(x, y);
        }
        vpii edges;
        for (int i = 0; i < n; i++){
            for (int z = i + 1; z < n; z++){
                int x1 = coords[i].first, x2 = coords[z].first;
                int y1 = coords[i].second, y2 = coords[z].second;
                double aux = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
                edges.emplace_back(aux, make_pair(i, z));
            }
        }
        double ans = 0;
        sort(all(edges));
        UnionFind aux(n);
        for(auto e: edges){
            if(aux.find(e.second.first) != aux.find(e.second.second)){
                aux.c_union(e.second.first, e.second.second);
                ans += e.first;
            }
        }
        printf("%.2lf\n", (ans / 100));
    }
    return 0;
}