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

void order_topology(int i, vi graph[], deque<int>& aux, int mark[]){
    for(int v: graph[i]){
        if(!(~mark[v])){
            mark[v] = 1;
            order_topology(v, graph, aux, mark);
        }
    }
    aux.push_front(i);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vi graph[n];
    for (int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1].push_back(v - 1);
    }
    int mark[n];
    fill(mark, -1);
    deque<int> topology;
    order_topology(0, graph, topology, mark);
    for(int i = 0; i < sz(topology); i++)
        printf("%d%s", (i + 1), ((i < m)? " -> " : "\n"));
    return 0;
}