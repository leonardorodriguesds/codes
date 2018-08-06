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
        void unionv(int i, int j){ return _union(i, j); };
};

vector<pair<int, ii>> kruskal(vector<pair<int, ii>>& edges){
    UnionFind uf(sz(edges));
    vector<pair<int, ii>> ans;
    sort(all(edges));
    for(pair<int, ii> edge: edges){
        if(uf.find(edge.second.first) == uf.find(edge.second.second)) continue;
        uf.unionv(edge.second.first, edge.second.second);
        ans.emplace_back(edge.first, make_pair(edge.second.first, edge.second.second));
    }
    return ans;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, ii>> edges;
    for (int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.emplace_back(w, make_pair(u, v));
    }
    vector<pair<int, ii>> mst = kruskal(edges);
    for(pair<int, ii> edge: mst)
        printf("[%d -> %d] => %d\n", edge.second.first, edge.second.second, edge.first);
    return 0;
}