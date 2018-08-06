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

class Graph{
    int n;
    vpii edges;
    int *visited;

    public:
        Graph(int n);
        ~Graph();
        void addEdge(int u, int v, int c);
        int kruskalMST();
};
Graph::Graph(int n){
    this->n = n;
    this->visited = new int[n];
}
Graph::~Graph(){
    delete [] this->visited;
}
void Graph::addEdge(int u, int v, int c){
    this->edges.emplace_back(c, make_pair(u, v));
}
int Graph::kruskalMST(){
    UnionFind uf(this->n);
    int ans = 0;
    sort(all(this->edges));
    for(auto edge: this->edges){
        if(uf.find(edge.second.first) != uf.find(edge.second.second))
            uf.c_union(edge.second.first, edge.second.second);
        else
            ans += edge.first;
    }
    return ans;
}

int main(){
    int n, c;
    while(true){
        scanf("%d %d", &n, &c);
        if(n == 0 and c == 0)
            break;
        Graph* aux = new Graph(n);
        for(int i = 0; i < n; i++){
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            aux->addEdge(a - 1, b - 1, w);
        }
        printf("%d\n", aux->kruskalMST());
        delete aux;
    }
    return 0;
}