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
typedef vector<pair<int, ii>> vpii;
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
            for (int i = 0; i < n; i++){
                id[i] = i;
            }
        };
        int find(int i){ return _find(i); };
        void c_union(int i, int j){ return _union(i, j); };
};

int n, m;

ll solveIt(vpii& edges){
    ll ans = 0;
    UnionFind aux(m);
    for(auto e: edges){
        if(aux.find(e.second.first) != aux.find(e.second.second)){
            aux.c_union(e.second.first, e.second.second);
            ans += e.first;
        }
    }
    return ans;
}

int main(){
    while(true){
        ll ans = 0;
        scanf("%d %d", &m, &n);
        if(n == 0 and m == 0)
            break;
        vpii edges;
        for (int i = 0; i < n; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges.emplace_back(z, make_pair(x, y));
        }
        sort(all(edges));
        printf("%lld\n", solveIt(edges));
    }
    return 0;
}