#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
int n, m, a, b;
vector<int> graph[1001];
long long table[1001][1001];

long long dp(int i, int end){
    if(i == end)
        return 1;
    if(i >= n)
        return 0;
    if(table[i][end] != -1)
        return table[i][end];
    long long ans = 0;
    for(int j = 0; j < graph[i].size(); j++)
        ans += dp(graph[i][j], end);
    ans %= 1000000007;
    table[i][end] = ans;
    return ans;
}

int main(){
    memset(table, -1, sizeof(table));
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x - 1].push_back(y - 1);
    }
    scanf("%d %d", &a, &b);
    printf("%lld\n", ((dp(a - 1, b - 1) + dp(b - 1, a - 1)) % 1000000007));
    return 0;
}