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
    int *disc;
    int *low;
    int time;

    public:
        Graph(int n);
        ~Graph();
        void addEdge(int u, int v, bool directed = true);
        int bfs(int i, int f);
        int solveIt();
};
Graph::Graph(int n){
    this->n = n;
    this->adj = new list<int>[n];
    this->visited = new int[n];
    this->disc = new int[n];
    this->low = new int[n];
}
Graph::~Graph(){
    delete [] this->adj;
    delete [] this->visited;
    delete [] this->disc;
    delete [] this->low;
}
void Graph::addEdge(int u, int v, bool directed){
    this->adj[u].push_back(v);
    if(directed)
        this->adj[v].push_back(u);
}
int Graph::solveIt(){
    this->time = 0;
    int aux = 0;
    memset(this->visited, -1, this->n * sizeof(int));
    for(int i = 0; i < this->n; i++){
        if(!~this->visited[i])
            aux += this->bfs(i, i);
    }
    return aux;
}
int Graph::bfs(int u, int f){
    int ans = 0;
    this->disc[u] = this->low[u] = this->time++;
    this->visited[u] = 1;
    for(int v: this->adj[u]){
        if(!~this->visited[v]){
            ans += this->bfs(v, u);
            this->low[u] = min(this->low[u], this->low[v]);
            if(this->low[v] > this->disc[u])
                ans++;
        } else if(v != f)
            this->low[u] = min(this->low[u], this->disc[v]);
    }
    return ans;
}

int main(){
    int c, p;
    while(scanf("%d %d", &c, &p) == 2){
        Graph* graph = new Graph(c);
        for(int i = 0; i < p; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            graph->addEdge(a - 1, b - 1);
        }
        printf("%d\n", graph->solveIt());
        delete graph;
    }
    return 0;
}