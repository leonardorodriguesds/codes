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

class Graph{
    int n;
    vector<int> *adj;
    int *visited;
    int *depth;
    int **parent;
    int level;
    void resetVisited(){
        memset(this->visited, -1, this->n * sizeof(int));
    }
    void dfs(int, int);
    void preComputeMatrix();
    int calculateGifts(int u, int v, vs& gifts, map<string, bool>& controll, int accum);

    public:
        Graph(int n);
        ~Graph();
        void addEdge(int u, int v, bool directed = true);
        void preProcessing();
        int lca(int u, int v, vs& gifts);
};
Graph::Graph(int n){
    this->n = n;
    this->adj = new vector<int>[n];
    this->visited = new int[n];
    this->depth = new int[n];
    this->level = ceil(log(n));
    this->parent = new int*[n];
    for(int i = 0; i < this->n; i++)
        this->parent[i] = new int[this->level];
}
Graph::~Graph(){
    delete [] this->adj;
    delete [] this->visited;
    delete [] this->depth;
    for(int i = 0; i < this->n; i++)
        delete [] this->parent[i];
    delete [] this->parent;
}
void Graph::addEdge(int u, int v, bool directed){
    this->adj[u].push_back(v);
    if(directed)
        this->adj[v].push_back(u);
}
void Graph::preProcessing(){
    for(int i = 0; i < this->n; i++)
        memset(this->parent[i], -1, this->level * sizeof(int));
    memset(this->depth, -1, this->n * sizeof(int));
    this->dfs(1, 0);
    this->preComputeMatrix();
}
void Graph::dfs(int u, int prev){
    this->depth[u] = this->depth[prev] + 1;
    this->parent[u][0] = prev;
    for(int i = 0; i < sz(this->adj[u]); i++){
        if(this->adj[u][i] != prev)
            this->dfs(this->adj[u][i], u);
    }
}
void Graph::preComputeMatrix(){
    for(int i = 1; i < this->level; i++){
        for(int j = 1; j < this->n; j++){
            if(this->parent[j][i - 1] != -1)
                this->parent[j][i] = this->parent[this->parent[j][i - 1]][i - 1];
        }
    }
}
int Graph::lca(int u, int v, vs& gifts){
    if(this->depth[v] < this->depth[u])
        swap(u, v);
    int diff = this->depth[v] - this->depth[u];
    int ou = u, ov = v;
    unordered_map<string, bool> controll;
    for(int i = 0; i < this->level; i++){
        if((diff >> i) & 1)
            v = this->parent[v][i];
    }
    this->resetVisited();
    if(u == v)
        return this->calculateGifts(u, ov, gifts, controll, 0);  
    
    for(int i = this->level - 1; i >= 0; i--){
        if(this->parent[u][i] != this->parent[v][i]){
            u = this->parent[u][i];
            v = this->parent[v][i];
        }
    }
    return (this->calculateGifts(this->parent[u][0], ou, gifts, controll, 0) + this->calculateGifts(this->parent[u][0], ov, gifts, controll, 0)) - 1;
}
int Graph::calculateGifts(int i, int e, vs& gifts, map<string, bool>& controll, int accum){
    this->visited[i] = 1;
    if(i == e){
        int aux = 0;
        if(!controll.count(gifts[i - 1])) aux++;
        controll[gifts[i - 1]] = true;
        return aux;
    }
    int ans = 0;
    for(int v: this->adj[i])
        if(!~this->visited[v]){
            ans += this->calculateGifts(v, e, gifts, controll, accum);
        }
    if(ans and !controll.count(gifts[i - 1])){
        controll[gifts[i - 1]] = true;
        cout << i << " <=> " << e << " " << ans + 1 << endl;
        ans++;
    }
    return ans;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Graph* aux = new Graph(n + 1);
    vs gifts(n, "");
    for(int i = 0; i < n; i++){
        string aux;
        cin >> aux;
        gifts[i] = aux;
    }
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        aux->addEdge(a, b);
    }
    aux->preProcessing();
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", aux->lca(a, b, gifts));
    }
    delete aux;
    return 0;
}