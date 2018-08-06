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
        UnionFind(int n): id(n, 0), size(n, 0){
            total = n;
            for (int i = 0; i < n; i++){
                id[i] = i;
            }
        };
        int find(int i){ return _find(i); };
        void c_union(int i, int j){ return _union(i, j); };
};

int main(){
    int n = 0, upper = 0;
    scanf("%d", &n);
    vpii galleries;
    for (int i = 0; i < n; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        galleries.emplace_back(w, make_pair(u - 1, v - 1));
        if(v > u) swap(u, v);
        if(u > upper)
            upper = u;
    }
    UnionFind umin(upper);
    UnionFind umax(upper);
    sort(all(galleries));
    int minimum = 0, maxc = 0;
    for(pair<int, ii> e: galleries){
        if(umin.find(e.second.first) != umin.find(e.second.second)){
            umin.c_union(e.second.first, e.second.second);
            minimum += e.first;
        }
    }
    reverse(all(galleries));
    for(pair<int, ii> e: galleries){
        if(umax.find(e.second.first) != umax.find(e.second.second)){
            umax.c_union(e.second.first, e.second.second);
            maxc += e.first;
        }
    }
    printf("%d\n%d\n", maxc, minimum);
    return 0;
}