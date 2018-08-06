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
    int *depth;
    int *recStack;
    bool cycleDetect(int);
    void _resetVisited(){
        memset(this->visited, -1, this->n * sizeof(int));
    }
    int bfsHeight(int);

    public:
        Graph(int n);
        ~Graph();
        void addEdge(int u, int v, bool directed = false);
        bool cycleDetect(){
            this->_resetVisited();
            memset(this->recStack, -1, this->n * sizeof(int));
            for(int i = 0; i < this->n; i++){
                if(!~visited[i] and this->cycleDetect(i))
                    return true;
            }
            return false;
        };
        int bfsHeight(){
            int ans = 0;
            this->_resetVisited();
            for(int i = 0; i < this->n; i++){
                if(!~visited[i])
                    ans = max(ans, this->bfsHeight(i));
            }
            return ans;
        };
};
Graph::Graph(int n){
    this->n = n;
    this->adj = new list<int>[n];
    this->visited = new int[n];
    this->recStack = new int[n];
    this->depth = new int[n];
}
Graph::~Graph(){
    delete[] this->adj;
    delete[] this->visited;
    delete[] this->depth;
    delete[] this->recStack;
}
void Graph::addEdge(int u, int v, bool directed){
    this->adj[u].push_back(v);
    if(directed)
        this->adj[v].push_back(u);
}
bool Graph::cycleDetect(int u){
    if(!~this->visited[u]){
        this->visited[u] = 1;
        this->recStack[u] = 1;
        for(int v: this->adj[u]){
            if((!~visited[v] and this->cycleDetect(v)) or (this->recStack[v] == 1))
                return true;
        }
    }
    this->recStack[u] = -1;
    return false;
}
int Graph::bfsHeight(int u){
    int& ans = this->depth[u];
    ans = 0;
    this->visited[u] = 1;
    for(int v: this->adj[u]){
        if(!~this->visited[v])
            ans = max(ans, this->bfsHeight(v));
        else
            ans = max(ans, this->depth[v]);
    }
    ans++;
    return ans;
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        Graph* aux = new Graph(n);
        for(int i = 0; i < n; i++){
            int a, b;
            scanf("%d", &a);
            while(a--){
                scanf("%d", &b);
                aux->addEdge(i, b - 1);
            }
        }
        printf("%d\n", aux->cycleDetect()? -1 : aux->bfsHeight());
        delete aux;
    }
    return 0;
}