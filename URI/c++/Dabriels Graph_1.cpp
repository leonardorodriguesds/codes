#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define SINF            (1e18)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)     (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)     (lower_bound(all(v), x) - v.begin())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;
int tab[101][101][101];

int main(){
    int n, m, q;
    int u, v, w;
    while(scanf("%d %d", &n, &m) == 2){
        for(int i = 0; i <= n; i++){
            for(int u = 0; u <= n; u++)
                tab[i][u][0] = INF;
        }
        for (int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &w);
            tab[u][v][0] = w;
            tab[v][u][0] = w;
        }
        for(int i = 0; i <= n; i++)
            tab[i][i][0] = 0;

        for(int k = 1; k <= n; k++){
            for(int u = 1; u <= n; u++){
                for(int v = 1; v <= n; v++)
                    if(tab[u][v][k - 1] > tab[u][k][k - 1] + tab[k][v][k - 1])
                        tab[u][v][k] = tab[u][k][k - 1] + tab[k][v][k - 1];
                    else
                        tab[u][v][k] = tab[u][v][k - 1];
            }
        }
        
        scanf("%d", &q);
        while(q--){
            int u, v, k;
            scanf("%d %d %d", &u, &v, &k);
            printf("%d\n", tab[u][v][k] == INF? -1 : tab[u][v][k]);
        }
    }
    return 0;
}