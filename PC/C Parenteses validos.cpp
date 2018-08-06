#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
long long table[1005];

long long dp(int i){
    if(i < 0)
        return 0;
    if(i >= 0 and i <= 1)
        return 1;
    if(table[i] != -1)
        return table[i];
    long long ans = 0;
    for(int j = 0; j < i; j++)
        ans = ((ans + (dp(j) * dp(i - (j + 1)))) % 1000000007);
    table[i] = ans;
    return ans;
}

int main(){
    int n;
    memset(table, -1, sizeof(table));
    scanf("%d", &n);
    printf("%lld\n", dp(n));
    return 0;
}