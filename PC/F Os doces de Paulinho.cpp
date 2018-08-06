#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
int n, m;
int table[1001][1001];

long long dp(int x, int y){
    if(x == (n - 1) or y == (m - 1))
        return 1;
    if(table[x][y] != -1)
        return table[x][y];
    long long ans = ((dp(x + 1, y)) + (dp(x, y + 1)));
    ans %= 1000000007;
    table[x][y] = ans;
    return ans;
}

int main(){
    memset(table, -1, sizeof(table));
    scanf("%d %d", &n, &m);
    printf("%lld\n", dp(0, 0));
    return 0;
}