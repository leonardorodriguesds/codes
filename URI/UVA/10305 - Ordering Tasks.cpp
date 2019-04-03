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
int visited[101];

void topologyOrder(int i, vvi& graph, deque<int>& ans){
    visited[i] = 1;
    for(int v: graph[i])
        if(!~visited[v]) topologyOrder(v, graph, ans);
    ans.push_front(i + 1);
}

int main(){
    int n, m;
    while(scanf2(n, m) and !(n == 0 and m == 0)){
        vvi graph(n);
        while(m--){
            int x, y;
            scanf2(x, y);
            graph[x - 1].push_back(y - 1);
        }
        fill(visited, -1);
        deque<int> ans;
        for(int i = 0; i < n; i++)
            if(!~visited[i]) topologyOrder(i, graph, ans);
        for(int u: ans) printf("%d ", u);
        printf("\n");
    }
    return 0;
}