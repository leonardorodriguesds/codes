#include <bits/stdc++.h>
using namespace std;
int w, n;
vector<int> weight;
vector<int> cost;
int table[1000][1000];

int dp(int i, int x){
    if(i >= n || x == 0)
        return 0;
    if(table[i][x] != -1)
        return table[i][x];
    int ans = 0;
    if(x >= weight[i])
        ans = cost[i] + dp(i + 1, x - weight[i]);
    ans = max(ans, dp(i + 1, x));
    table[i][x] = ans;
    return ans;
}

int main(){
    memset(table, -1, sizeof(table));
    scanf("%d %d", &w, &n);
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        weight.push_back(aux);
    }
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        cost.push_back(aux);
    }
    printf("%d\n", dp(0, w));
    return 0;
}