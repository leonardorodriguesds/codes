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
int n, k;
long long table[2 * 1001][1001][3];

long long dp(int i, int j, int z){
    if((j < 0) or (i > (2 * n)) or (j > n))
        return 0;
    if((i >= (2 * n)) and (j == 0) and (z == 1))
        return 1;
    if((i >= (2 * n)) and ((j != 0) or (z == 0)))
        return 0;
    if(table[i][j][z] != -1)
        return table[i][j][z];
    long long ans = 0;
    ans += dp((i + 1), (j + 1), (z or (j + 1) >= k));
    ans += dp((i + 1), (j - 1), (z or (j - 1) >= k));
    ans %= (1000000007);
    table[i][j][z] = ans;
    return ans;
}

int main(){
    fill(table, -1);
    scanf("%d %d", &n, &k);
    printf("%lld\n", dp(0, 0, 0));
    return 0;
}