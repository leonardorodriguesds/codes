#include <bits/stdc++.h>
using namespace std;
#define MAXN 201
typedef long long ll;

ll bin[MAXN][MAXN];

//Complexity: O(MAXN * K)
void preprocessingHelper(){
    for(int i = 0; i < MAXN; i++){
        bin[i][0] = bin[i][i] = 0;
        for(int j = 1; j < i; j++)
            bin[i][j] = bin[i][j - 1] + bin[i - 1][j - 1];
    }
}

int preprocessingH(int n, int k){
    ll dp[k + 1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = min(i, k); j > 0; j--){
            dp[j] = dp[j] + dp[j + 1];
        }
    }
    return dp[k];
}

int main(){
    
    return 0;
}