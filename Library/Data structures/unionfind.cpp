#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

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

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    UnionFind uf(n);
    for (int i = 0; i < m; i++){
        int p, q;
        scanf("%d %d", &p, &q);
        uf.c_union(p, q);
    }
    return 0;
}