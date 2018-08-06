#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        int blocks[n + 1];
        for(int i = 1; i <= n; i++){
            int aux;
            scanf("%d", &aux);
            blocks[i] = aux;
        }
        int table[n + 1][m + 1];
        fill(table, INF);
        for(int i = 0; i <= n; i++)
            table[i][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int w = 1; w <= m; w++)
                if(w >= blocks[i])
                    table[i][w] = min(table[i - 1][w], 1 + table[i][w - blocks[i]]);
                else
                    table[i][w] = table[i - 1][w];
        }
        printf("%d\n", table[n][m]);
    }
    return 0;
}