#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> coins;
int table[1000][1000];

int dp(int index, int value){
    if(index >= n)
        return (1e9 + 7);
    if(value == 0)
        return 0;
    if(table[index][value] != -1)
        return table[index][value];
    int ans = (1e9 + 7);
    if(value >= coins[index])
        ans = 1 + dp(index, value - coins[index]);
    ans = min(ans, dp(index + 1, value));
    table[index][value] = ans;
    return ans;
}

int main(){
    memset(table, -1, sizeof(table));
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; i++){
        int coin;
        scanf("%d", &coin);
        coins.push_back(coin);
    }
    printf("%d\n", dp(0, x));
    return 0;
}