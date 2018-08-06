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

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vvi graph(n);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    int visited[n + 1], ans = 0;
    fill(visited, -1);
    for (int i = 0; i < n; i++){
        if(!~visited[i]){
            ans++;
            visited[i] = 1;
            stack<int> aux;
            aux.push(i);
            while(!(aux.empty())){
                int u = aux.top();
                aux.pop();
                for(int v: graph[u]){
                    if(!~visited[v]){
                        visited[v] = 1;
                        aux.push(v);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}