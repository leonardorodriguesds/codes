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
    list<ii> *adj;
    vpii edges;
    int *visited;

    public:
        Graph(int n);
        void addEdge(int u, int v, int c, bool directed = false);
        void removeAdj(int u, int v, bool directed = false);
        void removeEdge(int u, int v);
        vii primsMST();
        vpii kruskalMST();
        ll djikstra(int start, int end);
        int bfs(int start, int end);
        int dfs(int start, int end);
};
Graph::Graph(int n){
    this->n = n;
    this->adj = new list<ii>[n];
    this->visited = new int[n];
}
void Graph::addEdge(int u, int v, int c, bool directed){
    this->adj[u].emplace_back(c, v);
    this->edges.emplace_back(c, make_pair(u, v));
    if(directed)
        this->adj[v].emplace_back(c, u);
}
void Graph::removeAdj(int u, int v, bool directed){
    for(auto it = this->adj[u].begin(); it != this->adj[u].end(); it++){
        if(it->second == v)
            this->adj[u].erase(it); 
    }
    if(!directed)
        return;
    for(auto it = this->adj[v].begin(); it != this->adj[v].end(); it++){
        if(it->second == u)
            this->adj[v].erase(it); 
    }
}
void Graph::removeEdge(int u, int v){
    for(auto it = this->edges.begin(); it != this->edges.end(); it++){
        if((it->second.first == u and it->second.second == v) or (it->second.first == v and it->second.second == u))
            this->edges.erase(it);
    }
}
vii Graph::primsMST(){
    vii mst;
    int inMST[n];
    int coust[n];
    int parent[n];
    for (int i = 0; i < n; i++)
        coust[i] = INF, inMST[i] = -1, parent[i] = -1;
    priority_queue<ii, vector<ii>, greater<ii>> aux;
    aux.emplace(0, 0);
    coust[0] = 0;
    int u, dt;
    for(int i = 0; i < n - 1; i++){
        tie(dt, u) = aux.top(), aux.pop();
        inMST[u] = 1;
        for(auto e: this->adj[u]){
            if(!~inMST[e.second] and e.first < coust[e.second])
                parent[e.second] = u, aux.push(e), coust[e.second] = e.first;
        }
    }
    for(int i = 1; i < n; i++)
        mst.emplace_back(i, parent[i]);
    return mst;
}
vpii Graph::kruskalMST(){
    UnionFind uf(this->n);
    vpii ans;
    sort(all(this->edges));
    for(auto edge: this->edges){
        if(uf.find(edge.second.first) == uf.find(edge.second.second)) continue;
        uf.c_union(edge.second.first, edge.second.second);
        ans.emplace_back(edge.first, make_pair(edge.second.first, edge.second.second));
    }
    return ans;
}
int Graph::dfs(int start, int end){
    fill(this->visited, -1);
    stack<ii> aux;
    aux.emplace(start, 0);
    this->visited[start] = 1;
    int u, dt;
    while(!(aux.empty())){
        tie(u, dt) = aux.top();
        aux.pop();
        if(u == end)
            return dt;
        for(auto e: this->adj[u]){
            if(!~this->visited[e.second]){
                this->visited[e.second] = 1;
                aux.emplace(e.second, dt + 1);
            }
        }
    }
    return -1;
}
int Graph::bfs(int start, int end){
    fill(this->visited, -1);
    queue<ii> aux;
    aux.emplace(start, 0);
    this->visited[start] = 1;
    int u, dt;
    while(!(aux.empty())){
        tie(u, dt) = aux.front();
        aux.pop();
        if(u == end)
            return dt;
        for(auto e: this->adj[u]){
            if(!~this->visited[e.second]){
                this->visited[e.second] = 1;
                aux.emplace(e.second, dt + 1);
            }
        }
    }
    return -1;
}

int main(){
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    vpii edges = g.kruskalMST();
    for(auto e: edges)
        printf("{%d, %d} => %d\n", e.second.first, e.second.second, e.first);

    return 0;
}