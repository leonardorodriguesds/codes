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
        UnionFind(int n, vi& points): id(n, 0), size(n, 0){
            total = n;
            for (int i = 0; i < n; i++){
                id[i] = i;
                size[i] = points[i];
            }
        };
        int find(int i){ return _find(i); };
        void c_union(int i, int j){ return _union(i, j); };
        int _size(int i){ return size[i]; }
};

int main(){
    int n, m;
    while(true){
        scanf("%d %d", &n, &m);
        if(n == 0 and m == 0)
            break;
        vi points(n);
        for (int i = 0; i < n; i++){
            int aux;
            scanf("%d", &aux);
            points[i] = aux;
        }
        UnionFind aux(n, points);
        int ans = 0;
        for (int i = 0; i < m; i++){
            int q, a, b;
            scanf("%d %d %d", &q, &a, &b);
            if(q == 1)
                aux.c_union(a - 1, b - 1);
            else{
                if(aux.find(a - 1) == aux.find(0) or aux.find(b - 1) == aux.find(0)){
                    if(aux.find(a - 1) != aux.find(0)) swap(a, b);
                    ans += (aux._size(aux.find(a - 1)) > aux._size(aux.find(b - 1))? 1 : 0);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}