#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> coins;
int table[15][10001];

int dp(int i, int value){
    if(value < 0)
        return 0;
    if(value == 0)
        return 1;
    if(table[i][value] != -1)
        return table[i][value];
    long long ans = 0;
    for(int j = 0; j < n; j++)
        ans += (dp(j, value - coins[j]));
    ans %= 1000000007;
    table[i][value] = ans;
    return ans;
}

int main(){
    memset(table, -1, sizeof(table));
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        coins.push_back(aux);
    }
    
    printf("%d\n", dp(0, x));
    return 0;
}