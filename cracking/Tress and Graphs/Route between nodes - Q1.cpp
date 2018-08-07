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

    public:
        Graph(int n): n(n){
            this->adj = new list<int>[n];
            this->visited = new int[n];
        };
        ~Graph(){
            delete [] this->adj;
            delete [] this->visited;
        };
        void addEdge(int u, int v, bool directed = false);
        int bfs(int, int);
};
void Graph::addEdge(int u, int v, bool directed){
    this->adj[u].push_back(v);
    if(directed)
        this->adj[v].push_back(u);
}
int Graph::bfs(int x, int y){
    this->resetVisited();
    if(x < 0 or x >= this->n)
        return -1;
    this->visited[x] = 1;
    queue<ii> aux;
    aux.emplace(x, 0);
    int u, dt;
    while(!(aux.empty())){
        tie(u, dt) = aux.front();
        aux.pop();
        if(u == y)
            return dt;
        for(int v: this->adj[u]){
            if(!~this->visited[v]){
                this->visited[v] = 1;
                aux.emplace(v, dt + 1);
            }
        }
    }
    return -1;
}

int main(){
    int n, m, q;
    while(scanf("%d %d %d", &n, &m, &q) == 3){
        if(n == 0)
            break;
        Graph* aux = new Graph(n);
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            aux->addEdge(a, b);
        }
        for(int i = 0; i < q; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            int ans = aux->bfs(a, b);
            if(ans < 0)
                printf("Doesn't exists\n");
            else
                printf("Distance from %d to %d: %d\n", a, b, ans);
        }
        delete aux;
    }
    return 0;
}