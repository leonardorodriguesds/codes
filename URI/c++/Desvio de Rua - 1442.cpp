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
    list<int> *adj;
    int *visited;
    void resetVisited(){
        memset(this->visited, -1, this->n * sizeof(int));
    }
    int count_bridges(int, int, int[], int[]);

    public:
        Graph(int n);
        ~Graph();
        void addEdge(int u, int v, bool directed = false);
        bool is_connected(int, bool);
        int count_bridges();
};
Graph::Graph(int n){
    this->n = n;
    this->adj = new list<int>[n];
    this->visited = new int[n];
}
Graph::~Graph(){
    delete [] this->adj;
    delete [] this->visited;
}
void Graph::addEdge(int u, int v, bool directed){
    this->adj[u].push_back(v);
    if(directed)
        this->adj[v].push_back(u);
}
bool Graph::is_connected(int x, bool transv = true){
    this->resetVisited();
    int count = 0;
    stack<int> aux;
    this->visited[x] = 1;
    aux.push(x);
    while(!aux.empty()){
        int u = aux.top();
        aux.pop();
        count++;
        for(int v: this->adj[u]){
            if(!~this->visited[v]){
                this->visited[v] = 1;
                aux.push(v);
            }
        }
    }
    if(count < this->n)
        return false;
    if(!transv)
        return true;

    int v;
    Graph* transverse = new Graph(this->n);
    for(auto i = 0; i < this->n; i++){
        for(int u: this->adj[i]){
            transverse->addEdge(u, i);
            v = u;
        }
    }
    bool ans = transverse->is_connected(v, false);
    delete transverse;
    return ans;
    return true;
}
int Graph::count_bridges(){
    int ans = 0;
    this->resetVisited();
    int disc[this->n], low[this->n];
    for(int i = 0; i < this->n; i++){
        if(!~this->visited[i])
            ans += this->count_bridges(i, -1, disc, low);
    }
    return ans;
}
int Graph::count_bridges(int u, int p , int disc[], int low[]){
    static int time = 0;
    int ans = 0;
    disc[u] = low[u] = time++;
    this->visited[u] = 1;
    for(int v: this->adj[u]){
        if(!~this->visited[v]){
            ans += this->count_bridges(v, u, disc, low);
            low[u] = min(low[u], low[v]);
            if(disc[u] < low[v])
                ans++;
        } else if(v != p)
            low[u] = min(low[u], disc[v]);
    }
    return ans;
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) == 2){
        Graph* directed = new Graph(n);
        Graph* undirected = new Graph(n);
        scanf("%*d %*d %*d");
        int a = 1, b, w;
        for(int i = 0; i < m - 1; i++){
            scanf("%d %d %d", &a, &b, &w);
            directed->addEdge(a - 1, b - 1, (w == 2));
            undirected->addEdge(a - 1, b - 1, true);
        }
        if(!undirected->is_connected(a - 1))
            printf("*\n");
        else if(directed->is_connected(a - 1))
            printf("-\n");
        else if(directed->count_bridges() >= 1)
            printf("2\n");
        else
            printf("1\n");
        delete directed;
        delete undirected;
    }
    return 0;
}