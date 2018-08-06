#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> coins(10001, 0);
int table[10001];

int dp(int i){
    if(i >= n)
        return 0;
    if(table[i] != -1)
        return table[i];
    int ans = max(coins[i] + dp(i + 2), dp(i + 1));
    table[i] = ans;
    return ans;
}

int main(){
    memset(table, -1, sizeof(table));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        coins[i] = aux;
    }
    printf("%d\n", dp(0));
    return 0;
}