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
    int *visited, *disc, *low;
    void resetVisited(){
        memset(this->visited, -1, this->n * sizeof(int));
    }
    public:
        Graph(int n): n(n){
            this->adj = new list<int>[n];
            this->visited = new int[n];
            this->disc = new int[n];
            this->low = new int[n];
        };
        ~Graph(){
            delete [] this->adj;
            delete [] this->visited;
            delete [] this->disc;
            delete [] this->low;
        };
        void addEdge(int u, int v, bool directed = true);
        void solveIt(){
            vi ans;
            this->resetVisited();
            int time = 0;
            this->dfs(0, -1, time, ans);
            sort(all(ans));
            if(sz(ans) >= 1)
                for(int u: ans) printf("%d ", u);
            else printf("nenhum");
        };
        void dfs(int, int, int&, vi&);
};
void Graph::addEdge(int u, int v, bool directed){
    this->adj[u].push_back(v);
    if(directed)
        this->adj[v].push_back(u);
}
void Graph::dfs(int u, int parent, int& time, vi& ans){
    if(!~this->visited[u]){
        bool flag = false;
        int nf = 0;
        this->visited[u] = 1;
        this->disc[u] = this->low[u] = ++time;
        for(int v: this->adj[u]){
            if(!~this->visited[v]){
                nf++;
                if(flag and ((parent == -1 and nf >= 2) or parent != -1)) break;
                this->dfs(v, u, time, ans);
                if(this->low[v] >= this->disc[u]) flag = true;
                this->low[u] = min(this->low[u], this->low[v]);
            } else this->low[u] = min(this->low[u], this->disc[v]);
        }
        if((parent == -1 and nf >= 2) or (parent != -1 and flag)) ans.push_back(u + 1);
    }
}


int main(){
    int n, m, x = 0;
    while(scanf("%d %d", &n, &m) == 2){
        if(n == 0 and m == 0)
            break;
        if(m == 0){
            printf("Teste %d\nnenhum\n\n", ++x);
            continue;
        } 
        Graph* aux = new Graph(n);
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            aux->addEdge(a - 1, b - 1);
        }
        printf("Teste %d\n", ++x);
        aux->solveIt();
        printf("\n\n");
        delete aux;
    }
    return 0;
}