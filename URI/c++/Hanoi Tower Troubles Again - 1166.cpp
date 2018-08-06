#include <bits/stdc++.h>
using namespace std;
int num;
int table[51][51];

int dp(int i, int z, int n){
    if(i >= num)
        return -(1e9 + 7);
    if(!n)
        return 0;
    
    int ans = 0;
    if((z == 0 and n == num) or (sqrt((i + 1) + (z + 1)) * sqrt((i + 1) + (z + 1)) == (i + 1) + (z + 1)))
        ans = 1 + dp(i + 1, i, n - 1);
    ans = max(ans, dp(i + 1, z, n));
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        memset(table, -1, sizeof(table));
        scanf("%d", &num);
        printf("%d\n", dp(0, 0, num));
    }
    return 0;
}