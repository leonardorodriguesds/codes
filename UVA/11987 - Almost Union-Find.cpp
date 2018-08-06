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
    int num;
    vi id, size;
    vector<ll> sum;
    
    int _find(int i){
        if(id[i] == i) return i;
        return id[i] = _find(id[i]);
    }
    void _union(int i, int j){
        int p = _find(i), q = _find(j);
        if(p == q) return;
        if(size[p] > size[q]) swap(p, q);
        id[p] = q, size[q] += size[p], total--, sum[q] += sum[p];
    }
    
    public:
        int total;
        UnionFind(int n): num(n), total(n), id(n, 0), size(n, 1), sum(n, 0){
            for (int i = 0; i < n; i++) id[i] = i, sum[i] = (ll)i + 1;
        };
        void move(int i, int j){
            int p = _find(i), q = _find(j);
            if(p == q) return;
            if(p == i and size[p] > 1){
                int k = p, x;
                for (x = 0; (x < num) and (k == p); x++)
                    if(_find(x) == p) k = x, id[x] = x;
                for (x++; (x < num); x++)
                    if(_find(x) == p) id[x] = k;
                size[k] = size[p] - 1, sum[k] = sum[p] - (i + 1);
                size[p] = 1, sum[p] = i + 1;
            }
            size[p]--, size[q]++, id[i] = q, sum[p] -= (i + 1), sum[q] += (i + 1);
        };
        int find(int i){ return _find(i); };
        void c_union(int i, int j){ return _union(i, j); };
        pair<int, ll> solveIt(int i){
            int p = _find(i);
            return {size[p], sum[p]};
        };
};

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) == 2){
        UnionFind aux(n);
        for(int i = 0; i < m; i++){
            int a, b, c;
            scanf("%d %d", &a, &b);
            if(a < 3) scanf("%d", &c);
            if(a == 1) aux.c_union(b - 1, c - 1);
            if(a == 2) aux.move(b - 1, c - 1);
            if(a == 3){
                pair<int, ll> ans = aux.solveIt(b - 1);
                printf("%d %lld\n", ans.first, ans.second);
            }
        }
    }
    return 0;
}