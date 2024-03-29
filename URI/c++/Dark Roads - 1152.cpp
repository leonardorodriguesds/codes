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
    int m, n;
    while(true){
        scanf("%d %d", &m, &n);
        if(m == 0 and n == 0)
            break;
        long long ans = 0;
        vector<pair<int, ii>> edges;
        for (int i = 0; i < n; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges.emplace_back(z, make_pair(x, y));
            ans += z;
        }
        UnionFind controll(m);
        sort(all(edges));
        for(pair<int, ii> edge: edges){
            if(controll.find(edge.second.first) == controll.find(edge.second.second)) continue;
            controll.c_union(edge.second.first, edge.second.second);
            ans -= edge.first;
        }
        printf("%lld\n", ans);
    }
    return 0;
}