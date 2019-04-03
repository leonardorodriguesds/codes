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

int bfs(int i, int graph[], int visited[]){
    int ans = 1;
    visited[i] = 1;
    if(!~visited[graph[i]]) ans += bfs(graph[i], graph, visited);
    return ans;
}

int main(){
    int t, n, z = 0;
    scanf("%d", &t);
    while((t--) and scanf("%d", &n)){
        int graph[n + 1];
        for(int i = 0; i < n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a - 1] = (b - 1);
        }
        int ans = 0, aux[n], visited[n];
        for(int i = 0; i < n; i++){
            fill(visited, -1);
            aux[i] = bfs(i, graph, visited);
            ans = (aux[i] > aux[ans])? i : ans;
        }
        printf("Case %d: %d\n", ++z, (ans + 1));
    }
    return 0;
}