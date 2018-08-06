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
int n, m, s;
vi graph[5001];
int reachable[5001];
int mark[5001];

void dfs(int i){
    reachable[i] = true;
    for(int v: graph[i]){
        if(!(~reachable[v]))
            dfs(v);
    }
}

int dfs_c(int i){
    int ans = 0;
    mark[i] = true;
    for(int v: graph[i]){
        if(!(~mark[v]) and !(~reachable[v]))
            ans += (1 + dfs_c(v));
    }
    return ans;
}

int main(){
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1].push_back(v - 1);
    }
    int ans = 0;
    fill(reachable, -1);
    dfs((s - 1));
    vector<ii> count;
    for(int i = 0; i < n; i++){
        if(!(~reachable[i])){
            fill(mark, -1);
            int aux = dfs_c(i);
            count.emplace_back(aux, i);
        }
    }
    sort(all(count), greater<ii>());
    for(auto e: count){
        if(!(~reachable[e.second])){
            ans++;
            dfs(e.second);
        }
    }
    printf("%d\n", ans);
    return 0;
}