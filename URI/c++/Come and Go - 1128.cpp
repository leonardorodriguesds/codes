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
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;
int visited[2001];

int solveIt(int i, vvi& graph, bool ignore){
    int ans = 0;
    if(!(~visited[i])){
        if(!ignore){
            visited[i] = 1;
            ans++;
        }
        for(int e: graph[i])
            ans += solveIt(e, graph, false);
    }
    return ans;
}

int main(){
    int n, m;
    while(true){
        scanf("%d %d", &n, &m);
        if(n == 0 and m == 0)
            break;
        fill(visited, -1);
        vvi graph(n, vi());
        for (int i = 0; i < m; i++){
            int v, w, p;
            scanf("%d %d %d", &v, &w, &p);
            graph[v - 1].push_back(w - 1);
            if(p == 2)
                graph[w - 1].push_back(v - 1);
        }
        printf("%d\n", (solveIt(0, graph, true) == n)? 1 : 0);
    }
    return 0;
}