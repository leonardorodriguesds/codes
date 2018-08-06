#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, q, l, r;
    scanf("%d %d %d", &n, &m, &q);
    vector<int> graph_in(n, 0);
    vector<int> graph_out(n, 0);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &l, &r);
        graph_in[r - 1]++;
        graph_out[l - 1]++;
    }
    for(int i = 0; i < q; i++){
        scanf("%d %d", &l, &r);
        printf("%d\n", (l == 1) ? graph_out[r - 1]: graph_in[r - 1]);
    }
    return 0;
}