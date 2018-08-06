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

pair<int, ll> solveIt(int, vpii&);
int count(int, vvi&);

int count(int n, vvi& graph){
    int ans = 0;
    int visited[n];
    fill(visited, -1);
    for(int i = 0; i < n; i++){
        if(!~visited[i]){
            ans++;
            visited[i] = 1;
            stack<int> aux;
            aux.push(i);
            while(!(aux.empty())){
                int u = aux.top();
                aux.pop();
                for(int e: graph[u]){
                    if(!~visited[e]){
                        visited[e] = 1;
                        aux.push(e);
                    }
                }
            }
        }
    }
    return ans;
}

pair<int, ll> solveIt(int n, vpii& edges){
    pair<int, ll> ans;
    ans.first = 0;
    UnionFind aux(n);
    vvi graph(n, vi());
    sort(all(edges));
    for(auto e: edges){
        if(aux.find(e.second.first) != aux.find(e.second.second)){
            aux.c_union(e.second.first, e.second.second);
            ans.second += e.first;
            graph[e.second.first].push_back(e.second.second);
            graph[e.second.second].push_back(e.second.first);
        }
    }
    ans.first = count(n, graph);
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    vpii edges;
    for (int i = 0; i < (n - 1); i++){
        int k;
        scanf("%d", &k);
        while(k--){
            int j, c;
            scanf("%d %d", &j, &c);
            edges.emplace_back(c, make_pair(i, j - 1));
        }
    }
    pair<int, ll> ans = solveIt(n, edges);
    printf("%d %lld\n", ans.first, ans.second);
    return 0;
}