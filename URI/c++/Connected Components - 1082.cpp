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

class Graph{
    int size;
    vvi graph;
    vector<bool> visited;

    void _create_edge(int x, int y, bool directed){
        if(size < x + 1 or size < y + 1)
            return;
        graph[x].push_back(y);
        if(!directed)
            graph[y].push_back(x);
    }
    vvi _connected_components(){
        vvi ans;
        visited = vector<bool>(size, false);
        for (int i = 0; i < size; i++){
            vi aux;
            _connected_component(i, aux);
            if(sz(aux)){
                sort(all(aux));
                ans.push_back(aux);
            }
        }
        return ans;
    }
    void _connected_component(int i, vi& aux){
        if(!visited[i]){
            visited[i] = true;
            aux.push_back(i);
            for(int u: graph[i])
                _connected_component(u, aux);
        }
    }
    public:
        Graph(int sz): graph(sz, vi()){ size = sz; }
        vvi connected_components(){ return _connected_components(); }
        vi _connected_component(int i){
            vi aux;
            _connected_component(i, aux);
            return aux;
        }
        void edge(int x, int y, bool directed = true) {return _create_edge(x, y, directed);}
};

int main(){
    int n, j = 0;
    scanf("%d", &n);
    while(n--){
        j++;
        int v, e;
        scanf("%d %d", &v, &e);
        Graph graph(v);
        for (int i = 0; i < e; i++){
            char a, b;
            cin >> a >> b;
            graph.edge(a - 'a', b - 'a', false);
        }
        vvi ans = graph.connected_components();
        printf("Case #%d:\n", j);
        for(vi component: ans){
            int i = 0;
            for(int elem: component)
                printf("%c,", elem + 'a');
            printf("\n");
        }
        printf("%d connected components%s", sz(ans), (j == n? "\n": "\n\n"));
    }
    return 0;
}