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
int table[100005];
int coins[1005];

int main(){
    int v, n;
    while(true){
        scanf("%d %d", &v, &n);
        if(v == 0 and n == 0)
            break;
        for (int i = 1; i <= n; i++){
            int aux;
            scanf("%d", &aux);
            coins[i] = aux;
        }
        fill(table, INF);
        table[0] = 0;
        for (int w = 0; w <= v; w++){
            for (int i = 1; i <= n; i++){
                if(w >= coins[i])
                    table[w] = 1 + table[w - coins[i]];
            }
        }
        printf("%s\n", table[v] <= n? "sim" : "nao");
    }
    return 0;
}