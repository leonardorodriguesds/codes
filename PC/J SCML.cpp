#include <bits/stdc++.h>
using namespace std;
int n;
int numbers[1001];
int table[1001][1002];

int dp(int i, int last){
    if(i >= n)
        return 0;
    if(table[i][last + 1] != -1)
        return table[i][last + 1];
    int ans = 0;
    if((last == -1) or (numbers[i] > numbers[last]))
        ans = 1 + dp(i + 1, i);
    ans = max(ans, dp(i + 1, last));
    table[i][last + 1] = ans;
    return ans;
}

int main(){
    memset(table, -1, sizeof(table));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        numbers[i] = aux;
    }
    printf("%d\n", dp(0, -1));
    return 0;
}