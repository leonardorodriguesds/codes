#include <bits/stdc++.h>
using namespace std;
#define ALFA            256
#define MOD             1000000007
#define INF             0x3f3f3f3f
#define INFLL           0x3f3f3f3f3f3f3f3f
#define EPS             (1e-9)
#define PI              3.141592653589793238462643383279502884
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b)    (scanf("%d %d", &a, &b))
#define scanf3(a, b, c) (scanf("%d %d %d", &a, &b, &c))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
bool solveIt(int, vvi&);
bool solveItHelper(int, vvi&);
vvi reverseGraph(int, vvi&);

vvi reverseGraph(int n, vvi& graph){
    vvi ans(n, vector<int>(0));
    for(int i = 0; i < n; i++)
        for(int v: graph[i])
            ans[v].push_back(i);
    return ans;
}

bool solveItHelper(int n, vvi& graph){
    int x = n - 1;
    queue<int> aux;
    int visited[n];
    fill(visited, -1);
    visited[0] = 1;
    aux.push(0);
    while(!aux.empty()){
        int u = aux.front();
        aux.pop();
        for(int v: graph[u])
            if(!~visited[v]) x--, aux.push(v), visited[v] = 1;
    }
    if(x) return false;
    return true;
}

bool solveIt(int n, vvi& graph){
    if(!solveItHelper(n, graph)) return false;
    vvi rgraph = reverseGraph(n, graph);
    if(!solveItHelper(n, rgraph)) return false;
    return true;
}

int main(){
    int n, m;
    while(scanf2(n, m) and n != 0 and m != 0){
        vvi graph(n, vector<int>(0));
        for(int i = 0; i < m; i++){
            int v, w, p;
            scanf("%d %d %d", &v, &w, &p);
            graph[v - 1].push_back(w - 1);
            if(p == 2) graph[w - 1].push_back(v - 1);
        }
        bool ans = solveIt(n, graph);
        printf("%d\n", ans? 1 : 0);
    }
    return 0;
}