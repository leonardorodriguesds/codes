#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> sizes;
vector<int> cost;
int table[3001][3001][4];

int ans(int i, int last, int bought){
    if(!bought)
        return 0;
    if(i >= n)
        return (1e9 + 7);
    if(table[i][last][bought] != -1)
        return table[i][last][bought];
    int aux = (1e9 + 7);
    if((last == 0 && bought == 3) || (sizes[i] > sizes[last]))
        aux = cost[i] + ans(i + 1, i, bought - 1);
    aux = min(aux, ans(i + 1, last, bought));
    table[i][last][bought] = aux;
    return aux;
}

int main(){
    memset(table, -1, sizeof(table));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        sizes.push_back(aux);
    }
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        cost.push_back(aux);
    }
    int result = ans(0, 0, 3);
    printf("%d\n", (result == (1e9 + 7))? -1 : result);
    return 0;
}