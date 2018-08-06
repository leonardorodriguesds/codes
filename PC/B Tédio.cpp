#include <bits/stdc++.h>
using namespace std;
int n;
int table[10005];
map<int, int> numbers;

int dp(int value){
    if(value > 10001)
        return 0;
    if(table[value] != -1)
        return table[value];
    int ans = 0;
    if(numbers[value])
        ans = (value * numbers[value] + dp(value + 2)); 
    ans = max(ans, dp(value + 1));
    table[value] = ans;
    return ans;
}

int main(){
    memset(table, -1, sizeof(table));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        numbers[aux]++;
    }
    printf("%d\n", dp(0));
    return 0;
}