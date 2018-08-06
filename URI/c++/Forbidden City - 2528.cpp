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

int n, m;
int solveIt(int start, int end, int avoid, vvi& graph){
    int table[n + 1];
    fill(table, -1);
    queue<ii> aux;
    table[start] = 1;
    aux.emplace(start, 0);
    int u, dt;
    while(!(aux.empty())){
        tie(u, dt) = aux.front();
        aux.pop();
        if(u == end)
            return dt;
        for(auto e: graph[u]){
            if((!~table[e]) and (e != avoid)){
                table[e] = 1;
                aux.emplace(e, dt + 1);
            }
        }
    }
    return -1;
}

int main(){
    while(scanf("%d %d", &n, &m) == 2){
        vvi graph(n);
        for (int i = 0; i < m; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            graph[x - 1].push_back(y - 1);
            graph[y - 1].push_back(x - 1);
        }
        int a, b, z;
        scanf("%d %d %d", &a, &b, &z);
        printf("%d\n", solveIt(a - 1, b - 1, z - 1, graph));
    }
    return 0;
}