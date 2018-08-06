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
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vii balls;
        for(int i = 0; i < n; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            balls.emplace_back(x, y);
        }
        int k, r;
        scanf("%d %d", &k, &r);
        int table[n + 1][k + 1];
        for(int i = 0; i <= n; i++){
            for(int w = 0; w <= k; w++){
                if(i == 0 or w == 0)
                    table[i][w] = 0;
                else if(w >= balls[i - 1].second)
                    table[i][w] = max(balls[i - 1].first + table[i - 1][w - balls[i - 1].second], table[i - 1][w]);
                else
                    table[i][w] = table[i - 1][w];
            }
        }
        printf("%s\n", table[n][k] >= r? "Missao completada com sucesso" : "Falha na missao");
    }
    return 0;
}