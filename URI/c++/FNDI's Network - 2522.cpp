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
        UnionFind(int n): id(n, 0), size(n, 0){
            total = n;
            for (int i = 0; i < n; i++){
                id[i] = i;
            }
        };
        int find(int i){ return _find(i); };
        void c_union(int i, int j){ return _union(i, j); };
};

int n;
double solveIt(vpii& edges){
    double ans = 0;
    sort(all(edges));
    UnionFind aux(n);
    for(auto e: edges){
        if(aux.find(e.second.first) != aux.find(e.second.second)){
            aux.c_union(e.second.first, e.second.second);
            ans += e.first;
        }
    }
    return ans;
}

int main(){
    while(scanf("%d", &n) == 1){
        vii coord;
        for (int i = 0; i < n; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            coord.emplace_back(x, y);
        }
        int table[n + 1][n + 1];
        fill(table, -1);
        vpii edges;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(i == j) continue;
                if(!~table[i][j]){
                    table[i][j] = 1;
                    double aux = sqrt(((coord[i].first - coord[j].first) * (coord[i].first - coord[j].first))
                                + (coord[i].second - coord[j].second) * (coord[i].second - coord[j].second));
                    edges.emplace_back(aux, make_pair(i, j));
                }
            }
        }
        printf("%.2lf\n", solveIt(edges));
    }
    return 0;
}