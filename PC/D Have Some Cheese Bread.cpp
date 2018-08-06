#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<string, int> msi;

int n;
mii cheese_bread;
vi graph[100005];
int visited[100005][2];

int dp(int i, int opt){
    if(i == (n - 1))
        return ((cheese_bread[i] == 1)? 1 : 0);
    if(visited[i][opt] != -1)
        return visited[i][opt];
    int ans = ((opt)? -INF : INF);
    for(int v: graph[i]){
        int count = dp(v, opt);
        ans = ((opt)? max(ans, count) : min(ans, count));
    }
    ans += ((cheese_bread[i] == 1)? 1 : 0);
    visited[i][opt] = ans;
    return ans;
}

int main(){
    memset(visited, -1, sizeof(visited));
    int c, m;
    scanf("%d %d %d", &n, &c, &m);
    for(int i = 0; i < c; i++){
        int aux;
        scanf("%d", &aux);
        cheese_bread[(aux - 1)] = 1;
    }
    for (int i = 0; i < m; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        graph[(l - 1)].push_back((r - 1));
    }
    int min, max;
    min = dp(0, false);
    max = dp(0, true);
    printf("%d %d\n", min, max);
    return 0;
}