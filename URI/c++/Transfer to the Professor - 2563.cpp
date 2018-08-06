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

int main(){
    int n, k;
    int candies[101];
    int weights[101];
    while(scanf("%d %d", &n, &k) == 2){
        for (int i = 1; i <= n; i++){
            int aux;
            scanf("%d", &aux);
            candies[i] = aux;
        }
        for (int i = 1; i <= n; i++){
            int aux;
            scanf("%d", &aux);
            weights[i] = aux;
        }
        int table[n + 1][k + 1];
        fill(table, 0);
        for(int i = 1; i <= n; i++){
            for(int w = 1; w <= k; w++){
                if(w >= weights[i])
                    table[i][w] = max(candies[i] + table[i - 1][w - weights[i]], table[i - 1][w]);
                else
                    table[i][w] = table[i - 1][w];
            }
        }
        printf("%d\n", table[n][k]);
    }
    return 0;
}